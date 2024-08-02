/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamsalem <eamsalem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 11:25:39 by eamsalem          #+#    #+#             */
/*   Updated: 2024/08/02 11:42:11 by eamsalem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FdF.h"

//	TODO:
// 	- add colour gradient

//	- if there is time: add a scaling factor depending on range of z values

int	main(int argc, char **argv)
{
	t_mlx_data	mlx;
	int			fd;
	char		*file_contents;

	if (argc != 2)
		return (1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit(EXIT_FAILURE);
	init_mlx_data(&mlx);
	init_img_data(&mlx.img, &mlx);
	file_contents = read_file(fd, &mlx);
	mlx.file_data = parse_file(file_contents, &mlx);
	init_grid_data(&mlx);
	isometric_projection(&mlx.grid);
	draw_model(&mlx);
	mlx_hook(mlx.win, KEY_PRS_EVT, 1L << 0, key_event, &mlx);
	mlx_hook(mlx.win, BTN_PRS_EVT, 1L << 2, mouse_event, &mlx);
	mlx_hook(mlx.win, DESTROY_EVT, 1L << 17, close_window, &mlx);
	mlx_loop(mlx.ptr);
}

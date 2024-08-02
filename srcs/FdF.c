/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamsalem <eamsalem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 11:25:39 by eamsalem          #+#    #+#             */
/*   Updated: 2024/08/02 12:47:55 by eamsalem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FdF.h"

void	isometric_projection(t_grid_data *grid)
{
	rotate('x', 30, grid);
	rotate('y', -30, grid);
	rotate('z', 30, grid);
}

void	side_projection(t_grid_data *grid)
{
	rotate('x', 90, grid);
}

void	init_grid_data(t_mlx_data *mlx)
{
	mlx->grid.width = ft_2darr_len((void *)(mlx->file_data));
	mlx->grid.len = ft_2darr_len((void *)(mlx->file_data[0]));
	init_grid_coords(&mlx->grid, mlx);
	init_grid_scale(&mlx->grid);
	init_grid_colours(&mlx->grid);
	scale_img(&mlx->grid);
	find_img_centre(&mlx->grid);
}

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
//	side_projection(&mlx.grid);
	recentre_img(&mlx.grid);
	draw_model(&mlx);
	mlx_hook(mlx.win, KEY_PRS_EVT, 1L << 0, key_event, &mlx);
	mlx_hook(mlx.win, BTN_PRS_EVT, 1L << 2, mouse_event, &mlx);
	mlx_hook(mlx.win, DESTROY_EVT, 1L << 17, close_window, &mlx);
	mlx_loop(mlx.ptr);
}

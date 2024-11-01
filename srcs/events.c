/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 10:26:57 by eamsalem          #+#    #+#             */
/*   Updated: 2024/11/01 07:43:51 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FdF.h"

int	mouse_event(int button, int x, int y, t_mlx_data *mlx)
{
	(void)x;
	(void)y;
	clear_img(mlx);
	if (button == SCROLL_UP)
		zoom(&mlx->grid, 20);
	if (button == SCROLL_DOWN)
		zoom(&mlx->grid, -20);
	draw_model(mlx);
	return (-1);
}

int	key_event(int keysym, t_mlx_data *mlx)
{
	clear_img(mlx);
	if (keysym == ESC_KEY)
		close_window(mlx);
	else if (keysym == A_KEY)
		rotate(Z_AXIS, -2, &mlx->grid);
	else if (keysym == D_KEY)
		rotate(Z_AXIS, 2, &mlx->grid);
	else if (keysym == W_KEY)
		rotate(X_AXIS, 2, &mlx->grid);
	else if (keysym == S_KEY)
		rotate(X_AXIS, -2, &mlx->grid);
	else if (keysym == Q_KEY)
		rotate(Y_AXIS, -2, &mlx->grid);
	else if (keysym == E_KEY)
		rotate(Y_AXIS, 2, &mlx->grid);
	else if (keysym == RIGHT_KEY)
		shift_x(4, &mlx->grid);
	else if (keysym == LEFT_KEY)
		shift_x(-4, &mlx->grid);
	else if (keysym == UP_KEY)
		shift_y(-4, &mlx->grid);
	else if (keysym == DOWN_KEY)
		shift_y(4, &mlx->grid);
	draw_model(mlx);
	return (0);
}

int	close_window(t_mlx_data *mlx)
{
	free_mem(mlx);
	exit(EXIT_SUCCESS);
}

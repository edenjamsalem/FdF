/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamsalem <eamsalem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 11:21:20 by eamsalem          #+#    #+#             */
/*   Updated: 2024/08/02 11:49:54 by eamsalem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FdF.h"

int	rgb_to_hex(t_colour colour)
{
	return ((colour.t << 24) | (colour.r << 16) | (colour.g << 8) | colour.b);
}

t_colour	hex_to_rgb(int hex)
{
	t_colour	colour;

	colour.t = (hex >> 24) & 0xFF;
	colour.r = (hex >> 16) & 0xFF;
	colour.g = (hex >> 8) & 0xFF;
	colour.b = hex & 0xFF;
	return (colour);
}

t_colour	terp_colour(t_colour color_1, t_colour color_2, float t)
{
	t_colour	result;

	if (t < 0.0f)
		t = 0.0f;
	if (t > 1.0f)
		t = 1.0f;
	result.r = (unsigned char)(color_1.r + t * (color_2.r - color_1.r));
	result.g = (unsigned char)(color_1.g + t * (color_2.g - color_1.g));
	result.b = (unsigned char)(color_1.b + t * (color_2.b - color_1.b));
	return (result);
}

double	find_t(double z, t_grid_data *grid)
{
	double	z_min;
	double	z_max;

	z_min = grid->range.z_min;
	z_max = grid->range.z_max;
	return ((z - z_min) / (z_max - z_min));
}

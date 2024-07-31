#include "FdF.h"

int	rgb_to_hex(t_colour colour)
{
	return ((colour.r << 16) | (colour.g << 8) | colour.b);
}

t_colour hex_to_rgb(int hex)
{
    t_colour colour;

    colour.r = (hex >> 16) & 0xFF;
    colour.g = (hex >> 8) & 0xFF;
    colour.b = hex & 0xFF;
    return colour;
}

t_colour interpolate_colour(t_colour start, t_colour end, float t)
{
    t_colour result;

    result.r = (int)((1 - t) * start.r + t * end.r);
    result.g = (int)((1 - t) * start.g + t * end.g);
    result.b = (int)((1 - t) * start.b + t * end.b);
    return result;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parallels <parallels@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 11:06:44 by parallels         #+#    #+#             */
/*   Updated: 2022/04/12 11:07:01 by parallels        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;
	
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

/* 
*  Bresenham's algorithm to draw a line
*/
void	draw_line(t_img *data, t_point a, t_point b, int color)
{
	int	dx;
	int	dy;
	int	d;
	int	y;
	int	x;

	dx = b.x - a.x;
	dy = b.y - a.y;
	d = 2 * dy - dx;
	y = a.y;
	x = a.x;
	while (x < b.x)
	{
		my_mlx_pixel_put(data, x, y, color);
		if (d > 0)
		{
			y++;
			d = d - 2 * dx;
		}
		d = d + 2 * dy;
		x++;
	}
}
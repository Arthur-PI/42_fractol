/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 21:38:04 by apigeon           #+#    #+#             */
/*   Updated: 2022/04/11 20:53:34 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_line(t_data *data, t_point a, t_point b, int color)
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

int main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WINDOW_WIDTH, WNIDOW_HEIGHT, WINDOW_TITLE);
	img.img = mlx_new_image(mlx, WINDOW_WIDTH, WNIDOW_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	draw_line(&img, (t_point){100, 100}, (t_point){800, 100}, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
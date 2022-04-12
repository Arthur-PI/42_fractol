/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parallels <parallels@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 21:38:04 by apigeon           #+#    #+#             */
/*   Updated: 2022/04/12 14:11:56 by parallels        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	init_mlx(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		exit(error("Can't initialize the mlx instance", 1));
	mlx->win = mlx_new_window(mlx->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
	if (!mlx->win)
		exit(error("Can't create a new mlx window", 1));

}

static void	usage(char *name)
{
	printf("Usage: %s [julia|mandelbrot]\n", name);
	exit(1);
}

static int	valid_fractal(char *fractal)
{
	if (ft_strncmp(fractal, "julia", ft_strlen(fractal)) == 0)
		return (1);
	if (ft_strncmp(fractal, "mandelbrot", ft_strlen(fractal)) == 0)
		return (1);
	return (0);
}

int main(int ac, char **av)
{
	t_mlx	mlx;
	// t_img	img;

	if (ac != 2)
		usage(av[0]);
	if (!valid_fractal(av[1]))
		usage(av[0]);
	init_mlx(&mlx);
	setup_hooks(&mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
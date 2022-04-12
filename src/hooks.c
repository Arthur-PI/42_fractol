/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parallels <parallels@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 11:25:37 by parallels         #+#    #+#             */
/*   Updated: 2022/04/12 13:39:05 by parallels        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void zoom_in(int x, int y, t_mlx *mlx)
{
    (void)mlx;
    printf("Zooming in at (%d,%d)\n", x, y);
}

static void zoom_out(int x, int y, t_mlx *mlx)
{
    (void)mlx;
    printf("Zooming out at (%d,%d)\n", x, y);
}

static int quit(t_mlx *mlx)
{
    mlx_loop_end(mlx->mlx);
    mlx_destroy_window(mlx->mlx, mlx->win);
    return (0);
}

static int key_hook(int keycode, t_mlx *mlx)
{
    if (keycode == KEY_ESC)
        quit(mlx);
    return (0);
}

static int mouse_hook(int button, int x, int y, t_mlx *mlx)
{
    if (button == MOUSE_SCROLL_UP)
        zoom_in(x, y, mlx);
    else if (button == MOUSE_SCROLL_DOWN)
        zoom_out(x, y, mlx);
    return (0);
}

void    setup_hooks(t_mlx *mlx)
{
    mlx_hook(mlx->win, ON_DESTROY, MASK_NO_EVENT, quit, mlx);
    mlx_hook(mlx->win, ON_KEYDOWN, MASK_KEY_PRESS, key_hook, mlx);
    mlx_mouse_hook(mlx->win, mouse_hook, mlx);
}
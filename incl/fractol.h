/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parallels <parallels@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 21:38:56 by apigeon           #+#    #+#             */
/*   Updated: 2022/04/12 13:32:17 by parallels        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <math.h>
# include <X11/X.h>
# include "libft.h"
# include "mlx.h"

# include <stdio.h>

# define WINDOW_HEIGHT 700
# define WINDOW_WIDTH 1000
# define WINDOW_TITLE "Fract'ol"

typedef struct s_img
{
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
}               t_img;

typedef struct s_mlx
{
    void    *mlx;
    void    *win;
}               t_mlx;


typedef struct s_point
{
    int x;
    int y;
}               t_point;

enum 
{
    ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

enum 
{
    KEY_ESC = 65307
};

enum 
{
    MOUSE_CLICK = 1,
    MOUSE_RIGHT_CLICK = 3,
    MOUSE_MIDDLE_CLICK = 2,
    MOUSE_SCROLL_UP = 4,
    MOUSE_SCROLL_DOWN = 5
};

enum 
{
    MASK_NO_EVENT = 0L,
    MASK_KEY_PRESS = 1L << 0,
};

int     get_color(int red, int green, int blue, int transarancy);

void    my_mlx_pixel_put(t_img *data, int x, int y, int color);
void    draw_line(t_img *data, t_point a, t_point b, int color);

int     error(char *message, int code);

void    setup_hooks(t_mlx *mlx);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 21:38:56 by apigeon           #+#    #+#             */
/*   Updated: 2022/03/23 23:12:15 by apigeon          ###   ########.fr       */
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

# define WNIDOW_HEIGHT 700
# define WINDOW_WIDTH 1000
# define WINDOW_TITLE "Fract'Ol"

typedef struct s_data
{
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
}               t_data;

typedef struct s_point
{
    int x;
    int y;
}               t_point;


#endif

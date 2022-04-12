/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parallels <parallels@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 10:59:30 by parallels         #+#    #+#             */
/*   Updated: 2022/04/12 11:05:49 by parallels        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int get_color(int red, int green, int blue, int transparancy)
{
    return (transparancy << 24 | red << 16 | green << 8 | blue);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   green.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpankewi <mpankewi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:45:07 by mpankewi          #+#    #+#             */
/*   Updated: 2022/11/22 10:19:53 by mpankewi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	greencolor(t_fractol *f, int n)
{
	if (n <= 5)
		my_mlx_pixel_put(f, f->x, f->y, 0x00000D00);
	else if (n <= 10)
		my_mlx_pixel_put(f, f->x, f->y, 0x00002D00);
	else if (n <= 15)
		my_mlx_pixel_put(f, f->x, f->y, 0x00004200);
	else if (n <= 20)
		my_mlx_pixel_put(f, f->x, f->y, 0x00005B00);
	else if (n <= 25)
		my_mlx_pixel_put(f, f->x, f->y, 0x00007417);
	else if (n <= 30)
		my_mlx_pixel_put(f, f->x, f->y, 0x001E8F31);
	else if (n <= 35)
		my_mlx_pixel_put(f, f->x, f->y, 0x0041AA4A);
	else if (n <= 40)
		my_mlx_pixel_put(f, f->x, f->y, 0x005FC663);
	else
		g2(f, n);
}

void	g2(t_fractol *f, int n)
{
	if (n <= 45)
		my_mlx_pixel_put(f, f->x, f->y, 0x007BE27D);
	else if (n <= 50)
		my_mlx_pixel_put(f, f->x, f->y, 0x00A0E989);
	else if (n <= 55)
		my_mlx_pixel_put(f, f->x, f->y, 0x00BDFFA4);
	else if (n <= 60)
		my_mlx_pixel_put(f, f->x, f->y, 0x00D9FFBF);
	else if (n <= 65)
		my_mlx_pixel_put(f, f->x, f->y, 0x00E9FFC7);
	else if (n <= 70)
		my_mlx_pixel_put(f, f->x, f->y, 0x00D6FFc4);
	else if (n <= 75)
		my_mlx_pixel_put(f, f->x, f->y, 0x00F7FFDC);
	else if (n <= 80)
		my_mlx_pixel_put(f, f->x, f->y, 0x00FFFFF9);
}

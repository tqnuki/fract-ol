/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpankewi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 12:44:34 by mpankewi          #+#    #+#             */
/*   Updated: 2022/11/22 12:44:53 by mpankewi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	vinit(t_fractol *f)
{
	f->v[0] = 0x00FF0000;
	f->v[1] = 0x00FF8000;
	f->v[2] = 0x00FFFF00;
	f->v[3] = 0x0080FF00;
	f->v[4] = 0x0000FF00;
	f->v[5] = 0x0000FF80;
	f->v[6] = 0x0000FFFF;
	f->v[7] = 0x000080FF;
	f->v[8] = 0x000000FF;
	f->v[9] = 0x007F00FF;
	f->v[10] = 0x00FF00FF;
	f->v[11] = 0x00FF007F;
}

void	rgb(t_fractol *f, int n)
{
	if (n <= 7)
		my_mlx_pixel_put(f, f->x, f->y, f->v[f->i]);
	else if (n <= 14)
		my_mlx_pixel_put(f, f->x, f->y, f->v[abs(f->i - 1)]);
	else if (n <= 21)
		my_mlx_pixel_put(f, f->x, f->y, f->v[abs(f->i - 2)]);
	else if (n <= 28)
		my_mlx_pixel_put(f, f->x, f->y, f->v[abs(f->i - 3)]);
	else if (n <= 35)
		my_mlx_pixel_put(f, f->x, f->y, f->v[abs(f->i - 4)]);
	else if (n <= 42)
		my_mlx_pixel_put(f, f->x, f->y, f->v[abs(f->i - 5)]);
	else if (n <= 47)
		my_mlx_pixel_put(f, f->x, f->y, f->v[abs(f->i - 6)]);
	else if (n <= 54)
		my_mlx_pixel_put(f, f->x, f->y, f->v[abs(f->i - 7)]);
	else if (n <= 61)
		my_mlx_pixel_put(f, f->x, f->y, f->v[abs(f->i - 8)]);
	else if (n <= 68)
		my_mlx_pixel_put(f, f->x, f->y, f->v[abs(f->i - 9)]);
	else if (n <= 75)
		my_mlx_pixel_put(f, f->x, f->y, f->v[abs(f->i - 10)]);
	else if (n <= 80)
		my_mlx_pixel_put(f, f->x, f->y, f->v[abs(f->i - 11)]);
}

int	render_next_frame(t_fractol *f)
{
	if (f->rgb == 1)
	{
		if (f->i == 11)
			f->i = 0;
		else
			f->i++;
		fractol(f);
	}
	return (0);
}

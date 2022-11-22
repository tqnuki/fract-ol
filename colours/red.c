/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpankewi <mpankewi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:44:41 by mpankewi          #+#    #+#             */
/*   Updated: 2022/11/22 12:37:55 by mpankewi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	redcolor(t_fractol *f, int n)
{
	if (n <= 5)
		my_mlx_pixel_put(f, f->x, f->y, 0x000e0000);
	else if (n <= 10)
		my_mlx_pixel_put(f, f->x, f->y, 0x001c0000);
	else if (n <= 15)
		my_mlx_pixel_put(f, f->x, f->y, 0x002a0000);
	else if (n <= 20)
		my_mlx_pixel_put(f, f->x, f->y, 0x00460000);
	else if (n <= 25)
		my_mlx_pixel_put(f, f->x, f->y, 0x00610000);
	else if (n <= 30)
		my_mlx_pixel_put(f, f->x, f->y, 0x007d0000);
	else if (n <= 35)
		my_mlx_pixel_put(f, f->x, f->y, 0x008b0000);
	else if (n <= 40)
		my_mlx_pixel_put(f, f->x, f->y, 0x00ff0000);
	else
		r2(f, n);
}

void	r2(t_fractol *f, int n)
{
	if (n <= 45)
		my_mlx_pixel_put(f, f->x, f->y, 0x00df2c14);
	else if (n <= 50)
		my_mlx_pixel_put(f, f->x, f->y, 0x00ed3419);
	else if (n <= 55)
		my_mlx_pixel_put(f, f->x, f->y, 0x00fb3b1e);
	else if (n <= 60)
		my_mlx_pixel_put(f, f->x, f->y, 0x00ff4122);
	else if (n <= 65)
		my_mlx_pixel_put(f, f->x, f->y, 0x00ff6242);
	else if (n <= 70)
		my_mlx_pixel_put(f, f->x, f->y, 0x00ff8164);
	else if (n <= 75)
		my_mlx_pixel_put(f, f->x, f->y, 0x00ffa590);
	else if (n <= 80)
		my_mlx_pixel_put(f, f->x, f->y, 0x00ffc9bb);
}

void	checkac(int ac)
{
	if (ac != 2)
	{
		ft_putstr_fd("Too many arguments\n", 1);
		exit(0);
	}
}

void	my_mlx_pixel_put(t_fractol *f, int x, int y, int color)
{
	char	*dst;

	dst = f->addr + (y * f->line_length + x * (f->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

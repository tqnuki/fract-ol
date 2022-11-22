/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpankewi <mpankewi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:13:34 by mpankewi          #+#    #+#             */
/*   Updated: 2022/11/22 10:28:55 by mpankewi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(double Z_im, double Z_re, unsigned maxiter, t_fractol *f)
{
	int		n;
	int		isin;
	double	tmp;

	isin = 1;
	n = 0;
	while (n < maxiter)
	{
		if (Z_im * Z_im + Z_re * Z_re > 4)
		{
			isin = 0;
			break ;
		}
		tmp = 2 * Z_re * Z_im + f->c_i;
		Z_re = Z_re * Z_re - Z_im * Z_im + f->c_r;
		Z_im = tmp;
		n++;
	}
	if (isin)
		my_mlx_pixel_put(f, f->x, f->y, 0x00000000);
	else
		handlecolor(f, n);
}

void	julia(double Z_im, double Z_re, unsigned maxiter, t_fractol *f)
{
	int		n;
	int		isin;
	double	tmp;

	isin = 1;
	n = 0;
	while (n < maxiter)
	{
		if (Z_im * Z_im + Z_re * Z_re > 4)
		{
			isin = 0;
			break ;
		}
		tmp = 2 * Z_re * Z_im + f->c_i;
		Z_re = Z_re * Z_re - Z_im * Z_im + f->c_r;
		Z_im = tmp;
		n++;
	}
	if (isin)
		my_mlx_pixel_put(f, f->x, f->y, 0x00000000);
	else
		handlecolor(f, n);
}

void	burningship(double Z_im, double Z_re, unsigned maxiter, t_fractol *f)
{
	int		n;
	int		isin;
	double	tmp;

	isin = 1;
	n = 0;
	while (n < maxiter)
	{
		if (Z_im * Z_im + Z_re * Z_re > 4)
		{
			isin = 0;
			break ;
		}
		Z_im = fabs(Z_im);
		Z_re = fabs(Z_re);
		tmp = 2 * Z_re * Z_im + f->c_i;
		Z_re = Z_re * Z_re - Z_im * Z_im + f->c_r;
		Z_im = tmp;
		n++;
	}
	if (isin)
		my_mlx_pixel_put(f, f->x, f->y, 0x00000000);
	else
		handlecolor(f, n);
}

double	ft_atof(const char *str)
{
	int		s;
	int		e;
	double	num;
	double	point;

	s = 1;
	e = 1;
	num = 0;
	point = 0.0;
	if (!ft_strchr(str, '.'))
		return (ft_atoi(str));
	if (*str == '-')
	{
		s = -1;
		str++;
	}
	while (ft_isdigit(*str))
		num = num * 10 + *str++ - '0';
	str++;
	while (ft_isdigit(*str))
	{
		point = point * 10 + *str++ - '0';
		e *= 10;
	}
	return (s * (num + point / e));
}

void	fractol(t_fractol *f)
{
	unsigned int	maxiter;
	double			z_re;
	double			z_im;

	maxiter = 80;
	f->y = 0;
	while (f->y < SIZE)
	{
		f->x = 0;
		if (f->type != 3)
			f->c_i = f->maxi - f->y * (f->maxi - f->mini) / (SIZE - 1);
		while (f->x < SIZE)
		{
			if (f->type != 3)
				f->c_r = f->minr + f->x * (f->maxr - f->minr) / (SIZE - 1);
			z_re = f->minr + f->x * (f->maxr - f->minr) / (SIZE - 1);
			z_im = f->maxi - f->y * (f->maxi - f->mini) / (SIZE - 1);
			handletype(z_im, z_re, maxiter, f);
			f->x++;
		}
		f->y++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}

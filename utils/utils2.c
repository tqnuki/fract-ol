/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpankewi <mpankewi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:44:35 by mpankewi          #+#    #+#             */
/*   Updated: 2022/11/22 12:44:14 by mpankewi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	handleargs(t_fractol *f, int ac, char **av)
{
	if (ft_strncmp(av[1], "mandelbrot", ft_strlen(av[1])) == 0)
	{
		checkac(ac);
		f->type = 1;
		return (1);
	}
	if (ft_strncmp(av[1], "burningship", ft_strlen(av[1])) == 0)
	{
		checkac(ac);
		f->type = 2;
		return (1);
	}
	if (ft_strncmp(av[1], "julia", ft_strlen(av[1])) == 0)
	{
		argjulia(f, ac, av);
		return (1);
	}
	ft_putstr_fd("Not a supported fractal type, please put \"mandelbrot", 1);
	ft_putstr_fd("\", \"julia\", or \"burningship\"\n", 1);
	return (0);
}

void	handlecolor(t_fractol *f, int n)
{
	if (f->rgb == 1)
		rgb(f, n);
	else if (f->col == 0)
		redcolor(f, n);
	else if (f->col == 1)
		greencolor(f, n);
	else if (f->col == 2)
		bluecolor(f, n);
}

void	handletype(double Z_im, double Z_re, unsigned maxiter, t_fractol *f)
{
	if (f->type == 1)
		mandelbrot(Z_im, Z_re, maxiter, f);
	if (f->type == 2)
		burningship(Z_im, Z_re, maxiter, f);
	if (f->type == 3)
		julia(Z_im, Z_re, maxiter, f);
}

void	structinit(t_fractol *f)
{
	f->mlx = NULL;
	f->win = NULL;
	f->minr = -2.0;
	f->maxr = 1.0;
	f->mini = -1.2;
	f->maxi = f->mini + (f->maxr - f->minr);
	f->col = 0;
	f->bits_per_pixel = 0;
	f->line_length = 0;
	f->endian = 0;
	f->rgb = 0;
	f->i = 0;
	vinit(f);
}

void	mlxinit(t_fractol *f)
{
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, SIZE, SIZE, "fractol");
	f->img = mlx_new_image(f->mlx, SIZE, SIZE);
	f->addr = mlx_get_data_addr(f->img, &f->bits_per_pixel, &f->line_length,
			&f->endian);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blue.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpankewi <mpankewi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:53:53 by mpankewi          #+#    #+#             */
/*   Updated: 2022/11/22 11:17:50 by mpankewi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	bluecolor(t_fractol *f, int n)
{
	if (n <= 5)
		my_mlx_pixel_put(f, f->x, f->y, 0x00000c19);
	else if (n <= 10)
		my_mlx_pixel_put(f, f->x, f->y, 0x00001833);
	else if (n <= 15)
		my_mlx_pixel_put(f, f->x, f->y, 0x0000254d);
	else if (n <= 20)
		my_mlx_pixel_put(f, f->x, f->y, 0x00003d80);
	else if (n <= 25)
		my_mlx_pixel_put(f, f->x, f->y, 0x000055b3);
	else if (n <= 30)
		my_mlx_pixel_put(f, f->x, f->y, 0x000062cc);
	else if (n <= 35)
		my_mlx_pixel_put(f, f->x, f->y, 0x00006ee6);
	else if (n <= 40)
		my_mlx_pixel_put(f, f->x, f->y, 0x00004FBB);
	else
		b2(f, n);
}

void	b2(t_fractol *f, int n)
{
	if (n <= 45)
		my_mlx_pixel_put(f, f->x, f->y, 0x00005BC9);
	else if (n <= 50)
		my_mlx_pixel_put(f, f->x, f->y, 0x000068D7);
	else if (n <= 55)
		my_mlx_pixel_put(f, f->x, f->y, 0x000075E4);
	else if (n <= 60)
		my_mlx_pixel_put(f, f->x, f->y, 0x00008FFF);
	else if (n <= 65)
		my_mlx_pixel_put(f, f->x, f->y, 0x0019A5FF);
	else if (n <= 70)
		my_mlx_pixel_put(f, f->x, f->y, 0x004DB9FF);
	else if (n <= 75)
		my_mlx_pixel_put(f, f->x, f->y, 0x0080CDFF);
	else if (n <= 80)
		my_mlx_pixel_put(f, f->x, f->y, 0x00B3E1FF);
}

void	argjulia(t_fractol *f, int ac, char **av)
{
	f->type = 3;
	if (ac == 3 || ac == 2)
	{
		ft_putstr_fd("Bad arguments for julia\n", 1);
		exit(0);
	}
	else
	{
		f->c_r = ft_atof(av[2]);
		f->c_i = ft_atof(av[3]);
	}
}

char	*ft_strchr(const char *s, int c)
{
	char	ch;

	ch = (char) c;
	while (*s)
	{
		if (*s == ch)
			return ((char *)s);
		s++;
	}
	if (*s == ch)
		return ((char *) s);
	return (0);
}

int	ft_isdigit(int c)
{
	int	i;

	i = 0;
	if (c >= '0' && c <= '9')
		i = 1;
	return (i);
}

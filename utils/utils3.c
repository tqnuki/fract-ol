/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpankewi <mpankewi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:47:25 by mpankewi          #+#    #+#             */
/*   Updated: 2022/11/22 11:39:31 by mpankewi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	zoom(t_fractol *f, double zoom)
{
	f->maxr = f->maxr + ((f->minr - f->maxr) - zoom * (f->minr - f->maxr)) / 2;
	f->minr = f->maxr + zoom * (f->minr - f->maxr);
	f->mini = f->mini + ((f->maxi - f->mini) - zoom * (f->maxi - f->mini)) / 2;
	f->maxi = f->mini + zoom * (f->maxi - f->mini);
}

void	move(t_fractol *f, double d, char dir)
{
	if (dir == 'L')
	{
		f->minr -= (f->maxr - f->minr) * d;
		f->maxr -= (f->maxr - f->minr) * d;
	}
	if (dir == 'R')
	{
		f->minr += (f->maxr - f->minr) * d;
		f->maxr += (f->maxr - f->minr) * d;
	}
	if (dir == 'U')
	{
		f->mini += (f->maxi - f->mini) * d;
		f->maxi += (f->maxi - f->mini) * d;
	}
	if (dir == 'D')
	{
		f->mini -= (f->maxi - f->mini) * d;
		f->maxi -= (f->maxi - f->mini) * d;
	}
}

int	key_handler(int key, t_fractol *f, void *param)
{
	k2(key, f);
	if (key == 15)
	{
		if (f->rgb == 1)
			f->rgb = 0;
		else
			f->rgb++;
	}
	if (key == 36)
	{
		f->minr = -2.0;
		f->maxr = 1.0;
		f->mini = -1.2;
		f->maxi = f->mini + (f->maxr - f->minr);
	}
	if (key == 8)
	{
		f->col++;
		if (f->col == 3)
			f->col = 0;
	}
	fractol(f);
	return (0);
}

int	mouse_handler(int key, int x, int y, t_fractol *f)
{
	if (key == 4)
	{
		zoom(f, 0.9);
		x -= SIZE / 2;
		y -= SIZE / 2;
		if (x > 0)
			move(f, (double)-x / SIZE, 'L');
		else if (x < 0)
			move(f, (double)x / SIZE, 'R');
		if (y > 0)
			move(f, (double)y / SIZE, 'U');
		else if (y < 0)
			move (f, (double)-y / SIZE, 'D');
	}
	if (key == 5)
		zoom(f, 2.0);
	fractol(f);
	return (0);
}

int	quit(t_fractol *f)
{
	(void) f;
	exit(0);
	return (0);
}

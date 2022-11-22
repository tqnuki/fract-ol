/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpankewi <mpankewi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:58:27 by mpankewi          #+#    #+#             */
/*   Updated: 2022/11/22 11:56:05 by mpankewi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>
# include <math.h>

# define SIZE 1000

typedef struct s_fractol
{
	int		col;
	double	minr;
	double	maxr;
	double	mini;
	double	maxi;
	int		y;
	int		x;
	double	c_i;
	double	c_r;
	void	*mlx;
	void	*win;
	int		type;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		rgb;
	int		v[12];
	int		i;
}		t_fractol;

void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
char	*ft_strchr(const char *s, int c);
double	ft_atof(const char *str);

void	checkac(int ac);
int		handleargs(t_fractol *f, int ac, char **av);
void	handlecolor(t_fractol *f, int n);
void	handletype(double Z_im, double Z_re, unsigned maxiter, t_fractol *f);

void	structinit(t_fractol *f);
void	mlxinit(t_fractol *f);
void	my_mlx_pixel_put(t_fractol *f, int x, int y, int color);

void	zoom(t_fractol *f, double zoom);
void	move(t_fractol *f, double d, char dir);

void	fractol(t_fractol *f);
void	burningship(double Z_im, double Z_re, unsigned maxiter, t_fractol *f);
void	mandelbrot(double Z_im, double Z_re, unsigned maxiter, t_fractol *f);
void	julia(double Z_im, double Z_re, unsigned maxiter, t_fractol *f);

int		key_handler(int key, t_fractol *f, void *param);
int		mouse_handler(int key, int x, int y, t_fractol *f);
int		render_next_frame(t_fractol *f);
void	k2(int key, t_fractol *f);
void	argjulia(t_fractol *f, int ac, char **av);
int		quit(t_fractol *f);

void	redcolor(t_fractol *f, int n);
void	greencolor(t_fractol *f, int n);
void	bluecolor(t_fractol *f, int n);
void	rgb(t_fractol *f, int n);
void	r2(t_fractol *f, int n);
void	g2(t_fractol *f, int n);
void	b2(t_fractol *f, int n);
void	vinit(t_fractol *f);
#endif

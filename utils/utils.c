/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpankewi <mpankewi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:45:58 by mpankewi          #+#    #+#             */
/*   Updated: 2022/11/22 12:32:33 by mpankewi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
	{
		while (*s != '\0')
		{
			write(fd, s, 1);
			s++;
		}
	}
}

size_t	ft_strlen(const char *str)
{
	int	l;

	l = 0;
	while (str[l] != '\0')
		l++;
	return (l);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	a;

	a = 0;
	if (n == 0)
		return (0);
	while ((s1[a] != '\0' || s2[a] != '\0') && s1[a] == s2[a] && a < n -1)
		a++;
	return ((unsigned char)s1[a] - (unsigned char)s2[a]);
}

void	k2(int key, t_fractol *f)
{
	if (key == 53)
		exit(0);
	if (key == 24)
		zoom(f, 0.5);
	if (key == 27)
		zoom(f, 2.0);
	if (key == 123)
		move(f, 0.1, 'L');
	if (key == 124)
		move(f, 0.1, 'R');
	if (key == 126)
		move(f, 0.1, 'U');
	if (key == 125)
		move(f, 0.1, 'D');
}

int	ft_atoi(const char *str)
{
	int	a;
	int	s;
	int	n;

	a = 0;
	s = 1;
	n = 0;
	while (str[a] == '\t' || str[a] == '\n' || str[a] == '\v'
		|| str[a] == '\f' || str[a] == '\r' || str[a] == ' ')
		a++;
	if (str[a] == '-')
		s = -1;
	if (str[a] == '-' || str[a] == '+')
		a++;
	while (ft_isdigit(str[a]) && str[a])
		n = (n * 10) + (str[a++] - '0');
	return (n * s);
}

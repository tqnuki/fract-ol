/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpankewi <mpankewi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:19:01 by mpankewi          #+#    #+#             */
/*   Updated: 2022/11/22 11:45:17 by mpankewi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_fractol	f;

	if (ac < 2)
		ft_putstr_fd("Not enough arguments, please try again\n", 1);
	else if (ac >= 5)
		ft_putstr_fd("Too many arguments, please try again\n", 1);
	else
	{
		structinit(&f);
		if (handleargs(&f, ac, av) == 0)
			return (0);
		mlxinit(&f);
		fractol(&f);
		mlx_hook(f.win, 17, 0, quit, &f);
		mlx_key_hook(f.win, key_handler, &f);
		mlx_mouse_hook(f.win, mouse_handler, &f);
		mlx_loop_hook(f.mlx, render_next_frame, &f);
		mlx_loop(f.mlx);
	}
}

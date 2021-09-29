/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantonio <gantonio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 21:18:09 by gantonio          #+#    #+#             */
/*   Updated: 2021/09/28 21:06:02 by gantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
		write(fd, s++, 1);
}

static int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	get_num(const char *str)
{
	int	n;
	int	i;

	n = 0;
	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			n = (n * 10) + (str[i] - '0');
		else
			return (0);
		i++;
	}
	return (n);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else
	{
		if (n < 0)
		{
			ft_putchar('-');
			n *= -1;
		}
		if (n > 9)
			ft_putnbr_fd(n / 10, fd);
		ft_putchar((n % 10) + '0');
	}
}

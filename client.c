/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantonio <gantonio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 22:06:45 by gantonio          #+#    #+#             */
/*   Updated: 2021/09/20 22:30:23 by gantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>

int	ft_atoi(const char *nptr)
{
	int	j;
	int	n;

	j = 1;
	n = 0;
	while (*nptr == ' ' || *nptr == '\t' || *nptr == '\n'
		|| *nptr == '\v' || *nptr == '\f' || *nptr == '\r')
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			j *= -1;
		nptr++;
	}
	while (*nptr > 47 && *nptr < 58)
	{
		n = (*nptr - '0') + (n * 10);
		nptr++;
	}
	return (n * j);
}

int main(int argc, char **argv)
{
	printf("test client: %s\n", argv[1]);
	kill(ft_atoi(argv[1]), SIGUSR1);
}
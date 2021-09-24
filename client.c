/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantonio <gantonio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 22:06:45 by gantonio          #+#    #+#             */
/*   Updated: 2021/09/23 21:43:25 by gantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

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

void	send_signal(char chr, int len, int pid)
{
	while (--len >= 0)
	{
		if ((chr % 2) == 1)
		{
			printf("1\n");
			if (kill(pid, SIGUSR1) == -1)
			{
				write(1, "Error signal!\n", 15);
				exit(0);
			}
		}
		else
		{
			printf("0\n");
			if (kill(pid, SIGUSR2) == -1)
			{
				write(1, "Error signal!\n", 15);
				exit(0);
			}
		}
		usleep(100);
		chr /= 2;
	}
}

void	send_message(int pid, char *message)
{
	int	i;

	i = -1;
	while (message[++i] != '\0')
		send_signal(message[i], 8, pid);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		send_message(ft_atoi(argv[1]), argv[2]);
	else
		write(1, "Errors at the parameters\n", 25);
}

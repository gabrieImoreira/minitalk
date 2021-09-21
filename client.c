/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantonio <gantonio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 22:06:45 by gantonio          #+#    #+#             */
/*   Updated: 2021/09/20 22:56:25 by gantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

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

void send_message(int pid, char *message)
{
	kill(pid, SIGUSR1);
	printf("message: %s\n", message);
}

int main(int argc, char **argv)
{
	if (argc == 3)
		send_message(ft_atoi(argv[1]), argv[2]);
	else
		write(1, "Errors at the parameters\n", 25);
}
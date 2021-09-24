/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantonio <gantonio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 21:44:34 by gantonio          #+#    #+#             */
/*   Updated: 2021/09/23 21:46:31 by gantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void	my_handler(int signum)
{
	if (signum == SIGUSR1)
	{
		printf("1\n");
	}
	if (signum == SIGUSR2)
	{
		printf("0\n");
	}
}

int	main(int argc, char *argv[])
{
	int	pid;

	signal(SIGUSR1, my_handler);
	signal(SIGUSR2, my_handler);
	printf("PID: %d\n", getpid());
	while (1)
		sleep(3);
	return (0);
}

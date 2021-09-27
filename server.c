/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantonio <gantonio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 21:44:34 by gantonio          #+#    #+#             */
/*   Updated: 2021/09/26 21:45:23 by gantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

void	handler(int signum)
{
	if (signum == SIGUSR1)
	{
		write(1, "1", 1);
	}
	if (signum == SIGUSR2)
	{
		write(1, "0", 1);
	}
}

int	main(void)
{
	int	pid;
	struct sigaction sa_signal;
	
	sa_signal.sa_flags = 0;
	sa_signal.sa_handler = &handler;
	sigaction(SIGUSR1, &sa_signal, NULL);
	sigaction(SIGUSR2, &sa_signal, NULL);
	printf("PID: %d\n", getpid());
	while (1)
		sleep(100);
	return (0);
}

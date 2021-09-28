/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantonio <gantonio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 21:44:34 by gantonio          #+#    #+#             */
/*   Updated: 2021/09/27 21:43:54 by gantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int sig)
{
	static unsigned int	i;
	static unsigned int	chr;

	if (i > 7)
	{
		i = 0;
		chr = 0;
	}
	if (sig == SIGUSR2)
		chr += 1 << i;
	i++;
	if (i == 8)
		write(1, &chr, 1);	
}

int	main(void)
{
	char					*pid;
	struct sigaction	sa_signal;

	sa_signal.sa_flags = 0;
	sa_signal.sa_handler = &handler;
	sigaction(SIGUSR1, &sa_signal, NULL);
	sigaction(SIGUSR2, &sa_signal, NULL);
	ft_putstr_fd("PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
	while (1)
		sleep(100);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantonio <gantonio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 21:44:34 by gantonio          #+#    #+#             */
/*   Updated: 2021/09/28 21:22:01 by gantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

static void	handler(int sig, siginfo_t *sa, void *context)
{
	static unsigned int	i;
	static unsigned int	chr;

	(void)context;
	if (i > 7)
	{
		i = 0;
		chr = 0;
	}
	if (sig == SIGUSR2)
		chr += 1 << i;
	i++;
	if (i == 8)
	{
		if (chr == 0)
		{
			write(1, "\n", 1);
			kill(sa->si_pid, SIGUSR1);
		}
		else
			write(1, &chr, 1);
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_putstr_fd("PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
	while (1)
		pause();
	return (0);
}


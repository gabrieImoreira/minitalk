/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantonio <gantonio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 22:06:45 by gantonio          #+#    #+#             */
/*   Updated: 2021/09/28 19:59:39 by gantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void	send_signal(unsigned char chr, int len, int pid)
{
	while (--len >= 0)
	{
		if ((chr % 2) == 0)
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				write(1, "Error signal!\n", 15);
				exit(0);
			}
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				write(1, "Error signal!\n", 15);
				exit(0);
			}
		}
		usleep(500);
		chr /= 2;
	}
}

void	send_message(int pid, char *message)
{
	int	i;

	i = -1;
	while (message[++i])
		send_signal(message[i], 8, pid);
}

static void handle(int sig)
{
	if(sig == SIGUSR1)
	{
		write(1, "Message received by Server!\n", 28);
		exit(0);
	}
}

int	main(int argc, char *argv[])
{
	pid_t pid;
	
	pid = get_num(argv[1]);
	if (argc != 3)
		ft_putstr_fd("Invalid parameters\n", 1);
	else
		send_message(pid, argv[2]);
	signal(SIGUSR1, handle);
	send_signal('\0', 8, pid);
}

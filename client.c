/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantonio <gantonio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 22:06:45 by gantonio          #+#    #+#             */
/*   Updated: 2021/09/27 22:09:28 by gantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
		usleep(100);
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

int	main(int argc, char **argv)
{
	pid_t pid;
	
	pid = ft_atoi(argv[1]);
	if (argc == 3)
		send_message(pid, argv[2]);
	else
		write(1, "Errors at the parameters\n", 25);
	send_signal('\0', 8, pid);
}

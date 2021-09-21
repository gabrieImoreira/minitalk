/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantonio <gantonio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 22:06:45 by gantonio          #+#    #+#             */
/*   Updated: 2021/09/20 22:20:45 by gantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	printf("test client: %s\n\n",argv[1]);
	//kill(argv[2], SIGUSR1);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassofi <eassofi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 20:12:16 by eassofi           #+#    #+#             */
/*   Updated: 2021/12/15 21:14:26 by eassofi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib.h"

void	send_message(pid_t pid, char msg)
{
	int	mv_right;

	mv_right = 7 ;
	while (mv_right >= 0)
	{
		if ((msg >> mv_right & 1) == 1)
		{
			kill(pid, SIGUSR1);
		}
		else
		{
			kill(pid, SIGUSR2);
		}
		mv_right--;
		usleep(100);
	}
}

int	main(int ac, char **av)
{
	pid_t	pid;
	char	*message;
	size_t	len;

	len = 0;
	if (ac - 1 == 2)
	{
		pid = ft_atoi(av[1]);
		if (pid <= 0)
		{
			ft_printf("Wrong pid");
			exit(1);
		}
		message = ft_strdup(av[2]);
		while (*message)
			send_message(pid, *message++);
	}
	else
	{
		ft_printf("Syntax error : Usage :./client [server PID] [message]\n");
		return (1);
	}
	return (0);
}

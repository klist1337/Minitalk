/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassofi <eassofi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 20:30:59 by eassofi           #+#    #+#             */
/*   Updated: 2021/12/15 21:30:02 by eassofi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib.h"

void	print(int nb)
{
	static char	my_char;
	static int	i;

	my_char = my_char | nb ;
	if (i < 7)
		my_char = my_char << 1;
	i++;
	if (i > 7)
	{
		ft_printf("%c", my_char);
		my_char = 0;
		i = 0;
	}
}

void	handler(int sig)
{
	if (sig == SIGUSR1)
	{
		print(1);
	}
	else if (sig == SIGUSR2)
	{
		print(0);
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("[SERVER PID] : [%d]", pid);
	ft_printf("\n");
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
		sleep(1);
}

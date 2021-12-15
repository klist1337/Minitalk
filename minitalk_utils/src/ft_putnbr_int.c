/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassofi <eassofi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 23:39:15 by eassofi           #+#    #+#             */
/*   Updated: 2021/12/14 16:38:38 by eassofi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib.h"

int	ft_putnbr_int(int n, int count)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		nb = -nb;
		count = ft_putchar('-', count);
	}
	if (nb < 10)
	{
		count = ft_putchar(nb + '0', count);
	}
	else
	{
		count = ft_putnbr_int(nb / 10, count);
		count = ft_putnbr_int(nb % 10, count);
	}
	return (count);
}

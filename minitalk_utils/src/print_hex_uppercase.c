/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassofi <eassofi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 14:51:12 by eassofi           #+#    #+#             */
/*   Updated: 2021/12/14 16:38:38 by eassofi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib.h"

int	print_hex_uppercase(unsigned long int n, int count)
{
	if (n >= 16)
		count = print_hex_uppercase(n / 16, count);
	n = n % 16;
	if (n < 10)
		n += '0';
	else
		n += 'A' - 10;
	write (1, &n, 1);
	count++;
	return (count);
}

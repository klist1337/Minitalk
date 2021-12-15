/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassofi <eassofi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 20:17:20 by eassofi           #+#    #+#             */
/*   Updated: 2021/12/15 19:47:25 by eassofi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <signal.h>
# include <sys/types.h>

int		ft_printf(const char *fmt, ...);
int		ft_putchar(char c, int count);
int		ft_putstr(const char *s, int count);
int		ft_putnbr_uint(unsigned int n, int count);
int		print_hex_lowercase(unsigned long int n, int count);
int		print_hex_uppercase(unsigned long int n, int count);
int		ft_putnbr_int(int n, int count);
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s1);
#endif

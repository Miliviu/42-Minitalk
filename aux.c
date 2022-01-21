/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhagon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 12:46:43 by juhagon           #+#    #+#             */
/*   Updated: 2021/12/15 12:48:20 by juhagon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *s)
{
	long int	tmp;
	long int	nmb;
	long int	sign;

	tmp = 0;
	nmb = 0;
	sign = 0;
	while (s[tmp] == 32 || s[tmp] == '\n' || \
	s[tmp] == '\v' || s[tmp] == '\r' || s[tmp] == '\t' || s[tmp] == '\f')
		tmp++;
	if (s[tmp] == '+')
		tmp++;
	else if (s[tmp] == '-')
	{
		tmp++;
		sign = 1;
	}
	while (s[tmp] >= '0' && s[tmp] <= '9')
	{
		nmb = nmb * 10 + s[tmp] - '0';
		tmp++;
	}
	if (sign == 1)
		nmb = -nmb;
	return (nmb);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

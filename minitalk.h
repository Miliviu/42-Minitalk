/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhagon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 08:41:43 by juhagon           #+#    #+#             */
/*   Updated: 2021/12/15 12:58:51 by juhagon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <signal.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_sig
{
	int		len;
	int		i;
	int		c;
	int		toggle;
	char	*message;
}			t_sig;

int	ft_atoi(const char *s);
int	ft_strlen(char *str);
#endif

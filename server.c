/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhagon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 08:42:35 by juhagon           #+#    #+#             */
/*   Updated: 2021/12/15 14:39:47 by juhagon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_sig	g_global;

void	handler1(int sig)
{
	(void)sig;
	if (g_global.toggle == 0)
		g_global.len++;
	else
	{
		if (g_global.toggle == 1)
			g_global.toggle = 2;
		else
		{
			g_global.c++;
		}
	}
	if (g_global.len <= 0 && g_global.toggle != 0)
	{
		g_global.message[g_global.i] = '\0';
		printf("%s\n", g_global.message);
		free(g_global.message);
		g_global.toggle = 0;
		g_global.len = 0;
		g_global.i = 0;
		g_global.c = 0;
	}
}

void	handler2(int sig)
{
	(void)sig;
	if (g_global.toggle == 0)
	{
		g_global.message = malloc(sizeof(char) * g_global.len + 2);
		g_global.toggle = 2;
		g_global.toggle = 1;
	}
	else
	{
		g_global.len--;
		g_global.message[g_global.i] = g_global.c;
		g_global.i++;
		g_global.c = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	printf("PID %d\n", pid);
	while (1)
	{
		signal(SIGUSR1, handler1);
		signal(SIGUSR2, handler2);
	}
}

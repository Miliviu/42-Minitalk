/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhagon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 10:02:22 by juhagon           #+#    #+#             */
/*   Updated: 2021/12/17 15:15:41 by juhagon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_len(int len, int pid)
{
	while (len-- > 0)
	{
		kill(pid, SIGUSR1);
		usleep(5);
	}
	kill(pid, SIGUSR2);
}

void	send_chars(int len, int pid, char *str)
{
	int	c;
	int	i;

	c = -1;
	i = 0;
	while (len--)
	{
		while (c < str[i])
		{
			usleep(15);
			kill(pid, SIGUSR1);
			usleep(5);
			c++;
		}
		i++;
		c = 0;
		kill(pid, SIGUSR2);
		usleep(5);
	}
}

int	error_check(int	argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 3)
	{
		write(1, "Error\n", 6);
		return (-1);
	}
	while (argv[1][i])
	{
		if (argv[1][i] < '0' || argv[1][i] > '9')
		{
			write(1, "Error\n", 6);
			return (-1);
		}
		i++;
	}
	if (argv[2][0] == '\0')
		return (-1);
	return (1);
}

int	main(int argc, char **argv)
{
	int		len;
	int		pid;

	if (error_check(argc, argv) == -1)
		return (0);
	len = ft_strlen(argv[2]);
	pid = ft_atoi(argv[1]);
	send_len(len, pid);
	usleep(5);
	send_chars(len, pid, argv[2]);
	kill(pid, SIGUSR1);
}

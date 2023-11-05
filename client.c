/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-cas <gude-cas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 13:40:18 by gude-cas          #+#    #+#             */
/*   Updated: 2023/07/15 17:01:40 by gude-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

int	ft_atoi(const char *str)
{
	int	i;
	int	b;
	int	c;

	i = 0;
	b = 1;
	c = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			b *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		c = (str[i] - '0') + (c * 10);
		i++;
	}
	return (c * b);
}

void	sendsignal(char *str, int pid)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (str[i])
	{
		c = str[i];
		j = 0;
		while (j < 8)
		{
			if (c & (1 << (7 - j)))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(200);
			j++;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		sendsignal(av[2], pid);
	}
	else
	{
		write(2, "Invalid input.\n", 16);
		return (-1);
	}
}

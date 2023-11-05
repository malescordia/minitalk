/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-cas <gude-cas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 13:40:23 by gude-cas          #+#    #+#             */
/*   Updated: 2023/07/15 17:01:33 by gude-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	if (n <= 9)
		ft_putchar(n + '0');
}

void	bintodecimal(char *bin)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (bin[i])
	{
		c = (c << 1) + (bin[i] - '0');
		if ((i + 1) % 8 == 0)
		{
			write(1, &c, 1);
			c = 0;
		}
		i++;
	}
}

void	receivesignal(int sig)
{
	static int	i;
	static char	str[8];

	if (sig == SIGUSR2)
		str[i] = '0';
	else if (sig == SIGUSR1)
		str[i] = '1';
	i++;
	if (i == 8)
	{
		i = 0;
		bintodecimal(str);
	}
}

int	main(void)
{
	ft_putnbr(getpid());
	write(1, "\n", 1);
	signal(SIGUSR1, receivesignal);
	signal(SIGUSR2, receivesignal);
	while (1)
		;
}

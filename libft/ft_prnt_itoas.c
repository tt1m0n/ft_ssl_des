/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prnt_itoas.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 21:56:26 by omakovsk          #+#    #+#             */
/*   Updated: 2017/12/18 21:56:28 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_rev(char *s)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = ft_strlen(s) - 1;
	while (i < j)
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
		i++;
		j--;
	}
}

static	int		ft_intlen(short n)
{
	int		i;
	short	sign;

	i = 0;
	if (n == 0)
		i = 1;
	if (n == -32768)
		return (6);
	if ((sign = n) < 0)
		n = -n;
	while (n != 0)
	{
		i++;
		n = n / 10;
	}
	if (sign < 0)
		i++;
	return (i);
}

static	void	ft_if(char *p, short n)
{
	int		i;
	short	sign;

	i = 0;
	if ((sign = n) < 0)
		n = -n;
	if (n == 0)
		p[i++] = '0';
	while (n != 0)
	{
		p[i++] = (n % 10) + '0';
		n = n / 10;
	}
	if (sign < 0)
		p[i++] = '-';
	p[i] = '\0';
}

char			*ft_prnt_itoas(short n)
{
	char *p;

	p = (char*)malloc(ft_intlen(n) + 1);
	if (p == NULL)
		return (NULL);
	if (n == -32768)
	{
		ft_strcpy(p, "-32768");
		return (p);
	}
	ft_if(p, n);
	ft_rev(p);
	return (p);
}

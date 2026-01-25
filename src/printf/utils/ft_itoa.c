/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icezar-s <icezar-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 20:37:08 by icezar-s          #+#    #+#             */
/*   Updated: 2025/10/21 00:37:22 by icezar-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_printf.h"

static size_t	ft_digits(long int n)
{
	if (n > 9)
		return (1 + ft_digits(n / 10));
	return (1);
}

static void	ft_recursive_itoa(char *ptr, long int n)
{
	if (n > 9)
		ft_recursive_itoa((ptr - 1), (n / 10));
	*ptr = (char)((n % 10) + '0');
}

char	*ft_itoa(int n)
{
	char		*nbr;
	long int	ln;
	int			terms;

	terms = 1;
	ln = n;
	if (n < 0)
	{
		terms += 1;
		ln = -ln;
	}
	nbr = malloc(sizeof(char) * (ft_digits(ln) + terms));
	if (!nbr)
		return (NULL);
	if (terms > 1)
		*nbr = '-';
	ft_recursive_itoa((nbr + ft_digits(ln) + (terms - 2)), ln);
	nbr[ft_digits(ln) + (terms - 1)] = '\0';
	return (nbr);
}

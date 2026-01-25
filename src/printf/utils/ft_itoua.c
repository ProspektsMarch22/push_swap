/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoua.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icezar-s <icezar-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 16:53:21 by icezar-s          #+#    #+#             */
/*   Updated: 2025/12/06 19:52:12 by icezar-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static size_t	ft_digits(unsigned long int n)
{
	if (n > 9)
		return (1 + ft_digits(n / 10));
	return (1);
}

static void	ft_recursive_itoua(char *ptr, long unsigned int n)
{
	if (n > 9)
		ft_recursive_itoua((ptr - 1), (n / 10));
	*ptr = (char)((n % 10) + '0');
}

char	*ft_itoua(unsigned int n)
{
	char				*nbr;
	long unsigned int	lun;

	lun = n;
	nbr = malloc(sizeof(char) * (ft_digits(lun) + 1));
	if (!nbr)
		return (NULL);
	ft_recursive_itoua((nbr + ft_digits(lun) - 1), lun);
	nbr[ft_digits(lun)] = '\0';
	return (nbr);
}

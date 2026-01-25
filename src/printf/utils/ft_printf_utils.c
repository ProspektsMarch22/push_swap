/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icezar-s <icezar-s@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:11:53 by icezar-s          #+#    #+#             */
/*   Updated: 2025/12/06 19:41:04 by icezar-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putcharc(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_putstrc(char *str)
{
	if (str == NULL)
		return (ft_putstrc("(null)"));
	write(1, str, ft_strlen(str));
	return ((int)ft_strlen(str));
}

int	ft_putnbrc(int nbr)
{
	char	*num;
	int		len;

	num = ft_itoa(nbr);
	len = ft_putstrc(num);
	free(num);
	return (len);
}

int	ft_putunbrc(unsigned int nbr)
{
	char	*num;
	int		len;

	num = ft_itoua(nbr);
	len = ft_putstrc(num);
	free(num);
	return (len);
}

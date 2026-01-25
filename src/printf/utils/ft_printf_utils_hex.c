/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_hex.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icezar-s <icezar-s@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:31:53 by icezar-s          #+#    #+#             */
/*   Updated: 2025/12/06 19:48:45 by icezar-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	ft_recursive_puthexc(unsigned long nbr, int *count, char *base)
{
	if (nbr >= 16)
		ft_recursive_puthexc(nbr / 16, count, base);
	ft_putchar_fd(base[nbr % 16], 1);
	*count += 1;
}

static void	ft_recursive_putaddressc(unsigned long mem, int *count, char *base)
{
	if (mem > 15)
		ft_recursive_putaddressc(mem / 16, count, base);
	ft_putchar_fd(base[mem % 16], 1);
	*count += 1;
}

int	ft_puthexc(char cc, unsigned int nbr)
{
	int				count;
	unsigned long	lnbr;

	count = 0;
	lnbr = nbr;
	if (lnbr == 0)
		return (ft_putcharc('0'));
	if (cc == 'x')
		ft_recursive_puthexc(lnbr, &count, "0123456789abcdef");
	else if (cc == 'X')
		ft_recursive_puthexc(lnbr, &count, "0123456789ABCDEF");
	return (count);
}

int	ft_putaddressc(void *add)
{
	int	count;

	count = 0;
	if (add == NULL)
		return (ft_putstrc("(nil)"));
	count += ft_putstrc("0x");
	ft_recursive_putaddressc((unsigned long)add, &count, "0123456789abcdef");
	return (count);
}

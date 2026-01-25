/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icezar-s <icezar-s@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 14:39:22 by icezar-s          #+#    #+#             */
/*   Updated: 2025/12/06 19:29:22 by icezar-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdarg.h>

int		ft_putcharc(char c);
int		ft_putstrc(char *str);
int		ft_putnbrc(int nbr);
int		ft_putunbrc(unsigned int nbr);
int		ft_puthexc(char cc, unsigned int nbr);
int		ft_putaddressc(void *add);
int		ft_printf(const char *fmt, ...);
char	*ft_itoa(int n);
char	*ft_itoua(unsigned int n);
void	ft_putchar_fd(char c, int fd);
size_t	ft_strlen(const char *s);
#endif

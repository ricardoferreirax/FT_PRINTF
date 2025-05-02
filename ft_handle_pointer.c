/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 21:27:27 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/05/02 11:42:17 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_xbasedigits(unsigned long long n)
{
	int	len;

	len = 1;
	while (n >= 16)
	{
		n /= 16;
		len++;
	}
	return (len);
}

char	*ft_ulltohex(unsigned long long n)
{
	int			p;
	char		*str;
	const char	*base;

	base = "0123456789abcdef";
	p = ft_xbasedigits(n);
	str = (char *)malloc(sizeof(char) * (p + 1));
	if (!str)
		return (NULL);
	str[p] = '\0';
	if (n == 0)
		str[0] = '0';
	while (n > 0)
	{
		str[--p] = base[n % 16];
		n /= 16;
	}
	return (str);
}

int	ft_handle_pointer(va_list args)
{
	unsigned long long	addr;
	char				*str;
	int					len;

	addr = va_arg(args, unsigned long long);
	if (addr == 0)
		return (ft_printstring("(nil)"));
	str = ft_ulltohex(addr);
	if (!str)
		return (0);
	len = ft_printstring("0x");
	len += ft_printstring(str);
	free(str);
	return (len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 21:27:27 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/05/04 18:43:07 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_basedigits(unsigned long long n, int base_len)
{
	int	count;

	count = 1;
	while (n >= (unsigned long long)base_len)
	{
		n /= base_len;
		count++;
	}
	return (count);
}

static char	*ft_ulltoabase(unsigned long long n, const char *base)
{
	size_t		len;
	int		digits;
	char	*str;

	len = 0;
	while (base[len])
		len++;
	digits = count_basedigits(n, len);
	str = (char *)malloc(sizeof(char) * (digits + 1));
	if (!str)
		return (NULL);
	str[digits] = '\0';
	if (n == 0)
		str[0] = '0';
	while (n > 0)
	{
		str[--digits] = base[n % len];
		n /= len;
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
	str = ft_ulltoabase(addr, "0123456789abcdef");
	if (!str)
		return (0);
	len = ft_printstring("0x");
	len += ft_printstring(str);
	free(str);
	return (len);
}

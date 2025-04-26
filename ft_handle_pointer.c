/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 21:27:27 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/04/26 23:11:50 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	digits_base(unsigned long long n)
{
	int	count;

	count = 1;
	while (n >= 16)
	{
		n /= 16;
		count++;
	}
	return (count);
}

char	*ft_pointer_base(unsigned long long n)
{
	int		p;
	char	*str;
	int		base_len;
	const char	*base_str = "0123456789abcdef";

	base_len = 16;
	p = digits_base(n);
	str = (char *)malloc(sizeof(char) * (p + 1));
	if (!str)
		return (NULL);
	str[p] = '\0';
	if (n == 0)
		str[0] = '0';
	while (n > 0)
	{
		str[--p] = base_str[n % base_len];
		n /= base_len;
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
		return (ft_print_str("(nil)"));
	str = ft_pointer_base(addr);
	if (!str)
		return (0);
	len = ft_print_str("0x");
	len += ft_print_str(str);
	free(str);
	return (len);
}
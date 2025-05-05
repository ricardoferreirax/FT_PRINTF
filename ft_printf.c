/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 21:50:25 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/05/05 01:06:41 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_handle_format(const char c, va_list args)
{
	if (c == 'c')
		return (ft_handle_char(args));
	if (c == 's')
		return (ft_handle_string(args));
	if (c == 'd' || c == 'i')
		return (ft_handle_integer(args));
	if (c == 'u')
		return (ft_handle_unsigned(args));
	if (c == 'x')
		return (ft_handle_hex(args, "0123456789abcdef"));
	if (c == 'X')
		return (ft_handle_hex(args, "0123456789ABCDEF"));
	if (c == 'p')
		return (ft_handle_pointer(args));
	if (c == '%')
		return (ft_printchar('%'));
	return (ft_printchar(c));
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;
	int		idx;

	if (!format)
		return (-1);
	va_start(args, format);
	len = 0;
	idx = 0;
	while (format[idx])
	{
		if (format[idx] == '%')
		{
			if (!format[idx + 1])
				return (va_end(args), -1);
			len += ft_handle_format(format[++idx], args);
		}
		else
			len += ft_printchar(format[idx]);
		idx++;
	}
	va_end(args);
	return (len);
}

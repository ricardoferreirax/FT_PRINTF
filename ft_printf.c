/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 21:50:25 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/05/02 11:39:15 by rmedeiro         ###   ########.fr       */
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
		return (ft_handle_hexlower(args));
	if (c == 'X')
		return (ft_handle_hexupper(args));
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
	size_t	i;

	i = 0;
	len = 0;
	va_start(args, format);
	if (!format || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			len += ft_handle_format(format[i], args);
		}
		else
			len += ft_printchar(format[i]);
		i++;
	}
	va_end(args);
	return (len);
}

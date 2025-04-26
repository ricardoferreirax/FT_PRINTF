/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 21:50:25 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/04/26 23:38:13 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_format(char c, va_list args)
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
		return (ft_print_char('%'));
	return (ft_print_char(c));
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;
	size_t	i;

	if (!format || (*format == '%' && !format[1]))
		return (-1);
	va_start(args, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			len += ft_handle_format(format[++i], args);
			i++;
		}
		else
		{
			len += ft_print_char(format[i]);
			i++;
		}
	}
	va_end(args);
	return (len);
}

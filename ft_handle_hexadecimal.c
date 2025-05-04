/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_hexadecimal.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 21:12:14 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/05/04 21:43:03 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_ubasedigits(unsigned int n, int base_len)
{
	unsigned int	count;

	count = 1;
	while (n >= (unsigned int)base_len)
	{
		n /= base_len;
		count++;
	}
	return (count);
}

static char	*ft_uitoabase(unsigned int n, const char *base)
{
	char	*str;
	int		len;
	int		digits;

	len = 0;
	while (base[len] != '\0')
		len++;
	digits = count_ubasedigits(n, len);
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

int	ft_handle_hex(va_list args, const char *base)
{
	unsigned int	un;
	char			*str;
	int				len;

	un = va_arg(args, unsigned int);
	str = ft_uitoabase(un, base);
	if (!str)
		return (0);
	len = ft_printstring(str);
	free(str);
	return (len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 21:38:11 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/05/04 18:43:32 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_udigits(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*ft_uitoa(unsigned int n)
{
	char	*str;
	int		u;

	u = count_udigits(n);
	str = (char *)malloc(sizeof(char) * (u + 1));
	if (!str)
		return (NULL);
	str[u] = '\0';
	if (n == 0)
		str[0] = '0';
	while (n > 0)
	{
		str[--u] = (n % 10) + 48;
		n /= 10;
	}
	return (str);
}

int	ft_handle_unsigned(va_list args)
{
	unsigned int	un;
	char			*str;
	int				len;

	un = va_arg(args, unsigned int);
	str = ft_uitoa(un);
	if (!str)
		return (0);
	len = ft_printstring(str);
	free(str);
	return (len);
}

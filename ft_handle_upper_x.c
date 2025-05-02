/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_upper_x.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 21:14:44 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/05/02 11:41:17 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_Xdigits(unsigned int num)
{
	unsigned int	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		num /= 16;
		len++;
	}
	return (len);
}

char	*ft_hexupper(unsigned int n)
{
	char			*str;
	int				x;
	unsigned int	num;

	num = n;
	x = ft_Xdigits(num);
	str = malloc(sizeof(char) * (x + 1));
	if (!str)
		return (NULL);
	str[x] = '\0';
	if (n == 0)
		str[0] = '0';
	while (x > 0)
	{
		x--;
		if ((num % 16) > 9)
			str[x] = (num % 16) + 65 - 10;
		else
			str[x] = (num % 16) + 48;
		num /= 16;
	}
	return (str);
}

int	ft_handle_hexupper(va_list args)
{
	unsigned int	un;
	char			*str;
	int				len;

	un = va_arg(args, unsigned int);
	str = ft_hexupper(un);
	if (!str)
		return (0);
	len = ft_printstring(str);
	free(str);
	return (len);
}

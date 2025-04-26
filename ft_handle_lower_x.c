/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_lower_x.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 21:12:14 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/04/26 23:39:57 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_lowerhexa(unsigned int n)
{
	char			*str;
	int				x;
	unsigned int	num;

	num = n;
	x = ft_hexalen(num);
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
			str[x] = (num % 16) + 97 - 10;
		else
			str[x] = (num % 16) + 48;
		num /= 16;
	}
	return (str);
}

int	ft_handle_hexlower(va_list args)
{
	unsigned int	un;
	char			*str;
	int				len;

	un = va_arg(args, unsigned int);
	str = ft_lowerhexa(un);
	if (!str)
		return (0);
	len = ft_print_str(str);
	free(str);
	return (len);
}

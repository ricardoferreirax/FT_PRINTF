/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_integer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 21:23:20 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/04/26 23:16:56 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_signed_len(long int num)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		len++;
		num = -num;
	}
	while (num > 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			i;
	long int	num;

	num = n;
	i = ft_signed_len(num);
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i] = '\0';
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	if (n == 0)
		str[0] = '0';
	while (num > 0)
	{
		str[--i] = (num % 10) + 48;
		num /= 10;
	}
	return (str);
}

int	ft_handle_integer(va_list args)
{
	char	*str;
	int		len;
	int		n;

	n = va_arg(args, int);
	str = ft_itoa(n);
	if (!str)
		return (0);
	len = ft_print_str(str);
	free(str);
	return (len);
}
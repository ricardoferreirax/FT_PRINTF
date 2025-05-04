/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 21:17:49 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/05/04 18:38:03 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printstring(const char *str)
{
	int	idx;

	if (!str)
		return (0);
	idx = 0;
	while (str[idx])
	{
		write(1, &str[idx], 1);
		idx++;
	}
	return (idx);
}

int	ft_handle_string(va_list args)
{
	char	*str;

	str = va_arg(args, char *);
	if (!str)
		return (ft_printstring("(null)"));
	return (ft_printstring(str));
}

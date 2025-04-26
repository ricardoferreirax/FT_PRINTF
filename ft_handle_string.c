/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 21:17:49 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/04/26 23:17:51 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_string(va_list args)
{
	char	*str;

	str = va_arg(args, char *);
	if (!str)
		return (ft_print_str("(null)"));
	return (ft_print_str(str));
}

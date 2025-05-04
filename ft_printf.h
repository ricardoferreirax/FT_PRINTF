/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 21:13:26 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/05/04 18:44:36 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stddef.h>

int		ft_printf(const char *format, ...);
int		ft_handle_string(va_list args);
int		ft_handle_char(va_list args);
int		ft_handle_unsigned(va_list args);
int		ft_handle_hex(va_list args, const char *base);
int		ft_handle_integer(va_list args);
int		ft_handle_pointer(va_list args);
int		ft_printstring(const char *str);
int		ft_printchar(char c);
int		ft_handle_char(va_list args);

#endif
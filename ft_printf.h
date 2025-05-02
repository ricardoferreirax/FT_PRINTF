/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 21:13:26 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/05/02 11:42:58 by rmedeiro         ###   ########.fr       */
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
int		ft_handle_hexlower(va_list args);
int		ft_handle_hexupper(va_list args);
int		ft_handle_integer(va_list args);
int		ft_handle_pointer(va_list args);
int		ft_printstring(const char *str);
int		ft_printchar(char c);
int		ft_handle_char(va_list args);

#endif
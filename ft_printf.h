/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 21:13:26 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/04/26 23:53:05 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stddef.h>

int		ft_printf(const char *format, ...);
int		ft_handle_format(char c, va_list args);
int		ft_handle_string(va_list args);
int		ft_handle_char(va_list args);
int		ft_handle_unsigned(va_list args);
int		ft_handle_hexlower(va_list args);
int		ft_handle_hexupper(va_list args);
int		ft_handle_integer(va_list args);
int		ft_handle_pointer(va_list args);
int		ft_print_digit(const char *str);
int		ft_print_str(const char *str);
int		ft_hexa_len(unsigned int num);
char	*ft_uitoa(unsigned int n);
int		ft_print_char(char c);
int		ft_handle_char(va_list args);
char	*ft_pointer_base(unsigned long long n);
char	*ft_itoa(int n);
char	*ft_lowerhexa(unsigned int n);
char	*ft_upperhexa(unsigned int n);

#endif
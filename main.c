/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 23:49:52 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/04/27 00:02:54 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	char	letter = 'a';
	char	*string = "my name is ricardo";
	char	*str = NULL;
	int		*ptr = NULL;
	int		number = -95;
	int		count[11];

	ft_printf("\n_____________FT_PRINTF_____________\n");
	count[0] = ft_printf("1 | Letter: %c", letter);
	count[1] = ft_printf("\n2 | String: %s", string);
	count[2] = ft_printf("\n3 | Number (i): %i", number);
	count[2] = ft_printf("\n3 | Number (d): %d", number);
	count[3] = ft_printf("\n4 | Unsigned: %u", number);
	count[4] = ft_printf("\n5 | Hex lower (x): %x", number);
	count[5] = ft_printf("\n6 | Hex UPPER (X): %X", number);
	count[6] = ft_printf("\n7 | Pointer: %p", &string);
	count[7] = ft_printf("\n8 | NULL string: %s", str);
	count[8] = ft_printf("\n9 | Percent sign: %%");
	count[9] = ft_printf("\n10 | NULL string direct: %s", str);
	count[10] = ft_printf("\n11 | NULL pointer: %p", ptr);

	ft_printf(NULL);

	for (int i = 0; i < 11; i++)
		printf("\nft_printf count%d: %d", i + 1, count[i]);

	printf("\n_______________PRINTF______________\n");
	count[0] = printf("1 | Letter: %c", letter);
	count[1] = printf("\n2 | String: %s", string);
	count[2] = printf("\n3 | Number (i): %i", number);
	count[2] = printf("\n3 | Number (d): %d", number);
	count[3] = printf("\n4 | Unsigned: %u", number);
	count[4] = printf("\n5 | Hex lower (x): %x", number);
	count[5] = printf("\n6 | Hex UPPER (X): %X", number);
	count[6] = printf("\n7 | Pointer: %p", &string);
	count[7] = printf("\n8 | NULL string: %s", str);
	count[8] = printf("\n9 | Percent sign: %%");
	count[9] = printf("\n10 | NULL string direct: %s", str);
	count[10] = printf("\n11 | NULL pointer: %p", ptr);

	printf("NULL");

	for (int i = 0; i < 11; i++)
		printf("\nprintf count%d: %d", i + 1, count[i]);

	printf("\n\nEnd\n");
	return (0);
}

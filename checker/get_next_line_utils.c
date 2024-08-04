/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:07:11 by adiban-i          #+#    #+#             */
/*   Updated: 2023/12/06 14:07:11 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_checker.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	char			*cdst;
	const char		*csrc;
	size_t			i;

	cdst = (char *)dst;
	csrc = (const char *)src;
	if (!dst && !src)
		return (NULL);
	i = 0;
	while (i < len)
	{
		cdst[i] = (char)csrc[i];
		i++;
	}
	return (dst);
}

void	*ft_memset(void *dst, int c, size_t len)
{
	size_t			i;
	unsigned char	*cdst;

	cdst = (unsigned char *)dst;
	i = 0;
	while (i < len)
	{
		cdst[i] = (unsigned char)c;
		i++;
	}
	return (dst);
}

void	*ft_calloc(size_t number, size_t size)
{
	void	*res;

	res = malloc(number * size);
	if (!res)
		return (NULL);
	ft_memset(res, 0, number * size);
	return (res);
}

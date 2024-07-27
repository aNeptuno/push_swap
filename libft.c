/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 17:26:36 by adiban-i          #+#    #+#             */
/*   Updated: 2024/07/27 14:05:34 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	i;
	int	j;
	int	k;
	int	needle_size;

	if (haystack != NULL && needle != NULL)
	{
		needle_size = ft_strlen(needle);
		i = 0;
		while (haystack[i])
		{
			j = 0;
			k = i;
			while (haystack[k] && needle[j] && haystack[k] == needle[j])
			{
				j++;
				k++;
			}
			if (j == needle_size)
				return ((char *)(haystack + i));
			i++;
		}
	}
	return (NULL);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

int	ft_isdigit(int c)
{
	return (c <= '9' && c >= '0');
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ponsumri <chocodeveloper020@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 21:05:42 by ponsumri          #+#    #+#             */
/*   Updated: 2026/09/13 17:04:13 by ponsumri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_memcpy(char *dst, char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		i++;
	}
}

void	ft_strlcpy(char *dst, char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

int	find_newline(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*lstcombine(char *old_str, char *new_str)
{
	size_t	oldlen;
	size_t	newlen;
	char	*bucket;

	if (new_str == NULL)
		return (NULL);
	oldlen = 0;
	if (old_str != NULL)
		oldlen = ft_strlen(old_str);
	newlen = ft_strlen(new_str);
	bucket = malloc(oldlen + newlen + 1);
	if (bucket == NULL)
		return (free(old_str), NULL);
	if (old_str != NULL)
		ft_memcpy(bucket, old_str, oldlen);
	ft_memcpy(bucket + oldlen, new_str, newlen);
	bucket[oldlen + newlen] = '\0';
	if (old_str != NULL)
		free(old_str);
	return (bucket);
}

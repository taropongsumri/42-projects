/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ponsumri <chocodeveloper020@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 21:05:49 by ponsumri          #+#    #+#             */
/*   Updated: 2026/09/13 16:28:59 by ponsumri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_gnl_list
{
	int					fd;
	char				*buf;
	struct s_gnl_list	*next;
}	t_gnl_list;

char	*get_next_line(int fd);
size_t	ft_strlen(char *s);
void	ft_memcpy(char *dst, char *src, size_t n);
void	ft_strlcpy(char *dst, char *src, size_t n);
int		find_newline(char *s);
char	*lstcombine(char *old_str, char *new_str);

#endif
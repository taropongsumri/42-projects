/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ponsumri <chocodeveloper020@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 21:05:46 by ponsumri          #+#    #+#             */
/*   Updated: 2026/09/13 11:56:00 by ponsumri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static t_gnl_list	*get_node(t_gnl_list **head, int fd)
{
	t_gnl_list	*node;

	node = *head;
	while (node != NULL)
	{
		if (node->fd == fd)
			return (node);
		node = node->next;
	}
	node = malloc(sizeof(t_gnl_list));
	if (node == NULL)
		return (NULL);
	node->fd = fd;
	node->buf = NULL;
	node->next = *head;
	*head = node;
	return (node);
}

static void	free_node(t_gnl_list **head, int fd)
{
	t_gnl_list	*node;
	t_gnl_list	*prev;

	node = *head;
	prev = NULL;
	while (node != NULL)
	{
		if (node->fd == fd)
		{
			if (prev == NULL)
				*head = node->next;
			else
				prev->next = node->next;
			free(node->buf);
			free(node);
			return ;
		}
		prev = node;
		node = node->next;
	}
}

static int	fill_buffer(t_gnl_list *node, int fd)
{
	char	*dst;
	ssize_t	r;

	dst = malloc(BUFFER_SIZE + 1);
	if (dst == NULL)
		return (-1);
	r = 1;
	while (r > 0 && (node->buf == NULL || find_newline(node->buf) == -1))
	{
		r = read(fd, dst, BUFFER_SIZE);
		if (r < 0)
		{
			free(dst);
			return (-1);
		}
		if (r > 0)
		{
			dst[r] = '\0';
			node->buf = lstcombine(node->buf, dst);
		}
	}
	free(dst);
	return (0);
}

static char	*build_line(t_gnl_list **head, t_gnl_list *node, int fd)
{
	char	*line;
	char	*rem;
	int		pos;
	int		len;

	pos = find_newline(node->buf);
	len = pos + 1;
	if (pos == -1)
		len = ft_strlen(node->buf);
	line = malloc(len + 1);
	if (line == NULL)
		return (NULL);
	ft_strlcpy(line, node->buf, len + 1);
	if (pos != -1 && ft_strlen(node->buf) - len > 0)
	{
		rem = malloc(ft_strlen(node->buf) - len + 1);
		if (rem == NULL)
		{
			free(line);
			return (NULL);
		}
		ft_strlcpy(rem, node->buf + len, ft_strlen(node->buf) - len + 1);
		free(node->buf);
		node->buf = rem;
	}
	else
		free_node(head, fd);
	return (line);
}

char	*get_next_line(int fd)
{
	static t_gnl_list	*head = NULL;
	t_gnl_list			*node;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	node = get_node(&head, fd);
	if (node == NULL)
		return (NULL);
	if (fill_buffer(node, fd) == -1)
	{
		free_node(&head, fd);
		return (NULL);
	}
	if (node->buf == NULL)
	{
		free_node(&head, fd);
		return (NULL);
	}
	return (build_line(&head, node, fd));
}

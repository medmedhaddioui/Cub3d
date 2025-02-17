/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noudrib <noudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:41:15 by noudrib           #+#    #+#             */
/*   Updated: 2024/04/19 23:08:31 by noudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include <fcntl.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

size_t	ft_strlen(const char *s);
char	*line_rest(const char *s, char **rest);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_realloc(void *str1, void *str2, size_t size1, size_t size2);
int		read_line(char *buf, char **rest, char **line, int fd);
int		join_buffer_to_rest(char *buf, char **rest, char **line);
char	*get_next_line(int fd);
#endif

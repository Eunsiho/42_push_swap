/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hogkim <hogkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 20:25:11 by hogkim            #+#    #+#             */
/*   Updated: 2022/06/15 16:51:40 by hogkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# define BUFFER_SIZE 10

char	*ft_strdup(const char *s1);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		ft_no_newline(char *buffer);
size_t	ft_strlen(const char *s);
char	*ft_strjoin_gnl(char *s1, char *s2);

char	*ft_restart(char *temp);
char	*ft_cut_temp(char *temp);
char	*ft_read_till_line(int fd, char *temp);
char	*get_next_line(int fd);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoykan <bsoykan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:07:48 by bsoykan           #+#    #+#             */
/*   Updated: 2023/12/07 18:07:49 by bsoykan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "unistd.h"

char	*join_me(char *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*result_string;

	s1_len = 0;
	s2_len = 0;
	result_string = NULL;
	if (s1 != NULL && s2 != NULL)
	{
		s1_len = ft_strlen(s1);
		s2_len = ft_strlen(s2);
		result_string = ft_strnew(s1_len + s2_len + 1);
		if (result_string)
		{
			ft_strlcpy(result_string, s1, s1_len);
			free(s1);
			ft_strlcpy((result_string + s1_len), s2, s2_len);
		}
		else
			return (NULL);
	}
	return (result_string);
}

char	*ft_get_read(int fd, char *result_string, int read_bytes)
{
	char	buffer_for_read[BUFFER_SIZE + 1];

	read_bytes = read(fd, buffer_for_read, BUFFER_SIZE);
	while (read_bytes > 0)
	{
		buffer_for_read[read_bytes] = '\0';
		if (!(result_string))
		{
			result_string = malloc(sizeof(char) * read_bytes + 1);
			if (!(result_string))
				return (NULL);
			ft_bzero(result_string, read_bytes + 1);
			ft_memcpy(result_string, buffer_for_read, read_bytes);
		}
		else
		{
			result_string = join_me(result_string, buffer_for_read);
			ft_strclr(buffer_for_read);
		}
		read_bytes = read(fd, buffer_for_read, BUFFER_SIZE);
	}
	if (read_bytes < 0)
		return (NULL);
	return (result_string);
}

char	*string_sub(char *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	string_len;
	size_t	j;

	j = 0;
	substring = NULL;
	string_len = ft_strlen(s);
	if (s[start] == '\n')
		start++;
	if (s && start < string_len + 1 && len < string_len + 1)
	{
		substring = malloc(sizeof(char) * len + 1);
		if (substring == NULL)
			return (NULL);
		while (start < string_len && j < len)
		{
			substring[j] = s[start];
			start++;
			j++;
		}
		substring[j] = '\0';
	}
	free(s);
	return (substring);
}

void	get_next_next(const int fd, char **line, char *result_string[])
{
	int		counter;
	char	*buffer;
	int		str_len;

	str_len = ft_strlen(result_string[fd]);
	counter = 0;
	while (*result_string[fd] != '\n' && *result_string[fd] != '\0')
	{
		result_string[fd]++;
		counter++;
	}
	result_string[fd] -= counter;
	buffer = ft_strnew(counter);
	buffer = ft_strncpy(buffer, result_string[fd], counter);
	result_string[fd] = string_sub(result_string[fd], counter,
			(str_len - counter));
	*line = buffer;
}

int	get_next_line(const int fd, char **line)
{
	static char	*result_string[4096];
	int			read_bytes;

	read_bytes = 0;
	if (fd < 0 || fd > 4096 || BUFFER_SIZE < 0 || line == NULL)
		return (ft_strclr(*line), *line = NULL, -1);
	result_string[fd] = ft_get_read(fd, result_string[fd], read_bytes);
	if (result_string[fd] == NULL)
		return (ft_strclr(*line), *line = NULL, -1);
	if (*result_string[fd] == '\0')
		return (ft_strclr(*line), *line = NULL, 0);
	get_next_next(fd, line, result_string);
	return (1);
}

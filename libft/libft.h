/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoykan <bsoykan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:07:44 by bsoykan           #+#    #+#             */
/*   Updated: 2023/12/08 13:03:08 by bsoykan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

int		ft_isalpha(int str);
int		ft_isdigit(int ch);
int		ft_isascii(int chr);
int		ft_isprint(int a);
int		ft_isalnum(int ch);
int		ft_toupper(int a);
int		ft_tolower(int a);
int		ft_strncmp(const char *str1, const char *str2, size_t a);
int		ft_memcmp(const void *str1, const void *str2, size_t n);
int		ft_atoi(const char *str);

char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *str, int a);
char	*ft_strnstr(const char *str1, const char *str2, size_t n);
char	*ft_strdup(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		get_next_line(const int fd, char **line);
char	*ft_strncpy(char *dst, char *src, size_t len);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *b, size_t n);
void	*ft_memcpy(void *b, const void *a, size_t len);
void	*ft_memmove(void *dest, const void *sour, size_t len);
void	*ft_memchr(const void *str, int c, size_t n);
void	*ft_calloc(size_t num, size_t size);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_strclr(char *s);
char	*ft_strnew(size_t size);
size_t	ft_strlen(const char *str);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *a, const char *b, size_t size);

#endif

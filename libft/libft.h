/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsabound <jsabound@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:40:27 by jsabound          #+#    #+#             */
/*   Updated: 2023/02/27 11:45:18 by jsabound         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_listnb
{
	int				content;
	struct s_listnb	*next;
}					t_listnb;

size_t				ft_strlen(const char *s);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
void				*ft_memset(void *s, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
int					ft_isprint(int c);
int					ft_isdigit(int c);
int					ft_isascii(int c);
int					ft_isalpha(int c);
int					ft_isalnum(int c);
void				ft_bzero(void *s, size_t n);
char				**ft_split(const char *s, char c);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_strrchr(const char *s, int c);
char				*ft_strnstr(const char *s1, const char *s2, size_t len);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strdup(const char *s);
char				*ft_strchr(const char *s, int c);
long long int		ft_atoi(const char *nptr, char **temp);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_substr(char const *s, unsigned int start, size_t len);
void				ft_putstr_fd(char *s, int fd);
void				ft_putchar_fd(char c, int fd);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strjoin(char const *s1, char const *s2);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_putnbr_fd(int n, int fd);
void				ft_putendl_fd(char *s, int fd);
char				*ft_itoa(int n);
void				*ft_calloc(size_t nmemb, size_t size);
t_listnb			*ft_lstnew(int content);
void				ft_lstadd_front(t_listnb **lst, t_listnb *new);
int					ft_lstsize(t_listnb *lst);
t_listnb			*ft_lstlast(t_listnb *lst);
void				ft_lstadd_back(t_listnb **lst, t_listnb *new);
t_listnb			*ft_lstmap(t_listnb *lst, void *(*f)(void *),
						void (*del)(void *));

#endif
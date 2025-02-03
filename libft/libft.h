/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoshker <kmoshker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 22:30:36 by kmoshker          #+#    #+#             */
/*   Updated: 2025/02/03 23:44:25 by kmoshker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif
# define OPEN_MAX 1024

# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <sys/types.h>
# include "ft_printf/ft_printf.h"

# ifndef EOB
#  define EOB -1
# endif

# define GNL_SUCCESS_FIN 0
# define GNL_FAILURE_BUFFER_SIZE 1
# define GNL_FAILURE_FD 2
# define GNL_FAILURE_MALLOC 3
# define GNL_FAILURE_READ 4

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
}					t_list;

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *s);
int		ft_istrlen(const char *s);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strcat(char *dst, const char *src);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
long	ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
char	*ft_strnstr(const char *str, const char *to_find, size_t len);
// void	ft_putnbr_fd(int n, int fd);
// void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
// void	ft_putchar_fd(char c, int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strtrim(char const *s1, char const *set);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_itoa(int n);
char	**ft_split(char const *str, char charset);
int		count_words(const char *s, char c);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstnew(int content);
void	ft_lstclear(t_list **lst, void (*del)(int));
void	ft_lstdelone(t_list *lst, void (*del)(int));
void	ft_lstiter(t_list *lst, void (*f)(int));
// t_list	*ft_lstmap(t_list *lst, void *(*f)(int), void (*del)(int));
int		ft_abs(int num);

typedef struct s_fd
{
	int			fd;
	char		*leftover;
	ssize_t		lo_len;
	ssize_t		lo_eol_i;
	char		*readbuff;
	ssize_t		rb_len;
	struct s_fd	*prev;
	struct s_fd	*next;
}	t_fd;

char	*get_next_line(int fd, int *return_code);
char	*get_next_line_core(int fd, t_fd *f, int *return_code);
ssize_t	find_eol(char *str);
char	*gnl_strjoin(t_fd *f_p);
char	*gnl_split(t_fd *f_p);
char	*gnl_free(t_fd *f_p, char **p_p, char *return_value);
void	delete_fd_node(t_fd *f_p);
t_fd	*new_fd_node(t_fd *last_node, int fd);
t_fd	*get_fd_node(t_fd *lst, int fd, int *return_code);

#endif
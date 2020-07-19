/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongpar <seongpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 16:01:41 by seongpar          #+#    #+#             */
/*   Updated: 2020/04/12 10:52:28 by seongpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

struct	s_list
{
	char			flag;
	int				width;
	char			precision;
	int				length;
	char			specifier;
	int				s_width;
	int				s_length;
	struct s_list	*next;
};
typedef struct s_list	t_list;

char	*ft_strdup(const char *s);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *s);
int		ft_strncmp(char *s1, char *s2, unsigned int n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memccpy(void *dest, const void *src, int c, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
char	*ft_strchr(const char *s, int c);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strrchr(const char *s, int c);
int		ft_atoi(const char *nptr);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
t_list	*ft_lstnew(t_list set_node);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst);
void	ft_lstclear(t_list **lst);
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
int		ft_set_end(const char *s, char const *set);
int		is_flag(char c);
int		is_width(char c);
int		is_precision(char c);
int		is_length(char c);
int		is_specifier(char c);
void	ft_parse(const char *str, t_list **start);
void	pass_num(const char *str, size_t *idx, t_list *node, int is_width);
void	parse_init_node(t_list *node);
void	make_node(t_list **start, t_list set_node);
void	print_node(t_list point, va_list *ap, int *result);
int		print_d(t_list node, int num);
int		print_u(t_list node, unsigned int num);
void	write_string(t_list *point, const char * str, va_list *ap, int *result);
int		print_c(t_list node, char c);
int		print_s(t_list node, char *print);
char	*ft_itox(long long n, char alpha);
int		print_x(t_list node, unsigned int num);
int		print_X(t_list node, unsigned int num);
size_t	ft_min(size_t num1, size_t num2);
size_t	ft_max(size_t num1, size_t num2);
void	ft_setspace(void *s, size_t n);
char	*ft_undifitoa(int n);
char	*ft_undifuitoa(unsigned int n);
void	set_zero(void *s, size_t n);
char	*make_zero(void);
int		print_p(t_list node, long long num);
char	*ft_lltoa_base(long long nbr, char *base);
void	ft_putzero_fd(char *s, int fd);

#endif

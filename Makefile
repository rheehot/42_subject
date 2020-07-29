CC		=	gcc
INC		=	-I ./Libft/
CFLAGS	=	-Wall -Wextra -Werror $(INC)

SRCS	=	./Libft/ft_atoi.c ./Libft/ft_bzero.c ./Libft/ft_calloc.c ./Libft/ft_isalnum.c ./Libft/ft_isalpha.c\
			./Libft/ft_isascii.c ./Libft/ft_isdigit.c ./Libft/ft_isprint.c ./Libft/ft_itoa.c ./Libft/ft_memccpy.c\
			./Libft/ft_memchr.c ./Libft/ft_memcmp.c ./Libft/ft_memcpy.c ./Libft/ft_memmove.c ./Libft/ft_memset.c\
			./Libft/ft_putchar_fd.c ./Libft/ft_putendl_fd.c ./Libft/ft_putnbr_fd.c ./Libft/ft_putstr_fd.c\
			./Libft/ft_split.c ./Libft/ft_strchr.c ./Libft/ft_strdup.c ./Libft/ft_strjoin.c ./Libft/ft_strlcat.c\
			./Libft/ft_strlcpy.c ./Libft/ft_strlen.c ./Libft/ft_strmapi.c ./Libft/ft_strncmp.c\
			./Libft/ft_strnstr.c ./Libft/ft_strrchr.c ./Libft/ft_strtrim.c ./Libft/ft_substr.c ./Libft/ft_tolower.c\
			./Libft/ft_toupper.c\
			./ft_printf.c ft_parse.c ./ft_check_parse.c\
			./print_diu.c ./print_c.c ./print_s.c ./print_xX.c\
			./Libft/ft_lstadd_back.c ./Libft/ft_lstnew.c ./Libft/ft_max.c ./Libft/ft_setspace.c\
			./Libft/ft_undifitoa.c ./Libft/ft_undifuitoa.c ./print_p.c ./Libft/ft_lltoa_base.c ./Libft/ft_putzero_fd.c


OBJS	=	$(SRCS:.c=.o)

NAME	= libftprintf.a

all : $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I./libft/

$(NAME):	$(OBJS)
	ar rc $(NAME) $(OBJS)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean $(NAME)

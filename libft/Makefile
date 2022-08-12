NAME = libft.a  
SRCS =    	ft_strlen.c \
			ft_substr.c ft_strjoin.c\
			ft_split.c ft_strncmp.c

HEADER = libft.h

OBJS = ${SRCS:%.c=%.o}
CC = cc

CFLAGS = -Wall -Wextra -Werror -I$(HEADER)

.PHONY : all clean fclean re 

all : $(NAME)

$(NAME):${OBJS} $(HEADER)
	ar rcs $(NAME) $? 

%.o:%.c $(HEADER)
	${CC} ${CFLAGS} -c $< -o $@

clean :
	@rm -f ${OBJS}

fclean : clean
	@rm -f $(NAME)

re : fclean all


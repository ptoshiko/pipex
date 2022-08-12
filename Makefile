NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDES)
SRC  = 	pipex.c free_process.c processes.c
OBJ = $(patsubst %.c,%.o,$(SRC))
INCLUDES = pipex.h
DIR_LIB = libft
LIB = $(DIR_LIB)/libft.a

all : $(NAME)

lib : 
	make -sC $(DIR_LIB)

$(NAME) : lib $(OBJ) $(LIB)
	$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $(NAME) 

%.o : %.c $(INCLUDES)
	cc $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJ)
	make clean -C $(DIR_LIB)

fclean : clean
	rm -f $(NAME)
	make fclean -C $(DIR_LIB)
	
re : fclean all

.PHONY : all clean fclean re
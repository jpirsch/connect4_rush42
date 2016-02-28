NAME		= ../puissance4
SRC		= main.c \
			ia.c \
			board.c \
			interface.c \
			get_next_line.c
INCLUDES	=	-I ../includes
CC		=	gcc
RM		=	rm -f
LIB		=	-L ../libft -lft
OBJ		= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(INCLUDES) $(SRC) $(LIB) -o $(NAME)

%.o:%.c
	$(CC) -O3 -c $(SRC) $(FLAGS) $(INCLUDES)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY : re fclean clean all

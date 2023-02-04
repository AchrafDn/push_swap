CC = cc
Cflags = -Wall -Wextra -Werror 
Cfiles = moves.c push.c utils.c ft_atoi.c ft_split.c ft_substr.c

OBJ = ${Cfiles:.c=.o}

RM = rm -f
NAME = push_swap

all : $(NAME)

$(NAME) : $(OBJ)
		cc $(Cflags) $(OBJ) -o $(NAME)

.c.o:
		$(CC) $(Cflags) -c $< -o $@

clean :
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean all
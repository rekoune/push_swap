CFILES = push_swap.c utils.c switch_to_integer.c rules.c array.c sort_less.c utils2.c
HEADER = push_swap.h
CC = cc 
CFLAGS = -Wall -Werror -Wextra
NAME = push_swap
ARG =""


all: $(NAME)
	
$(NAME) : $(CFILES) $(HEADER)
		$(CC) $(CFILES) -o $(NAME)
		
clean:


fclean: clean
	rm -rf $(NAME)

re: fclean all

arg: 
	 ./push_swap $(ARG) | ./checker_Mac $(ARG)

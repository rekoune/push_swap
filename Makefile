CFILES = push_swap.c utils.c switch_to_integer.c rules.c array.c sort_less.c utils2.c
BFILES = checker.c switch_to_integer.c utils.c utils2.c array.c sort_less.c rules.c get_next_line.c get_next_line_utils.c
HEADER = push_swap.h
BHEADER = checker.h
CC = cc 
CFLAGS = -Wall -Werror -Wextra
NAME = push_swap
BNAME = checker


all: $(NAME)
	
$(NAME) : $(CFILES) $(HEADER)
		$(CC) $(CFILES) -o $(NAME)

$(BNAME): $(BFILES) $(BHEADER)
		$(CC) $(BFILES) -o $(BNAME)

bonus:  $(BNAME) 
	
 
clean:


fclean: clean
	rm -rf $(NAME) $(BNAME)

re: fclean all


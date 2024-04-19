CFILES = push_swap.c utils.c switch_to_integer.c rules.c array.c sort_less.c utils2.c
BFILES = checker.c switch_to_integer.c utils.c utils2.c array.c sort_less.c rules.c get_next_line.c get_next_line_utils.c

OFILES = $(CFILES:.c=.o)
BOFILES = $(BFILES:.c=.o)

HEADER = push_swap.h
BHEADER = checker.h

CC = cc 
CFLAGS = -Wall -Werror -Wextra

NAME = push_swap
BNAME = checker


all: $(NAME)
	
$(NAME) : $(CFILES) $(HEADER) $(OFILES)
		$(CC) $(CFLAGS) $(CFILES) -o $(NAME)

$(BNAME): $(BFILES) $(BHEADER) $(BOFILES)
		$(CC) $(CFLAGS) $(BFILES) -o $(BNAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus:  $(BNAME)
	
 
clean:
	rm -rf $(OFILES) $(BOFILES)

fclean: clean
	rm -rf $(NAME)

fcbonus: clean
	rm -rf $(BNAME)

re: fclean all

reb: fcbonus bonus

.PHONY : all bonus clean fclean fcbonus re reb
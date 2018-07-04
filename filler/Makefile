NAME = dkotenko.filler

LBMK = make -C libft/ fclean && make -C libft/

SRCS = filler.c get_next_line.c field_flr.c atoi_map.c token.c base_flr.c\
 vector_distance.c distance.c distance_token.c rewrite.c read_plus.c token_plus.c\
 token_dd.c tracking.c token_field.c free_flr.c bust_run.c mllc.c

GCCO = gcc -Wall -Wextra -Werror -c $(SRCS) -Ifiller.h
GCC = gcc -Wall -Wextra -Werror *.o ./libft/libft.a -o dkotenko.filler

all: $(NAME)

$(NAME): $(SRCS) filler.h
	$(LBMK)
	$(GCCO)
	$(GCC)
clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f dkotenko.filler

re: fclean all
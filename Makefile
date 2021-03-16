##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile of navy
##

SRC	=	$(wildcard *.c)

NAME	=	navy

all:	$(NAME)

$(NAME):
	make -C ./lib/my
	gcc -W -Wall -Wextra -g -o $(NAME) $(SRC) -L./lib/my -lmy

clean:
	make clean -C ./lib/my
	rm -f *~
	rm -f *#

fclean: clean
	make fclean -C ./lib/my
	rm -f $(NAME)

re:	fclean all
	make -C ./lib/my

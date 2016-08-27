NAME = 21sh

SRC = src/history.c src/cursor.c src/ft_addchar.c src/commands.c src/mem.c src/main.c src/environ.c src/term_init.c src/ft_termios.c libft/libft.a

FLAGS = clang -Werror -Wextra -Wall -g -I includes -o

all: $(NAME)

$(NAME):
	@make -C libft/ fclean && make -C libft/ all
	@$(FLAGS) $(NAME) $(SRC) -ltermcap

clean:
	@make -C libft/ clean

fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME)

re: fclean all

##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

CC	=	gcc

WAY	=	src

SRC	=	$(WAY)/main.c						\
		$(WAY)/main_loop.c	\
		$(WAY)/choice_built.c				\
		$(WAY)/convert_str_in_tab/my_str_to_word_array.c	\
		$(WAY)/utilitaries/how_long_tab.c			\
		$(WAY)/utilitaries/find_occurence_env.c			\
		$(WAY)/utilitaries/get_position.c			\
		$(WAY)/utilitaries/get_value_var_env.c			\
		$(WAY)/utilitaries/my_arrcpy.c				\
		$(WAY)/utilitaries/parsing.c				\
		$(WAY)/utilitaries/is_executable.c			\
		$(WAY)/set_env/set_env.c				\
		$(WAY)/set_env/built_set_env.c				\
		$(WAY)/set_env/create_env_by_default.c			\
		$(WAY)/unset_env/unset_env.c				\
		$(WAY)/unset_env/built_unset_env.c			\
		$(WAY)/display_env/display_env.c			\
		$(WAY)/exit/exit.c					\
		$(WAY)/destroy/destroy_element_tab.c			\
		$(WAY)/move_folder/move_folder.c			\
		$(WAY)/move_folder/delete_position.c			\
		$(WAY)/move_folder/add_position.c			\
		$(WAY)/move_folder/built_move_folder.c			\
		$(WAY)/display_path/display_path.c			\
		$(WAY)/execute_program/execute_program.c		\
		$(WAY)/execute_program/signal_program.c			\

OBJ	=	$(SRC:.c=.o)

NAME	=	mysh

CFLAGS	=	-Wall -W -Wextra -Werror -I./include -g3

LIB	=	-L./lib/my -lmy -lgnl

all:	$(OBJ)
	make -C./lib/my
	$(CC) -o $(NAME) $(OBJ) $(LIB)

clean:
	rm -f *~
	make clean -C./tests
	make clean -C./lib/my
	rm -f $(OBJ)

fclean:	clean
	make fclean -C./tests
	make fclean -C./lib/my
	rm -f $(NAME)

re:	clean all

tests_run:
	make -C./tests

##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

CC	=	gcc

WAY	=	../src

SRC	=	$(WAY)/main_loop.c					\
		$(WAY)/choice_built.c					\
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

SRC_UT	=	convert_str_in_tab/tests_utils.c		\
		convert_str_in_tab/tests_utils_second.c		\
		how_long_tab/tests_utils.c			\
		set_env/tests_utils.c				\
		set_env/tests_utils_second.c			\
		set_env/tests_utils_third.c			\
		unset_env/tests_utils.c				\
		display_env/tests_utils.c			\
		exit/tests_utils.c				\
		exit/tests_utils_second.c			\
		destroy/tests_utils.c				\
		move_folder/tests_utils.c			\
		move_folder/tests_utils_second.c		\
		move_folder/tests_utils_third.c			\
		move_folder/tests_utils_four.c			\
		find_occurence_env/tests_utils.c		\
		utilitaries/get_position/tests_utils.c		\
		utilitaries/get_value_var_env/tests_utils.c	\
		utilitaries/my_arrcpy/tests_utils.c		\
		utilitaries/parsing/tests_utils.c		\
		utilitaries/is_executable/tests_utils.c		\
		choice_built/tests_utils.c			\
		display_path/tests_utils.c			\
		execute_program/tests_utils.c			\
		execute_program/tests_utils_second.c		\
		my_printf/tests_utils.c				\

OBJ	=	$(SRC:.c=.o)

OBJ_UT	=	$(SRC_UT:.c=.o)

NAME	=	./units

CFLAGS	=	-Wall -W -Wextra -Werror -I../include -g3 --coverage

LIB	=	-L../lib/my -lmy

LDFLAGS	=	-lcriterion -lgcov

all:	$(OBJ) $(OBJ_UT)
	make -C../lib/my
	$(CC) -o $(NAME) $(OBJ) $(OBJ_UT) $(LIB) $(LDFLAGS)
	./$(NAME)

clean:
	rm -f *~
	rm -f $(OBJ)
	rm -f $(OBJ_UT)
	rm -f $(OBJ:.o=.gcda)
	rm -f $(OBJ_UT:.o=.gcda)
	rm -f $(OBJ:.o=.gcno)
	rm -f $(OBJ_UT:.o=.gcno)

fclean:	clean
	rm -f $(NAME)

re:	clean all

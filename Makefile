#* ************************************************************************** *#
#*                                                                            *#
#*                                                                            *#
#*   Makefile                                                                 *#
#*                                                                            *#
#*   By: blukasho <blukasho@ustork.com.ua>                                    *#
#*                                                                            *#
#*   Created: 2020/10/28 00:02:38 by blukasho                                 *#
#*   Updated: 2020/10/28 02:34:11 by blukasho                                 *#
#*                                                                            *#
#* ************************************************************************** *#

SRCS = read.c malloc.c init.c

SRCS_DIR = srcs/

OBJ = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

OBJ_DIR = obj/

LIBFT_PATH = libft/

CURR_PATH = .

LIB_NAME = libft/libft.a

LABSP2 = labSp2

FLAGS =  -I includes -Wall -Wextra -Werror

DEBUG_FLAGS = -g3 -fsanitize=address

LABSP2_MAIN = srcs/main.c

all: make_obj_dir make_lib $(LABSP2)

$(LABSP2): $(LIB_NAME) $(LABSP2_MAIN)
	gcc $(FLAGS) $(LABSP2_MAIN) $(LIB_NAME) -o $(LABSP2)

$(LIB_NAME): $(OBJ)
	ar -rv $(LIB_NAME) $^
	ranlib $(LIB_NAME)

set_debug_flags:
	$(eval FLAGS=$(FLAGS) $(DEBUG_FLAGS))

$(OBJ_DIR)%.o: $(SRCS_DIR)%.c
	gcc $(FLAGS) -c $< -o $@

debug: make_debug_lib set_debug_flags all

make_debug_lib:
	make debug -C $(LIBFT_PATH)

make_obj_dir:
	@mkdir -p $(OBJ_DIR)

make_lib:
	@make -C $(LIBFT_PATH)

make_clean_lib:
	make clean -C $(LIBFT_PATH)

clean: make_clean_lib
	rm -rf $(OBJ_DIR)
	rm $(LABSP2)

fclean: clean
	make fclean -C $(LIBFT_PATH)

re: fclean all

.PHONY: all clean fclean re debug

#* ************************************************************************** *#
#*                                                                            *#
#*                                                                            *#
#*   Makefile                                                                 *#
#*                                                                            *#
#*   By: yhetman <yhetman@student.unit.ua>                                    *#
#*                                                                            *#
#*   Created: 2020/10/28 00:02:38 by yhetman                                  *#
#*   Updated: 2020/10/28 10:45:51 by yhetman                                  *#
#*                                                                            *#
#* ************************************************************************** *#

SRCS = malloc.c states.c read.c check_w1_w2.c input_w1_w2.c extra_error_exit.c \
		find_connection.c free.c

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

debug: fclean make_debug_lib set_debug_flags all

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

fclean: clean
	make fclean -C $(LIBFT_PATH)
	rm -f $(LABSP2)

re: fclean all

.PHONY: all clean fclean re debug

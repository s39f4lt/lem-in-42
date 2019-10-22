# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/08 14:50:16 by idunaver          #+#    #+#              #
#    Updated: 2019/10/22 19:18:14 by idunaver         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all libft clean fclean re

OBJDIR = obj
SRCDIR = src
LIBDIR = libft
HEADER = -I ./include
HEADER_LIBFT = -I ./libft/include -I ./libft/src/ft_printf/include
FLAGS = -Wall -Wextra -Werror -g -O0

LEM-IN = lem-in
SRC_LEM-IN_NAME = main.c \
				  error.c \
				  node.c \
				  links.c \
				  lem_in.c \
				  id_node.c \
				  get_ants.c \
				  quick_sort.c \
				  check_repeat.c \
				  adj_matrix.c \
				  breadth_first_search.c \
				  queque.c \
				  path_for_ants.c \
				  create_path.c \
				  nuller.c \
				  all_free_1.c \
				  all_free_2.c \
				  valid.c \
				  output_book.c \
				  prints.c \
				  init_struct.c \
				  array_node.c \
				  print_result.c

OBJ_LEM-IN_NAME = $(SRC_LEM-IN_NAME:.c=.o);
SRC_LEM-IN = $(addprefix $(OBJDIR)/, $(SRC_LEM-IN_NAME))
OBJ_LEM-IN = $(addprefix $(OBJDIR)/, $(OBJ_LEM-IN_NAME))

all: libft $(LEM-IN)

$(LEM-IN): $(OBJ_LEM-IN)
	@gcc $(FLAGS) $^ -o $@ $(HEADER_LIBFT) $(HEADER) -L libft -lft

$(OBJDIR)/%.o: $(SRCDIR)/%.c include/lem_in.h
	@mkdir -p $(OBJDIR)
	@gcc $(FLAGS) $(HEADER_LIBFT) $(HEADER) -o $@ -c $<

libft:
	@make -C $(LIBDIR)

clean:
	@make clean -C $(LIBDIR)
	@rm -Rf $(OBJDIR)

fclean: clean
	@make fclean -C $(LIBDIR)
	@rm -Rf $(LEM-IN)

re: fclean all

norm:
	norminette $(SRCDIR)
	norminette ./include

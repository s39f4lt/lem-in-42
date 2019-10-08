# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/08 14:50:16 by idunaver          #+#    #+#              #
<<<<<<< HEAD
#    Updated: 2019/10/05 20:00:42 by rgendry          ###   ########.fr        #
=======
#    Updated: 2019/10/06 21:01:57 by idunaver         ###   ########.fr        #
>>>>>>> 517fca4c4fcad88db3ec485d41b4b3d00e2622ca
#                                                                              #
# **************************************************************************** #

.PHONY: all libft clean fclean re

OBJDIR = obj
SRCDIR = src
LIBDIR = libft
HEADER = -I ./include
HEADER_LIBFT = -I ./libft/include -I ./libft/src/ft_printf/include
FLAGS = -Wall -Wextra -Werror -g

LEM-IN = lem-in
SRC_LEM-IN_NAME = main.c \
				  error.c \
				  arr_len.c \
				  check_char.c \
				  check_int.c \
				  free_arr.c \
				  validation.c \
				  get_data.c \
				  get_link.c \
				  get_node.c

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
	@rm -Rf $(LEM_IN)

re: fclean all

norm:
	norminette $(SRCDIR)
	norminette ./include

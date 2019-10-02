# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/08 14:50:16 by idunaver          #+#    #+#              #
#    Updated: 2019/10/02 17:32:09 by rgendry          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all libft clean fclean re

OBJDIR = obj
SRCDIR = src
LIBDIR = libft
HEADER = -I ./include
HEADER_LIBFT = -I ./libft/include -I ./libft/src/ft_printf/include
FLAGS = -Wall -Wextra -Werror -g

LEM-IN = lem_in
SRC_LEM-IN_NAME = main.c \
				  error.c \
				  validation.c \
				  get_data.c

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

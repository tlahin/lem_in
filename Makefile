# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlahin <tlahin@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/08 10:42:05 by tlahin            #+#    #+#              #
#    Updated: 2022/11/08 10:42:07 by tlahin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

SRCS_DIR = srcs/
SRCS = main parse_map parse_map_utils

OBJS_DIR = objs/
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRCS)))

FLAGS = -Wall -Wextra -Werror
INCLUDES = includes/
LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJS)
	gcc $(OBJS) $(LIBFT) -I $(INCLUDES) $(FLAGS) -o $@

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(INCLUDES)lem_in.h $(LIBFT)
	@mkdir -p $(OBJS_DIR)
	gcc -c $(FLAGS) -I $(INCLUDES) $< -o $@

$(LIBFT):
	make -C libft/

clean:
	@make clean -C libft/
	@rm -f $(OBJS)
	@rm -rf $(OBJS_DIR)

fclean: clean
	@make fclean -C libft/
	@/bin/rm -f $(NAME)
	@/bin/rm -f a.out

re: fclean all

.PHONY: all clean fclean re

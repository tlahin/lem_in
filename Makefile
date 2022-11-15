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
SRCS = main reader

OBJS_DIR = objs/lem_in/
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRCS)))

FLAGS = -Wall -Wextra -Werror
INCLUDES = includes/
LIBFT = libft/libft.a

OPTIMIZATION = -Ofast

all: $(NAME)

$(NAME): $(OBJS)
	gcc $(OBJS) $(LIBFT) -I $(INCLUDES) $(FLAGS) -o

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(INCLUDES) $(LIBFT)
	@mkdir -p $(OBJS_DIR)
	gcc -c $(FLAGS) -I $(INCLUDES) $< -o $@ $(OPTIMIZATION)

$(LIBFT):
	make -C libft/

clean:
	@make clean -C libft/
	@rm -f $(OBJS)
	@rm -rf $(OBJS_DIR)

fclean: clean
	@make clean -C libft/
	@rm -f $(OBJS)
	@rm -rf $(OBJS_DIR)

re: fclean all

.PHONY: all clean fclean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dtrigalo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/07 17:58:51 by dtrigalo          #+#    #+#              #
#    Updated: 2019/05/07 18:50:35 by anleclab         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CFLAGS = -Wall -Wextra -Werror 

SRC = 	gradient.c \
		mouse.c \
		projection_calculus.c \
		command_menu.c \
		rotate.c \
		main.c \
		error.c \
		reader.c \
		projection.c \
		get_placement_info.c \
		new_image.c \
		draw_image.c \
		events.c \
		event_actions.c \
		apply_colors.c \
		tools.c \
		draw_point.c
SRCSFD = srcs/
OBJSFD = objs/
OBJS = $(addprefix $(OBJSFD),$(SRC:.c=.o))

HDR = fdf.h
HDRSFD = includes/
HDRS = $(addprefix $(HDRSFD), $(HDR))

HDR_INC = -I./includes
LIBFT_HDR = -I./libft/includes
LIB_BINARY = -L./libft -lft
LIBFT= libft/libft.a

MLX = -I /usr/local/include -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

RED = \033[0;31m
GREEN = \033[0;32m
NONE = \033[0m

all: check_libft project $(NAME)

check_libft:
	@echo "Checking libft..."
	@make -C libft

project:
	@echo "Checking project..."

$(OBJSFD):
	@mkdir $@
	@echo "\t[ $(GREEN)✔$(NONE) ] $(OBJSFD) directory"

$(OBJSFD)%.o: $(SRCSFD)%.c $(HDRS) $(LIBFT)
	@gcc $(CFLAGS) $(HDR_INC) $(LIBFT_HDR) -c $< -o $@
	@echo "\t[ $(GREEN)✔$(NONE) ] $@ object"

$(NAME): $(OBJSFD) $(OBJS) $(LIBFT) $(HDRS)
	@gcc $(CFLAGS) $(OBJS) $(MLX) $(LIB_BINARY) -o $@
	@echo "\t[ \033[0;32m✔\033[0m ] $(NAME) executable"

clean:
	@/bin/rm -rf $(OBJSFD)
	@echo "\t[ $(RED)✗$(NONE) ] $(OBJSFD) directory"
	@make -C ./libft clean

fclean: clean
	@/bin/rm -rf $(NAME)
	@echo "\t[ $(RED)✗$(NONE) ] $(NAME) executable"
	@make -C ./libft fclean

re: fclean all

.PHONY: check_libft project clean fclean re

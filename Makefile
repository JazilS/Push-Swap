# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsabound <jsabound@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/29 18:16:16 by jsabound          #+#    #+#              #
#    Updated: 2023/01/23 16:14:40 by jsabound         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables

NAME		= push_swap
INCLUDE		= ./
LIBFT		= libft
PRINTF		= ft_printf
SRC_DIR		= srcs/
OBJ_DIR		= objects/
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g3
RM			= rm -f
SMAKE		= make --no-print-directory

# Colors

END			=	\033[0m
BOLD		=	\033[1m
UNDER		=	\033[4m
REV			=	\033[7m
DEF_COLOR	=	\033[0;39m
GRAY		=	\033[0;90m
RED			=	\033[0;91m
LIGHT_RED	=	\033[0;31m
GREEN		=	\033[0;92m
YELLOW		=	\033[0;93m
BLUE		=	\033[0;94m
MAGENTA		=	\033[0;95m
CYAN		=	\033[0;96m
WHITE		=	\033[0;97m

# Sources

SRC_FILES	=	parsing main push_swap init


SRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

###

OBJF		=	.cache_exists

all:		$(NAME)

bonus:		all

$(NAME):	$(OBJ)
			@$(SMAKE) -C $(LIBFT)
			@$(SMAKE) -C ${PRINTF}
			@$(CC) $(OBJ) -L $(LIBFT) -L $(PRINTF) -lX11 -lXext -lft -lm -o $@
			@echo "$(GREEN)$(BOLD)push_swap compiled!$(DEF_COLOR)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
			@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
			@$(CC) $(CFLAGS) -I $(INCLUDE) -I $(LIBFT)/includes -I $(PRINTF) -c $< -o $@

$(OBJF):
			@mkdir -p $(OBJ_DIR)

clean:
			@$(RM) -r $(OBJ_DIR)
			@echo "$(BLUE)push_swap object files cleaned!$(DEF_COLOR)"

fclean:		clean
			@$(RM) $(NAME)
			@$(RM) $(PRINTF)/libftprintf.a
			@$(SMAKE) -C $(LIBFT) fclean
			@echo "$(CYAN)printf executable files cleaned!$(DEF_COLOR)"
			@echo "$(CYAN)push_swap executable files cleaned!$(DEF_COLOR)"

re:			fclean all

norm:
			@norminette $(SRC) $(INCLUDE) | grep -v Norme | awk '{\
			if ($$NF == "OK!") { \
				print "$(GREEN)"$$0"$(END)" \
			} else if ($$NF == "Error!") { \
				print "$(RED)$(BOLD)"$$0"$(END)" \
			} else if ($$1 == "Error:") { \
				print "$(LIGHT_RED)"$$0"$(END)" \
			} else { print }}'

.PHONY:		all clean fclean re norm
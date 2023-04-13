# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: victgonz <victgonz@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/21 23:08:02 by efrre-m           #+#    #+#              #
#    Updated: 2023/02/22 09:19:28 by victgonz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROJECT = PRINTF

LIBS_DIR = libft

TEST        = src/main.c

LIBTEST     = ftprintf

INCLUDES = includes/include

NAME = libftprintf.a

CC = gcc

RM = rm -f

CFLAGS = -Wall -Werror -Wextra

SRC_DIR = src/

OBJ_DIR = obj/

SRCS_FILES =	ft_printf 					\
				func_ptr					\
				func_putnbr 				\
				utils_1						\
				utils_2						\
				std_func 					\
				std_func_2 					\
				func_conv/func_s_c			\
				func_conv/func_e_f			\
				func_conv/func_p			\
				func_conv/func_u			\
				func_conv/func_x			\
				func_conv/func_o			\
				func_conv/func_d_i			\
				func_conv/func_d_i_utils	\
				func_conv/func_b			\
				func_conv/func_g			\
				func_conv/func_n			\
				get_info/get_info	 		\
				get_info/get_info_2			\
				free_info/free_1

SRCS = $(addprefix $(SRC_DIR),  $(addsuffix .c, $(SRCS_FILES)))

OBJS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRCS_FILES)))

OBJBONUS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRCS_FILES)))

OBJF        =   .cache_exists

####	COLORS	####

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

#### COMMANDS ####

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

$(OBJF):
			@mkdir -p $(OBJ_DIR)

$(NAME):	$(OBJS)
			cp libft/libft.a .
			mv libft.a $(NAME)
			ar rcs $(NAME) $(OBJS)
			ranlib $(NAME)

all: 		make_libs $(NAME) write_name

write_name:
		@echo "$(MAGENTA)╔═════════════════════════════════════════╗$(DEF_COLOR)"
		@echo "$(MAGENTA)║                  $(CYAN)$(PROJECT)$(MAGENTA)                 ║$(DEF_COLOR)"
		@echo "$(MAGENTA)╚═══════════════╦═════════╦═══════════════╝$(DEF_COLOR)"
		@echo "$(MAGENTA)                ║  $(GREEN)VIC'S$(MAGENTA)  ║$(DEF_COLOR)"
		@echo "$(MAGENTA)                ╚═════════╝     $(DEF_COLOR)"

bonus:		all
			
clean: 		
			$(RM) $(OBJS) $(OBJSBONUS) 
			make clean -C $(LIBS_DIR)

fclean: 	clean
			$(RM) $(NAME)
			$(RM) -f ./a.out
			make fclean -C $(LIBS_DIR)

re:			fclean all

test:	$(NAME)
		$(CC) $(TEST) -L. -l$(LIBTEST) $(CFLAGS) -I $(INCLUDES)

make_libs:
			make -C $(LIBS_DIR)

.PHONY: all clean fclean re bonus test
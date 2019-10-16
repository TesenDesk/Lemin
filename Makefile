# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/11 18:21:00 by ftothmur          #+#    #+#              #
#    Updated: 2019/10/16 22:57:27 by jjerde           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY:			all clean_lib clean_this clean fclean_lib fclean_thisfclean re
#====================================LIB=======================================#
#---------------------------------directories----------------------------------#
LIB_DIR			:=	./lib_ftot/
HL_DIR			:=	$(LIB_DIR)
MHL_DIR			:=	./libft_t/includes/
LEM_HDR_M		:=	./includes/
#---------------------------------ftothmur lib---------------------------------#
LIB				:=	$(LIB_DIR)libft_f.a
#===================================PROJECT====================================#
#---------------------------------directories----------------------------------#
DIR				:=	./
HEADER_DIR		:=	$(DIR)
OBJ_DIR			:=	$(DIR)
SRC_DIR			:=	$(DIR)src/
#------------------------------------files-------------------------------------#
NAME			:=	initiator
SRC				:=	$(addprefix $(SRC_DIR),main_initializer.c line_condition.c \
parsers.c vertex_funcs.c fillers.c fill_map.c) algorithm.c bfs.c ft_qeue.c

OBJ				:=	$(patsubst %.c,%.o, $(SRC))
NAME_HDR_DIR	:=	$(SRC_DIR)
#----------------------------------includes------------------------------------#
M_HDR			:=	$(MHL_DIR)libft.h
LIB_HEADER		:=	$(HL_DIR)libft_f.h
NAME_HDR		:=	$(NAME_HDR_DIR)ftothmur.h
LEM_HDR_M		:=	$(LEM_HDR_M)lemin.h
HEADERS			:=	$(M_HDR) $(LIB_HEADER) $(NAME_HDR) $(LEM_HDR_M)
#------------------------------------flags-------------------------------------#
ifeq ($(DEBUG), 1)
	CFLAGS		:=	-Wall -Wextra -Werror -g
else
	CFLAGS		:=	-Wall -Wextra -Werror
endif
LIB_FLAGS		:=	-L$(LIB_DIR) -lft_f
HDR_FLAGS		:=	-I$(NAME_HDR_DIR) -I$(HL_DIR) -I$(MHL_DIR)
#===================================RULES======================================#
all:				$(NAME)
					
$(NAME):			$(SRC) $(LIB) $(OBJ) $(HEADERS)
					gcc -o $(NAME) $(OBJ) $(HDR_FLAGS) $(LIB_FLAGS) $(CFLAGS)

$(LIB):
					make -C $(LIB_DIR)

%.o:				%.c 
					gcc $(CFLAGS) -c $< $(HDR_FLAGS) -o $@

clean_lib:
					make clean -C $(LIB_DIR)

clean_this:
					rm -rf $(OBJ)

clean: 				clean_lib clean_this
					
fclean_lib:
					make fclean -C $(LIB_DIR)

fclean_this:
					rm -rf $(NAME)
				
fclean:				fclean_lib clean_this fclean_this					

re:					fclean all
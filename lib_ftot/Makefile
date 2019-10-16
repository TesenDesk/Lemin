# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/12 20:24:31 by ftothmur          #+#    #+#              #
#    Updated: 2019/10/16 19:19:40 by ftothmur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# This Makfeile compile mstygg lib and adds files fro this subproject to that  #
# function.

.PHONY:			all clean_lib clean_this clean fclean_lib fclean_thisfclean re
#====================================LIB=======================================#
#---------------------------------mstygg lib-----------------------------------#
M_LIB_DIR		:=	../libft_t/
M_HL_DIR		:=	$(M_LIB_DIR)includes/
M_LIB			:=	$(M_LIB_DIR)libft.a
M_LIB_FLAGS		:=	-L $(M_LIB_DIR) -lft
#===================================PROJECT====================================#
#---------------------------------directories----------------------------------#
DIR				:=	./
HEADER_DIR		:=	$(DIR)
OBJ_DIR			:=	$(DIR)
#------------------------------------files-------------------------------------#
NAME			:=	libft_f.a
SRC				:=	ft_dlstadd.c ft_dlstaddtip.c ft_dlstcmp.c \
					ft_dlstcontentdel.c ft_dlstdel.c ft_dlstfind.c \
					ft_dlstfind_i.c ft_dlstfind_ir.c ft_dlstfind_r.c \
					ft_dlstforeach.c ft_dlstiter.c ft_dlstnew.c \
					ft_dlstpop.c ft_dlstpop_rear.c ft_dlstpush.c \
					ft_dlstpush_back.c ft_dlstsize.c ft_dlstswap.c \
					ft_imaxtostr.c ft_isdigitnstr.c ft_isdigitstr.c \
					ft_lstcmp_next.c ft_lstfind.c ft_lstremove.c \
					ft_realloc.c ft_reverse.c ft_strint_ou_flow.c \
					ft_strrev.c ft_swap.c ft_uimaxdiv.c ft_free_ptr_ar.c \
					ft_delfunc_dummy.c ft_ddeq_new_a.c ft_ddeqdel.c \
					ft_ddeqnew.c ft_ddeqpush_b_all.c ft_ddeqpush_b.c
OBJ				:=	$(patsubst %.c,%.o, $(SRC))
#------------------------------------flags-------------------------------------#
ifeq ($(DEBUG), 0)
	CFLAGS		:=	-Wall -Wextra -Werror -g
else
	CFLAGS		:=	-Wall -Wextra -Werror
endif
HDR_FLAGS		:=	-I $(HEADER_DIR) -I $(M_HL_DIR)
#===================================RULES======================================#
all:				$(NAME)

$(NAME):			$(M_LIB) $(OBJ)
					mv $(M_LIB) $(DIR)
					mv $(notdir $(M_LIB)) $(NAME)
					ar rc $(NAME) $(OBJ)
					ranlib $(NAME)

$(M_LIB):
					make -C $(M_LIB_DIR)

%.o:				%.c
					gcc $(CFLAGS) -c $< $(HDR_FLAGS) -g

clean_lib:
					make clean -C $(M_LIB_DIR)

clean_this:
					rm -rf *.o

clean:				clean_lib clean_this

fclean_lib:
					make fclean -C $(M_LIB_DIR)

fclean_this:		clean_this
					rm -rf $(NAME)
fclean:				fclean_lib fclean_this
					
re:					fclean all

print_arg:
					printf "$(OBJ)"
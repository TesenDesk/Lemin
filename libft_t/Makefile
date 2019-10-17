NAME := libft.a
CFLAGS := -Wall -Wextra 
INCLUDE_PATH := ./includes
SEARCH := ft_atoi.c ft_atol.c ft_avl_balance.c ft_avl_bfactor.c ft_avl_create.c ft_avl_findmin.c\
		   ft_avl_fix_height.c ft_avl_height.c ft_avl_insert.c ft_avl_remove.c ft_avl_rot_left.c\
		    ft_avl_rot_right.c ft_avl_search.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c\
  		 ft_isdigit.c ft_isprint.c ft_itoa.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c\
	      ft_lstmap.c ft_lstnew.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c\
         ft_memdel.c ft_memjoin.c ft_memmove.c ft_memset.c ft_pow.c ft_putchar.c ft_putchar_fd.c\
		      ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c\
		     ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c\
		ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c\
		            ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c\
		            ft_strnstr.c ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c\
		                              ft_tolower.c ft_toupper.c get_next_line.c ft_is_negative.c\
		  find_max_from_three.c find_min_from_three.c find_middle_from_three.c ft_min.c ft_max.c\
			  ft_count_snum_size.c ft_str_avl_balance.c ft_str_avl_bfactor.c ft_str_avl_create.c\
		    ft_str_avl_findmin.c ft_str_avl_fix_height.c ft_str_avl_height.c ft_str_avl_insert.c\
			ft_str_avl_remove.c ft_str_avl_rot_left.c ft_str_avl_rot_right.c ft_str_avl_search.c\
			                hash_table_init.c adjust_prec_analize_cell.c adjust_prec_norm_form.c\
	 adjust_prec_rebuild_func.c adjust_prec_sci_form.c adjust_prec_utility_func.c char_manager.c\
   chose_content.c chose_content2.c content_decision_maker.c  distinct_types.c fill_spec_func1.c\
   fill_spec_func2.c ldouble_manager1.c ldouble_manager2.c ldouble_utilities.c ldouble_inf_nan.c\
                 ft_itoa_base.c ft_printf.c libft_func_1.c long_arythmetic1.c long_arythmetic2.c\
		     long_arythmetic3.c long_arythmetic4.c long_arythmetic5.c manage_str.c num_manager.c\
		        num_manager_utilities.c print_func.c put_into_buf_func1.c put_into_buf_ldouble.c\
		 put_into_buf_ldouble_utilities.c put_buf_ld_sci_form.c put_into_buf_utf.c str_manager.c\
		 ft_avl_del.c ft_str_avl_del.c
OBJECTS := $(patsubst %.c,%.o,$(SEARCH))
LIBHEADER := includes/libft.h

all:  $(NAME)

$(NAME): $(OBJECTS)
	ar rc $@ $^
	ranlib $@	

%.o: %.c $(LIBHEADER)
	gcc $(CFLAGS) -c $< -I $(INCLUDE_PATH) -g

clean:
	rm -rf $(OBJECTS) 

fclean:	clean
	rm -rf $(NAME)

re:	fclean all

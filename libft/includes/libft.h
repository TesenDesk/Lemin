/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:31:20 by mstygg            #+#    #+#             */
/*   Updated: 2019/10/08 20:53:40 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef LIBFT_H
#	define LIBFT_H

#include <string.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_avl_t
{
	int				key;
	unsigned char	height;
	void			*content;
	size_t			size;
	struct s_avl_t	*left;
	struct s_avl_t	*right;
}					t_avl_t;

typedef	struct 				s_pair
{
	void					*key;
	void					*content;
}							t_pair;

typedef struct				s_keystr_avl_t
{
	// void					*key;
	unsigned char			height;
	// void					*content;
	t_pair					*pair;
	size_t					size;
	struct s_keystr_avl_t	*left;
	struct s_keystr_avl_t	*right;
}							t_keystr_avl_t;
//map_size-сколько ячеек в карте(каждая ячейка-узел дерева, представляющий собой список)
//arr_size-размер массива деревьев
//limit узнаем при чтении(количество узлов в дереве/количество вершин в графе),
//multiplier и lfactor не используются(нужны для расширения мапы, а мы заранее знаем размер)

//в нашем случае ar_size будет равен map_size после заполнения всеми вершинами

// пропущено _ в типе хеш-таблицы vvvvv
typedef struct				s_hashmap
{
    t_keystr_avl_t 			**data;
    size_t 					map_size;
    size_t 					arr_size;
	size_t					limit;
	size_t					l_factor;
	float					multiplier;
}							t_hash_map;

/*
**FUNC_DEFS
*/
# define CMP(s1, s2) ft_strcmp(s1, s2)

/*
**COSNT
*/


# define BUFF_SIZE  10000

/*
**TYPES
*/

# define ULL			unsigned long long
# define LL		   		long long
# define U_CHAR			unsigned char

/*
**HASH_CONST
*/

# define HASH_CONST		5381

/*
**BASIC_FUNCTIONS
*/
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
char				*ft_memjoin(char *s1, char *s2, size_t t1, size_t t2);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *src);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack,
					const char *needle);
char				*ft_strnstr(const char *haystack,
					const char *needle, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
long long			ft_atol(const unsigned char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int,
					char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char
					(*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2,
					size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
unsigned long long	ft_pow(unsigned long long base, int exp);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);

/*
**NUMBER COUNTING FUNCTIONS
*/
int					ft_is_negative(LL num);
LL					ft_min(LL num1, LL num2);
LL					ft_max(LL num1, LL num2);
LL					find_min_from_three(LL num1, LL num2, LL num3);
LL					find_max_from_three(LL num1, LL num2, LL num3);
LL					find_middle_from_three(LL num1, LL num2, LL num3);
size_t				ft_count_snum_size(long long k);

/*
**LIST_FUNCTIONS
*/

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

/*
**TREE_FUNCTIONS
*/

t_avl_t						*ft_avl_create(int key);
U_CHAR						ft_avl_height(t_avl_t *p);
int							ft_avl_bfactor(t_avl_t *p);
void						ft_avl_fix_height(t_avl_t *p);
t_avl_t						*ft_avl_rot_right(t_avl_t *p);
t_avl_t						*ft_avl_rot_left(t_avl_t *p);
t_avl_t						*ft_avl_balance(t_avl_t *p);
t_avl_t						*ft_avl_insert(t_avl_t *p, int key);
t_avl_t						*ft_avl_search(t_avl_t *p, int key);
t_avl_t						*ft_avl_findmin(t_avl_t *p);
t_avl_t						*ft_avl_remove(t_avl_t *p, int key);


t_keystr_avl_t				*ft_keystr_avl_create(t_pair *pair);
U_CHAR						ft_keystr_avl_height(t_keystr_avl_t *p);
int							ft_keystr_avl_bfactor(t_keystr_avl_t *p);
void						ft_keystr_avl_fix_height(t_keystr_avl_t *p);
t_keystr_avl_t				*ft_keystr_avl_rot_right(t_keystr_avl_t *p);
t_keystr_avl_t				*ft_keystr_avl_rot_left(t_keystr_avl_t *p);
t_keystr_avl_t				*ft_keystr_avl_balance(t_keystr_avl_t *p);
t_keystr_avl_t				*ft_keystr_avl_insert(t_keystr_avl_t *p, t_pair *pair);
t_keystr_avl_t				*ft_keystr_avl_search(t_keystr_avl_t *p, void *key);
t_keystr_avl_t				*ft_keystr_avl_findmin(t_keystr_avl_t *p);
t_keystr_avl_t				*ft_keystr_avl_remove(t_keystr_avl_t *p, void *key);
/*
**HASHMAP_FUNC
*/
ULL      					hashcode(U_CHAR *str);
t_hash_map					*createHashmap(size_t vertices_num);
int          		  		push_to_map(t_hash_map **map, t_pair *pair);
int							hm_put(t_hash_map **map, void *key, void *content);




/*
**GET_NEXT_LINE
*/

int					get_next_line(const int fd, char **line);


#	endif

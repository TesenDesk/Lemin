/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 15:05:36 by ftothmur          #+#    #+#             */
/*   Updated: 2019/11/05 16:43:44 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/*
** Header files dependencies.
**
** string.h for NULL and size_t.
** stdlib.h for malloc and free.
** unistd.h for write.
** limits.h for limits of types macroconstants.
** inttypes.h for fixed-width integer types, like intmax_t
** wchar.h for wint_t and wchar_to
** fcntl.h for open()
*/
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <wchar.h>
# include <fcntl.h>
# include <stdio.h>

/*
** MAX_SIZE is a MACRO SIZE_MAX of stdint.h, which is forbidden to include
** at the project. It's size is size_t or 18446744073709551615LUU == 2 ^ 64 - 1
** It is too big, to count. Malloc returns error for this value, zsh kills
** proces, when it is bigger then MAX_INT * 2048. But it do well with
** MAX_INT * 2, which is 4294967295. So let MAX_SIZE be it. Or, if necessary,
** you can use a value equal to the massed address. This is the number that can
** be obtained using 8 bytes. size_t(-1)
** macro STDOUT is for fd of ft_putchar etc.
** macro MIN_INT is for mininimal integer value
*/

# ifndef SIZE_MAX
#  define SIZE_MAX			0xffffffffffffffffL
# endif

# define MAX_SIZE			SIZE_MAX
# define STDIN				0
# define STDOUT				1
# define STDERR				2

# ifndef EOF
#  define EOF 				(-1)
# endif

# ifndef SSIZE_MAX
#  define SSIZE_MAX			0x7fffffffffffffffLL
# endif

# ifndef INT_MAX
#  define INT_MAX			0x7fffffff
# endif

# ifndef UINT_MAX
#  define UINT_MAX			0xffffffffU
# endif

# define MIN_INT			(-2147483648)

# define BITS_AT_BYTE		8
# define INTMAX_BITS		64

# define CHAR_BYTES			1
# define SHORT_BYTES		2
# define INT_BYTES			4
# define INTMAX_BYTES		8

# define CHAR_SGN_MASK		0x80
# define SHORT_SGN_MASK		0x8000
# define INT_SGN_MASK		0x80000000
# define MAX_SGN_MASK		0x8000000000000000

# define DEL_CHAR_SGN		0x7f
# define DEL_SHORT_SGN		0x7fff
# define DEL_INT_SGN		0x7fffffff
# define DEL_MAX_SGN		0x7fffffffffffffffL

# define REMOVE_SIGN		1

/*
** BIN_CHECK is number of bites should be cheked if the variable is binary.
** It is for the ft_isbinary() function.
*/
# define BIN_CHECK			1024

/*
**		BUFSIZE			optimum I/O blocksize $>: stat -f %k filename
**		BEST_SIZE		the same
*/
# define BUFSIZE			4096
# define BEST_SIZE			4096

/*
** List of error values for custom error() function. Values are from ERRNO.
**
**	Previous:
**		ONEARG:				only one argument, argc == 2
**
** 		defines:			ft_error.c
** 		NOFILES:			argc < ONEARG
**		TOO_MANY_FILES	:	argc > ONEARG
** 		NOTOPEN:			fd < EXIT_SUCCESS
** 		NOTREAD:			read(fd) == -1
** 		NOTCLOSE:			close(fd) != 0
*/

# define ERROR				(-1)

# define FAILURE			(-1)
# define SUCCESS			0

# define TRUE				1
# define FALSE				0

# define ENOENTRY			1
# define EINOUT				2
# define E2BIGENT			3
# define EBADFD				4
# define ENOMEMORY			5
# define ENOACCES			6
# define EINVALARG			7
# define EFILE2BIG			8
# define ENOMSGS			9
# define EOVERFLOW			10

# define NOCHANGES			1

# define F_BK_B				"\e[30m"
# define F_BL_B				"\e[34m"
# define F_CY_B				"\e[36m"
# define F_GN_B				"\e[32m"
# define F_MG_B				"\e[35m"
# define F_RD_B				"\e[31m"
# define F_YL_B				"\e[33m"
# define F_WT_B				"\e[37m"

# define F_BK_L				"\e[30;1m"
# define F_BL_L				"\e[34;1m"
# define F_CY_L				"\e[36;1m"
# define F_GN_L				"\e[32;1m"
# define F_MG_L				"\e[35;1m"
# define F_RD_L				"\e[31;1m"
# define F_YL_L				"\e[33;1m"
# define F_WT_L				"\e[37;1m"

# define B_BK_L				"\e[40m"
# define B_BL_L				"\e[44m"
# define B_CY_L				"\e[46m"
# define B_GN_L				"\e[42m"
# define B_MG_L				"\e[45m"
# define B_RD_L				"\e[41m"
# define B_YL_L				"\e[43m"
# define B_WT_L				"\e[47m"

# define B_BK_B				"\e[100m"
# define B_BL_B				"\e[104m"
# define B_CY_B				"\e[106m"
# define B_GN_B				"\e[102m"
# define B_MG_B				"\e[105m"
# define B_RD_B				"\e[101m"
# define B_YL_B				"\e[103m"
# define B_WT_B				"\e[107m"

# define BLD				"\e[1m"

# define CL					"\e[0m"

/*
**	Trie.
*/

# ifndef ASCII_ABC
#  define ASCII_ABC			128
# endif

/*
**				Arbitrary precision arithmetic constants.
*/

# define LDBL_EXP_BIAS		16383
# define SGNFND_BITS		64

# define BIGNUM_RADIX		0xffffffff
# define BIGNUM_SIZE		516

/*
**						States of float point variable
*/
# define NAN				0
# define INF				1
# define NORMAL_NBR			2
# define SUBNORM_NBR		3

# define INTSTR_MAX			10
# define LONGINTSTR_MAX		20

# define U_CHAR				unsigned char
# define ULL				unsigned long long
# define HASH_CONST			5381

/*
**						FUNC_DEFS
*/
# define CMP(s1, s2) ft_strcmp(s1, s2)

/*
**	Data structures.
*/

/*
**	Linked list.
*/
typedef struct				s_list
{
	void					*content;
	size_t					content_size;
	struct s_list			*next;
}							t_list;

/*
** Circular double linked list
*/
typedef struct				s_dlist
{
	void					*content;
	size_t					content_size;
	struct s_dlist			*next;
	struct s_dlist			*prev;
	int						flow;
}							t_dlist;

/*
**	Binary tree.
*/
typedef struct				s_btree
{
	struct s_btree			*left;
	struct s_btree			*right;
	void					*item;
}							t_btree;

typedef	struct				s_pair
{
	char					*key;
	void					*content;
}							t_pair;

typedef struct				s_keystr_avl_t
{
	unsigned char			height;
	t_pair					*pair;
	size_t					size;
	struct s_keystr_avl_t	*left;
	struct s_keystr_avl_t	*right;
}							t_keystr_avl_t;

typedef struct				s_hashmap
{
	t_keystr_avl_t			**data;
	size_t					map_size;
	size_t					arr_size;
	size_t					limit;
	size_t					l_factor;
	float					multiplier;
}							t_hash_map;
/*
**	Trie.
*/
struct						s_trie
{
	struct trie				*children[ASCII_ABC];
	int						isleaf;
}							t_trie;

/*
**	Hash table.
*/
typedef struct				s_hitem
{
	char					*key;
	char					*value;
}							t_hitem;

typedef struct				s_htab
{
	int						size;
	int						count;
	t_hitem					**items;
}							t_htab;

/*
**	Double deque (double double-ended queue)
*/
typedef struct				s_ddeq
{
	t_dlist					*a;
	t_dlist					*b;
}							t_ddeq;

typedef long long int		t_lli;
typedef unsigned int		t_ui;

typedef struct				s_imaxdiv
{
	intmax_t				quot;
	intmax_t				rem;
}							t_imaxdiv;

typedef struct				s_uimaxdiv
{
	uintmax_t				quot;
	uintmax_t				rem;
}							t_uimaxdiv;

typedef struct				s_udiv
{
	uintmax_t				quot;
	uintmax_t				rem;
}							t_udiv;

/*
**	We have little endian machine (see ft_check_endiannes().
**	Next 3 typedefs are for extracting doubles and their parts.
** https://android.googlesource.com/platform/bionic/+/02c78a3/libc/\
**arch-arm/include/machine/ieee.h
*/
typedef struct				s_dbl80
{
	unsigned int			sgd_low:(sizeof(int) * BITS_AT_BYTE);
	unsigned int			sgd_high:(sizeof(int) * BITS_AT_BYTE);
	unsigned int			exp:(sizeof(short int) * BITS_AT_BYTE - 1);
	unsigned int			sign:1;
	unsigned int			forbidden_low:(sizeof(short int) * BITS_AT_BYTE);
	unsigned int			forbidden_high:(sizeof(int) * BITS_AT_BYTE);
}							t_dbl80;

typedef union				u_ldbl
{
	long double				var;
	t_dbl80					bit_field;
	char					char_ar[sizeof(long double)];
}							t_ldbl;

/*
**	State: NAN, IS_INF, IS_NRMLZD, IS_DNRMLZD
*/
typedef struct				s_ldbl_extraсt
{
	int						state;
	unsigned int			sign;
	int						exp_pow;
	uintmax_t				significand;
}							t_ldbl_extract;

/*
**					Arbitrary precision arithmetic types.
*/
typedef struct				s_bignum
{
	uintmax_t				digits[BIGNUM_SIZE];
	int						size;
}							t_bignum;

typedef union				u_print_ldbl
{
	long double				raw;
	char					ar[sizeof(long double)];
}							t_print_ldbl;

/*
**	Standart library functions protoripes used in the project.
** But some new functions after passing the project may use forbidden in the
** project functions, like read();
**	Here are the prototipes, of the functions:
**
** void			*malloc(size_t size);
** void			free(void *ptr);
** ssize_t		write(int fildes, const void *buf, size_t nbytes);
*/

/*
** Part 1.
*/
void						*ft_memset(void *dst, int c, size_t size);
void						ft_bzero(void *str, size_t size);
void						*ft_memcpy(void *dst, const void *src, size_t len);
void						*ft_memccpy(void *dst, const void *src, int c,
							size_t size);
void						*ft_memmove(void *dst, const void *src,
								size_t size);
void						*ft_memchr(const void *str, int c, size_t size);
int							ft_memcmp(const void *min, const void *sub,
								size_t size);
size_t						ft_strlen(const char *str);
char						*ft_strdup(const char *str);
char						*ft_strcpy(char *dst, const char *src);
char						*ft_strncpy(char *dst, const char *src,
								size_t maxlen);
char						*ft_strcat(char *dst, const char *src);
char						*ft_strncat(char *dst, const char *src,
								size_t size);
size_t						ft_strlcat(char *dst, const char *src, size_t size);
char						*ft_strchr(const char *src, int c);
char						*ft_strrchr(const char *src, int c);
char						*ft_strstr(const char *dst, const char *src);
char						*ft_strnstr(const char *dst, const char *src,
								size_t size);
int							ft_strcmp(const char *min, const char *sub);
int							ft_strncmp(const char *min, const char *sub,
								size_t len);
int							ft_atoi(const char *str);
int							ft_isalpha(int c);
int							ft_isdigit(int c);
int							ft_isalnum(int c);
int							ft_isascii(int c);
int							ft_isprint(int c);
int							ft_toupper(int c);
int							ft_tolower(int c);

/*
** Part 2.
*/
void						*ft_memalloc(size_t size);
void						ft_memdel(void **address_ptr);
char						*ft_strnew(size_t len);
void						ft_strdel(char **as);
void						ft_strclr(char *s);
void						ft_striter(char *str, void (*fptr)(char *));
void						ft_striteri(char *str, void (*fptr)(unsigned int,
								char *));
char						*ft_strmap(const char *str, char (*fptr)(char));
char						*ft_strmapi(const char *str,
								char (*fptr)(unsigned int,
								char));
int							ft_strequ(const char *min, const char *sub);
int							ft_strnequ(const char *min, const char *sub,
								size_t len);
char						*ft_strsub(const char *str, unsigned int start,
								size_t len);
char						*ft_strjoin(const char *s1, const char *s2);
char						*ft_strtrim(const char *src);
char						**ft_strsplit(const char *str, char c);
char						*ft_itoa(int nbr);
void						ft_putchar(char c);
void						ft_putstr(const char *str);
void						ft_putendl(const char *str);
void						ft_putnbr(int nbr);
void						ft_putchar_fd(char c, int fd);
void						ft_putstr_fd(const char *str, int fd);
void						ft_putendl_fd(const char *str, int fd);
void						ft_putnbr_fd(int nbr, int fd);

/*
** Bonus.
*/
t_list						*ft_lstnew(const void *content,
								size_t content_size);
void						ft_lstdelone(t_list **alst, void (*delptr)(void*,
								size_t));
void						ft_lstdel(t_list **alst,
								void (*delptr)(void*, size_t));
void						ft_lstadd(t_list **alst, t_list *new);
void						ft_lstiter(t_list *lst, void (*f)(t_list *node));
t_list						*ft_lstmap(t_list *lst, t_list *(*f)(t_list *node));

/*
** Expansion.
*/
int							ft_isspace(int c);
int							ft_isupper(int c);
int							ft_islower(int c);
size_t						ft_strnlen(const char *str, size_t maxlen);
int							ft_power(int base, int pow);
char						*ft_itostr(int nbr, char *str);
char						*ft_strchr_no(const char *str, int c);
char						*ft_strnchr(const char *str, int c, size_t size);
void						ft_strtoupper(char *str);
void						ft_strtolower(char *str);
void						*ft_realloc(void *buf1, size_t size1, size_t size2);
void						*ft_memjoin(void *buf1, size_t size1, void *buf2,
								size_t size2);
int							ft_imax(int x, int y);
int							ft_imin(int x, int y);
int							ft_isbinary(void *buf, size_t size);
void						ft_lstaddtip(t_list **head, t_list *new);
t_list						*ft_lstat(t_list *head, size_t nbr);
t_list						*ft_lstlast(t_list *head);
size_t						ft_lstsize(t_list *head);
void						ft_lstremove(t_list **head, t_list *node,
								int (*ft_lstcmp)(t_list *, void *));
int							ft_lstcmp_next(t_list *head, void *node);
void						ft_lstforeach_if(t_list	*node, void (*fptr)(void *),
								void *data_ref, int (*cmp)(void *, void *));
void						ft_lstforeach(t_list *node, void(*fptr)(void *));
void						ft_lstcontentdel(void *content,
								size_t content_size);
void						ft_lstrev(t_list **head);
t_list						*ft_lstfind(t_list *head, void *data_ref,
								int (*cmp)());
t_list						*ft_lstfind_prev(t_list *head, t_list *curr);
char						*ft_reverse(char *buffer, int i, int j);
char						*ft_strrev(char *str);
void						ft_swap(void *x, void *y, size_t size);
int							ft_set_nth_bit(int x, int n);
int							ft_unset_nth_bit(int x, int n);
int							ft_set_nth_bit(int x, int n);
int							ft_ispowerof2(int nbr);
size_t						ft_powerof2roundup(long long int nbr);
size_t						ft_powerof2rounddown(long long int nbr);
int							ft_abs(int nbr);
intmax_t					ft_imaxabs(intmax_t nbr);
char						*ft_delim(char **line, char *str, char c);
int							ft_fit_size(ssize_t *bank_size, ssize_t line_size,
								ssize_t step);
int							ft_error(int errno, int line, char *file);
void						*ft_error_ptr(int unused);
void						ft_div_mod(int devidend, int devider,
								int *div, int *mod);
void						ft_lldiv_mod(t_lli devidend, t_lli devider,
								t_lli *div, t_lli *mod);
t_imaxdiv					ft_imaxdiv(intmax_t numer, intmax_t denom);
t_uimaxdiv					ft_uimaxdiv(uintmax_t numer, uintmax_t denom);
t_udiv						ft_udiv_struc(unsigned int numer,
								unsigned int denom);
char						*ft_imaxtostr(char *str, uintmax_t nbr,
								unsigned int base, int issign);
char						*ft_uintmaxtostr(char *str, uintmax_t nbr,
								t_ui radix, int issign);
int							ft_isnan(long double ldbl);
int							ft_isinf(long double ldbl);
void						ft_print_bits(unsigned long long int nbr,
								int bits_nbr);
size_t						ft_wcslen(const wchar_t *str);
int							ft_wclen(wchar_t wc);
size_t						ft_wcsnlen(const wchar_t *str, size_t maxlen);
wchar_t						*ft_wcscpy(wchar_t *dst, const wchar_t *src);
wchar_t						*ft_wcsncpy(wchar_t *dst, const wchar_t *src,
								size_t maxlen);
wchar_t						*ft_wcsnew(size_t len);
wchar_t						*ft_wcsdup(const wchar_t *str);
void						ft_putwchar(wchar_t c);
void						ft_putwchar_fd(wchar_t c, int fd);
void						ft_putwcs(wchar_t const *wcs);
void						ft_putwcs_fd(wchar_t const *wcs, int fd);
void						ft_putnstr(char const *str, size_t len);
void						ft_putnstr_fd(char const *s, int fd, size_t len);
void						ft_putnwcs(wchar_t const *str, size_t len);
void						ft_putnwcs_fd(wchar_t const *wcs, int fd,
								size_t len);
int							ft_remove_sign_bit(unsigned char *nbr_ar, int size);
void						ft_quicksort(int *arr, int size);
int							ft_dlstsize(t_dlist *head);
t_dlist						*ft_dlstextract(t_dlist **head, t_dlist *node);
void						ft_dlstsort_bubble(t_dlist *head);
void						ft_dlstiter(t_dlist *top, void (*f)(t_dlist *elem));
t_dlist						*ft_dlstnew(void const *content,
								size_t content_size);
void						ft_dlstadd(t_dlist	**head, t_dlist *new);
void						ft_dlstaddtip(t_dlist **head, t_dlist *new);
void						ft_dlstdel(t_dlist **alst, void (*delptr)(void *,
								size_t));
void						ft_dlstcontentdel(void *content,
								size_t content_size);
void						ft_dlstforeach(t_dlist *node, void (*fptr)(void *));
void						ft_dlstswap(t_dlist *fst, t_dlist *snd);
t_dlist						*ft_dlstpop(t_dlist **head);
t_dlist						*ft_dlstpop_rear(t_dlist **head);
void						ft_dlstpush(t_dlist	**head, t_dlist *new);
void						ft_dlstpush_back(t_dlist **head, t_dlist *new);
t_dlist						*ft_dlstfind(t_dlist *head, void *data_ref,
								int (*cmp)(const void *min, const void *sub));
int							ft_dlstfind_i(t_dlist *head, void *data_ref,
								int (*cmp)(const void *min, const void *sub));
t_dlist						*ft_dlstfind_r(t_dlist *head, void *data_ref,
								int (*cmp)(const void *min, const void *sub));
int							ft_dlstfind_ir(t_dlist *head, void *data_ref,
								int (*cmp)(const void *min, const void *sub));
int							ft_dlstcmp(const void *node_l, const void *node_r);
t_dlist						*ft_dlstnew_ptr(void *content);
void						ft_dlstmerge(t_dlist **head_dst,
								t_dlist **head_src);
int							ft_memrcmp(const void *min, const void *sub,
								size_t size);
int							ft_intrcmp(const void *min, const void *sub);
int							ft_get_next_line(const int fd, char **line);
void						ft_free_ptr_ar(void ***ar);
int							ft_isdigitstr(char *str);
int							ft_strint_ou_flow(char *str, int *nbr);
int							ft_isdigitnstr(char *str, int n);
t_ddeq						*ft_ddeqnew(t_dlist *a);
t_dlist						*ft_ddeq_new_a(t_ddeq **ddeq,
								void *content, ssize_t content_size);
void						ft_ddeqdel(t_ddeq **ddeq,
							void (*delfunc)(void *, size_t));
void						ft_ddeqpush_b_all(t_ddeq *ddeq);
void						ft_ddeqpush_b(t_ddeq *ddeq);
void						ft_ddeqextract_b(t_ddeq *ddeq, t_dlist *from_a);
void						ft_ddeqreset_a(t_ddeq **hub, void *content);
void						ft_delfunc_dummy(void *who_cares,
								size_t never_mind);
t_keystr_avl_t				*ft_keystr_avl_create(t_pair *pair);
U_CHAR						ft_keystr_avl_height(t_keystr_avl_t *p);
int							ft_keystr_avl_bfactor(t_keystr_avl_t *p);
void						ft_keystr_avl_fix_height(t_keystr_avl_t *p);
t_keystr_avl_t				*ft_keystr_avl_rot_right(t_keystr_avl_t *p);
t_keystr_avl_t				*ft_keystr_avl_rot_left(t_keystr_avl_t *p);
t_keystr_avl_t				*ft_keystr_avl_balance(t_keystr_avl_t *p);
t_keystr_avl_t				*ft_keystr_avl_insert(t_keystr_avl_t *p,
								t_pair *pair);
t_keystr_avl_t				*ft_keystr_avl_search(t_keystr_avl_t *p, void *key);
t_keystr_avl_t				*ft_keystr_avl_findmin(t_keystr_avl_t *p);
t_keystr_avl_t				*ft_keystr_avl_remove(t_keystr_avl_t *p, void *key);
void						ft_keystr_avl_del(t_keystr_avl_t **root_input);

/*
** Forbidden in libft project
*/
ssize_t						ft_read_file(int fd, char **line, ssize_t step);

/*
** ft_lststrsplit.c ft_lsttoar.c ft_getfile.c, ft_itoa_base
*/

#endif

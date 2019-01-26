/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_global.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <omakovsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 15:59:00 by omakovsk          #+#    #+#             */
/*   Updated: 2018/08/25 15:59:00 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GLOBAL_H
# define FT_GLOBAL_H

# include "libft.h"
# include <fcntl.h>

# define MD5_OUTPUT_SIZE 16
# define SHA224_OUTPUT_SIZE 28
# define SHA256_OUTPUT_SIZE 32
# define SHA384_OUTPUT_SIZE 48
# define SHA512_OUTPUT_SIZE 64

# define USAGE_STRING "usage: ft_ssl command [command opts] [command args]\n"
# define STDIN ""
# define BUFFER_SIZE 512
# define UNKNOWN_FLAG 2
# define START_VALUE  0

typedef unsigned int	t_uint;
typedef unsigned char	t_uchar;
typedef unsigned long	t_ulong;

# define Q	1
# define R	2
# define S	4
# define P	8

typedef enum	e_error_type
{
	no_file = 0,
	no_flag,
	error_command,
	try_open_dir
}				t_error_type;

typedef enum	e_sha_type
{
	sha_224 = 0,
	sha_256,
	sha_384,
	sha_512
}				t_sha_type;

typedef enum	e_crypt_type
{
	base64_type = 0,
	des_type,
	unknown_type
}				t_crypt_type;


typedef void	(*t_hash_ptr)(char*, int* flags, char* filename);

typedef struct	s_hash_info
{
	t_hash_ptr	hashptr;
	int			flags;
}				t_hash_info;

typedef	struct 		s_crypt_flags
{
	uint8_t 		a;
	uint8_t 		d;
	uint8_t 		i;
	char 			*input_file;
	uint8_t 		k;
	unsigned char 	*key;
	uint8_t 		o;
	char			*output_file;
	uint8_t			p;
	char			*password;
	uint8_t			s;
	unsigned char	*salt;
	uint8_t			v;
	unsigned char	*in_vector;
}				t_crypt_flags;

typedef struct 	    s_crypt_info
{
	t_crypt_type	crypt_type;
	void (*cryptptr)(struct s_crypt_info *crypt_info);
	t_crypt_flags	flags;
    unsigned int	data_len;
}				    t_crypt_info;

typedef void	(*t_crypt_ptr)(t_crypt_info *crypt_info);
typedef int		(*t_add_flag_ptr)(char***, t_crypt_info*);

/*
** main hash functions
*/
void			md5(char *need_hash, int *flags, char *filename);
void			sha224(char *need_hash, int *flags, char *filename);
void			sha256(char *need_hash, int *flags, char *filename);
void			sha384(char *need_hash, int *flags, char *filename);
void			sha512(char *need_hash, int *flags, char *filename);

/*
** added crypt flags to struct
*/
int				add_a_flag(char ***argv, t_crypt_info *info);
int				add_d_flag(char ***argv, t_crypt_info *info);
int				add_e_flag(char ***argv, t_crypt_info *info);
int				add_i_flag(char ***argv, t_crypt_info *info);
int				add_k_flag(char ***argv, t_crypt_info *info);
int				add_o_flag(char ***argv, t_crypt_info *info);
int				add_p_flag(char ***argv, t_crypt_info *info);
int				add_s_flag(char ***argv, t_crypt_info *info);
int				add_v_flag(char ***argv, t_crypt_info *info);

char			*take_text_from_output(int fd);

/*
** print_error.c
*/
int				print_error(t_hash_ptr hash_type,\
						t_error_type error_type, char *filename);
int				printf_no_flag_error(t_hash_ptr hash_type);

extern const t_uint			g_sha_word[64];
extern const t_ulong		g_sha1_word[80];
extern char					*g_hash_name[6];
extern char					*g_crypt_name[5];
extern char 				*g_des_flag_name[10];
extern char 				*g_base_flag_name[5];
extern const t_add_flag_ptr g_add_flag_des_functions[10];
extern const t_add_flag_ptr g_add_flag_base_functions[5];
extern const t_hash_ptr 	g_hash_function[6];
extern const t_crypt_ptr 	g_crypt_function[5];

#endif

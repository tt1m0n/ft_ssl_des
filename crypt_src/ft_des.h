#ifndef DES_H
#define DES_H

#include "../global/ft_global.h"

#define DES_KEY_LEN 8
#define DES_IV_VECTOR_LEN 8

/*
** ft_des_operations.c
*/
void				des(t_crypt_info *crypt_info);
void				des_ecb(t_crypt_info *crypt_info);
void				des_cbc(t_crypt_info *crypt_info);
void				des_operations(t_crypt_info *crypt_info);

/*
** ft_des_validate_key.c
*/
unsigned char		*get_hex_string(char *argv, int len);
unsigned char		*des_rewrite(unsigned char *key);
int 				is_hex_string(unsigned char *str);
unsigned char		get_hex_val(unsigned char first, unsigned char second);
int					is_hex_char(char c);

/*
** ft_des_cbc.c
*/
void 				des_cbc_crypt(t_crypt_info *crypt_info);
void				des_cbc_message(t_crypt_info *crypt_info);
void				des_cbc_action(t_crypt_info *crypt_info,
									unsigned char *crypt);

/*
** ft_des_cbc_align_input.c
*/
void				des_align_input(unsigned char **crypt_text,
									t_crypt_info *crypt_info);
unsigned char		*append(unsigned char *crypt_text, unsigned char *padding,
						 	unsigned int data_len, unsigned int alignment);
unsigned char		*expand(unsigned char *crypt_text, unsigned char *padding,
							 unsigned int data_len, unsigned int alignment);

#endif

#ifndef DES_H
#define DES_H

#include "../global/ft_global.h"

#define DES_KEY_LEN 8
#define DES_IV_VECTOR_LEN 8

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

#endif

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
** ft_des.c
*/
void 				des_crypt(t_crypt_info *crypt_info);
void				des_message(t_crypt_info *crypt_info,
									unsigned char **text);
void				des_action(t_crypt_info *crypt_info,
									unsigned char *crypt);

/*
** ft_des_align_input.c
*/
void				des_align_input(unsigned char **crypt_text,
									t_crypt_info *crypt_info);
unsigned char		*append(unsigned char *crypt_text, unsigned char *padding,
						 	unsigned int data_len, unsigned int alignment);
unsigned char		*expand(unsigned char *crypt_text, unsigned char *padding,
							unsigned int data_len, unsigned int alignment);

/*
** ft_des_output.c
*/
void				des_cbc_result_output(t_crypt_info *crypt_info,
											unsigned char *result);
void    			write_des_to_file(unsigned char *result, t_crypt_info *crypt_info);

/*
** ft_des_key_operation.c
*/
unsigned char		*des_key_reduction(unsigned char *key, int it);
void				des_key_r_rotation(unsigned char *key, int num);
void				des_key_l_rotation(unsigned char *key, int num);
unsigned char		*des_get_subkey(unsigned char *key);


/*
** ft_des_block_operation.c
*/
unsigned char		*set_block(unsigned char *str,
							unsigned int i, unsigned int len);
void				data_copy(unsigned char *dst,
							unsigned char *src, unsigned int len);
void				data_xor(unsigned char *str,
						 	unsigned char *vector, unsigned int len);


/*
** ft_des_common_block_operation.c
*/
unsigned char		*des_common_block(unsigned char *block,
								   unsigned char *key, int d);
unsigned char		*create_same(unsigned char *block, unsigned int len);
void				swap_ptr(void **a, void **b);

/*
** ft_des_block_permutation.c
*/
unsigned char		set_init_byte(unsigned char *res, unsigned char pos);
void				des_init_permutation(unsigned char *eight);
unsigned char		set_final_byte(unsigned char *eight, unsigned int row);
void				des_final_permutation(unsigned char *eight);

/*
** ft_des_round.c
*/
void				des_round(unsigned char *left,
						unsigned char *right, unsigned char *subkey);
unsigned char		des_expansion(unsigned char fourth_byte);
unsigned char		*des_expansion_perm(unsigned char *right);
unsigned char		*des_pbox_perm(unsigned char *str);

/*
** ft_des_sbox.c
*/
unsigned char		des_sbox(unsigned char sixbits, unsigned char *box);
unsigned char		*des_sbox_sub(unsigned char *six);

/*
** ft_pad.c
*/
void				des_pad(t_crypt_info *crypt_info, unsigned int i,
								unsigned char *str, unsigned char **text);
void				handle_decode(t_crypt_info *crypt_info,
								unsigned int len, unsigned char *text);

/*
** ft_cbc_pre_post_block.c
*/
void				cbc_post_block(t_crypt_info *crypt_info, unsigned char *block,
								   unsigned int i, unsigned char *text);
void				cbc_pre_block(t_crypt_info *crypt_info, unsigned char *block);

static unsigned char	g_des_sbox_1[64] = {
		14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7,
		0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8,
		4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0,
		15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13 };
static unsigned char	g_des_sbox_2[64] = {
		15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10,
		3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5,
		0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15,
		13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9 };
static unsigned char	g_des_sbox_3[64] = {
		10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8,
		13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1,
		13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7,
		1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12 };
static unsigned char	g_des_sbox_4[64] = {
		7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15,
		13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9,
		10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4,
		3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14 };
static unsigned char	g_des_sbox_5[64] = {
		2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9,
		14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6,
		4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14,
		11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3 };
static unsigned char	g_des_sbox_6[64] = {
		12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11,
		10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8,
		9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6,
		4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13 };
static unsigned char	g_des_sbox_7[64] = {
		4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1,
		13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6,
		1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2,
		6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12 };
static unsigned char	g_des_sbox_8[64] = {
		13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7,
		1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2,
		7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8,
		2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11 };

static int				g_des_key_enc[16] = {
		1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};
static int				g_des_key_dec[16] = {
		0, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};

#endif

#ifndef BASE64_H
#define BASE64_H

#include "../global/ft_global.h"

# define KEY "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"


/*
** ft_base64_encrypt.c
*/

void			base64_encrypt(t_crypt_info *crypt_info);

/*
** ft_base64_encrypt_operations.c
*/

void            base64_encrypt_operations(unsigned char *crypt_text,
										  t_crypt_info *crypt_info);
unsigned char   *base64_encrypt_alghoritm(unsigned char *crypt_text,
										  unsigned int data_len);
void			three_to_four(unsigned char *str, char *key,
							  unsigned char *result, int num);

/*
** ft_base64_decrypt.c
*/

void			base64_decrypt(t_crypt_info *crypt_info);

/*
** ft_base64_decrypt_operations.c
*/

void			base64_decrypt_operations(unsigned char *decrypt_text,
											t_crypt_info *crypt_info);
unsigned char	*base64_decrypt_alghoritm(unsigned char *crypt_text,
										   unsigned int data_len);
void			base64_trim_decode(char *str);



/*
** ft_base64_operations.c
*/

void			base64(t_crypt_info *crypt_info);
void			base64_operations(t_crypt_info *crypt_info);



/*
** ft_base64_write_to_file.c
*/

void            base64_result_output(unsigned char *result,
                        t_crypt_info *crypt_info, unsigned int len);
void    		write_to_file(unsigned char *result, unsigned int len,
							char *filename, uint8_t is_decode);


#endif

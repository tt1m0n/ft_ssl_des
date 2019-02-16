/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base64.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 21:23:09 by omakovsk          #+#    #+#             */
/*   Updated: 2019/02/16 21:24:20 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BASE64_H
# define FT_BASE64_H

# include "ft_global.h"

# define KEY "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"

/*
** ft_base64_encrypt.c
*/
void			base64_encrypt(t_crypt_info *crypt_info);

/*
** ft_base64_encrypt_operations.c
*/

void			base64_encrypt_operations(unsigned char *crypt_text,
										t_crypt_info *crypt_info);
unsigned char	*base64_encrypt_alghoritm(unsigned char *crypt_text,
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
unsigned char	*base64_decrypt_alghoritm(unsigned char *crypt_text);
void			base64_trim_decode(char *str);
int				four_to_three(unsigned char *str,
						unsigned char *enc, char *key);
int				copy_over(unsigned char *c, unsigned char *e, unsigned char *s);

/*
** ft_base64_operations.c
*/
void			base64(t_crypt_info *crypt_info);
void			base64_operations(t_crypt_info *crypt_info);

/*
** ft_base64_write_to_file.c
*/
void			base64_result_output(unsigned char *result,
						t_crypt_info *crypt_info, unsigned int len);
void			write_to_file(unsigned char *result, unsigned int len,
						char *filename, uint8_t is_decode);

#endif

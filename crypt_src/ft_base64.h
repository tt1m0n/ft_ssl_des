#ifndef BASE64_H
#define BASE64_H

#include "../global/ft_global.h"

void	base64(t_crypt_info *crypt_info);
void	base64_encrypt(t_crypt_info *crypt_info);
void	base64_decrypt(t_crypt_info *crypt_info);
void	base64_operations(t_crypt_info *crypt_info);

char	*read_base64_crypt_text(t_crypt_info *crypt_info);

#endif

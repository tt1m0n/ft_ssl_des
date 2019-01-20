#include "ft_base64.h"
#include "ft_crypt_operations.h"

void			base64_encrypt(t_crypt_info *crypt_info)
{
	unsigned char *crypt_text;

	crypt_text = read_base64_crypt_text(crypt_info);
	if (!crypt_text)
		return ;
	base64_encrypt_operations(crypt_text, crypt_info);
}

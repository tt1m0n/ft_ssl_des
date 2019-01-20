#include "ft_base64.h"
#include "ft_crypt_operations.h"

void	base64_decrypt(t_crypt_info *crypt_info)
{
	unsigned char *decrypt_text;

	decrypt_text = read_base64_crypt_text(crypt_info);
	if (!decrypt_text)
		return ;
	base64_decrypt_operations(decrypt_text, crypt_info);
}



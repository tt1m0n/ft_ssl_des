#include "ft_base64.h"

void	base64_operations(t_crypt_info *crypt_info)
{
	crypt_info->cryptptr(crypt_info);
}

void	base64(t_crypt_info *crypt_info)
{
	if (crypt_info->flags.d)
		base64_decrypt(crypt_info);
	else
		base64_encrypt(crypt_info);
}


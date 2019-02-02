#include "ft_des.h"

void		des_operations(t_crypt_info *crypt_info)
{
	crypt_info->cryptptr(crypt_info);
}

void			des(t_crypt_info *crypt_info)
{
	des_crypt(crypt_info);
}

void			des_cbc(t_crypt_info *crypt_info)
{
	des_crypt(crypt_info);
}

void			des_ecb(t_crypt_info *crypt_info)
{
	des_crypt(crypt_info);

}


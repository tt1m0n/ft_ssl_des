#include "ft_des.h"
#include "ft_base64.h"
#include "ft_crypt_operations.h"

void			ft_print_show(t_crypt_info *crypt_info)
{
	if (crypt_info->flags.s)
	{
		ft_printf("salt=");
		ft_print_hex(crypt_info, crypt_info->flags.salt, 8);
	}
	if (crypt_info->flags.k && (crypt_info->cryptptr == des ||
		crypt_info->cryptptr == des_cbc || crypt_info->cryptptr == des_ecb))
	{
		ft_printf("key =");
		ft_print_hex(crypt_info, crypt_info->flags.key, 8);
	}
	else
	{
		ft_printf("key =");
		ft_print_hex(crypt_info, crypt_info->flags.key, 24);
	}
	if (crypt_info->flags.v &&
		crypt_info->cryptptr != des_ecb &&
		crypt_info->cryptptr != des3_ecb)
	{
		ft_printf("iv  =");
		ft_print_hex(crypt_info, crypt_info->flags.in_vector, 8);
	}
}

void			ft_print_hex(t_crypt_info *crypt_info,
								unsigned char *str, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		ft_printf("%02X", (int)str[i++]);
	}
	ft_printf("\n");
}

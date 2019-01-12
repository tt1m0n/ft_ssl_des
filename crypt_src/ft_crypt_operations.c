#include "../global/ft_global.h"
#include "ft_base64.h"
#include "ft_des.h"
#include "ft_print_functions.h"
#include "ft_flags_operations.h"

void		crypt_info_operations(char **argv, t_crypt_info *crypt_info)
{
	zero_crypt_flags(&crypt_info->flags);
	if (!is_parse_crypt_flags(argv, &crypt_info->flags))
		return ;
	if (!crypt_info->cryptptr)
		base64_operations(crypt_info);
	else
		des_operations(crypt_info);
}

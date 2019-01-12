#ifndef FLAGS_OPERATIONS_H
#define FLAGS_OPERATIONS_H

#include "../global/ft_global.h"

void		zero_crypt_flags(t_crypt_flags *flags);
int 		add_flag_to_struct(char	***argv, t_crypt_flags *flags);
int			is_parse_crypt_flags(char **argv, t_crypt_flags *flags);

#endif
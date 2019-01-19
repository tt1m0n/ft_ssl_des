#ifndef FLAGS_OPERATIONS_H
#define FLAGS_OPERATIONS_H

#include "../global/ft_global.h"

void		zero_crypt_flags(t_crypt_flags *flags);
int 		add_flag_to_base_struct(char ***argv, t_crypt_info *info);
int 		add_flag_to_des_struct(char	***argv, t_crypt_info *info);
int			is_parse_crypt_flags(char **argv, t_crypt_info *info);

#endif
#ifndef DES_H
#define DES_H

#include "../global/ft_global.h"

void		des(t_crypt_info *crypt_info);
void		des_ecb(t_crypt_info *crypt_info);
void		des_cbc(t_crypt_info *crypt_info);
void		des_operations(t_crypt_info *crypt_info);

#endif

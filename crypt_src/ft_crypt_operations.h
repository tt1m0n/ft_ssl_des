#ifndef CRYPT_OPERATIONS_H
#define CRYPT_OPERATIONS_H

#include "../global/ft_global.h"

int 			print_crypt_flags_usage(char *argument, t_crypt_type crypt_type);
void			crypt_info_operations(char **argv, t_crypt_info *crypt_info);
int 			print_base64_flags_usage(char *argument);
int 			print_des_flags_usage(char *argument);
unsigned char	*take_crypt_text_from_output(int fd, t_crypt_info *crypt_info);
unsigned char	*ft_strjoin_unsigned(const unsigned char *s1,
									 const unsigned char *s2);
size_t			ft_strlen_unsigned(const unsigned char *s);
unsigned char	*read_base64_crypt_text(t_crypt_info *crypt_info);
int				ft_isspace(int c);


#endif

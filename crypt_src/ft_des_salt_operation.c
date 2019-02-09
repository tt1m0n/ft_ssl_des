#include "ft_des.h"

void	get_random_salt(t_crypt_info *crypt_info)
{
	int 	fd;
	char 	salt[9];

	ft_bzero(salt, 9);
	fd = open("/dev/urandom", O_RDONLY);
	if (fd == -1)
		ft_printf("error to open random /dev/urandom file\n");
	read(fd, salt, 8);
	crypt_info->flags.salt = ft_memalloc(9);
	ft_memcpy(crypt_info->flags.salt, salt, 8);
}

void		salt_password(t_crypt_info *crypt_info)
{
	char	*ptr_to_free;
	size_t	old_pass_len;

	old_pass_len = ft_strlen(crypt_info->flags.password);
	crypt_info->flags.pass_len = ft_strlen(crypt_info->flags.password);
	ptr_to_free = crypt_info->flags.password;
	crypt_info->flags.password = ft_memalloc(old_pass_len + 8 + 1);
	ft_memcpy(crypt_info->flags.password, ptr_to_free, old_pass_len);
	ft_memcpy(&crypt_info->flags.password[old_pass_len], crypt_info->flags.salt, 8);
	crypt_info->flags.pass_len += 8;
	if (!crypt_info->flags.p)
		free(ptr_to_free);
}
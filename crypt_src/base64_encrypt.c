#include "ft_base64.h"

void	base64_encrypt(t_crypt_info *crypt_info)
{
	char *crypt_text;

	crypt_text = NULL;
	crypt_text = read_base64_crypt_text(crypt_info);
	if (!crypt_text)
		return ;

}

char	*read_base64_crypt_text(t_crypt_info *crypt_info)
{
	int fd;

	fd = 0;
	if (crypt_info->flags.input_file)
		fd = open(crypt_info->flags.input_file, O_RDONLY);
	if (fd == -1)
		ft_printf("%s: Noo such file or directory\n",
				crypt_info->flags.input_file);

	return NULL;
}


//int		read_hash_info(t_hash_info *hash_info, char *info, int file)
//{
//	int		fd;
//	char	*need_to_hash;
//
//	fd = START_VALUE;
//	need_to_hash = NULL;
//	if (info[0] != 0 && file)
//		fd = open(info, O_RDONLY);
//	if (fd == -1)
//		return (print_error(hash_info->hashptr, no_file, info));
//	if (read(fd, NULL, 0) == -1)
//		return (print_error(hash_info->hashptr, try_open_dir, info));
//	if (file)
//		need_to_hash = take_text_from_output(fd);
//	else
//		need_to_hash = info;
//	if (hash_info->flags >= P)
//	{
//		ft_printf("%s", need_to_hash);
//		hash_info->flags &= (Q | R | S);
//	}
//	hash_info->hashptr(need_to_hash, &hash_info->flags, info);
//	if (fd != 0)
//		free(need_to_hash);
//	return (1);
//}

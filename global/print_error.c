#include "../hash_src/ft_parse_and_read.h"

int			print_error(t_hash_ptr hash_type,\
						t_error_type error_type, char *filename)
{
	if (error_type == no_flag)
		return (printf_no_flag_error(hash_type));
	if (hash_type == md5)
		ft_printf("md5: ");
	if (hash_type == sha224)
		ft_printf("sha224: ");
	if (hash_type == sha256)
		ft_printf("sha256: ");
	if (hash_type == sha384)
		ft_printf("sha384: ");
	if (hash_type == sha512)
		ft_printf("sha512: ");
	if (error_type == no_file)
		ft_printf("%s: No such file or directory\n", filename);
	if (error_type == try_open_dir)
		ft_printf("%s: Is a directory\n", filename);
	if (error_type == error_command)
	{
		ft_printf("Message Digest commands:\n");
		ft_printf("md5\nsha224\nsha256\nsha384\nsha512\n\n");
		ft_printf("Cipher commands:\nbase64\ndes\ndes-ecb\ndes-cbc\n");
		ft_printf("des3\ndes3-ecb\ndes3-cbc\n\n");
	}
	return (1);
}

int			printf_no_flag_error(t_hash_ptr hash_type)
{
	ft_printf("usage: ");
	if (hash_type == md5)
		ft_printf("md5 ");
	if (hash_type == sha224)
		ft_printf("sha224 ");
	if (hash_type == sha256)
		ft_printf("sha256 ");
	if (hash_type == sha384)
		ft_printf("sha384 ");
	if (hash_type == sha512)
		ft_printf("sha512 ");
	ft_printf("[-pqrtx] [-s string] [files ...]\n");
	return (1);
}
#include "ft_base64.h"
#include "ft_crypt_operations.h"

void			base64_encrypt(t_crypt_info *crypt_info)
{
	unsigned char *crypt_text;

	crypt_text = read_base64_crypt_text(crypt_info);
	if (!crypt_text)
		return ;
}

unsigned char	*read_base64_crypt_text(t_crypt_info *crypt_info)
{
	int fd;

	fd = 0;
	if (crypt_info->flags.input_file)
		fd = open(crypt_info->flags.input_file, O_RDONLY);
	if (fd == -1)
		ft_printf("%s: Noo such file or directory\n",
				crypt_info->flags.input_file);
	if (read(fd, NULL, 0) == -1)
		ft_printf("%s: Is a directory\n", crypt_info->flags.input_file);
	return take_crypt_text_from_output(fd);
}


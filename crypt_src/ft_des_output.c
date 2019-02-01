#include "ft_des.h"

void		des_cbc_result_output(t_crypt_info *crypt_info,
								unsigned char *result)
{
	unsigned int i;

	i = 1;
	if (result)
	{
		if (crypt_info->flags.output_file)
			write_des_to_file(result, crypt_info->data_len,
					crypt_info->flags.output_file, crypt_info->flags.d);
		else
		{
			write(1, result, crypt_info->data_len);
			if (crypt_info->flags.a && !crypt_info->flags.d)
				write(1, "\n", 1);
		}
	}
}

void    write_des_to_file(unsigned char *result, size_t length,
					  char *filename, uint8_t is_decode)
{
	int				fd;
	unsigned int

			i = 1;
	fd = open(filename, O_WRONLY | O_CREAT, 0644);
	if (fd == -1)
		ft_printf("unable to open file %s\n", filename);
	if (write(fd, result, length) == -1)
	{
		ft_printf("unable to write to file %s\n", filename);
		return ;
	}
	if (!is_decode && write(fd, "\n", 1) == -1)
		ft_printf("unable to write to file %s\n", filename);
}

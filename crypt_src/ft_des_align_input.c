#include "ft_des.h"
#include "ft_crypt_operations.h"

void			des_align_input(unsigned char **crypt_text, t_crypt_info *crypt_info)
{
	unsigned char	*padding;
	unsigned int	alignment;
	unsigned int	i;

	if (crypt_info->flags.d)
		return;

	alignment = 8 - (crypt_info->data_len % 8);
	padding = (unsigned char *)ft_strnew(alignment);
	i = 0;
	while (i < alignment)
		padding[i++] = alignment;
	*crypt_text = append(*crypt_text, padding, crypt_info->data_len, alignment);
	crypt_info->data_len += alignment;
}

unsigned char	*append(unsigned char *crypt_text, unsigned char *padding,
						 unsigned int data_len, unsigned int alignment)
{
	unsigned char	*final;

	final = expand(crypt_text, padding, data_len, alignment);
	free(padding);
	return (final);
}

unsigned char	*expand(unsigned char *crypt_text, unsigned char *padding,
						 unsigned int data_len, unsigned int alignment)
{
	unsigned char	*final;
	unsigned int	i;

	final = (unsigned char *)ft_strnew(data_len + alignment);
	i = 0;
	while (i < data_len)
	{
		final[i] = crypt_text[i];
		i++;
	}
	i = 0;
	while (i < alignment)
	{
		final[i + data_len] = padding[i];
		i++;
	}
	free(crypt_text);
	return (final);
}


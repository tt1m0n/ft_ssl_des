#include "ft_base64.h"
#include "ft_crypt_operations.h"

void			base64_decrypt_operations(unsigned char *decrypt_text,
										  t_crypt_info *crypt_info)
{
	unsigned char *result;

	result = base64_decrypt_alghoritm(decrypt_text, crypt_info->data_len);
	base64_result_output(result, crypt_info, ft_strlen((char*)result));
	if (result)
		free(result);
}


unsigned char	*base64_decrypt_alghoritm(unsigned char *decrypt_text,
										   unsigned int data_len)
{
	unsigned int	oldlen;
	unsigned int	i;
	unsigned char	*result;
	unsigned int	result_len;
	int				ret;

	base64_trim_decode((char *)decrypt_text);
	result_len = (ft_strlen((char*)decrypt_text) / 4) * 3;
	result = (unsigned char *)ft_strnew(result_len);
	if (!result)
		return (NULL);
	i = 0;
	while (i < result_len)
	{
		ret = four_to_three(&(result[i]), decrypt_text, result_len);
		if (ret == -1)
		{
			free(result);
			return (NULL);
		}
		i += 3;
		decrypt_text += 4;
	}
	result_len -= ret;
	return (result);
}

void			base64_trim_decode(char *str)
{
	unsigned int	start;
	unsigned int	end;

	start = 0;
	end = 0;
	while (str[end])
	{
		if (!ft_isspace(str[end]))
		{
			str[start] = str[end];
			start++;
		}
		end++;
	}
}

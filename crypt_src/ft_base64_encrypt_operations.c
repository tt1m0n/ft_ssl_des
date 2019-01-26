#include "ft_base64.h"

void            base64_encrypt_operations(unsigned char *crypt_text,
                                          t_crypt_info *crypt_info)
{
    unsigned char *result;

    result = base64_encrypt_alghoritm(crypt_text, crypt_info->data_len);
    if (result)
    {
		base64_result_output(result, crypt_info, ft_strlen((char *) result));
		free(result);
	}
}

unsigned char 	*base64_encrypt_alghoritm(unsigned char *crypt_text,
                                           unsigned int data_len)
{
    unsigned int	base_it;
    unsigned int	result_it;
    unsigned int	result_len;
    unsigned char	*result;

    base_it = 0;
    result_it = 0;
    result_len = (((data_len + 2) / 3) * 4);
    result = (unsigned char *)ft_strnew(result_len);
    if (!result)
        return (NULL);
    while (result_it < result_len)
    {
        three_to_four(&(crypt_text[base_it]),
                      KEY,
                      &(result[result_it]),
                      data_len - base_it);
        result_it += 4;
        base_it += 3;
    }
    return (result);
}

void			three_to_four(unsigned char *str, char *key,
                              unsigned char *result, int num)
{
    int		i;
    int		done;

    i = 0;
    done = 0;
    result[0] = key[(str[i++] & 252) >> 2];
    num--;
    result[1] = key[((str[i - 1] & 3) << 4) | (str[i] >> 4)];
    if (!num)
        done = 1;
    if (num)
    {
        i++;
        num--;
    }
    result[2] = done ? '=' : key[((str[i] & 192) >> 6) | ((str[i - 1] & 15) << 2)];
    if (!num)
        done = 1;
    result[3] = done ? '=' : key[str[i] & 63];
}

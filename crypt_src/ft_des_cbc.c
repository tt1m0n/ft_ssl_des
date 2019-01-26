#include "ft_des.h"
#include "ft_base64.h"
#include "ft_crypt_operations.h"

void	des_cbc_crypt(t_crypt_info *crypt_info)
{
	unsigned char	*temp;
	unsigned char	*crypt;

	if (crypt_info->flags.k && !crypt_info->flags.v)
	{
		ft_printf("iv undefined\n");
		return;
	}
	get_cbc_encrypt_password(crypt_info);
	if (!crypt_info->flags.password)
		return;
	crypt = read_crypt_text(crypt_info);
	if (crypt && crypt_info->flags.d && crypt_info->flags.a)
	{
		temp = base64_decrypt_alghoritm(crypt, ft_strlen_unsigned(crypt));
		free(crypt);
		crypt = temp;
	}
	if (!crypt)
		return;
	des_align_input(&crypt, crypt_info);
	if (!crypt_info->flags.d || ((crypt_info->crypt_type % 8) == 0))
		des_cbc_action(crypt_info, crypt);
	else
		ft_printf("Message not multiple of block length\n");
}

void	des_cbc_action(t_crypt_info *crypt_info, unsigned char *crypt_text)
{
	unsigned char	*temp;

	des_cbc_message(crypt_info);
	if (crypt_info->flags.a && !crypt_info->flags.d)
	{
		temp = base64_encrypt_alghoritm(crypt_text, crypt_info->data_len);
		free(crypt_text);
		crypt_text = temp;
		crypt_info->data_len = (unsigned)ft_strlen_unsigned(crypt_text);
	}
	des_cbc_result_output(crypt_info, crypt_text);
	if (crypt_text)
		free(crypt_text);
}

void			des_cbc_message(t_crypt_info *crypt_info)
{

}

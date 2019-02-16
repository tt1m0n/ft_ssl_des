#include "../global/ft_global.h"
#include "ft_crypt_operations.h"

int 		print_crypt_flags_usage(char *argument, t_crypt_type crypt_type)
{
	if (crypt_type == base64_type)
		return print_base64_flags_usage(argument);
	else
		return print_des_flags_usage(argument);

}

int 		print_des_flags_usage(char *argument)
{
	if (argument)
		ft_printf("unknown options \'%s\'\n\n", argument);
	ft_printf("-a    decode/encode the input/output in base64,\""
			  "depending on the encrypt mode\n");
	ft_printf("-d    decrypt mode\n");
	ft_printf("-e    encrypt mode\n");
	ft_printf("-i    input file for message is the next argument\n");
	ft_printf("-k    key in hex is the next argument\n");
	ft_printf("-o    output file for message is the next argument\n");
	ft_printf("-p    password in ascii is the next argument\n");
	ft_printf("-s    salt in hex is the next argument\n");
	ft_printf("-v    initialization vector in hex is the next argument\n");
	ft_printf("-show print key, salt, iv values\n\n");

	return (0);
}

int 		print_base64_flags_usage(char *argument)
{
	if (argument)
		ft_printf("unknown options \'%s\'\n\n", argument);
	ft_printf("-a    decode/encode the input/output in base64,\""
			  "depending on the encrypt mode\n");
	ft_printf("-d    decrypt mode\n");
	ft_printf("-e    encrypt mode\n");
	ft_printf("-i    input file for message is the next argument\n\n");

	return (0);
}

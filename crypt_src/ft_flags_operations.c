#include "ft_flags_operations.h"
#include "ft_crypt_operations.h"
#include "ft_base64.h"
#include "ft_des.h"

void		zero_crypt_flags(t_crypt_flags *flags)
{
	flags->a = 0;
	flags->d = 0;
	flags->input_file = NULL;
	flags->key = NULL;
	flags->output_file = NULL;
	flags->password = NULL;
	flags->salt = NULL;
	flags->in_vector = NULL;
}

int 		add_flag_to_base_struct(char ***argv, t_crypt_info *info)
{
	int i;

	i = START_VALUE;
	while (g_add_flag_base_functions[i] != 0)
	{
		if (ft_strcmp(g_base_flag_name[i], **argv) == 0)
		{
			return g_add_flag_base_functions[i](argv, &info->flags);
		}
		i++;
	}
	print_crypt_flags_usage(**argv, info->crypt_type);
	return (0);
}

int 		add_flag_to_des_struct(char	***argv, t_crypt_info *info)
{
	int i;

	i = START_VALUE;
	while (g_add_flag_des_functions[i] != 0)
	{
		if (ft_strcmp(g_des_flag_name[i], **argv) == 0)
		{
			return g_add_flag_des_functions[i](argv, &info->flags);
		}
		i++;
	}
	print_crypt_flags_usage(**argv, info->crypt_type);
	return (0);
}

int			is_parse_crypt_flags(char **argv, t_crypt_info *info)
{
	int (*func_ptr)(char ***argv, t_crypt_info *info);

	if (!*argv)
		return 1;
	if (info->cryptptr == base64)
		func_ptr = add_flag_to_base_struct;
	else
		func_ptr = add_flag_to_des_struct;
	if (*argv[0] != '-')
		print_crypt_flags_usage(*argv, info->crypt_type);
	while (*argv)
	{
		if (!func_ptr(&argv, info))
			return (0);
		argv++;
	}
	return (1);
}


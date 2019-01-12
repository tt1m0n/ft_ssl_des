#include "ft_flags_operations.h"
#include "ft_print_functions.h"

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

int 		add_flag_to_struct(char	***argv, t_crypt_flags *flags)
{
	int i;

	i = START_VALUE;
	while (g_add_flag_functions[i] != 0)
	{
		if (ft_strcmp(g_flag_name[i], **argv) == 0)
		{
			g_add_flag_functions[i](argv, flags);
			return (1);
		}
		i++;
	}
	print_crypt_flags_usage(**argv);
	return (0);
}

int			is_parse_crypt_flags(char **argv, t_crypt_flags *flags)
{
	if (!*argv)
		return 1;
	if (*argv[0] != '-')
		print_crypt_flags_usage(*argv);
	while (*argv)
	{
		if (!add_flag_to_struct(&argv, flags))
			return (0);
		argv++;
	}
	return (1);
}


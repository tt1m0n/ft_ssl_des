#include "../global/ft_global.h"
#include "ft_print_functions.h"

int		add_a_flag(char ***argv, t_crypt_flags *flags)
{
	(void)argv;
	flags->a = 1;
	return (1);
}

int		add_d_flag(char ***argv, t_crypt_flags *flags)
{
	(void)argv;
	flags->d = 1;
	return (1);
}

int		add_e_flag(char ***argv, t_crypt_flags *flags)
{
	(void)argv;
	flags->d = 0;
	return (1);
}

int		add_i_flag(char ***argv, t_crypt_flags *flags)
{
	flags->i = 1;
	(*argv)++;
	flags->input_file = **argv;
	if (!flags->input_file)
	{
		ft_printf("missing file argument for -i\n\n");
		print_crypt_flags_usage(NULL);
		return (0);
	}
	return (1);
}

int		add_k_flag(char ***argv, t_crypt_flags *flags)
{
	flags->k = 1;
	(*argv)++;
	flags->key = **argv;
	if (!flags->key)
	{
		ft_printf("missing key argument for -k\n\n");
		print_crypt_flags_usage(NULL);
		return (0);
	}
	return (1);
}
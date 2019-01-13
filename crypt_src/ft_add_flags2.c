#include "../global/ft_global.h"
#include "ft_print_functions.h"

int		add_o_flag(char ***argv, t_crypt_flags *flags)
{
	flags->o = 1;
	(*argv)++;
	flags->output_file = **argv;
	if (!flags->output_file)
	{
		ft_printf("missing file argument for -o\n\n");
		print_crypt_flags_usage(NULL);
		return (0);
	}
	return (1);
}

int		add_p_flag(char ***argv, t_crypt_flags *flags)
{
	flags->p = 1;
	(*argv)++;
	flags->password = **argv;
	if (!flags->password)
	{
		ft_printf("missing source argument for -p\n\n");
		print_crypt_flags_usage(NULL);
		return (0);
	}
	return (1);
}

int		add_s_flag(char ***argv, t_crypt_flags *flags)
{
	flags->s = 1;
	(*argv)++;
	flags->salt = **argv;
	if (!flags->salt)
	{
		ft_printf("missing salt argument for -s\n\n");
		print_crypt_flags_usage(NULL);
		return (0);
	}
	return (1);
}

int		add_v_flag(char ***argv, t_crypt_flags *flags)
{
	flags->v = 1;
	(*argv)++;
	flags->in_vector = **argv;
	if (!flags->in_vector)
	{
		ft_printf("missing IV argument for -v\n\n");
		print_crypt_flags_usage(NULL);
		return (0);
	}
	return (1);
}
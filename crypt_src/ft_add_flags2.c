#include "../global/ft_global.h"

void	add_o_flag(char ***argv, t_crypt_flags *flags)
{
	(**argv)++;
	flags->output_file = **argv;
}

void	add_p_flag(char ***argv, t_crypt_flags *flags)
{
	(**argv)++;
	flags->password = **argv;
}

void	add_s_flag(char ***argv, t_crypt_flags *flags)
{
	(**argv)++;
	flags->salt = **argv;
}

void	add_v_flag(char ***argv, t_crypt_flags *flags)
{
	(**argv)++;
	flags->in_vector = **argv;
}
#include "../global/ft_global.h"

void	add_a_flag(char ***argv, t_crypt_flags *flags)
{
	(void)argv;
	flags->a = 1;
}

void	add_d_flag(char ***argv, t_crypt_flags *flags)
{
	(void)argv;
	flags->d = 1;
}

void	add_e_flag(char ***argv, t_crypt_flags *flags)
{
	(void)argv;
	flags->d = 0;
}

void	add_i_flag(char ***argv, t_crypt_flags *flags)
{
	(**argv)++;
	flags->input_file = **argv;
}

void	add_k_flag(char ***argv, t_crypt_flags *flags) {
	(**argv)++;
	flags->key = **argv;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlogin <xlogin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 17:55:00 by xlogin            #+#    #+#             */
/*   Updated: 2018/09/01 17:55:00 by xlogin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_global.h"
#include "ft_parse_and_read.h"

void	common_hash_parse(int *flags, char *need_hash, char *filename)
{
	if (*flags == (S | R))
		ft_printf(" \"%s\"", need_hash);
	if (*flags == R)
		ft_printf(" %s", filename);
	ft_printf("\n");
	if (*flags > (Q | R))
		*flags &= (Q | R);
}

int		parse_helpers_for_s(t_hash_info *hash_info, char ***argv)
{
	if (*(*argv + 1) == NULL)
		return (UNKNOWN_FLAG);
	else
	{
		(*argv)++;
		hash_info->flags |= S;
		return (read_hash_info(hash_info, **argv, 0));
	}
}

int		parse_flags(t_hash_info *hash_info, char ***argv)
{
	if (ft_strcmp(**argv, "-s") == 0)
		return (parse_helpers_for_s(hash_info, argv));
	else if (ft_strcmp(**argv, "-p") == 0)
	{
		hash_info->flags |= P;
		return (read_hash_info(hash_info, STDIN, 1));
	}
	else if (ft_strcmp(**argv, "-q") == 0)
	{
		if (*(*argv + 1) == NULL)
			read_hash_info(hash_info, STDIN, 1);
		hash_info->flags |= Q;
	}
	else if (ft_strcmp(**argv, "-r") == 0)
	{
		if (*(*argv + 1) == NULL)
			read_hash_info(hash_info, STDIN, 1);
		hash_info->flags |= R;
	}
	else
		return (UNKNOWN_FLAG);
	return (1);
}

int		read_hash_info(t_hash_info *hash_info, char *info, int file)
{
	int		fd;
	char	*need_to_hash;

	fd = START_VALUE;
	need_to_hash = NULL;
	if (info[0] != 0 && file)
		fd = open(info, O_RDONLY);
	if (fd == -1)
		return (print_error(hash_info->hashptr, no_file, info));
	if (read(fd, NULL, 0) == -1)
		return (print_error(hash_info->hashptr, try_open_dir, info));
	if (file)
		need_to_hash = take_text_from_file(fd);
	else
		need_to_hash = info;
	if (hash_info->flags >= P)
	{
		ft_printf("%s", need_to_hash);
		hash_info->flags &= (Q | R | S);
	}
	hash_info->hashptr(need_to_hash, &hash_info->flags, info);
	if (fd != 0)
		free(need_to_hash);
	return (1);
}

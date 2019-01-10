/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_and_read.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlogin <xlogin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 17:55:00 by xlogin            #+#    #+#             */
/*   Updated: 2018/09/01 17:55:00 by xlogin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSE_AND_READ_H
# define FT_PARSE_AND_READ_H

# include "ft_global.h"

/*
** parse
*/
void	common_hash_parse(int *flags, char *need_hash, char *filename);
int		parse_helpers_for_s(t_hash_info *hash_info, char ***argv);
int		parse_flags(t_hash_info *hash_info, char ***argv);

/*
** read
*/
int		read_hash_info(t_hash_info *hash_info, char *info, int file);
char	*take_text_from_file(int fd);
int		print_error(t_hash_ptr hash_type,\
		t_error_type error_type, char *filename);

#endif

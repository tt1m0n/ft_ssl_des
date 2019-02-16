/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_operations.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 18:56:40 by omakovsk          #+#    #+#             */
/*   Updated: 2019/02/16 18:56:42 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FLAGS_OPERATIONS_H
# define FT_FLAGS_OPERATIONS_H

# include "ft_global.h"

void		zero_crypt_flags(t_crypt_flags *flags);
int			add_flag_to_base_struct(char ***argv, t_crypt_info *info);
int			add_flag_to_des_struct(char	***argv, t_crypt_info *info);
int			is_parse_crypt_flags(char **argv, t_crypt_info *info);

#endif

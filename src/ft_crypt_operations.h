/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_crypt_operations.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 18:53:43 by omakovsk          #+#    #+#             */
/*   Updated: 2019/02/16 18:53:44 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CRYPT_OPERATIONS_H
# define FT_CRYPT_OPERATIONS_H

# include "../global/ft_global.h"

int				print_crypt_flags_usage(char *argument,
									t_crypt_type crypt_type);
int				print_base64_flags_usage(char *argument);
int				print_des_flags_usage(char *argument);
unsigned char	*take_crypt_text_from_output(int fd, t_crypt_info *crypt_info);

/*
** ft_crypt_operations.c
*/
void			crypt_info_operations(char **argv, t_crypt_info *crypt_info);
unsigned char	*read_crypt_text(t_crypt_info *crypt_info);
int				ft_isspace(int c);
void			get_crypt_password(t_crypt_info *crypt_info);
void			get_crypt_key(t_crypt_info *crypt_info);

#endif

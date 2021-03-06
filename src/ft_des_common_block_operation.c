/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_des_common_block_operation.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 18:54:54 by omakovsk          #+#    #+#             */
/*   Updated: 2019/02/16 18:54:56 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_des.h"

unsigned char	*des_common_block(unsigned char *block,
									unsigned char *key, int d)
{
	unsigned int	i;
	unsigned char	*subkey;
	unsigned char	*left;
	unsigned char	*right;

	des_init_permutation(block);
	left = create_same(block, 4);
	right = create_same(&(block[4]), 4);
	i = 0;
	while (i < 16)
	{
		if (d)
			des_key_r_rotation(key, g_des_key_dec[i]);
		else
			des_key_l_rotation(key, g_des_key_enc[i]);
		subkey = des_get_subkey(key);
		des_round(left, right, subkey);
		free(subkey);
		swap_ptr((void**)&left, (void**)&right);
		i++;
	}
	free(block);
	block = append(right, left, 4, 4);
	des_final_permutation(block);
	return (block);
}

unsigned char	*create_same(unsigned char *block, unsigned int len)
{
	unsigned char	*new;
	unsigned int	i;

	new = (unsigned char *)ft_strnew(len);
	i = 0;
	while (i < len)
	{
		new[i] = block[i];
		i++;
	}
	return (new);
}

void			swap_ptr(void **a, void **b)
{
	void	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

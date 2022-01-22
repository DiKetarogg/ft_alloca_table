/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloca.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzoltan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 09:37:07 by jzoltan           #+#    #+#             */
/*   Updated: 2022/01/22 09:37:12 by jzoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_alloca.h"

void	*ft_alloca_internal(unsigned int end_block_id, unsigned int consecutive)
{
	unsigned int *const	blocks = ft_alloca_blocks();
	unsigned int		id;
	void				*block;

	id = end_block_id - consecutive;
	block = &(ft_alloca_raw_memory()[id * ALLOCA_STEP]);
	while (consecutive)
	{
		blocks[id] = consecutive;
		--consecutive;
		++id;
	}
	return (block);
}

void	*ft_alloca(size_t size)
{
	unsigned int *const		blocks = ft_alloca_blocks();
	size_t					it;
	size_t					consecutive;
	size_t					size_found;

	it = 0;
	size_found = 0;
	consecutive = 0;
	while (42)
	{
		while (it != ALLOCA_BLOCKS && blocks[it])
			++it;
		if (it == ALLOCA_BLOCKS)
			return (0);
		size_found += ALLOCA_STEP;
		++consecutive;
		if (size_found >= size)
			return (ft_alloca_internal(it + 1, consecutive));
		if (++it != ALLOCA_SIZE && blocks[it])
		{
			size_found = 0;
			consecutive = 0;
		}
	}
}

void	ft_alloca_free(void *block)
{
	unsigned int		block_id;
	unsigned int		consecutive;
	unsigned int *const	blocks = ft_alloca_blocks();

	if (!block)
		return ;
	block_id = ((size_t)block - (size_t)ft_alloca_raw_memory()) / ALLOCA_STEP;
	consecutive = ft_alloca_blocks()[block_id];
	while (consecutive)
	{
		blocks[block_id] = 0;
		--consecutive;
	}
}

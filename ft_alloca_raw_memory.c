/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloca_raw_memory.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzoltan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 09:37:36 by jzoltan           #+#    #+#             */
/*   Updated: 2022/01/22 09:37:37 by jzoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_alloca.h"

char	*ft_alloca_raw_memory(void)
{
	static char	memory[ALLOCA_SIZE];

	return (memory);
}

unsigned int	*ft_alloca_blocks(void)
{
	static unsigned int	blocks[ALLOCA_BLOCKS] = {0};

	return (blocks);
}

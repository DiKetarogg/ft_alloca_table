/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloca.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzoltan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 09:36:39 by jzoltan           #+#    #+#             */
/*   Updated: 2022/01/22 09:36:43 by jzoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ALLOCA_H
# define FT_ALLOCA_H

# define ALLOCA_SIZE 4096000
# define ALLOCA_STEP 4096
// ALLOCA_BLOCKS = ALLOCA_SIZE / ALLOCA_STEP
# define ALLOCA_BLOCKS 1000
# include <unistd.h>

void			ft_alloca_thread_lock(void);
void			ft_alloca_thread_unlock(void);

char			*ft_alloca_raw_memory(void);
unsigned int	*ft_alloca_blocks(void);

void			*ft_alloca(size_t size);
void			ft_alloca_free(void *block);

#endif

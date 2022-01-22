/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloca_thread.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzoltan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 09:37:20 by jzoltan           #+#    #+#             */
/*   Updated: 2022/01/22 09:37:22 by jzoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	*ft_alloca_get_thread_lock(void)
{
	static int	locked = 2;

	return (&locked);
}

void	ft_alloca_thread_lock(void)
{
	int *const	locked = ft_alloca_get_thread_lock();

	--*locked;
	while (*locked)
		;
}

void	ft_alloca_thread_unlock(void)
{
	int *const	locked = ft_alloca_get_thread_lock();

	*locked = 2;
}

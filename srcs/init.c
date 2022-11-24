/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlahin <tlahin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:35:39 by tlahin            #+#    #+#             */
/*   Updated: 2022/11/21 13:35:40 by tlahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_lem_in	*init_struct(t_lem_in *main_struct)
{
	main_struct->ants = 0;
	main_struct->ants_checked = -1;
	main_struct->hash_table = (t_room_list *)malloc(sizeof(t_room_list));
	return (main_struct);
}

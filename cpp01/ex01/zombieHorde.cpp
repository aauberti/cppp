/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aauberti <aauberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 07:17:51 by aauberti          #+#    #+#             */
/*   Updated: 2025/02/24 07:29:51 by aauberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde( int N, std::string name )
{
	if ( N <= 0 )
		return ( NULL );
	Zombie	*aZombieHorde = new Zombie[N];
	
	for (int i = 0; i < N; i++) {
		aZombieHorde[i].setName( name );
	}
	return (aZombieHorde);
}
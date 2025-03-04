/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aauberti <aauberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 07:10:06 by aauberti          #+#    #+#             */
/*   Updated: 2025/02/24 07:12:50 by aauberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

#define	NC "\e[0m"
#define RED "\e[31m"
#define GREEN "\e[32m"
#define YELLOW "\e[33m"
#define BLUE "\e[34m"
#define PURPLE "\e[35m"
#define CYAN "\e[36m"

std::string	colorZombieName( std::string const color, std::string const name ) {
	std::string	colorName( name );

	colorName.insert( 0, color );
	colorName.append( NC );
	return ( colorName );
}

int	main(void) {
	Zombie	*firstZombie = newZombie(colorZombieName( RED, "Lucy" ));
	Zombie	*secondZombie = newZombie(colorZombieName( YELLOW, "Greg" ));
	Zombie	*thirdZombie = newZombie(colorZombieName( GREEN, "Mrok" ));

	randomChump(colorZombieName( CYAN, "Chump" ));
	randomChump(colorZombieName( PURPLE, "Chomp" ));
	randomChump(colorZombieName( BLUE, "Champ" ));

	firstZombie->announce();
	delete firstZombie;
	secondZombie->announce();
	thirdZombie->announce();
	delete thirdZombie;
	delete secondZombie;
	return ( 0 );
}
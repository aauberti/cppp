#include "Weapon.hpp"

#define RESET "\e[0m"
#define GREEN "\e[32m"


Weapon::Weapon( std::string const type ) : _type( type )
{
	return ;
}

Weapon::~Weapon( void )
{
	return ;
}

std::string const	&Weapon::getType( void ) const
{
	return ( this->_type );
}

void	Weapon::setType( std::string const newType )
{
	if ( newType.empty() && !(this->getType().empty()) )
	{
		std::cout << GREEN
			<< "The " << this->getType() << " vanishes!"
			<< RESET << std::endl;
	}
	else if ( !(this->getType().empty()) )
	{
		std::cout << GREEN
			<< "The " << this->getType() << " magically turns into a " << newType
			<< RESET << std::endl;
	}
	else
	{
		std::cout << GREEN
			<< "A " << newType << " magically appears!"
			<< RESET << std::endl;
	}
	this->_type = newType;
	return ;
}
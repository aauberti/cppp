#include "HumanA.hpp"

#define RESET "\e[0m"
#define	CYAN "\e[36m"
#define GREEN "\e[32m"
#define RED "\e[31m"


HumanA::HumanA( std::string const aName, Weapon const &aWeapon )
				: _name( aName ),	_weapon( aWeapon )
{
	std::cout << CYAN
		<< this->_name << " enters the Colosseum with a roar!"
		<< RESET << std::endl;
	return ;
}

HumanA::~HumanA( void )
{
	std::cout << CYAN
		<< this->_name << " commits seppuku";
	if ( !(this->_weapon.getType().empty()) )
		std::cout << " with their " << this->_weapon.getType();
	std::cout << "." << RESET << std::endl;
	return ;
}


void	HumanA::attack( void ) const
{
	std::cout << RED
		<< this->_name << " attacks with their ";
	if ( this->_weapon.getType() == "" )
		std::cout << "bare hands!";
	else
		std::cout << this->_weapon.getType() << ".";
	std::cout << RESET << std::endl;
	return ;
}
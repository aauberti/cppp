#ifndef HUMAN_A_CLASS_H
# define HUMAN_A_CLASS_H

# include "Weapon.hpp"

class	HumanA
{
	private:
		std::string const	_name;
		Weapon const 		&_weapon;
		
	public:
		HumanA( std::string const aName, Weapon const &aWeapon );
		~HumanA( void );

		void	attack( void ) const;
};

#endif
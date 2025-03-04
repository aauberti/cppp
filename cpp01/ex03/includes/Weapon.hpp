#ifndef WEAPON_CLASS_H
# define WEAPON_CLASS_H

# include <string>
# include <iostream>

class	Weapon
{
	private:
		std::string	_type;
		
	public:
		Weapon( std::string const type );
		~Weapon( void );
		std::string const	&getType( void ) const;
		void				setType( std::string const newType );
};

#endif
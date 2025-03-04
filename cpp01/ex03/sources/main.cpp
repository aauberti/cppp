#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

// int main( void )
// {
// 	Weapon	knife = Weapon( "butter knife" );
// 	Weapon	club = Weapon( "crude spiked club" );
// 	Weapon	flamethrower = Weapon( "flamethrower" );
// 	Weapon	fists = Weapon( "" );

// 	std::cout << "\n* WELCOME TO THE COLOSSEUM! *\n" << std::endl;

// 	HumanA	alice( "Alice", club  );
// 	HumanB	bob( "Bob" );

// 	std::cout << "\n* 3, 2, 1... FIGHT! *\n" << std::endl;
	
// 	alice.attack();
// 	bob.attack();

// 	bob.setWeapon( knife );
// 	club.setType("");
// 	alice.attack();
// 	bob.attack();

// 	bob.setWeapon( fists );
// 	club.setType( "whip" );
// 	alice.attack();
// 	bob.attack();

// 	bob.setWeapon( flamethrower );
// 	bob.attack();
// 	club.setType( "butter knife" );
// 	alice.attack();

// 	std::cout << std::endl;
// 	return ( 0 );
// }

int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	return (0);
}
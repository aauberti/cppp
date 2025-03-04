#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    std::cout << "=== Testing Animal, Dog, and Cat with polymorphism ===" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << "J type: " << j->getType() << std::endl;
    std::cout << "I type: " << i->getType() << std::endl;
    
    i->makeSound();
    j->makeSound();
    meta->makeSound(); 

    delete meta;
    delete j;
    delete i;
    
    std::cout << "\n=== Testing WrongAnimal and WrongCat without proper polymorphism ===" << std::endl;
    const WrongAnimal* wrongAnimal = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();
    
    std::cout << "WrongCat type: " << wrongCat->getType() << std::endl;
    
    wrongCat->makeSound();
    wrongAnimal->makeSound();
    
    std::cout << "\n=== Additional tests with direct instances ===" << std::endl;
    Cat directCat;
    Dog directDog;
    WrongCat directWrongCat;
    
    std::cout << "Direct Cat type: " << directCat.getType() << std::endl;
    std::cout << "Direct Dog type: " << directDog.getType() << std::endl;
    std::cout << "Direct WrongCat type: " << directWrongCat.getType() << std::endl;
    
    directCat.makeSound();
    directDog.makeSound();
    directWrongCat.makeSound();
    
    delete wrongAnimal;
    delete wrongCat;
    
    return 0;
}
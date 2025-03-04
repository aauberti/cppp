#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main() {
    std::cout << "=== Basic test with Dog and Cat ===" << std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    
    delete j;
    delete i;
    
    std::cout << "\n=== Creating an array of Animals ===" << std::endl;
    const int arraySize = 4;
    Animal* animals[arraySize];

    for (int i = 0; i < arraySize; i++) {
        if (i < arraySize / 2) {
            animals[i] = new Dog();
        } else {
            animals[i] = new Cat();
        }
    }

    std::cout << "\n=== Deleting all animals ===" << std::endl;
    for (int i = 0; i < arraySize; i++) {
        delete animals[i];
    }
    
    std::cout << "\n=== Testing deep copy for Dog ===" << std::endl;
    Dog originalDog;
    originalDog.getBrain()->setIdea(0, "I want to chase cats");
    originalDog.getBrain()->setIdea(1, "I love bones");
    
    Dog copyDog = originalDog;
    
    std::cout << "Original dog idea 0: " << originalDog.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copy dog idea 0: " << copyDog.getBrain()->getIdea(0) << std::endl;
    
    copyDog.getBrain()->setIdea(0, "I want to sleep");
    std::cout << "After modification:" << std::endl;
    std::cout << "Original dog idea 0: " << originalDog.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copy dog idea 0: " << copyDog.getBrain()->getIdea(0) << std::endl;
    
    std::cout << "\n=== Testing deep copy for Cat ===" << std::endl;
    Cat originalCat;
    originalCat.getBrain()->setIdea(0, "I want to sleep all day");
    originalCat.getBrain()->setIdea(1, "Humans are my servants");
    
    Cat copyCat = originalCat;
    
    std::cout << "Original cat idea 0: " << originalCat.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copy cat idea 0: " << copyCat.getBrain()->getIdea(0) << std::endl;
    
    copyCat.getBrain()->setIdea(0, "I want to eat fish");
    std::cout << "After modification:" << std::endl;
    std::cout << "Original cat idea 0: " << originalCat.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copy cat idea 0: " << copyCat.getBrain()->getIdea(0) << std::endl;
    
    return 0;
}
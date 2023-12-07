/**
 * @file main.cpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief Main file.
 * @version 1
 * @date 2023-12-05
 * 
 * @copyright Copyright (c) 2023
 */

#include "Animal.class.hpp"
#include "Cat.class.hpp"
#include "Dog.class.hpp"
#include "WrongAnimal.class.hpp"
#include "WrongCat.class.hpp"

#define MAX_ANIMALS 4
namespace tests
{
	
}

int main(void)
{
	std::string const food[2] = {"steak", "fish"};
	Animal* animals[MAX_ANIMALS];

	for (int i = 0; i < MAX_ANIMALS; i++) {
		if (i < MAX_ANIMALS / 2) {
			animals[i] = new Dog();
		}
		else {
			animals[i] = new Cat();
		}
	}
	for (int i = 0; i < MAX_ANIMALS; i++) {
		if (i < MAX_ANIMALS / 2) {
			animals[i]->getBrain()->setIdea(food[0], 0);
		}
		else {
			animals[i]->getBrain()->setIdea(food[1], 0);
		}
	}
	for (int i = 0; i < MAX_ANIMALS; i++) {
		std::cout << animals[i]->getBrain()->getIdea(0) << std::endl;
	}
	tests::testCopy(animals);
	for (int i = 0; i < MAX_ANIMALS; i++) {
		delete animals[i];
	}
	return (0);
}

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

namespace tests
{
	void wrongTest(void) {
		const WrongAnimal* meta = new WrongAnimal();
		const Animal* j = new Dog();
		const WrongAnimal* i = new WrongCat();

		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound();
		j->makeSound();
		meta->makeSound();

		delete meta;
		delete j;
		delete i;
	}

	void copyTest(void) {
		const Animal* j = new Dog();
		const Animal* i = new Animal(*j);

		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound();
		j->makeSound();

		delete j;
		delete i;
	}

	void operatorTest(void) {
		const Animal j = Dog();
		Animal i;

		i = j;
		std::cout << j.getType() << " " << std::endl;
		std::cout << i.getType() << " " << std::endl;
		i.makeSound();
		j.makeSound();
	}
}

int main(void)
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;
	std::cout << std::endl;
	tests::wrongTest();
	std::cout << std::endl;
	tests::copyTest();
	std::cout << std::endl;
	tests::operatorTest();
	std::cout << std::endl;
	return 0;
}

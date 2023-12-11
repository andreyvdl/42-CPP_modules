/**
 * @file main.cpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief Main file.
 * @version 1
 * @date 2023-12-05
 * 
 * @copyright Copyright (c) 2023
 */

#include "AAnimal.abstract.hpp"
#include "Cat.class.hpp"
#include "Dog.class.hpp"
#include "WrongAnimal.class.hpp"
#include "WrongCat.class.hpp"

#define MAX_ANIMALS 4
namespace tests
{
	void animalArray(void)
	{
		std::string const food[2] = {"steak", "fish"};
		AAnimal* animals[MAX_ANIMALS];

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
		std::cout << std::endl;
		std::cout << "What are they thiking about?" << std::endl;
		std::cout << std::endl;
		for (int i = 0; i < MAX_ANIMALS; i++) {
			std::cout << animals[i]->getBrain()->getIdea(0) << std::endl;
		}
		std::cout << std::endl;
		for (int i = 0; i < MAX_ANIMALS; i++) {
			delete animals[i];
		}
	}

	void animalShallow(void)
	{
		Cat* cat = new Cat();
		Dog* dog = new Dog();

		for (int i = 0; i < 101; i++) {
			cat->getBrain()->setIdea("destroy couch", i);
			dog->getBrain()->setIdea("get my tail", i);
		}
		Cat* copyCat = new Cat(*cat);
		Dog* copyDog = new Dog(*dog);
		std::cout << std::endl;
		std::cout << "cat addres:" << cat << std::endl;
		std::cout << "copycat addres:" << copyCat << std::endl;
		std::cout << "dog addres:" << dog << std::endl;
		std::cout << "copydog addres:" << copyDog << std::endl;
		std::cout << std::endl;
		for (int i = 0; i < 101; i++) {
			std::cout << copyCat->getBrain()->getIdea(i) << std::endl;
			std::cout << copyDog->getBrain()->getIdea(i) << std::endl;
		}
		delete cat;
		delete dog;
		delete copyCat;
		delete copyDog;
	}
}

int main(void)
{
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();

	delete j;//should not create a leak
	delete i;

	std::cout << std::endl;
	std::cout << "ARRAY TEST =================================================="
		<< std::endl;
	std::cout << std::endl;
	tests::animalArray();
	std::cout << std::endl;
	std::cout << "SHALLOW TEST ================================================"
		<< std::endl;
	std::cout << std::endl;
	tests::animalShallow();
	return 0;
}

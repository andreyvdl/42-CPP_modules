#include <cstdlib>
#include <ctime>

#include "Character.class.hpp"
#include "MateriaSource.class.hpp"
#include "Ice.class.hpp"
#include "Cure.class.hpp"
#include "AMateria.abstract.hpp"
#include "ICharacter.interface.hpp"
#include "IMateriaSource.interface.hpp"

#include "defines.hpp"

namespace tests
{
	void pdfTest(void)
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter* me = new Character("me");

		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		ICharacter* bob = new Character("bob");

		me->use(0, *bob);
		me->use(1, *bob);

		delete bob;
		delete me;
		delete src;
	}

	void characterInventory(void)
	{
		// AMateria materia; // will generate a error
		// ICharacter character; // will generate a error
		AMateria* materias[2];
		materias[0] = new Ice();
		materias[1] = new Cure();

		ICharacter* tifa = new Character("Tifa");
		ICharacter* aerith = new Character("Aerith");

		tifa->equip(materias[0]);
		aerith->equip(materias[1]);

		tifa->use(0, *aerith);
		tifa->use(-42, *aerith);
		tifa->use(42, *aerith);
		aerith->use(0, *tifa);
		aerith->use(-42, *tifa);
		aerith->use(42, *tifa);

		tifa->unequip(0);
		tifa->unequip(42);
		tifa->unequip(-42);
		aerith->unequip(0);
		aerith->unequip(42);
		aerith->unequip(-42);

		tifa->use(0, *aerith);
		tifa->use(42, *aerith);
		tifa->use(-42, *aerith);
		aerith->use(0, *tifa);
		aerith->use(42, *tifa);
		aerith->use(-42, *tifa);

		delete tifa;
		delete aerith;
	}

	void bossFight(void)
	{
		srand(time(NULL));

		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter* cloud = new Character("Cloud");
		ICharacter* sephiroth = new Character("Sephiroth");

		cloud->equip(src->createMateria("ice"));
		sephiroth->equip(src->createMateria("ice"));
		cloud->equip(src->createMateria("cure"));
		sephiroth->equip(src->createMateria("cure"));

		for (int i = 0; i < 10; i++) {
			cloud->use(rand() % 2, *sephiroth);
			sephiroth->use(rand() % 2, *cloud);
		}

		delete cloud;
		delete sephiroth;
		delete src;
	}

	void constructors(void)
	{
		ICharacter* red = new Character("Red XIII");
		AMateria* iced = new Ice();
		AMateria* cured = new Cure();

		red->equip(iced);
		red->equip(cured);

		// isso aqui foi uma gambiarra, mas deu super certo
		ICharacter* cait = new Character(*(dynamic_cast<Character*>(red)));

		std::cout << cait->getName() << std::endl;
		cait->use(0, *red);
		cait->use(1, *red);
		cait->unequip(0);
		cait->unequip(1);
		red->use(0, *cait);
		red->use(1, *cait);

		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		IMateriaSource* dst = new MateriaSource(
			*(dynamic_cast<MateriaSource*>(src))
		);

		red->equip(dst->createMateria("ice"));
		red->use(2, *cait);
		cait->use(2, *red);

		delete red;
		delete cait;
		delete src;
		delete dst;
	}
}

int main()
{
	std::cout << BG_YELLOW "PDF TEST:" << std::endl;
	std::cout << RESET << std::endl;
	tests::pdfTest();
	std::cout << std::endl;
	std::cout << BG_YELLOW "CHARACTER INVENTORY TEST:" << std::endl;
	std::cout << RESET << std::endl;
	tests::characterInventory();
	std::cout << std::endl;
	std::cout << BG_YELLOW "COPIES:" << std::endl;
	std::cout << RESET << std::endl;
	tests::constructors();
	std::cout << std::endl;
	std::cout << BG_YELLOW "CLOUD VS SEPHIROTH:" << std::endl;
	std::cout << RESET << std::endl;
	tests::bossFight();
	std::cout << std::endl;
	return (0);
}

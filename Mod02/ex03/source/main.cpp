/**
 * @file main.cpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief Main file.
 * @version 1
 * @date 2023-11-21
 * 
 * @copyright Copyright (c) 2023
 */

#include "Point.class.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

namespace tests {
	void test1(void) {
		Point const a;
		Point b;
		Point const c(1.0f, 0.0f);
		Point const p(0.25f, 0.25f);

		b = Point(0.0f, 1.0f);
		bool result = bsp(a, b, c, p);
		std::cout << "a: x " << a.getX() << ", y " << a.getY() << std::endl;
		std::cout << "b: x " << b.getX() << ", y " << b.getY() << std::endl;
		std::cout << "c: x " << c.getX() << ", y " << c.getY() << std::endl;
		std::cout << "p: x " << p.getX() << ", y " << p.getY() << std::endl;
		std::cout << "bsp(a, b, c, p): " << result << std::endl;
	}

	void test2(void) {
		Point const a2;
		Point const b2(a2);
		Point const c2(b2);
		Point const p2(c2);

		bool result2 = bsp(a2, b2, c2, p2);
		std::cout << "a2: x " << a2.getX() << ", y " << a2.getY() << std::endl;
		std::cout << "b2: x " << b2.getX() << ", y " << b2.getY() << std::endl;
		std::cout << "c2: x " << c2.getX() << ", y " << c2.getY() << std::endl;
		std::cout << "p2: x " << p2.getX() << ", y " << p2.getY() << std::endl;
		std::cout << "bsp(a2, b2, c2, p2): " << result2 << std::endl;
	}

	void test3(void) {
		Point const a3;
		Point const b3(0.1f, 0.0f);
		Point const c3(0.2f, 0.0f);
		Point const p3(0.15f, 0.1f);

		bool result3 = bsp(a3, b3, c3, p3);
		std::cout << "a3: x " << a3.getX() << ", y " << a3.getY() << std::endl;
		std::cout << "b3: x " << b3.getX() << ", y " << b3.getY() << std::endl;
		std::cout << "c3: x " << c3.getX() << ", y " << c3.getY() << std::endl;
		std::cout << "p3: x " << p3.getX() << ", y " << p3.getY() << std::endl;
		std::cout << "bsp(a3, b3, c3, p3): " << result3 << std::endl;

		Point const a4;
		Point const b4(0.0f, 0.5f);
		Point const c4(0.5f, 0.0f);
		Point const p4(0.25f, 0.25f);

		bool result4 = bsp(a4, b4, c4, p4);
		std::cout << "a4: x " << a4.getX() << ", y " << a4.getY() << std::endl;
		std::cout << "b4: x " << b4.getX() << ", y " << b4.getY() << std::endl;
		std::cout << "c4: x " << c4.getX() << ", y " << c4.getY() << std::endl;
		std::cout << "p4: x " << p4.getX() << ", y " << p4.getY() << std::endl;
		std::cout << "bsp(a4, b4, c4, p4): " << result4 << std::endl;
	}
}

int main(void) {
	tests::test1();
	tests::test2();
	tests::test3();
}

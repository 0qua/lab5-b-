#include "DataChain.h"
#include <iostream>

int main() {
	CDataSimple simple;
	simple.Generate(15, 20);  // Генеруємо послідовність довжиною 20 цифр
	std::cout << "Generated String: " << simple.GetFullString() << std::endl;

	return 0;
}

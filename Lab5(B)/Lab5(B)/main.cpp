#include "DataChain.h"
#include <iostream>

int main() {
	CDataSimple simple;
	simple.Generate(15, 20);  // �������� ����������� �������� 20 ����
	std::cout << "Generated String: " << simple.GetFullString() << std::endl;

	return 0;
}

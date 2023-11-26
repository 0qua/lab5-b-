#include "DataChain.h"
#include "Workspace.h"
#include <iostream>

int main() {
	CDataSimple data;
	CWorkspace ws(data);

	ws.Init(15, 20); // ����������� �����������
	std::cout << "Generated String: " << ws.GetChainString() << std::endl;

	ws.Save("chain.txt"); // ��������� ����� � ����

	CDataSimple newData; // ��������� ����� ��'��� ��� ���������� �����
	CWorkspace newWs(newData);
	newWs.Load("chain.txt"); // ³��������� ����� � �����
	std::cout << "Loaded String: " << newWs.GetChainString() << std::endl;

	return 0;
}

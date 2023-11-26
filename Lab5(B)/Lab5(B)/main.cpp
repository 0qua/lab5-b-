#include "DataChain.h"
#include "Workspace.h"
#include <iostream>

int main() {
	CDataSimple data;
	CWorkspace ws(data);

	ws.Init(15, 20); // Ініціалізація послідовності
	std::cout << "Generated String: " << ws.GetChainString() << std::endl;

	ws.Save("chain.txt"); // Зберігання стану в файл

	CDataSimple newData; // Створюємо новий об'єкт для відновлення даних
	CWorkspace newWs(newData);
	newWs.Load("chain.txt"); // Відновлення стану з файлу
	std::cout << "Loaded String: " << newWs.GetChainString() << std::endl;

	return 0;
}

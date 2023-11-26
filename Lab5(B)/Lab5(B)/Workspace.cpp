#include "Workspace.h"
#include "Workspace.h"

CWorkspace::CWorkspace(CDataChain& data) : m_refChain(data) {}

CWorkspace::~CWorkspace() {}

void CWorkspace::Init(int nDepth, int nLength) {
	m_refChain.Generate(nDepth, nLength);
}

const char* CWorkspace::GetChainString() const {
	return m_refChain.GetFullString();
}


bool CWorkspace::Save(const std::string& sFilepath) const {
	std::ofstream file(sFilepath, std::ios::out);
	if (file) {
		file << m_refChain.GetChain(); // Використання геттера замість прямого доступу
		file.close();
		return true;
	}
	return false;
}

bool CWorkspace::Load(const std::string& sFilepath) {
	std::ifstream file(sFilepath, std::ios::in);
	if (file) {
		std::string line;
		getline(file, line);
		file.close();
		m_refChain = CDataSimple();
		dynamic_cast<CDataSimple&>(m_refChain).SetChain(line); 
		return true;
	}
	return false;
}
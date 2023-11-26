#include "DataChain.h"
#include <sstream>

CDataChain::CDataChain() {}

CDataChain::~CDataChain() {}

void CDataChain::SetChain(const std::string& chain) {
	m_sChain = chain;
}

size_t CDataChain::GetLength() const {
	return m_sChain.length();
}

int CDataChain::Find(const char* sSubStr, int nPos) const {
	size_t pos = m_sChain.find(sSubStr, nPos);
	return pos != std::string::npos ? static_cast<int>(pos) : -1;
}

std::string CDataChain::GetSubStr(int nPos, int nLength) const {
	return m_sChain.substr(nPos, nLength);
}

const char* CDataChain::GetFullString() const {
	return m_sChain.c_str();
}

CDataSimple::CDataSimple() {}

CDataSimple::~CDataSimple() {}

void CDataSimple::Generate(int nDepth, int nMaxLength) {
	std::stringstream ss;
	for (int i = 0; i <= nDepth; ++i) {
		ss << i;
		if (nMaxLength > 0 && ss.str().length() >= static_cast<size_t>(nMaxLength)) {
			m_sChain = ss.str().substr(0, nMaxLength);
			return;
		}
	}
	m_sChain = ss.str();
}


std::string CDataChain::GetChain() const {
	return m_sChain;
}
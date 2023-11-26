#include "DataChain.h"
#include <sstream>

CDataChain::CDataChain() {}

CDataChain::~CDataChain() {}

size_t CDataChain::GetLength() {
	return m_sChain.length();
}

int CDataChain::Find(const char* sSubStr, int nPos) {
	size_t pos = m_sChain.find(sSubStr, nPos);
	return pos != string::npos ? pos : -1;
}

string CDataChain::GetSubStr(int nPos, int nLength) {
	return m_sChain.substr(nPos, nLength);
}

const char* CDataChain::GetFullString() {
	return m_sChain.c_str();
}

CDataSimple::CDataSimple() {}

CDataSimple::~CDataSimple() {}

void CDataSimple::Generate(int nDepth, int nMaxLength) {
	std::stringstream ss;
	for (int i = 0; i <= nDepth; ++i) {
		ss << i;
		if (nMaxLength > 0 && ss.str().length() >= nMaxLength) {
			m_sChain = ss.str().substr(0, nMaxLength);
			return;
		}
	}
	m_sChain = ss.str();
}

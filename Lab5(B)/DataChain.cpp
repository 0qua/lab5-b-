#pragma once
#include "DataChain.h"
#include "CDataSimple.h"
#include <sstream>

CDataChain::CDataChain() : m_sChain("") {} // Визначаємо змінну m_sChain в конструкторі

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

std::string CDataChain::GetChain() const {
	return m_sChain;
}



std::ostream & operator<<(std::ostream & os, const CDataChain & chain)
{
	os << chain.GetChain(); 
	return os; 
}

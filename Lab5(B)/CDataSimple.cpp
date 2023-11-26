#pragma once
#include "CDataSimple.h"
#include <sstream>

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

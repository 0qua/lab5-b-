#pragma once
#include "CLink.h"

CLink::CLink(CDataChain& refChain) : m_refChain(refChain), m_nPos(-1), m_nSize(0) {}

CLink::~CLink() {}

bool CLink::Attach(const char* sSubStr) {
	int pos = m_refChain.Find(sSubStr);
	if (pos != -1) {
		m_nPos = pos;
		m_nSize = strlen(sSubStr);
		return true;
	}
	return false;
}

void CLink::Output(std::ostream& os) {
	os << "Link: Position = " << m_nPos << ", Size = " << m_nSize << std::endl;
}

bool CLink::Save(std::ostream& so) {
	so << m_nPos << " " << m_nSize << std::endl;
	return so.good();
}

bool CLink::Load(std::istream& is) {
	is >> m_nPos >> m_nSize;
	return is.good();
}
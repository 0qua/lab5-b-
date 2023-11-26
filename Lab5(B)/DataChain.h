#pragma once
#include <string>
#include <iostream>

class CDataChain {
public:
	CDataChain();
	virtual ~CDataChain();

	virtual void Generate(int nDepth, int nMaxLength = 0) = 0;
	size_t GetLength() const;
	int Find(const char* sSubStr, int nPos = 0) const;
	std::string GetSubStr(int nPos, int nLength = -1) const;
	const char* GetFullString() const;
	std::string GetChain() const;
	void SetChain(const std::string& chain);

protected:
	std::string m_sChain;
};

std::ostream& operator<<(std::ostream& os, const CDataChain& chain);

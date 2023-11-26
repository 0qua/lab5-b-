#pragma once
#include <string>

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

class CDataSimple : public CDataChain {
public:
	CDataSimple();
	~CDataSimple();

	void Generate(int nDepth, int nMaxLength = 0) override;
};

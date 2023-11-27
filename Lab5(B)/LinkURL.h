#pragma once
#include "CLink.h"
#include <string>

class CLinkURL : public CLink {
public:
	CLinkURL(CDataChain& refChain);
	virtual ~CLinkURL(void);

	bool AttachURL(const std::string& url);
	void SetURL(const std::string& url); 

private:
	std::string m_sURL; 
};

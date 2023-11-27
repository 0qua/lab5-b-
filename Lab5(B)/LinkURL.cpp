#include "LinkURL.h"
#include <regex> 
#include <iostream>

CLinkURL::CLinkURL(CDataChain& refChain) : CLink(refChain) {
	// Реалізація конструктора
}


CLinkURL::~CLinkURL() {}

void CLinkURL::SetURL(const std::string& url) {
	// Метод для встановлення URL
	this->m_sURL = url;
}

bool CLinkURL::AttachURL(const std::string& url) {
	std::regex urlRegex("^(http://www\\.|https://www\\.|http://|https://)[a-z0-9]+([\\-\\.]{1}[a-z0-9]+)*\\.[a-z]{2,5}(:[0-9]{1,5})?(/.*)?$");
	if (!std::regex_match(url, urlRegex)) {
		std::cout << "Invalid URL format." << std::endl;
		return false;
	}

	if (!this->Attach("your_substring_to_attach")) { // Припустимо, що Attach - це метод з класу CLink
		std::cout << "Failed to attach URL to a substring in the chain." << std::endl;
		return false;
	}

	// Якщо всі перевірки пройдено, зберігаємо URL
	this->m_sURL = url;
	return true;
}

#ifdef FLYTOELEPHANT_EXPORTS
#define FLYTOELEPHANT_API __declspec(dllexport)
#else
#define FLYTOELEPHANT_API __declspec(dllimport)
#endif

#include "Application.h"

class FLYTOELEPHANT_API CFlyToElephant {
public:
	CFlyToElephant(void);
	void findInterjacentWords(
		const std::string& sourceWord,
		const std::string& destinationWord,
		std::vector<std::string>& interjacentWords) const;
};

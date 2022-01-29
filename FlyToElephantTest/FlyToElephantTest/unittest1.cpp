#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\FlyToElephant\FlyToElephant.h"
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace FlyToElephantTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		// Ќаивна€ проверка по количеству промежуточных слов.
		TEST_METHOD(TestMethod1)
		{
			CFlyToElephant flyToElephant;
			std::vector<std::string> interjacentWords;

			flyToElephant.findInterjacentWords("CAT", "POT", interjacentWords);
			Assert::IsTrue(interjacentWords.size() == 3);

			interjacentWords.clear();

			flyToElephant.findInterjacentWords("ADOAB", "IPGOR", interjacentWords);
			Assert::IsTrue(interjacentWords.size() == 6);

			interjacentWords.clear();

			flyToElephant.findInterjacentWords("GLOBAT", "EKUDAT", interjacentWords);
			Assert::IsTrue(interjacentWords.size() == 5);
		}

		// Ќаивна€ проверка со сравнением.
		TEST_METHOD(TestMethod2)
		{
			CFlyToElephant flyToElephant;
			std::vector<std::string> interjacentWords;

			flyToElephant.findInterjacentWords("CAT", "POT", interjacentWords);

			Assert::IsTrue(interjacentWords[0].compare("VAT") == 0);
			Assert::IsTrue(interjacentWords[1].compare("BAT") == 0);
			Assert::IsTrue(interjacentWords[2].compare("BOT") == 0);

			interjacentWords.clear();

			flyToElephant.findInterjacentWords("ADOAB", "IPGOR", interjacentWords);

			Assert::IsTrue(interjacentWords[0].compare("ADOOB") == 0);
			Assert::IsTrue(interjacentWords[1].compare("APOOB") == 0);
			Assert::IsTrue(interjacentWords[2].compare("OPOOB") == 0);
			Assert::IsTrue(interjacentWords[3].compare("OPGOB") == 0);
			Assert::IsTrue(interjacentWords[4].compare("APGOB") == 0);
			Assert::IsTrue(interjacentWords[5].compare("APGOR") == 0);

			interjacentWords.clear();

			flyToElephant.findInterjacentWords("GLOBAT", "EKUDAT", interjacentWords);

			Assert::IsTrue(interjacentWords[0].compare("OLOBAT") == 0);
			Assert::IsTrue(interjacentWords[1].compare("OKOBAT") == 0);
			Assert::IsTrue(interjacentWords[2].compare("OKONAT") == 0);
			Assert::IsTrue(interjacentWords[3].compare("OKUNAT") == 0);
			Assert::IsTrue(interjacentWords[4].compare("EKUNAT") == 0);
		}

	};
}
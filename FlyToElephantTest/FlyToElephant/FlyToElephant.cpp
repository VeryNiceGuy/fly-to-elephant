#include "stdafx.h"
#include "FlyToElephant.h"

CFlyToElephant::CFlyToElephant(){}

// ����� - �������.
void CFlyToElephant::findInterjacentWords(
	const std::string& sourceWord,
	const std::string& destinationWord,
	std::vector<std::string>& interjacentWords) const
{
	Application application;
	application.findInterjacentWords(sourceWord, destinationWord, interjacentWords);
}
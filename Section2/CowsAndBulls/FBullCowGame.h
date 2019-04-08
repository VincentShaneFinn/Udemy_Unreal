#pragma once
#include <string>

//NEVER DO USING NAMESPACE IN HEADER FILE
//using namespace std;
class FBullCowGame {

public:
	FBullCowGame(); //Constructor

	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool IsGameWon() const;

	bool CheckGuessValidity(std::string); //TODO make a richer return value;
	void Reset(); //TODO make a richer return value.

private:
	//initialized in constructor
	int MyCurrentTry;
	int MyMaxTries;
};
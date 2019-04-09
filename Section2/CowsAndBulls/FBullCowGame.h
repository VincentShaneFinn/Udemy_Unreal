#pragma once
#include <string>

using FString = std::string;
using int32 = int;

struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

//NEVER DO USING NAMESPACE IN HEADER FILE
//using namespace std;
class FBullCowGame {

public:
	FBullCowGame(); //Constructor

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	bool IsGameWon() const;

	bool CheckGuessValidity(FString); //TODO make a richer return value;
	FBullCowCount SubmitGuess(FString);
	void Reset(); //TODO make a richer return value.

private:
	//initialized in constructor
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
};
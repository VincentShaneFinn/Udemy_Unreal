#pragma once
#include <string>
#include <map>
#define TMap std::map


using FString = std::string;
using int32 = int;

struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus {
	OK, 
	Not_Isogram, 
	Wrong_Length,
	Not_Lowercase,
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

	EGuessStatus CheckGuessValidity(FString);
	FBullCowCount SubmitValidGuess(FString);
	void Reset(); //TODO make a richer return value.

private:
	//initialized in constructor
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
	bool bGameIsWon;

	bool IsIsogram(FString) const;
	bool IsLowercase(FString) const;
};
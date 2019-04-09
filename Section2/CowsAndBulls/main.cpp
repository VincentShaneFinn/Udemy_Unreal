#include <iostream>
#include <string>
#include "FBullCowGame.h"

/*
	This is the console executable that makes use of the bull cow class
	This acts as the view in an MVC pattern and is responsible for all
	user interaction. For game logic, see the FBullCowGame class.
*/

using FText = std::string;
using int32 = int;

void PrintIntro();
std::string GetGuess();
void PlayGame();
bool AskToPlayAgain();

FBullCowGame BCGame; //notice the object is construced even tho we havent used the c# new Keyword

//entry point for our application
int main()
{
	do {
		PrintIntro();
		PlayGame();
	} 
	while (AskToPlayAgain());
	return 0;
}

void PrintIntro()
{
	

	std::cout << "Welcome to bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength() << " letter isogram I'm thinking of?\n";
}

void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();

	//constexpr int NUMBER_OF_TURNS = 5;
	for (int32 count = 1; count <= MaxTries; count++) {
		FText Guess = GetGuess();

		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);

		std::cout << "Bulls =  " << BullCowCount.Bulls << std::endl;
		std::cout << "Cows =  " << BullCowCount.Cows << std::endl;

		std::cout << std::endl;
	}

	//TODO add a game summary
}

FText GetGuess()
{
	int32 CurrentTry = BCGame.GetCurrentTry();

	FText Guess = "";

	std::cout << "Try " << CurrentTry << ". Enter your guess: ";
	std::getline(std::cin, Guess);
	std::cout << std::endl;

	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again? (y/n) ";
	FText Response = "";
	std::getline(std::cin, Response);
	std::cout << std::endl;

	return (Response[0] == 'y') || (Response[0] == 'Y');
}
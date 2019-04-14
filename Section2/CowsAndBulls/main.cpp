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
std::string GetValidGuess();
void PlayGame();
bool AskToPlayAgain();
void PrintGameSummary();

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

	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries) {
		FText Guess = GetValidGuess();

		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);

		std::cout << "Bulls =  " << BullCowCount.Bulls << std::endl;
		std::cout << "Cows =  " << BullCowCount.Cows << std::endl;

		std::cout << std::endl;
	}

	PrintGameSummary();
}

// loop continually until a valid guess is provided
FText GetValidGuess()
{		
	FText Guess = "";
	EGuessStatus Status;
	do {
		int32 CurrentTry = BCGame.GetCurrentTry();

		std::cout << "Try " << CurrentTry << ". Enter your guess: ";
		std::getline(std::cin, Guess);
		std::cout << std::endl;

		Status = BCGame.CheckGuessValidity(Guess);

		switch (Status) {
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n";
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter a word without repeating letters.\n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter all lowercase letters.\n";
			break;
		default:
			break;
		}
	} while (Status != EGuessStatus::OK);
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

void PrintGameSummary() {
	if (BCGame.IsGameWon()) {
		std::cout << "WELL DONE - YOU WIN!!!\n";
	}
	else {
		std::cout << "Better luck next time!\n:";
	}
}
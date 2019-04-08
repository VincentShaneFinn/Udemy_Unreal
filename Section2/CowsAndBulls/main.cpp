#include <iostream>
#include <string>
#include "FBullCowGame.h"

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
	constexpr int WORD_LENGTH = 5;

	std::cout << "Welcome to bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?\n";
}

void PlayGame()
{
	BCGame.Reset();
	int MaxTries = BCGame.GetMaxTries();

	//constexpr int NUMBER_OF_TURNS = 5;
	for (int count = 1; count <= MaxTries; count++) {
		std::string Guess = GetGuess();
		std::cout << "Your guess was: " << Guess << std::endl;
		std::cout << std::endl;
	}

	//TODO add a game summary
}

std::string GetGuess()
{
	int CurrentTry = BCGame.GetCurrentTry();

	std::string Guess = "";

	std::cout << "Try " << CurrentTry << ". Enter your guess: ";
	std::getline(std::cin, Guess);
	std::cout << std::endl;

	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again? (y/n) ";
	std::string Response = "";
	std::getline(std::cin, Response);
	std::cout << std::endl;

	return (Response[0] == 'y') || (Response[0] == 'Y');
}
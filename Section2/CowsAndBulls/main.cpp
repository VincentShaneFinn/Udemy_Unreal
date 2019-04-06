#include <iostream>
#include <string>
#include "main.h"

using namespace std;

void PrintIntro();
string GetGuessAndPrint();

//entry point for our application
int main()
{

	PrintIntro();
	for (int count = 1; count <= 5; count++) {
		GetGuessAndPrint();
		cout << endl;
	}

	return 0;
}

string GetGuessAndPrint()
{
	string Guess = "";

	cout << "Enter your guess: ";
	getline(cin, Guess);
	cout << endl;

	//print the guess back
	cout << "Your guess was: " << Guess << endl;

	return Guess;
}

void PrintIntro()
{
	constexpr int WORD_LENGTH = 5;

	cout << "Welcome to bulls and Cows, a fun word game.\n";
	cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?\n";
}

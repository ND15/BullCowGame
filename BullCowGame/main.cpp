#include <iostream>
#include <string>
#include "FBullCowGame.h"


//prototypes
void PrintIntro();
void PlayGame();
std::string GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame; //instantiate a new game

int main() //entry to the game
{
	bool bPlayAgain = false;
	do 
	{
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	} while (bPlayAgain);

	return 0;//exit
}


void PrintIntro()
{
	//Introduction to the game
	constexpr int WORD_LENGTH = 5;

	std::cout << "Welcome to Bulls and Cow game!" << std::endl;
	std::cout << "Can you guess the " << WORD_LENGTH << " letter iosgram I am thinking of?" << std::endl;
	return;

}


void PlayGame()
{
	int MaxTries = BCGame.GetMaxTries();
	std::cout << MaxTries << std::endl;

	//loop for the number of turns
	for (int count = 1; count <= MaxTries; count++)
	{
		std::string Guess = GetGuess();
		std::cout << "Your Guess was: " << Guess << std::endl;
		std::cout << std::endl;
	}
}


std::string GetGuess()
{
	int CurrentTry = BCGame.getCurrentTry();

	//get the guess word 
	std::cout <<"Try "<< CurrentTry << ". Enter your Guess: ";
	std::string Guess = "";
	std::getline(std::cin, Guess);

	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again (y/n)?" << std::endl;
	std::string Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');

	return false;
}

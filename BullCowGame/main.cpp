#include <iostream>
#include <string>
#include "FBullCowGame.h"


using FText = std::string;

//prototypes
void PrintIntro();
void PlayGame();
FText GetGuess();
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

	std::cout << "Welcome to Bulls and Cow game!" << std::endl;
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength() << " letter iosgram I am thinking of?" << std::endl;
	return;

}


void PlayGame()
{
	BCGame.Reset();

	int MaxTries = BCGame.GetMaxTries();

	//loop for the number of turns
	for (int32 count = 1; count <= MaxTries; count++)
	{
		FText Guess = GetGuess();

		EGuessStatus Status = BCGame.checkGuessValidity(Guess);

		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
		
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ", Cows = " << BullCowCount.Cows << std::endl;
		
		std::cout << std::endl;
	}
}


FText GetGuess()
{
	int32 CurrentTry = BCGame.getCurrentTry();

	//get the guess word 
	std::cout <<"Try "<< CurrentTry << ". Enter your Guess: ";
	FText Guess = "";
	std::getline(std::cin, Guess);

	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again (y/n)?" << std::endl;
	FText Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');

	return false;
}

#include "FBullCowGame.h"

void FBullCowGame::Reset()
{
	return;
}

int FBullCowGame::GetMaxTries() const
{
	return MyMaxTries;
}

int FBullCowGame::getCurrentTry() const
{
	return MyCurrentTry;
}

bool FBullCowGame::isGameWon() const
{
	return false;
}

bool FBullCowGame::checkGuessValidity(std::string)
{
	return false;
}


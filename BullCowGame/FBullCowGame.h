#pragma once
#include <string>


class FBullCowGame
{
public:
	int GetMaxTries() const;
	int getCurrentTry() const;
	bool isGameWon() const;
	
	void Reset(); //TODO make a more rich return value
	bool checkGuessValidity(std::string);


private:
	int MyCurrentTry = 1;
	int MyMaxTries = 5;
};

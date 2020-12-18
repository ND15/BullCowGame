#pragma once
#include <string>

using FString = std::string;
using int32 = int;

struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus
{
	OK,
	Not_Isogram,
	Word_Length,
	Not_Lowercase
};

class FBullCowGame
{
public:
	FBullCowGame(); //constructor

	int32 GetMaxTries() const;
	int32 getCurrentTry() const;

	int32 GetHiddenWordLength() const;
	bool isGameWon() const;
	
	void Reset(); //TODO make a more rich return value
	EGuessStatus checkGuessValidity(FString) const;

	FBullCowCount SubmitGuess(FString);

private:
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
};

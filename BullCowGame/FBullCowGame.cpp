#include "FBullCowGame.h"

FBullCowGame::FBullCowGame()
{
	Reset();
}


void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;
	MyCurrentTry = 1;

	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;

	return;
}

int32 FBullCowGame::GetMaxTries() const
{
	return MyMaxTries;
}

int32 FBullCowGame::getCurrentTry() const
{
	return MyCurrentTry;
}

int32 FBullCowGame::GetHiddenWordLength() const
{
	return MyHiddenWord.length();
}

bool FBullCowGame::isGameWon() const
{
	return false;
}

EGuessStatus FBullCowGame::checkGuessValidity(FString) const
{
	if (false)
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (false)
	{
		return EGuessStatus::Not_Lowercase;
	}
	else if (false)
	{
		return EGuessStatus::Word_Length;
	}
	else
	{
		return EGuessStatus::OK;
	}
}

FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	MyCurrentTry++;

	FBullCowCount BullCowCount;
	int32 HiddenWordLength = MyHiddenWord.length();

	for (int32 HWChar = 0; HWChar < HiddenWordLength; HWChar++)
	{
		for (int32 GChar = 0; GChar < HiddenWordLength; GChar++)
		{
			if (Guess[GChar] == MyHiddenWord[HWChar])
			{
				if (HWChar == GChar)
				{
					BullCowCount.Bulls++;
				}
				else
				{
					BullCowCount.Cows++;
				}
			}
		}
	}
	return BullCowCount;
}


#include "FBullCowGame.h"

FBullCowGame::FBullCowGame(){Reset();}

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const{ return MyHiddenWord.length() ;}

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 6;
	const FString HIDDEN_WORD = "planet";
	
	MyMaxTries = MAX_TRIES;
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	bGameIsWon = false;
	return;
}

bool FBullCowGame::IsGameWon() const{return bGameIsWon;}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{	
	if (false) {	// if the guess isn't an isogram
		return EGuessStatus::Not_Isogram;	//TODO write function
	}
	else if (false) {	// if the guess isn't all lowercase
		return EGuessStatus::Not_Lowercase;		//TODO write function 
	}
	else if (GetHiddenWordLength() != Guess.length()) { // if the guess length is wrong
		return EGuessStatus::Wrong_Length;
	}
	else
	{
		return EGuessStatus::OK;
	}
}

// receuves a VALID guess, increments turn, and returns count
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;
	int32 WordLength = MyHiddenWord.length();

	// loop through all letters in the hidden word
	for (int32 i = 0; i < WordLength; i++) {
		// compare letters against the guess
		for (int32 j = 0; j < WordLength; j++) {
			//if they match
			if (Guess[i] == MyHiddenWord[j]) {
				if (i == j) { // if they're in the same place
					BullCowCount.Bulls++;	// incriment bulls
				}
				else BullCowCount.Cows++;	// else incriment cows
			}
		}
	}
	if (BullCowCount.Bulls == WordLength) {
		bGameIsWon = true;
	}
	else {
		bGameIsWon = false;
	}

	return BullCowCount;
}
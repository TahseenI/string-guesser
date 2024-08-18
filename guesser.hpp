/**
 * @file guesser.hpp
 * @author Tahseen Intesar
 * @brief Guessing the random Word 
 */

#include <iostream>
#include <algorithm>
#include <cstring>
#include "word_chooser.hpp"

class Guesser
{
    public:
    Guesser(int iWordLength_)
    {
        bMySolved = false;

        pclMyAnswer = new Word(iWordLength_);
        if(!pclMyAnswer)
        {
            printf("[ERROR] CREATING A NEW WORD.");
            exit(0);
        }

        szMyCurrentBoardState = (char*) malloc(iWordLength_);
        if(!szMyCurrentBoardState)
        {
            printf("[ERROR] BOARD START NULL.");
            exit(0);
        }
        memset(szMyCurrentBoardState, '_', sizeof(szMyCurrentBoardState));
    }

    void printBoard()
    {
        for (int i = 0; i < pclMyAnswer->getWordLength(); i++)
        {
            std::cout << szMyCurrentBoardState[i];
        }

        std::cout << "\n\n";
    }

    void checkGuess(std::string userGuess_)
    {
        iMyTurnCount++;

        // Convert inputs to uppercase
        std::transform(userGuess_.begin(), userGuess_.end(), userGuess_.begin(), ::toupper);

        // User's Guess is correct
        if (userGuess_ == pclMyAnswer->getAnswer())
        {
            bMySolved = true;
            return;
        }

        // At this point, the guess is incorrect, but it could contain some of the correct characters
        int wordLength = pclMyAnswer->getWordLength();
        
        // Temporarily get the string object for the answer, as we need the iterators
        std::string tmp = pclMyAnswer->getAnswer();

        // i iterates through the each character of the user's guess
        for (int i = 0; i < wordLength; i++)
        {
            // Check number of times this character appears in the answer
            int iNumOfCharRemainingInWord = std::count(tmp.begin(), tmp.end(), userGuess_.at(i));

            if (userGuess_.at(i) == pclMyAnswer->getAnswer().at(i))
            {
                // Character at this position matches
                szMyCurrentBoardState[i] = '*';

                // Here, check if there were any # for this character earlier. update the board state
                for(int j = 0; j < i; j++)
                {
                    if(szMyCurrentBoardState[j] == '#' && (userGuess_.at(j) == userGuess_.at(i)))
                    {
                        szMyCurrentBoardState[j] = '_';
                    }
                }
            }
            else
            {
                // Character could be in a later position
                // Assume the character does not appear later in the word
                char cCharacterToAdd = '_';

                if(iNumOfCharRemainingInWord == 0)
                {
                    // Character doesn't exist in the rest of the word
                    cCharacterToAdd = '_';
                }
                else
                {
                    // j iterates through the the characters in the answer
                    // Need to start from 0 in case the character occurs earlier in the string
                    for(int j = 0; j < wordLength; j++)
                    {
                        if(iNumOfCharRemainingInWord <= 0)
                        {
                            cCharacterToAdd = '_';
                            break;
                        }
                        else if(userGuess_.at(i) == pclMyAnswer->getAnswer().at(j) && (j < i))
                        {
                            if(szMyCurrentBoardState[j] == '*')
                            {
                                // Matches on an earlier position should already have a *
                                iNumOfCharRemainingInWord--;
                            }
                        }
                        else if (j > i)
                        {
                            // if the answer contains the character in a future value, then the current board state char should be '#'
                            // the board state will be updated when the for loop reaches there
                            cCharacterToAdd = '#';
                            iNumOfCharRemainingInWord--;
                            break;
                        }
                    }
                }

                szMyCurrentBoardState[i] = cCharacterToAdd;
            }
        }
    }

    bool isSolved()
    {
        return bMySolved;
    }

    int getTurnCount()
    {
        return iMyTurnCount;
    }

    private:
    // The answer
    Word *pclMyAnswer;

    // Current state of the board - variable length
    char *szMyCurrentBoardState;

    // Is the game solved?
    bool bMySolved;

    // How many turns it took
    int iMyTurnCount = 0;
};


/**
 * @file main.cpp
 * @author Tahseen Intesar
 * @brief wordle but the answer is just characters lol
 */

#include <iostream>
#include "guesser.hpp"

#define MIN_WORD_LENGTH 2
#define MAX_WORD_LENGTH 10
#define DEFAULT_WORD_LENGTH 5

int main()
{
    unsigned int uiGameOption = 0;
    unsigned int uiWordLength = DEFAULT_WORD_LENGTH;

    std::cout << "\n============= String Guesser ===============";

    std::cout << "\nEnter a game mode:" << std::endl;
    std::cout << "0) Randomized characters, 5 letters (default)" << "\n1) Randomized characters, user specified length\n>> ";
    std::cin >> uiGameOption;

    if(uiGameOption == 1)
    {
        std::cout << "How long should the string be?\n>> ";
        std::cin >> uiWordLength;

        // arbitrary string length limit
        if(uiWordLength > MAX_WORD_LENGTH)
        {
            std::cout << "Word length too big. Setting to " << MAX_WORD_LENGTH << std::endl;
            uiWordLength = MAX_WORD_LENGTH;
        }
        else if (uiWordLength < MIN_WORD_LENGTH)
        {
            std::cout << "Word length too small. Setting to " << DEFAULT_WORD_LENGTH << std::endl;
            uiWordLength = DEFAULT_WORD_LENGTH;
        }
    }
    else if (uiGameOption > 1)
    {
        std::cout << "Invalid Option. Setting game mode to default." << std::endl;;
        uiGameOption = 0;
        uiWordLength = DEFAULT_WORD_LENGTH;
    }

    // Generate a random string
    Guesser theGuesserGame(uiWordLength);

    // std::cout <<"\n[DEBUG] answer = " << theGuesserGame.pclMyAnswer->getAnswer() << std::endl;
    std::cout << "* = Correct Letter, Correct Spot\n# = Correct Letter, Wrong Spot\n_ = Wrong Letter\n\n";
    
    std::string userGuess;
    std::cout << "Guess a string that is " << uiWordLength << " characters long: \n";

    while (!theGuesserGame.isSolved())
    {
        theGuesserGame.printBoard();

        std::cout << ">> ";
        std::cin >> userGuess;

        if(userGuess == "Q")
        {
            std::cout << "Quitting the game.";
            return 0;
        }

        if (userGuess.length() != uiWordLength)
        {
            std::cout << "Please make sure that the guess is the right length.\nInputted characters: " << userGuess.length() << std::endl;
        }
        else
        {
            theGuesserGame.checkGuess(userGuess);
        }
    }

    std::cout << "\n\nYou won in " << theGuesserGame.getTurnCount() << " turns! Thanks for playing :)" << std::endl;
    return 0;
}

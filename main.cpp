/**
 * @file main.cpp
 * @author Tahseen Intesar
 * @brief wordle but the answer is just characters lol
 * @version 0.1
 * @date 2022-08-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "guesser.h"
//#include "word-chooser.h"

int main()
{
    Guesser guess;
    std::string userGuess = "";

    std::cout << "\nThe random word is: " << guess.getAnswer() << std::endl;

    std::cout << "Input a guess that is " << guess.getAnswerLength() << " letters long." << std::endl;
    while(!guess.isSolved())
    {
        guess.printBoard();
        std::cin >> userGuess;

        if (userGuess.length() != guess.getAnswerLength())
        {
            std::cout << "Please make sure that the guess is the right length." << std::endl;
        }
        else
        {
            guess.checkGuess(userGuess);
        }
    }

    std::cout << "\n\nYou beat the game!" << std::endl;

    return 0;
}
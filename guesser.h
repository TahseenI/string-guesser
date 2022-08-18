/**
 * @file guesser.h
 * @author Tahseen Intesar
 * @brief guessing the randomizer word
 * @version 0.1
 * @date 2022-08-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include "word-chooser.h"

class Guesser
{
    public:
    Guesser()
    {
        this->answer = new Word;
        this->initializeStats();

        std::cout << "guesser initialized\n\n";
    }

    void initializeStats()
    {
        //get the length of the word
        int s = this->answer->getSize();

        found = new char[s];

        //initialize char states to NOT_IN_WORD
        for(int i = 0; i < s; i++)
        {   
            char a = this->answer->getAnswer().at(i);

            uniques[a]++;
            found[i] = '_';
        }
        
    }

    void printBoard()
    {
        for (int i = 0; i < this->getAnswerLength(); i++)
        {
            std::cout << this->found[i];
        }

        std::cout << std::endl << std::endl;
    }

    void checkGuess(std::string guess)
    {
        //convert to uppercase
        std::transform(guess.begin(), guess.end(), guess.begin(), ::toupper);

        //right answer
        if ( guess == this->getAnswer() )
        {
            this->solved = true;
            return;
        }

        //wrong answer
        for(int i = 0; i < this->getAnswerLength(); i++)
        {
            if(guess[i] == this->answer->getAnswer()[i])
            {
                found[i] = 'O';
            }
            else if (uniques.find(guess[i]) != uniques.end())
            {
                found[i] = 'X';
            }
            else
            {
                found[i] = '_';
            }
        }
    }

    std::string getAnswer()
    {
        return this->answer->getAnswer();
    }

    int getAnswerLength()
    {
        return this->answer->getAnswer().length();
    }

    bool isSolved()
    {
        return this->solved;
    }

    private:
    Word *answer;

    //get all unique chars in the answer, and count number
    std::unordered_map<char, int> uniques;

    //current state of the game
    char *found;

    bool solved = false;
};


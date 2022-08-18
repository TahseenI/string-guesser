/**
 * @file guesser.h
 * @author Tahseen
 * @brief guessing the randomizer word
 * @version 0.1
 * @date 2022-08-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include "word-chooser.h"

class Guesser
{
    public:
    
    typedef enum {
        NOT_IN_WORD = 0,     //"grey"
        IN_WORD_WRONG_SPOT,  //"yellow"
        IN_WORD_RIGHT_SPOT   //"green"
    } charState_e;



    Guesser(Word w)
    {
        //get answer
        this->answer = w.getAnswer();

        //set all the stats
        this->initializeStats();

        std::cout << "guesser initialized\n\n";

    }

    void initializeStats()
    {
        //get the size of the word
        int s = this->answer.getSize();

        //set all the char states to NOT_IN_WORD
        this->answer_chars = new charState_e[s];
        for(int i = 0; i < s; i++)
        {
            answer_chars[i] = NOT_IN_WORD;
        }

        //parse all unique characters
        this->uniqueChars = new char[s];
        
    }

    

    private:
    std::string answer;

    char uniqueChars[];

    bool solved = false;

    charState_e answer_chars[];
};


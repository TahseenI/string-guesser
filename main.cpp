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

#include <iostream>
//#include "guesser.h"
#include "word-chooser.h"

int main()
{
    //test code
    //Word word;

    Word word;

    std::cout << "\nThe random word is: " << word.getAnswer() << std::endl;

    //Guesser guess = new Guesser(word);

    return 0;
}
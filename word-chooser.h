/**
 * @file word-chooser.h
 * @author Tahseen Intesar
 * @brief randomize or choose a 5 character string
 * @version 0.1
 * @date 2022-08-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <string>
#include <cstdlib>

class Word
{
    public:
    Word()
    {
        this->answer = generateWord();
        this->size   = (uint16_t) (this->answer.length());
    }
    
    /**
     * @brief randomize the string
     * 
     * @return std::string 
     */
    std::string generateWord() 
    {
        //randomizes based on time seed
        srand(time(NULL));

        std::string result;
        size_t len = characters.length(); 
        size_t size = 5;

        for (size_t i = 0; i < size; i++)
        {
            result += characters[rand() % len];
        }

        return result;
    }

    std::string getAnswer()
    {
        return this->answer;
    }

    uint16_t getSize()
    {
        return this->size;
    }



    private:

    //character bank
    const std::string characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    //stored word
    std::string answer = "";

    //length of the word
    int size;
};


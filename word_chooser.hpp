/**
 * @file word_chooser.hpp
 * @author Tahseen Intesar
 * @brief Create a randomized Word of varying length
 */

#include <string>
#include <cstdlib>

class Word
{
    public:
    Word(int iDesiredWordLength_)
    {
        printf("\n\nA %d letter word has been created.", iDesiredWordLength_);
        myAnswer = generateRandomWord(iDesiredWordLength_);
    }
    
    /**
     * @brief randomize the string
     * @return std::string 
     */
    std::string generateRandomWord(int iLengthOfWord_) 
    {
        myWordLength = iLengthOfWord_;
        
        // randomizes based on time seed
        srand(time(NULL));

        std::string result;
        size_t len = characterMap.length(); 
        for (size_t i = 0; i < myWordLength; i++)
        {
            result += characterMap[rand() % len];
        }

        return result;
    }

    std::string getAnswer()
    {
        return myAnswer;
    }

    int getWordLength()
    {
        return myWordLength;
    }

    private:
    // character map
    const std::string characterMap = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    // stored word
    std::string myAnswer = "";

    // length of the word
    int myWordLength;
};


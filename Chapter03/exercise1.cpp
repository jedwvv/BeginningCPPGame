//Program that asks users to unjumble words for some points.
//Practice of using string and array data types
//Extra features(not part of exercise): 
// - Whether to play more rounds
// - Losing points for incorrect guess and asking for hint

//Possible improvements for future versions of this program:
// - Allow the user(gamemaster) to add more words and hints for future playthroughs
// - "Game Rewards" upon reaching milestones, e.g.: after reaching 500 points tell user a funny joke.
// - Remembering highest scores.

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using std::string;
using std::cout;
using std::cin;
using std::endl;

string jumble(string word, int numberSwaps);

int scoreGame(string word, string hint);

int main()
{
    enum fields {WORD, HINT, NUM_FIELDS};
    const int NUM_WORDS = 5;
    const string WORDS[NUM_WORDS][NUM_FIELDS] =
    {
        {"wall", "Do you feel you're banging your head against something?"},
        {"glasses", "These might help you see the answer."},
        {"labored", "Going slowly, is it?"},
        {"persistent", "Keep at it."},
        {"jumble", "It's what the game is all about."}
    };

    cout << "\n\t\t\tWelcome to Word Jumble!";
    cout << "\n\nUnjumble the words for some points.";
    cout << "\nYou get 10 points per character of the word guessed correctly (5 letter word = 50 points)";
    cout << "\nbut -1 point per incorrect guess and -10 points for using the hint\n\n";

    bool keepPlaying = true;
    int choice;
    string theWord;
    string theHint;
    int gameScore;
    int totalScore = 0;
    string userInput;
    srand( static_cast<unsigned int>(time(0)));
    while (keepPlaying)
    {
        choice = (rand() % NUM_WORDS);
        theWord = WORDS[choice][WORD]; //Word to guess
        theHint = WORDS[choice][HINT]; //Hint for the word
        gameScore = scoreGame(theWord, theHint);
        if (gameScore == -1)
        {
            keepPlaying = false;
        }
        else
        {
            totalScore += gameScore;
            cout << "\nCurrent score: " << totalScore << " points";
            cout << "\nWould you like to play another round? (y/n): ";
            cin >> userInput;
            if (userInput == "n")
            {
                keepPlaying = false;
            }
        }
    }
    cout << "\nCongratulations, you scored a total of " << totalScore << " points.";
    cout << "\nIs that enough to buy a cookie or something nice?";
    cout << "\nThanks for playing!\n"; 
    return 0;
};

//Function that jumbles word by swapping characters numberSwaps times.
string jumble(string word, int numberSwaps)
{   
    int wordLength = word.size();
    string jumbledWord = word;
    for (int i=0; i < numberSwaps; ++i)
    {
        int index1, index2;
        index1 = rand() % wordLength;
        index2 = rand() % wordLength;
        while (index2 == index1) //Make sure index2 != index1
        {
            index2 = rand() % wordLength;
        }
        char temp = jumbledWord[index1];
        jumbledWord[index1] = jumbledWord[index2];
        jumbledWord[index2] = temp;
    }
    return jumbledWord;
}

//Function that loops through ONE game round which jumbles theWord for a maximum of points equal to 10 times word length.
//Return 0 if points are exhausted, -1 if user asks to quit, otherwise return gameScore if user guesses correctly.
int scoreGame(string theWord, string theHint)
{   
    //Initialize score as 10 times the word length.
    int gameScore = theWord.size();
    gameScore *= 10;

    //Jumble the word.
    string jumbledWord = jumble(theWord, theWord.size());

    // Game Loop starts here asking user to un-jumble word.
    cout << "\nFor a maximum of " << gameScore << " points, can you unjumble these letters to form a word? ";
    string guess;
    guess = "";
    while ((guess != theWord) && (guess != "quit") && (gameScore > 0) && (guess != "skip"))
    {   
        cout << "\nEnter 'quit' to quit program, 'skip' to skip this word, or 'hint' for a hint(-10 points), ";
        cout << "\nJumbled word: " << jumbledWord;
        cout << "\nYour answer: ";
        cin >> guess;
        if (guess == "hint") 
        {   
            gameScore -= 10;
            cout << "\n[Hint]: " << theHint << " (" << gameScore << " points remaining.)"; 
        }
        else if ( (guess != theWord) && (guess != "quit") && (guess != "skip") )
        {   
            gameScore -= 1;
            cout << "\nSorry, that's not quite right. Try again. (" <<  gameScore << " points remaining)";
        }
    }

    if ( guess == "quit" ) //Return invalid gameScore to signal the exit of program.
    {
        return -1; 
    }

    if ( guess == "skip" ) //Return a gameScore of 0 when skipping the word.
    {
        cout << "\nGood luck for next time!"; 
        return 0; 
    }


    if ( gameScore <= 0 ) //Return a minimum of 0 points, even if the value ends up below 0.
    {
        cout << "\nSorry, you've exhausted all points for this word."; 
        return 0; 
    }

    if ( gameScore <= 0 ) //Return a minimum of 0 points, even if the value ends up below 0.
    {
        cout << "\nSorry, you've exhausted all points for this word."; 
        return 0; 
    }

    if ( guess == theWord ) //Otherwise, return remaining gameScore if user guesses the word correctly.
    {
        cout << "\nYou guessed the right answer! Here is " << gameScore << " points for you. ";
        return gameScore;
    }

    return 0;
}



// Instructions
// Demonstrates writing new functions
#include <iostream>
using namespace std;

// function prototype (declaration)
void instructions();

int main()
{
instructions();
return 0;
}
// function definition
void instructions()
{
cout << "Welcome to the most fun you’ve ever had with text!\n\n";
cou<< "Here’s how to play the game...\n";
}
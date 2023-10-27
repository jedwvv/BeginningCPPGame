// Make a Hangman Game with functions that 1) ask for player's guess, 2) check player's guess
// Extra features
// - Also modify currentGuess in place right after checking if the player's guess is correct!
// -  ^ this is achieved by passing a reference.           
// - print hangman depending on number of guesses left. Good use of switch structure (case 1, case 2, ....) 
// - Send a command to system to clear output each time a guess is made.

// Possible additions
//  - Use a new word from a set of possible words, e.g. get a word from a dataset of existing English words.
//  - Multiple rounds with scoring depending on word length and number of guesses.

#include <iostream>
#include <string>
using namespace std;

//Function prototypes
string askPlayer(string question);
bool checkPlayerGuess(string letterGuess, string finalWord, string& currentGuess);
void printHangman(int incorrectGuesses);

int main()
{   
    system("clear");
    string finalWord = "CHICKEN";
    string letterGuess;
    bool correctGuess;
    string currentGuess;
    int wordSize = finalWord.size();
    cout << "\n\t\tLet's play hangman!\n";
    cout << "\nCan you guess the word?";
    for (int idx=0 ; idx < wordSize; ++idx)
    {   
        currentGuess += "-";   
    }

    int incorrectGuesses = 0;
    cout << "\nword: " << currentGuess;
    while (incorrectGuesses < 10 && currentGuess != finalWord)
    {   
        
        cout << "\nYou have " << 10-incorrectGuesses << " guesses remaining.";
        letterGuess = askPlayer("\nEnter a letter: ");
        correctGuess = checkPlayerGuess(letterGuess, finalWord, currentGuess);
        system("clear");
        if (correctGuess)
        {
            cout << "\nYou guessed a letter correctly!";
        }
        else
        {   
            cout << "\nTry Again.";
            incorrectGuesses += 1;
        }
        printHangman(incorrectGuesses);
        cout << "\nword: " << currentGuess;
    }

    if (incorrectGuesses >= 10)
    {
        cout << "\nSorry, you have no more guesses. Thanks for playing!\n\n";
    }
    else
    {
        cout << "\nCongratulations! You guessed " << currentGuess << ".\n\n"; 
    }
    
    return 0;
}

//Ask player a question and return the response string.
string askPlayer(string question)
{
    string response;
    cout << question;
    cin >> response;
    return response;
}

//Returns true/false if the guess is correct
bool checkPlayerGuess(string letterGuess, string finalWord, string& currentGuess)
{   
    //First check if the guess contains only one character,
    //If not, it is invalid and function returns
    if (letterGuess.size() != 1)
        {
            cout << "\nSorry, that was an invalid guess.";
            return false;
        }
    char letterCheck = toupper(letterGuess[0]);
    int wordSize = finalWord.size();
    bool correctGuess = false;
    for (int idx = 0; idx < wordSize; ++idx)
    {
        if (letterCheck ==  finalWord[idx] )
        {
            currentGuess[idx] = letterCheck;
            correctGuess = true;
        }   
    }
    return correctGuess;
}

void printHangman(int incorrectGuesses)
{
    switch(incorrectGuesses)
    {
        case 0:
            cout << "\n";
            cout << "\n";
            cout << "\n";
            cout << "\n";
            cout << "\n";
            cout << "\n";
            break;
        
        case 1:
            cout << "\n";
            cout << "\n" ;
            cout << "\n";
            cout << "\n" ;
            cout << "\n";
            cout << "\n‾‾‾‾‾‾";
            break;

        case 2:
            cout << "\n";
            cout << "\n|" ;
            cout << "\n|";
            cout << "\n|" ;
            cout << "\n|";
            cout << "\n‾‾‾‾‾‾";
            break;

        case 3:
            cout << "\n_____";
            cout << "\n|" ;
            cout << "\n|";
            cout << "\n|" ;
            cout << "\n|";
            cout << "\n‾‾‾‾‾‾";
            break;

        case 4:
            cout << "\n_____";
            cout << "\n|  |" ;
            cout << "\n|";
            cout << "\n|" ;
            cout << "\n|";
            cout << "\n‾‾‾‾‾‾";
            break;

        case 5:
            cout << "\n_____";
            cout << "\n|  |" ;
            cout << "\n|  O";
            cout << "\n|" ;
            cout << "\n|";
            cout << "\n‾‾‾‾‾‾";
            break;

        case 6:
            cout << "\n_____";
            cout << "\n|  |" ;
            cout << "\n|  O";
            cout << "\n|  |" ;
            cout << "\n|";
            cout << "\n‾‾‾‾‾‾";
            break;

        case 7:
            cout << "\n_____";
            cout << "\n|  |" ;
            cout << "\n|  O";
            cout << "\n| \\|" ;
            cout << "\n|";
            cout << "\n‾‾‾‾‾‾";
            break;

        case 8:
            cout << "\n_____";
            cout << "\n|  |" ;
            cout << "\n|  O";
            cout << "\n| \\|/" ;
            cout << "\n|";
            cout << "\n‾‾‾‾‾‾";
            break;

        case 9:
            cout << "\n_____";
            cout << "\n|  |" ;
            cout << "\n|  O";
            cout << "\n| \\|/" ;
            cout << "\n|  ⅃";
            cout << "\n‾‾‾‾‾‾";
            break;

        case 10:
            cout << "\n_____";
            cout << "\n|  |" ;
            cout << "\n| (X)";
            cout << "\n| \\|/" ;
            cout << "\n|  ⅃L";
            cout << "\n‾‾‾‾‾‾";
    }
}
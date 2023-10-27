//Program that asks users for a number and the computer keeps guessing at it.

//Extra features not part of exercise:
// - Terminating of program if user puts in nonsensical values.
// - Allowing user to tell computer range of values to guess from

//Possible improvements for future versions of this program:
// - Allow user to say "more" or "less" instead of the computer knowing.
// - Ask the user for another round and keep track of guesses.

#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cin;
using std::cout;
using std::endl;

int main()
{   
    int minValue;
    int maxValue;

    cout << "What is the minimum number to guess from? ";
    cin >> minValue;
    if (!cin.good())
    {   
        cout << "\nI don't know that number.\n";
        return -1;
    }

    cout << "What is the maximum number to guess up to (including)? ";
    cin >> maxValue;
    if (!cin.good() || maxValue < minValue)
    {
        cout << "\nThat's not a valid maximum value!\n";
        return -1;
    }
    int userNumber = minValue - 1;

    cout << "Enter your integer number for me(the computer) to guess: "; 
    cin >> userNumber;
    if (!cin.good() || userNumber < minValue || userNumber > maxValue)
    {
        cout << "\nI don't know that number or its outside your specified range.\n";
        return -1;
    }
    
    int range = maxValue - minValue + 1;
    srand(static_cast<unsigned int>(time(0))); //Seed using current time
    int randomNumber = rand() % range + minValue;
    int computerGuesses = 1;
    while (randomNumber!=userNumber)
    {   
        cout << "\nGuess " << computerGuesses << ": " << randomNumber; 
            if (randomNumber < userNumber)
            {
                cout << "\nI sense this is less than your number.\n";
                minValue = randomNumber + 1;
                range = maxValue - minValue + 1;
                randomNumber = ( rand() % range ) + minValue;
            }
            else if (randomNumber > userNumber)
            {
                cout << "\nI sense this is more than your number.\n";
                maxValue = randomNumber - 1;
                range = maxValue - minValue + 1;
                randomNumber = ( rand() % range ) + minValue;
            }
            else
            {
            }
        ++computerGuesses;
    }
    cout << "\nI guessed your number: " << randomNumber;
    cout << "\nIt took me " << computerGuesses << " tries.\n";
    return 0;
}
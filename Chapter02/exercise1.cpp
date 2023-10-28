// This program is a MENU chooser of 4 difficulties, taking user input
// Extra features not part of exercise:
//  - Extra difficulty level
//  - Use of arrays and while loops for convenient printing to
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{  
    enum difficulty {NEWBIE=1, EASY, NORMAL, HARDCORE};
    char* difficulties[] = {"", "NEWBIE", "EASY", "NORMAL", "HARDCORE"};
    cout << "\nDifficulty Levels\n";
    cout << "1 - NEWBIE\n";
    cout << "2 - EASY\n";
    cout << "3 - NORMAL\n";
    cout << "4 - HARDCORE\n\n";

    int difficultyLevel = 0;
    while (difficultyLevel > 4 || difficultyLevel < 1)
    {
        cout << "Pick Difficulty Level(rounded down): ";
        cin >> difficultyLevel;
        if (!cin.good())
        {
            cout << "You picked a non-numeric value which is invalid.\n";
            return -1; //Force end program after invalid input
        }
        if (difficultyLevel > 4 || difficultyLevel < 1)
        {
            cout << "Choose a level from 1 to 4\n" << endl;
        }
    }
    
    cout << "You picked " << difficulties[difficultyLevel] << endl; 

    return 0;
}

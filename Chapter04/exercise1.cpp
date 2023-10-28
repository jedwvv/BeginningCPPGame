//Program to let user maintain a list of favorite (or non favorite!) games
//Practice of using STD Library algorithms with vectors and iterators
//Own idea: when inserting a new gametitle, rate it out of 5
//Main menu: Ask user whether to INSERT, REMOVE, and VIEW(all) game titles.
//Functions: INSERT, REMOVE, VIEWSCORES, VIEWLIST
//Helper function: askUserYesNo return true/false when user types yes/no

//Possible improvements for future versions of this program: 
// - Saving and loading of existing game lists, with multiple possible lists.
// - Sorting game list by inputted score.
// - Multiple input in one prompt (e.g. gameTitle gameScore) separated by a space for user convenience.


#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
using namespace std;

//Define global vector with starting capacity of up to 100 titles
//Define also a map for pairs of (gameTitle, ratingScore)
vector<string> gameList;
map<string, float> gameScores;

int insertTitle();
int removeTitle();
int viewGameList();
int viewGameScores();
bool askUserYesNo();

int main()
{       
    //Ask User input whether to INSERT, REMOVE or VIEW or QUIT

    string userInput = "add";
    bool viewScore;
    while (userInput == "add" || userInput == "remove" || userInput == "view")
    {
        cout << "\n\nWould you like to ADD to, REMOVE from, or VIEW your list?";
        cout << "\nNote: To update a game score, simply re-enter new score with the same name.";
        cout << "\n[Enter 'add', 'remove', 'view', or 'quit' to quit]: ";
        cin >> userInput;

        if (userInput == "add")
        {
            insertTitle();
        }
        else if (userInput == "remove")
        {
            removeTitle();
        }
        else if (userInput == "view")
        {
            if (gameList.size() == 0)
            {   
                cout << "\n________________________________________________";
                cout << "\nYour list is currently empty."; 
                cout << "\n________________________________________________";
            }
            else
            {
                cout << "\nWould you like to view the games list including your scores?";
                bool viewScore = askUserYesNo();
                if (viewScore)
                {
                    viewGameScores();
                }
                else
                {
                    viewGameList();
                }
            }
           
        }
        else{}
    }
    if (userInput == "quit")
    {
        cout << "\nHave a good day!\n";
    }
    else
    {
        cout << "\nThat was an invalid input. Terminating program...\n";
    }

    return 0;
}

int insertTitle()
{
    vector<string>::const_iterator iter;
    bool keepAdding = true;
    string userInput = "";
    while (keepAdding)
    {
        string gameTitle;
        float ratingScore;
        cout << "\nEnter a game title to add to your list: ";
        cin >> gameTitle;
        cout << "\nWhat would you rate this game out of 5?";
        ratingScore = -1;
        while ( ratingScore < 0.0 || ratingScore > 5.0 )
        {
            cout << "\n[Enter value between 0.0 and 5.0]: ";
            cin >> ratingScore;

            //Return the function, stopping the loop if user provides a bad value
            if (!cin.good())
            {
                return -1;
            }
        }
        gameScores[gameTitle] = ratingScore;

        //First, make sure it is not already in vector before adding
        iter = find(gameList.begin(), gameList.end(), gameTitle);
        if ( iter == gameList.end() )
        {
            gameList.push_back(gameTitle);
            cout << "\nYou added '" << gameTitle << "' with a score of " << ratingScore << "."; 
        }
        else
        {
            cout << "\nYou updated the score of '" << gameTitle << "'.";
        }
        cout << "\nWould you like to update or add another game title?";
        keepAdding = askUserYesNo();
    }
    return 0;
}

int removeTitle()
{
    vector<string>::const_iterator iter;
    string gameTitle;
    string userInput = "";
    bool keepRemoving = true;
    while (keepRemoving)
    {
        cout << "\nWhat would you like to remove from the list? ";
        cin >> gameTitle;
        
        //First, make sure it is in the records
        iter = find(gameList.begin(), gameList.end(), gameTitle);
        if ( iter == gameList.end() )
        {
            cout << "\nThis is not in the list. Skipping...";
        }
        else
        {   
            gameList.erase( iter );
            gameScores.erase( *iter );
            cout << "\nYou removed '" << gameTitle << "' from the records.";
        }
        cout << "\nWould you like to remove another game title?";
        keepRemoving = askUserYesNo();
    }
    return 0;
}

int viewGameList()
{   
    vector<string>::const_iterator iter;
    cout << "\n________________________________________________";
    cout << "\nHere are your games sorted from oldest to newest";
    cout << "\n________________________________________________";
    for (iter=gameList.begin(); iter!=gameList.end(); ++iter)
    {
        cout << "\n\t-" << *iter;
    }
    return 0;
}

int viewGameScores()
{   
    map<string, float>::const_iterator iter;
    cout << "\n________________________________________________";
    cout << "\nHere are your games sorted from oldest to newest";
    cout << "\n________________________________________________";
    for (iter=gameScores.begin(); iter!=gameScores.end(); ++iter)
    {
        cout << "\n\t-" << iter->first << "(" << iter->second << ")";
    }
    return 0;
}

bool askUserYesNo()
{   
    bool userResponse = true;
    bool keepAsking = true;
    string inputYesNo = "";
    while (keepAsking)
    {
        cout << "\n[Enter 'yes' or 'no']: ";
        cin >> inputYesNo;
        if (inputYesNo == "yes")
        {
            keepAsking = false;
        }
        else if (inputYesNo == "no")
        {
            userResponse = false;
            keepAsking = false;
        }
        else{}
    }
    return userResponse;
}
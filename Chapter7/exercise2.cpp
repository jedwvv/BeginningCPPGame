// Original Mad Lib Program saved in a separate file, directly copied from the book
// Goal: Identify where POINTERS can be used (specifics below)
//      - We can use pointers in place of references in Chapter6/exercise1.cpp

// Using the ideas above, we can have EXACTLY ONE object for each important variable.
// Functions do not ever (copy) or make new objects.
// Implementation details:
//      1) Declare the variables ONLY in main.
//      2) Pass only pointers to constants and constant pointers to constants to functions


//Note: most content is copy pasted with the sole purpose of making the passing of arguments more efficient.
//Looking at the function prototype, only references are ever passed, and references are returned.

#include <iostream>
#include <string>
using namespace std;
void askText(const string* const prompt, string* const response);
void askNumber(const string* const prompt, int* const response);
void tellStory(const string* const name, const string* const noun, const int* const number, const string* const bodyPart, const string* const verb);

int main()
{
    cout << "Welcome to Mad Lib.\n\n";
    cout << "Answer the following questions to help create a new story.\n";
    
    //Declare important variables to store values from user
    string name; 
    string noun;
    int number;
    string bodyPart;
    string verb;

    string prompt = "Please enter a name: ";
    askText(&prompt, &name);
    prompt = "Please enter a plural noun: ";
    askText(&prompt, &noun);
    prompt = "Please enter a number: ";
    askNumber(&prompt, &number);
    prompt = "Please enter a body part: ";
    askText(&prompt, &bodyPart);
    prompt = "Please enter a verb: ";
    askText(&prompt, &verb);

    tellStory(&name, &noun, &number, &bodyPart, &verb);
    cout << "\n\n";
    return 0;
}

//Inputs: constant pointer to constant[prompt] and constant pointer[response].
// constant pointer to constant for 'prompt' since it is unchanged in function and it does not change what it points to.
// constant pointer for 'response' since its value changes but it does not change what it points to.
void askText(const string* const prompt, string* const response)
{
    cout << *prompt;
    cin >> *response;
}   

//Same as askTest but using a pointer to integer data type instead.
void askNumber(const string* const prompt, int* const response)
{
    cout << *prompt;
    cin >> *response;
}

void tellStory(const string* const name, const string* const noun, const int* const number, const string* const bodyPart, const string* const verb)
{
    cout << "\nHere’s your story:\n";
    cout << "The famous explorer ";
    cout << *name;
    cout << " had nearly given up a life-long quest to find\n";
    cout << "The Lost City of ";
    cout << *noun;
    cout << " when one day, the ";
    cout << *noun;
    cout << " found the explorer.\n";
    cout << "Surrounded by ";
    cout << *number;
    cout << " " << *noun;
    cout << ", a tear came to ";
    cout << *name << "’s ";
    cout << *bodyPart << ".\n";
    cout << "After all this time, the quest was finally over. ";
    cout << "And then, the ";
    cout << *noun << "\n";
    cout << "promptly devoured ";
    cout << *name << ". ";
    cout << "The moral of the story? Be careful what you ";
    cout << *verb;
    cout << " for.";
}
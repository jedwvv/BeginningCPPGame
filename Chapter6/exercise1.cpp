// Original Mad Lib Program saved in a separate file, directly copied from the book
// Goal: Identify where references can be used (specifics below)
//      -   Each string literal can be referenced to avoid making copies.
//      -   Use constant references for user prompts, since the function does not modify them.
//      -   Use non-constant references for user inputs which are returned also as references.

// Using the ideas above, we can have EXACTLY ONE object for each important variable.
// Functions do not ever (copy) or make new objects.
// Implementation details:
//      1) Declare the variables ONLY in main.
//      3) Passing those variables as references to the functions to be modified in place, so no return values are required.
//      4) Additionally, the prompts are passed as constant references


//Note: most content is copy pasted with the sole purpose of making the passing of arguments more efficient.
//Looking at the function prototype, only references are ever passed and nothing is returned(so nothing is copied)
#include <iostream>
#include <string>
using namespace std;
void askText(const string& prompt, string& response);
void askNumber(const string& prompt, int& response);
void tellStory(const string& name, const string& noun, const int& number, const string& bodyPart, const string& verb);

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

    //Unmodified flow of Mad Lib program
    askText("\nPlease enter a name: ", name);
    askText("\nPlease enter a plural noun: ", noun);
    askNumber("\nPlease enter a number: ", number);
    askText("\nPlease enter a body part: ", bodyPart);
    askText("\nPlease enter a verb: ", verb);

    tellStory(name, noun, number, bodyPart, verb);
    return 0;
}

void askText(const string& prompt, string& response)
{
    cout << prompt;
    cin >> response;
}

void askNumber(const string& prompt, int& response)
{
    cout << prompt;
    cin >> response;
}

void tellStory(const string& name, const string& noun, const int& number, const string& bodyPart, const string& verb)
{
    cout << "\nHere’s your story:\n";
    cout << "The famous explorer ";
    cout << name;
    cout << " had nearly given up a life-long quest to find\n";
    cout << "The Lost City of ";
    cout << noun;
    cout << " when one day, the ";
    cout << noun;
    cout << " found the explorer.\n";
    cout << "Surrounded by ";
    cout << number;
    cout << " " << noun;
    cout << ", a tear came to ";
    cout << name << "’s ";
    cout << bodyPart << ".\n";
    cout << "After all this time, the quest was finally over. ";
    cout << "And then, the ";
    cout << noun << "\n";
    cout << "promptly devoured ";
    cout << name << ". ";
    cout << "The moral of the story? Be careful what you ";
    cout << verb;
    cout << " for.";
}
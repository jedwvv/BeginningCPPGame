// This program is a SCORER taking user input and then calculating the average score
// Extra features not part of exercise:
//  - Use of arrays with a predefined number of scores
//  - Use of arrays and while loops for convenient storing of all scores

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

int main()
{   
    int numScores;
    cout << "\nHow many scores(rounded down) would you like to record? ";
    cin >> numScores;
    if (!cin.good() || numScores < 0)
    {
        cout << "\nThat's not a valid number of scores. Terminating...";
        return -1;
    }
    cout << "\nRecording " << numScores << " scores.\n";
    long double scores[numScores]; 
    int idx = 0;
    long double averageScore = 0;
    long double score;
    for (int idx = 0; idx < numScores; ++idx)
    {
        cout << "Enter Score " << idx+1 << ": ";
        cin >> score;
        scores[idx] = score;
        averageScore += score;
    }
    for (int idx = 0; idx < numScores; ++idx)
    {
        cout << "Score " << idx+1 << ": " << scores[idx] << endl;
    } 
    averageScore /= numScores;
    cout << 
        "____________________" << "\n" <<
        "Average Score: " << averageScore <<
    endl;
    return 0;
}
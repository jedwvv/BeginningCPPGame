//Original code from Chapter 8 except for the following addition,
// - Member function Critter::Reveal as per exercise1
// - When calling member functions, critter hints at its stats as per exercise 2
//      - This was achieved by adding private member function Critter::Express().
//      - Express() is then called each time PassTime() is called.

//Critter Caretaker
//Simulates caring for a virtual pet
#include <iostream>
using namespace std;

class Critter
{
    public:
        Critter(int hunger = 0, int boredom = 0);
        void Talk();
        void Eat(int food = 4);
        void Play(int fun = 4);
        void Reveal(); //Add Critter::Reveal to secretly reveal stats
    private:
        int m_Hunger;
        int m_Boredom;
        int GetMood() const;
        void PassTime(int time = 1);
        void Express(); //Add Critter::Express to hint at mood
};

Critter::Critter(int hunger, int boredom):
    m_Hunger(hunger),
    m_Boredom(boredom)
    {
    }

inline int Critter::GetMood() const
{
    return (m_Hunger + m_Boredom);
}

void Critter::PassTime(int time)
{
    m_Hunger += time;
    m_Boredom += time;
    Express(); //Express if hungry, bored or both.
}

void Critter::Express()
{
    if (GetMood() > 10) //Will only express needs when it gets frustrated.
    {
        if ( m_Hunger > m_Boredom ) //More hungry than bored.
        {
            cout << "Do you have something yum?\n"; 
        }
        else if (m_Hunger < m_Boredom) //More bored than hungry
        {
            cout << "Can we play? ...Please?\n";
        }
        else //Equally bored AND hungry
        {
            cout << "x_x\n";
        }
    }
        
}

void Critter::Talk()
{
    cout << "I’m a critter and I feel ";
    int mood = GetMood();
    if (mood > 15)
    {
        cout << "mad.\n";
    }
    else if (mood > 10)
    {
        cout << "frustrated.\n";
    }
    else if (mood > 5)
    {
        cout << "okay.\n";
    }
    else
    {
        cout << "happy.\n";
    }
    PassTime();
}

void Critter::Eat(int food)
{
    cout << "Brruppp.\n";
    m_Hunger -= food;
    if (m_Hunger < 0)
    {
        m_Hunger = 0;
    }
    PassTime();
}

void Critter::Play(int fun)
{
    cout << "Wheee!\n";
    m_Boredom -= fun;
    if (m_Boredom < 0)
    {
        m_Boredom = 0;
    }
    PassTime();
}

void Critter::Reveal()
{
    cout << "CRITTER CURRENT STATS:";
    cout << "\nhunger: " << m_Hunger;
    cout << "\nboredom: " << m_Boredom;
}

int main()
{
    Critter crit;
    crit.Talk();
    int choice;
    do
    {
        cout << "\nCritter Caretaker\n\n";
        cout << "0 - Quit\n";
        cout << "1 - Listen to your critter\n";
        cout << "2 - Feed your critter\n";
        cout << "3 - Play with your critter\n\n";
        cout << "Choice: ";
        cin >> choice;
        switch (choice)
        {
            case 0:
                cout << "Good-bye.\n";
                break;
            case 1:
                crit.Talk();
                break;
            case 2:
                crit.Eat();
                break;
            case 3:
                crit.Play();
                break;
            case 999: //Unlisted but the choice exists under the hood
                crit.Reveal();
                break;
            default:
                cout << "\nSorry, but " << choice << " isn’t a valid choice.\n";
        }
    } while (choice != 0);
    return 0;
}
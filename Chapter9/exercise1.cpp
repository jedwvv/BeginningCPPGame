//MOSTLY COPIED FROM game_lobby.cpp - additions or modifications are described.
//Exercise goals:
// 1) Write a friend function of Player class that sends Player object to cout.
// 2) Update the overloaded << function in Lobby class to use the new friend function of Player class.

// Game Lobby
// Simulates a game lobby where players wait

#include <iostream>
#include <string>

using namespace std;

class Player
{
    friend ostream& operator<<(ostream& os, const Player& aPlayer); //Prototype of friend function of Player class to send Player object to cout (Goal 1)

public:
	Player(const string& name = " ");
	string GetName() const;
	Player* GetNext() const;
	void SetNext(Player* next);

	
private:
	string m_Name;
	Player* m_pNext;	// Pointer to next player in list
};

Player::Player(const string& name):
	m_Name(name),
	m_pNext(0)			// null pointer
{}

ostream& operator<<(ostream& os, const Player& aPlayer) //Definition of friend function declared in prototype (Goal 1)
{   
    //Send player name to the object referenced by os
    os << aPlayer.GetName(); 
    return os;
}

string Player::GetName() const
{
	return m_Name;
}

Player* Player::GetNext() const
{
	return m_pNext;
}

void Player::SetNext(Player* next)
{
	m_pNext = next;
}

class Lobby
{
	friend ostream& operator<<(ostream& os, const Lobby& aLobby);
	
public:
	Lobby();
	~Lobby();
	void AddPlayer();
	void RemovePlayer();
	void Clear();
	
private:
	Player* m_pHead;
};

Lobby::Lobby():
	m_pHead(0)			// null pointer
{}

Lobby::~Lobby()
{
	Clear();
}

void Lobby::AddPlayer()
{
	// create a new player node
	cout << "Please enter a name of the new player: ";
	string name;
	cin >> name;
	Player* pNewPlayer = new Player(name);
	

    // TEST for Goal 1). Check if the program prints the m_Name of the last Player object within Lobby object.
    // Send to cout the object "Player from heap memory pNewPlayer is pointing to".
    cout << "The last player added is: ";
    cout << *pNewPlayer << endl; 

	// if list is empty, make head of list this new player
	if (m_pHead == 0)
	{
		m_pHead = pNewPlayer;
	}
	// otherwise find the end of the list and add the player there
	else
	{
		Player* pIter = m_pHead;
		while (pIter->GetNext() != 0)
		{
			pIter = pIter->GetNext();
		}
		pIter->SetNext(pNewPlayer);
	}
}

void Lobby::RemovePlayer()
{
	if (m_pHead == 0)
	{
		cout << "The game lobby is empty.	No one to remove!\n";
	}
	else
	{
		Player* pTemp = m_pHead;
		m_pHead = m_pHead->GetNext();
		delete pTemp;
	}
}

void Lobby::Clear()
{
	while (m_pHead != 0)
	{
		RemovePlayer();
	}
}

ostream& operator<<(ostream& os, const Lobby& aLobby)
{
	Player* pIter = aLobby.m_pHead;
	os << "\nHere's who's in the game lobby:\n";
	if (pIter == 0)
	{
		os << "The lobby is empty.\n";
	}
	else
	{
		while (pIter != 0)
		{   
            //Goal 2) changed pIter->GetName() to use the overloaded << friend function of Player class instead of the GetName() member function of Player class.
			os << *pIter << endl; // Achieves the exact same thing as the original code: ' os << pIter->GetName() << endl; '
			pIter = pIter->GetNext();
		}
	}
	
	return os;
}

int main()
{
	Lobby myLobby;
	int choice;
	
	do
	{
		cout << myLobby;
		cout << "\nGAME LOBBY\n";
		cout << "0 - Exit the program\n";
		cout << "1 - Add a player to the lobby\n";
		cout << "2 - Remove a player from the lobby\n";
		cout << "3 - Clear the lobby\n";
		cout << endl << "Enter a choice: ";
		cin >> choice;
		
		switch (choice)
		{
			case 0: cout << "Good-bye\n"; break;
			case 1: myLobby.AddPlayer(); break;
			case 2: myLobby.RemovePlayer(); break;
			case 3: myLobby.Clear(); break;
			default: cout << "That was not a valid choice\n";
		}
	} while (choice != 0);
	
	return 0;
}
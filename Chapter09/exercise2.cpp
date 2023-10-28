//MOSTLY COPIED FROM game_lobby.cpp - additions or modifications are described.
//Exercise goal:
// - Modify AddPlayer() of Lobby class to make it more efficient by using a new pointer to the last Player object in Lobby object

// Game Lobby
// Simulates a game lobby where players wait

#include <iostream>
#include <string>

using namespace std;

class Player
{
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
    Player* m_pTail; //Exercise goal: Declare private pointer to m_pTail that should point to last Player object in Lobby.
};

Lobby::Lobby():
	m_pHead(0), // null pointer
    m_pTail(0) // Exercise goal: assign null pointer, just like m_pHead above.
{}

Lobby::~Lobby()
{
	Clear();
}

//Added more comments in order to understand flow for the exercise goal of using m_pTail pointer pointing to last Player in Lobby.
void Lobby::AddPlayer()
{
	// create a new player node
	cout << "Please enter a name of the new player: ";
	string newName; // Renamed variable to newName to make clearer that this is the name of the NEW Player object to be added.
	cin >> newName;
	Player* pNewPlayer = new Player(newName); // pNewPlayer is a pointer pointing to a Player object in heap named newName.
	
	// if list is empty, make this new Player the head
    // also make this new Player the tail
    // More specifically, assign the pointers m_pHead AND m_pTail to the same Player object in heap that pNewPlayer is pointing to.
	if (m_pHead == 0)
	{
		m_pHead = pNewPlayer;
        m_pTail = pNewPlayer;
	}

	// Original code is commented below to see the unmodified flow.
    // Specifically, it makes a pointer that iterates through EACH of the Players until the Player's m_pNext pointer is the null pointer, indicating it is the last Player.
	// else
	// {
	// 	Player* pIter = m_pHead; 
	// 	while (pIter->GetNext() != 0)
	// 	{
	// 		pIter = pIter->GetNext();
	// 	}
	// 	pIter->SetNext(pNewPlayer);
	// }

    else // Since we have a pointer to the last Player, we can skip the iterating step!
    {
        m_pTail->SetNext(pNewPlayer); // This makes m_Next of last Player point to the new Player.
        m_pTail = pNewPlayer; // We still need to update the last Player to the new Player.
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
			os << pIter->GetName() << endl;
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
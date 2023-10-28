// Most of the code is copied from abstract_creature.cpp
// Exercise goal: Derive a OrcBoss class from Orc class with 180 health, overrides the Orc::Greet() member function.

// Abstract Creature
// Demonstrates abstract classes

#include <iostream>

using namespace std;

class Creature	// abstract class
{
public:
	Creature(int health = 100);
	virtual void Greet() const = 0;		// pure virtual member function
	virtual void DisplayHealth() const;
	
protected:
	int m_Health;
};

Creature::Creature(int health):
	m_Health(health)
{}

void Creature::DisplayHealth() const
{
	cout << "Health: " << m_Health << endl;
}

class Orc : public Creature
{
public:
	Orc(int health = 120);
	virtual void Greet() const;
};

Orc::Orc(int health):
	Creature(health)
{}

void Orc::Greet() const
{
	cout << "The orc grunts hello.\n";
}

//Exercise: Added OrcBoss class derived from Orc Class
class OrcBoss : public Orc
{
public:
	OrcBoss(int health = 180);
	virtual void Greet() const; //override Orc::Greet()
};

//Instead of Creature(health) like in Orc class, we need to use Orc(health) since Orc::Orc is what is inherited from Orc class and not Orc::Creature
//But under Orc::Orc() constructor, we see it calls Creature(health), so this still uses the Creature's original constructor ultimately
OrcBoss::OrcBoss(int health):
	Orc(health) 
{}

void OrcBoss::Greet() const
{
	cout << "The orc boss growls *hello*\n";
}


//To test my new OrcBoss classes in the main body, I use two methods of creating the same OrcBoss object with different pointers.
//The first pointer is a new pointer called pCreature2.
//The second pointer re-uses the pointer pCreature1, freeing the Orc object in heap first.
int main()
{
	Creature* pCreature = new Orc();
	pCreature->Greet();
	pCreature->DisplayHealth();

    //Before freeing Orc object, print its address to compare with OrcBosses later.
    cout << "--Orc lived in heap memory address: " << pCreature << "--"; 

    // ==== Using a 2nd pointer pCreature2 ====
    Creature* pCreature2 = new OrcBoss(); //Create NEW OrcBoss object in heap and the pointer to it is pCreature2.

    // ==== Re-using the pCreature pointer ====
    cout << "\n\nFreeing Orc and creating OrcBoss.\n"; 
    delete pCreature; // Free memory associated to Orc pointed to by pCreature.
    pCreature = new OrcBoss(); // Re-assign pointer pCreature to a newly allocated OrcBoss().
    
    // Now if I use either pointers it should display the same thing, since they both generate equivalent OrcBoss objects.
    cout << "\nOrcBoss 1: \n";
    pCreature->Greet();
    pCreature->DisplayHealth();
    cout << "\nOrcBoss 2: \n";
    pCreature2->Greet();
    pCreature2->DisplayHealth();

    // To demonstrate they are pointing to different (equivalent) OrcBosses, I simply print their address:
    cout << "\n--OrcBoss 1 lives in heap memory address: " << pCreature << "--";
    cout << "\n--OrcBoss 2 lives in heap memory address: " << pCreature2 << "--";
	cout << "\n"; 
	return 0;
}
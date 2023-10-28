// Improved Simple Boss 2.0 (Most of the code is from Simple Boss 2.0 with the addition of a derived class FinalBoss)
// Demonstrates access control under inheritance
// Extra feature - simple addition of a name for the Final Boss

#include <iostream>
#include <string>

using namespace std;

class Enemy
{
public:
	Enemy();
	void Attack() const;
	
protected:
	int m_Damage;
};

Enemy::Enemy():
	m_Damage(10)
{}

void Enemy::Attack() const
{
	cout << "Attack inflicts " << m_Damage << " damage points!\n";
}

class Boss : public Enemy
{
public:
	Boss();
	void SpecialAttack() const;
	
//For exercise, changed private to protected data member to be accessible by derived FinalBoss 
protected:
	int m_DamageMultiplier;
};

Boss::Boss():
	m_DamageMultiplier(3)
{}

void Boss::SpecialAttack() const
{
	cout << "Special Attack inflicts " << (m_DamageMultiplier * m_Damage);
	cout << " damage points!\n";
}

//Exercise addition begins here
class FinalBoss : public Boss
{
public:
	FinalBoss(string name="");
	void UltimateAttack() const;
	
private:
    int m_UltimateDamageMultiplier;
    string m_Name;
};

//Constructor that initializes the Ultimate damage multiplier and the FinalBoss' name.
FinalBoss::FinalBoss(string name):
    m_UltimateDamageMultiplier(10),
    m_Name(name)
{}

//Definition of member function UltimateAttack unique to FinalBoss only (does not exist for Boss NOR Enemy classes).
void FinalBoss::UltimateAttack() const
{
    cout << m_Name << " Used Ultimate Attack, inflicts " << ( m_UltimateDamageMultiplier * m_DamageMultiplier * m_Damage ) ;
	cout << " damage points! Youch.\n";
}



int main()
{
	cout << "\nCreating an enemy.\n";
	Enemy enemy1;
	enemy1.Attack();
	
	cout << "\nCreating a boss.\n";
	Boss boss1;
	boss1.Attack();
	boss1.SpecialAttack();

    // Test if exercise goals are met by creating FinalBoss object and calling all its associated member functions
    string finalBossName = "LavaBoy";
	cout << "\nFinal Boss " << finalBossName << " appears!\n";
    FinalBoss finalBoss(finalBossName);
    finalBoss.Attack();
    finalBoss.SpecialAttack();
    finalBoss.UltimateAttack();
    cout << "\nHope you're okay. Good luck!\n";

	return 0;
}
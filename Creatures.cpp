/*******************************************************************************
* Filename: Creatures.cpp                                                      *
* Author:   Daniel Wilson                                                      *
* E-Mail:   wilsond3@oregonstate.edu                                           *
* Date:     2 May 2017                                                         *
*                                                                              *
* Description: Provides the implementation of an abstract class that will be   *
*    used to represent different characters in a fantasy themed combat game.   *
*                                                                              *
*******************************************************************************/

#include "Creatures.hpp"    // class Creature
#include "CreatureType.hpp" // enum class CreatureType
#include "Die.hpp"          // class Die
#include <string>           // string
#include <iostream>         // cout, endl
#include <cmath>            // ceil()
#include <cstdlib>          // rand()

using std::string;
using std::cout;
using std::endl;


/*******************************************************************************
*    Function: Creature::Creature                                              *
*                                                                              *
* Description: Default constructor. Initializes values to zero and sets type of*
*              creature to CREATURE (which should never instantiate). This     *
*              creature does not yet have an enemy.                            *
*                                                                              *
*      Inputs: void                                                            *
*                                                                              *
*     Outputs: void                                                            *
*******************************************************************************/
Creature::Creature()
{
   armor    = 0;
   strength = 0;

      // There is currently no enemy
   enemy    = nullptr;
}



/*******************************************************************************
*    Function: Creature::Creature                                              *
*                                                                              *
* Description: Constructor. Initializes all data members based on parameter    *
*              values.                                                         *
*                                                                              *
*      Inputs:   numAttackDice - unsigned short                                *
*               faceAttackDice - unsigned short                                *
*               numDefenseDice - unsigned short                                *
*              faceDefenseDice - unsigned short                                *
*                        armor - unsigned short                                *
*                     strength - unsigned short                                *
*                         type - CreatureType (enum class)                     *
*                                                                              *
*     Outputs: void                                                            *
*******************************************************************************/
Creature::Creature(unsigned short numAttackDice,  unsigned short faceAttackDice, 
                   unsigned short numDefenseDice, unsigned short faceDefenseDice, 
                   unsigned short armor,          unsigned short strength)
{
      // Resizes dice vectors to hold a specified number of same die
   attackDice.resize(numAttackDice, Die(faceAttackDice));
   defenseDice.resize(numDefenseDice, Die(faceDefenseDice));

   this->armor    = armor;
   this->strength = strength;

      // There is currently no enemy
   enemy = nullptr;
}



/*******************************************************************************
*    Function: virtual Creature::~Creature                                     *
*                                                                              *
* Description: Virtual base class destructor. Removes the pointer to the enemy *
*              creature by setting it to nullptr.                              * 
*                                                                              *
*      Inputs: void                                                            *
*                                                                              *
*     Outputs: void                                                            *
*******************************************************************************/
Creature::~Creature()
{
   enemy = nullptr;
}



/*******************************************************************************
*    Function: Creature::attackRoll const                                      *
*                                                                              *
* Description: Rolls all attack dice and returns the sum.                      *
*                                                                              *
*      Inputs: void                                                            *
*                                                                              *
*     Outputs: void                                                            *
*******************************************************************************/
unsigned int Creature::attackRoll() const
{
   unsigned int attackRoll = 0;
   
   for (unsigned int i = 0; i < attackDice.size(); ++i)
      attackRoll += attackDice.at(i).roll();

   return attackRoll;
}



/*******************************************************************************
*    Function: Creature::defenseRoll const                                     *
*                                                                              *
* Description: Rolls all defense dice and returns the sum.                     *
*                                                                              *
*      Inputs: void                                                            *
*                                                                              *
*     Outputs: void                                                            *
*******************************************************************************/
unsigned int Creature::defenseRoll() const
{
   unsigned int defenseRoll = 0;
   
   for (unsigned int i = 0; i < defenseDice.size(); ++i)
      defenseRoll += defenseDice.at(i).roll();

   return defenseRoll;
}



/*******************************************************************************
*    Function: static Creature::CreatureFactory                                *
*                                                                              *
* Description: Returns a pointer to a newly created Creature of the specified  *
*              type.                                                           *
*                                                                              *
*      Inputs: newCreatureType - CreatureType (enum class)                     *
*                                                                              *
*     Outputs: void                                                            *
*******************************************************************************/
Creature* Creature::CreatureFactory(CreatureType newCreatureType)
{
   if (newCreatureType == CreatureType::BARBARIAN)
      return new Barbarian();
   else if (newCreatureType == CreatureType::BLUE_MEN)
      return new BlueMen();
   else if (newCreatureType == CreatureType::VAMPIRE)
      return new Vampire();
   else if (newCreatureType == CreatureType::MEDUSA)
      return new Medusa();
   else if (newCreatureType == CreatureType::HARRY_POTTER)
      return new HarryPotter();
   else
      return nullptr;
}



/*******************************************************************************
*    Function: Creature::printCurrentStats const                               *
*                                                                              *
* Description: Prints information about this Creature's particular statistics. *
*                                                                              *
*      Inputs: void                                                            *
*                                                                              *
*     Outputs: void                                                            *
*******************************************************************************/
void Creature::printCurrentStats() const
{
   cout << "   Class: " << getTypeAsString()            << endl
        << "  Attack: " << attackDice.size() << 'd' 
                        << attackDice.at(0).getFaces()  << endl
        << " Defense: " << defenseDice.size() << 'd' 
                        << defenseDice.at(0).getFaces() << endl
        << "   Armor: " << armor                        << endl
        << "Strength: " << strength                     << endl;
}



/*******************************************************************************
*    Function: virtual Creature::attack override                               *
*                                                                              *
* Description: Returns the total of all rolled attack dice.                    *
*                                                                              *
*      Inputs: void                                                            *
*                                                                              *
*     Outputs: unsigned int - value of all the attack dice rolled.             *
*******************************************************************************/
unsigned int Creature::attack()
{
   unsigned int attackTotal = attackRoll();

   cout << getTypeAsString() << " rolled a " << attackTotal
        << " for its attack!";

   return attackTotal;
}



/*******************************************************************************
*    Function: virtual Creature::defend                                        *
*                                                                              *
* Description: Takes the incoming damage from an attack and subtracts that by  *
*              the creatures defense dice roll and armor.                      *
*                                                                              *
*      Inputs: void                                                            *
*                                                                              *
*     Outputs: void                                                            *
*******************************************************************************/
void Creature::defend(unsigned int incomingDamage)
{
      // If there is no incoming damage
   if (!incomingDamage)
      return;
   
   unsigned int defenseRollTotal = defenseRoll();
   int dealtDamage = incomingDamage - (defenseRollTotal + armor);

      // Do nothing on negative or zero damage
   cout << endl << getTypeAsString() << " rolled a " 
        << defenseRollTotal << " for defense.";

   if (dealtDamage <= 0)
      return;

      // Killing blow? Set strength to zero
   if (dealtDamage >= strength)
      setStrength(0);
   else
      setStrength(strength - dealtDamage);
}



/*******************************************************************************
******************************* BARBARIAN METHODS ******************************
*******************************************************************************/
Barbarian::Barbarian()
   : Creature(2, 6, 2, 6, 0, 12)
{
   ;
}


void Barbarian::refresh()
{
   int potentialToHeal = 12 - strength;
   int heal = 0;

   if (potentialToHeal)
   {
      heal = rand() % potentialToHeal + 1;
      setStrength(strength + heal);
   }

   cout << "\nBarbarian healed " << heal << " strength points.";
}


/*******************************************************************************
******************************** BLUE MEN METHODS ******************************
*******************************************************************************/
BlueMen::BlueMen()
   : Creature(2, 10, 3, 6, 3, 12)
{
   ;
}



/*******************************************************************************
*    Function: virtual BlueMen::setStrength                                    *
*                                                                              *
* Description: Sets the strength based on the parameter and reduces the number *
*              of defense dice by one for every four damage.                   *
*                                                                              *
*      Inputs: strength - unsigned short                                       *
*                                                                              *
*     Outputs: void                                                            *
*******************************************************************************/
void BlueMen::setStrength(unsigned short strength)
{
   this->strength = strength;

      // Every 4 damage, the Blue Men lose one defense die
   unsigned int defenseDiceLeft = ceil((strength / 4.0));

      // If Blue Men have lost a defense die, print a message and pop the die
   if (defenseDiceLeft < defenseDice.size() && defenseDiceLeft != 0)
   {
      cout << "\nThe Blue Men lost some of the mob, now they roll with "
         << defenseDiceLeft << " defense dice";
      defenseDice.pop_back();
   }
}


void BlueMen::refresh()
{
   int potentialToHeal = 12 - strength;
   int heal = 0;

   if (potentialToHeal)
   {
      heal = rand() % potentialToHeal + 1;
      setStrength(strength + heal);
   }

   cout << "\nBlue Men healed " << heal << " strength points.";
}



/*******************************************************************************
******************************** VAMPIRE METHODS *******************************
*******************************************************************************/
Vampire::Vampire()
   : Creature(1, 12, 1, 6, 1, 18)
{
   ;
}



/*******************************************************************************
*    Function: virtual Vampire::setStrength                                    *
*                                                                              *
* Description: Allows the Vampire a 50% chance to ignore the attack damage,    *
*              otherwise, call regular defend method.                          *
*                                                                              *
*      Inputs: incomingDamage - unsigned int                                   *
*                                                                              *
*     Outputs: void                                                            *
*******************************************************************************/
void Vampire::setStrength(unsigned short strength)
{
      // 50% chance vampire charms opponent
   if (rand() % 2)
      cout << "\nHow charming, the vampire dodged the attack!";
   else
      Creature::setStrength(strength);
}



void Vampire::refresh()
{
   int potentialToHeal = 18 - strength;
   int heal = 0;

   if (potentialToHeal)
   {
      heal = rand() % potentialToHeal + 1;
      setStrength(strength + heal);
   }

   cout << "\nVampire healed " << heal << " strength points.";
}



/*******************************************************************************
******************************** VAMPIRE METHODS *******************************
*******************************************************************************/
Medusa::Medusa()
   : Creature(2, 6, 1, 6, 3, 8)
{
   ;
}



/*******************************************************************************
*    Function: virtual Medusa::attack                                          *
*                                                                              *
* Description: If Medusa rolls a 12, then returns 100 damage for a killing     *
*              blow.                                                           *
*                                                                              *
*      Inputs: void                                                            *
*                                                                              *
*     Outputs: unsigned int - Return result from attackRoll()                  *
*******************************************************************************/
unsigned int Medusa::attack()
{
   unsigned int attackTotal  = attackRoll();

   if (attackTotal == 12)
   {
      cout << "Medusa glares fiercly at her enemy!";
      enemy->setStrength(0);
      return 0;
   }
   else
      cout << getTypeAsString() << " rolled a " << attackTotal
           << " for its attack!";

   return attackTotal;
}


void Medusa::refresh()
{
   int potentialToHeal = 12 - strength;
   int heal = 0;

   if (potentialToHeal)
   {
      heal = rand() % potentialToHeal + 1;
      setStrength(strength + heal);
   }

   cout << "\nMedusa healed " << heal << " strength points.";
}


/*******************************************************************************
***************************** HARRY POTTER METHODS *****************************
*******************************************************************************/
HarryPotter::HarryPotter()
   : Creature(2, 6, 2, 6, 0, 10)
{
   hogwartsAvailable = true;
}



/*******************************************************************************
*    Function: virtual HarryPotter::setStrength                                *
*                                                                              *
* Description: The first time Harry's strength is set to 0, set it to 20       *
*              instead.                                                        *
*                                                                              *
*      Inputs: strength - unsigned short                                         *
*                                                                              *
*     Outputs: void                                                            *
*******************************************************************************/
void HarryPotter::setStrength(unsigned short strength)
{
      // If the first killing blow has been dealt to Harry...
   if (strength == 0 && hogwartsAvailable)
   {
      this->strength = 20;
      cout << endl << "The pheonix is risen--HOGWARTS!!!";
      hogwartsAvailable = false;
   }
   else
      this->strength = strength;
}


void HarryPotter::refresh()
{
   unsigned int potentialToHeal;
   unsigned int heal = 0;

   if (hogwartsAvailable)
      potentialToHeal = 10 - strength;
   else
      potentialToHeal = 20 - strength;

   if (potentialToHeal)
   {
      heal = rand() % potentialToHeal + 1;
      setStrength(strength + heal);
   }

   cout << "\nHarry Potter healed " << heal << " strength points.";
}

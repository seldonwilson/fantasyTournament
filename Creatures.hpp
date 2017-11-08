/*******************************************************************************
* Filename: Creatures.hpp                                                      *
* Author:   Daniel Wilson                                                      *
* E-Mail:   wilsond3@oregonstate.edu                                           *
* Date:     2 May 2017                                                         *
*                                                                              *
* Description: Provides the interface to an abstract class that will be used to*
*    represent different characters in a fantasy themed combat game.           *
*                                                                              *
*******************************************************************************/

#ifndef CREATURES_HPP
#define CREATURES_HPP

#include "CreatureType.hpp" // enum class CreatureType
#include "Die.hpp"          // class Die
#include <vector>           // vector
#include <string>           // string


class Creature
{
   public:
      // Creature factory
   static Creature* CreatureFactory(CreatureType);

   protected:
      std::vector<Die> attackDice;
      std::vector<Die> defenseDice;
      unsigned short   armor;
      unsigned short   strength;
      Creature*        enemy;

   public:
         // Constructors/Destructor
      Creature();
      Creature(unsigned short numAttackDice,  unsigned short faceAttackDice, 
               unsigned short numDefenseDice, unsigned short faceDefenseDice, 
               unsigned short armor,          unsigned short strength);
       virtual ~Creature();

          // Combat Methods
      unsigned int attackRoll() const;
      unsigned int defenseRoll() const;
      virtual unsigned int attack();
      virtual void defend(unsigned int);
      virtual void refresh() = 0;

         // Getters/Setters
      virtual CreatureType getType() const = 0;
      virtual std::string getTypeAsString() const = 0;
      unsigned short getArmor() const 
         {return armor;}
      unsigned short getStrength() const 
         {return strength;}
      virtual void setStrength(unsigned short strength)
         {this->strength = strength;}
      void setEnemy(Creature* enemy) 
         {this->enemy = enemy;}

         // Prints all the Creature's data members
      virtual void printCurrentStats() const;
};



/*******************************************************************************
*             Class: Barbarian                                                 *
*                                                                              *
*     Initial Stats: Attack   - 2d6                                            *
*                    Defense  - 2d6                                            *
*                    Armor    - 0                                              *
*                    Strength - 12                                             *
*                                                                              *
* Special Abilities: No special abilities.                                     *
*******************************************************************************/
class Barbarian : public Creature
{
   public:
         // Default Constructor
      Barbarian();

         // Overriden Getters
      virtual CreatureType getType() const override 
         {return CreatureType::BARBARIAN;}
      virtual std::string getTypeAsString() const override 
         {return "Barbarian";}
      virtual void refresh() override;
};



/*******************************************************************************
*             Class: BlueMen                                                   *
*                                                                              *
*     Initial Stats: Attack   - 2d10                                           *
*                    Defense  - 3d6                                            *
*                    Armor    - 3                                              *
*                    Strength - 12                                             *
*                                                                              *
* Special Abilities: Loses one defense die for every 4 points of damage taken. *
*******************************************************************************/
class BlueMen : public Creature
{
   public:
         // Default Constructor
      BlueMen();

         // Overriden Getters
      virtual CreatureType getType() const override 
         {return CreatureType::BLUE_MEN;}
      virtual std::string getTypeAsString() const override 
         {return "Blue Men";}

         // Loses one defense die for every 4 points of strength lost
      virtual void setStrength(unsigned short strength) override;
      virtual void refresh() override;
};



/*******************************************************************************
*             Class: Vampire                                                   *
*                                                                              *
*     Initial Stats: Attack   - 1d12                                           *
*                    Defense  - 1d6                                            *
*                    Armor    - 1                                              *
*                    Strength - 18                                             *
*                                                                              *
* Special Abilities: Has a 50% chance to not get hit by the enemy attack.      *
*******************************************************************************/
class Vampire : public Creature
{
   public: 
         // Default Constructor
      Vampire();

         // Overriden Getters
      virtual CreatureType getType() const override 
         {return CreatureType::VAMPIRE;}
      virtual std::string getTypeAsString() const override 
         {return "Vampire";}

         // 50% chance Vampire will charm opponent and not take damage
      virtual void setStrength(unsigned short strength) override;
      virtual void refresh() override;
};



/*******************************************************************************
*             Class: Medusa                                                    *
*                                                                              *
*     Initial Stats: Attack   - 2d6                                            *
*                    Defense  - 1d6                                            *
*                    Armor    - 3                                              *
*                    Strength - 8                                              *
*                                                                              *
* Special Abilities: On a 12, glares the enemy and sets their strength to 0.   *
*******************************************************************************/
class Medusa : public Creature
{
   public:
         // Default Constructor
      Medusa();

         // Overriden Getters
      virtual CreatureType getType() const override 
         {return CreatureType::MEDUSA;}
      virtual std::string getTypeAsString() const override 
         {return "Medusa";}

         // On a 12, glares opponent by setting enemy strength to 0
      virtual unsigned int attack() override;
      virtual void refresh() override;
};



/*******************************************************************************
*             Class: Harry Potter                                              *
*                                                                              *
*     Initial Stats: Attack   - 2d6                                            *
*                    Defense  - 2d6                                            *
*                    Armor    - 0                                              *
*                    Strength - 10                                             *
*                                                                              *
* Special Abilities: First time Harry's strength is set to 0, set it to 20.    *
*******************************************************************************/
class HarryPotter : public Creature
{
   private:
      bool hogwartsAvailable;

   public:
         // Default Constructor
      HarryPotter();

         // Overriden Getters
      virtual CreatureType getType() const override 
         {return CreatureType::HARRY_POTTER;}
      virtual std::string getTypeAsString() const override 
         {return "Harry Potter";}

         // The first time Harry has strength reduced to 0, it's set to 20
      virtual void setStrength(unsigned short strength) override;
      virtual void refresh() override;
};


#endif // CREATURES_HPP

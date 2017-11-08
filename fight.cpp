/*******************************************************************************
* Filename: fight.cpp                                                          *
* Author:   Daniel Wilson                                                      *
* E-Mail:   wilsond3@oregonstate.edu                                           *
* Date:     27 May 2017                                                        *
*                                                                              *
* Description: Provides the definition of the function which implements the    *
*    tournament between two different rosters of teams.                        *
*                                                                              *
*******************************************************************************/

#include "CreatureQueue.hpp"
#include "CreatureStack.hpp"
#include "CreatureStack.hpp"
#include "ioutil.hpp"
#include <cstdlib>
#include <utility>
#include <iomanip>
#include <iostream>

using std::cout;
using std::endl;


void fight(CreatureQueue& teamOneRoster, CreatureQueue& teamTwoRoster)
{
   srand(time(0));
   CreatureStack deadPile;

   int teamOneScore = 0;
   int teamTwoScore = 0;
   int round = 1;
   int turn  = 1;
   ValidatedInput input;
   CreatureNode* teamOneActiveCreature = teamOneRoster.pop();
   CreatureNode* teamTwoActiveCreature = teamTwoRoster.pop();
   Creature* attacker = nullptr;
   Creature* defender = nullptr;
   unsigned int attackValue;

      // Sets Current Fighters to be each others enemy
   teamOneActiveCreature->creature->setEnemy(teamTwoActiveCreature->creature);
   teamTwoActiveCreature->creature->setEnemy(teamOneActiveCreature->creature);

      // Randomly Assign an Attacker and Defender
   if (rand() % 2)
   {
      attacker = teamOneActiveCreature->creature;
      defender = teamTwoActiveCreature->creature;
   }
   else
   {
      attacker = teamTwoActiveCreature->creature;
      defender = teamOneActiveCreature->creature;
   }


   do
   {
      terminalClear();
      cout << "Round: " << std::setw(2) <<round << "\n Turn: " 
           << std::setw(2) << turn << endl << endl
           << "Team 1 Fighters Left\n"
           << "====================\n";
      teamOneRoster.printNoTeam();

      cout << "\n\nTeam 2 Fighters Left\n"
           <<   "====================\n";
      teamTwoRoster.printNoTeam();

      cout << "\n\nTeam 1's Current Fighter: " << *(teamOneActiveCreature->name)
           << endl;
      teamOneActiveCreature->creature->printCurrentStats();

      cout << "\n\nTeam 2's Current Fighter: " << *(teamTwoActiveCreature->name)
           << endl;
      teamTwoActiveCreature->creature->printCurrentStats();

      cout << "\n\n";

      attackValue = attacker->attack();
      defender->defend(attackValue);

      if (teamOneActiveCreature->creature->getStrength() == 0)
      {
         cout << "\nTeam 1's fighter has died... RIP.\n";
         cout << "Team 2's " 
              << teamTwoActiveCreature->creature->getTypeAsString()
              << " reigned supreme and is heading to the back of the lineup.";
         
         deadPile.push(teamOneActiveCreature);
         teamOneActiveCreature = teamOneRoster.pop();
         teamTwoActiveCreature->creature->refresh();
         teamTwoRoster.push(teamTwoActiveCreature);
         teamTwoActiveCreature = teamTwoRoster.pop();
         ++round;
         ++teamTwoScore;
         turn = 0;
         if (teamOneActiveCreature && teamTwoActiveCreature)
         {
            teamOneActiveCreature->creature->setEnemy(teamTwoActiveCreature->creature);
            teamTwoActiveCreature->creature->setEnemy(teamOneActiveCreature->creature);
            attacker = teamOneActiveCreature->creature;
            defender = teamTwoActiveCreature->creature;
         }
      }
      else if (teamTwoActiveCreature->creature->getStrength() == 0)
      {
         cout << "\nTeam 2's fighter has died... RIP.\n";
         cout << "Team 1's " 
              << teamOneActiveCreature->creature->getTypeAsString()
              << " reigned supreme and is heading to the back of the lineup.";

         deadPile.push(teamTwoActiveCreature);
         teamTwoActiveCreature = teamTwoRoster.pop();
         teamOneActiveCreature->creature->refresh();
         teamOneRoster.push(teamOneActiveCreature);
         teamOneActiveCreature = teamOneRoster.pop();
         ++round;
         ++teamOneScore;
         turn = 0;
         if (teamOneActiveCreature && teamTwoActiveCreature)
         {
            teamOneActiveCreature->creature->setEnemy(teamTwoActiveCreature->creature);
            teamTwoActiveCreature->creature->setEnemy(teamOneActiveCreature->creature);
            attacker = teamTwoActiveCreature->creature;
            defender = teamOneActiveCreature->creature;
         }
      }
      
      std::swap(attacker, defender);

      ++turn;

      cout << "\n\nPress ENTER to play next turn of combat...";
      input.fromKeyboard();

   } while (teamOneActiveCreature != nullptr && 
            teamTwoActiveCreature != nullptr);

   terminalClear();
   
   cout << "Congratulations! Team " 
        << (teamOneScore > teamTwoScore ? "1" : "2") << " is the winner.";

   cout << "\nTeam 1 Score: " << teamOneScore << endl;
   cout << "Team 2 Score: " << teamTwoScore << endl;

   cout << "\nA pile of the fallen is printed below...\n";
   deadPile.print();

   if (teamOneActiveCreature)
      delete teamOneActiveCreature;
   else if (teamTwoActiveCreature)
      delete teamTwoActiveCreature;

   cout << "\n\nPress ENTER to return to the main menu...";
   input.fromKeyboard();
}

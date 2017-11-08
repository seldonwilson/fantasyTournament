/*******************************************************************************
* Filename: main.cpp                                                           *
* Author:   Daniel Wilson                                                      *
* E-Mail:   wilsond3@oregonstate.edu                                           *
* Date:     28 May 2017                                                        *
*                                                                              *
* Description: Defines the main function which controls the main menu loop that*
*    allows access to all the different components of the program.             *
*                                                                              *
*******************************************************************************/

#include "ioutil.hpp"
#include <string>
#include <vector>
#include <iostream>
#include "CreatureQueue.hpp"
#include "testingSuite.hpp"
#include "configureTeam.hpp"
#include "fight.hpp"

using std::string;
using std::vector;
using std::cout;


int main()
{
      // Initialize Main Menu
   string title = "---====Fantasy-Battle Tournament Simulator====---";
   vector<string> items = {"Fight!",
                           "Pick Team Size",
                           "Configure Team 1",
                           "Configure Team 2",
                           "Test Suite",
                           "Quit"};
   string prompt = "Enter a menu selection: ";
   Menu mainMenu(title, items, prompt);

      // Menu selection variables
   const int QUIT = 6;
   int menuSelection;

      // Fantasy-Battle Tournament Variables
   int  teamSize = 0;

   CreatureQueue teamOneRoster;
   CreatureQueue teamTwoRoster;
   ValidatedInput input;

   do
   {
      terminalClear();
      mainMenu.print();
      printSettings(teamSize);
      printTeamConfigStatus(teamOneRoster, teamTwoRoster);

      menuSelection = mainMenu.getSelection();

      switch (menuSelection)
      {
         case 1: if (!teamOneRoster.isEmpty() && !teamTwoRoster.isEmpty())
                    fight(teamOneRoster, teamTwoRoster);
                 else
                 {
                    terminalClear();
                    cout << "Both teams must be configured before starting"
                         << "\n\nPress ENTER to return to the main menu...";
                    input.fromKeyboard();
                 }
                 break;

         case 2: if (teamOneRoster.isEmpty() && teamTwoRoster.isEmpty())
                    pickTeamSize(teamSize);
                 else
                 {
                    terminalClear();
                    cout << "A roster has already been set, what's done is done"
                         << "\nno team size changes are permitted."
                         << "\n\nPress ENTER to return to the main menu...";
                    input.fromKeyboard();
                 }
                 break;

         case 3: if (!teamSize)
                 {
                    terminalClear();
                    cout << "The team size must be set before configuring the "
                         << "rosters."
                         << "\n\nPress ENTER to return to the main menu...";
                    input.fromKeyboard();
                 }
                 else
                    configureTeam(teamOneRoster, teamSize, '1');
                 break;

         case 4: if (!teamSize)
                 {
                    terminalClear();
                    cout << "The team size must be set before configuring the "
                         << "rosters."
                         << "\n\nPress ENTER to return to the main menu...";
                    input.fromKeyboard();
                 }
                 else
                    configureTeam(teamTwoRoster, teamSize, '2');
                 break;

         case 5: testSuite();
                 break;
      }
   
   } while (menuSelection != QUIT);

   terminalClear();
   return 0;
}

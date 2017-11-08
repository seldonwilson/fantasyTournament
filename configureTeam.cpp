/*******************************************************************************
* Filename: configureTeam.cpp                                                  *
* Author:   Daniel Wilson                                                      *
* E-Mail:   wilsond3@oregonstate.edu                                           *
* Date:     27 May 2017                                                        *
*                                                                              *
* Description: Provides the definitions for functions that are used to allow   *
*    the user to configure their team rosters.                                 *
*                                                                              *
*******************************************************************************/

#include "ioutil.hpp"
#include "configureTeam.hpp"
#include <iostream>

using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::cin;


/*******************************************************************************
*    Function: pickTeamSize                                                    *
*                                                                              *
* Description: Allows the user to select the size of the teams.                *
*                                                                              *
*      Inputs:   teamSize - int&                                               *
*              anyTeamSet - bool                                               *
*                                                                              *
*     Outputs: void                                                            *
*******************************************************************************/
void pickTeamSize(int& teamSize, bool anyTeamSet)
{
   terminalClear();
   ValidatedInput input;

   if (!anyTeamSet)
   {
      cout << "There's no \"I\" in team!\nPick between 2-20 for the team size: ";
      input.fromKeyboard();

      while (!input.isIntegerBetween(2, 20))
      {
         terminalClear();
         cout << "Well, that's an idea. But, let's try again.\n"
              << "Pick between 2-20 for the team size: ";
         input.fromKeyboard();
      }

      teamSize = stoi(input.getInput());
   }
   else
      cout << "A team's already configured. What's done is done.";

   cout << "\n\nPress ENTER to return to the main menu...";
   input.fromKeyboard();
}



/*******************************************************************************
*    Function: printSettings                                                   *
*                                                                              *
* Description: Prints the size of the teams.                                   *
*                                                                              *
*      Inputs: teamSize - int                                                  *
*                                                                              *
*     Outputs: void                                                            *
*******************************************************************************/
void printSettings(int teamSize)
{
   cout << "\nTeam Size: ";

   if (teamSize == 0)
      cout << "UNSET\n";
   else
      cout << teamSize << endl;
}



/*******************************************************************************
*    Function: configureTeam                                                   *
*                                                                              *
* Description: Allows the user to set the members of their roster.             *
*                                                                              *
*      Inputs:   roster - CreatureQueue&                                       *
*              teamSize - int                                                  *
*                  char - team                                                 *
*                                                                              *
*     Outputs: void                                                            *
*******************************************************************************/
void configureTeam(CreatureQueue& roster, int teamSize, char team)
{
      // If team has already been configured, delete the roster and reconfigure
   if (!roster.isEmpty())
   {
      CreatureNode* garbage = nullptr;

      while ((garbage = roster.pop()) != nullptr)
         delete garbage;
   }
   
   int rosterPosition = 1;

      // Initialize Roster Menu
   string title = "---====Fantasy Roster Configuration====---";
   vector<string> items = {"Vampire",
                           "Barbarian",
                           "Blue Men",
                           "Medusa",
                           "Harry Potter"};
   string posAsString = std::to_string(rosterPosition);
   string teamSizeAsString = std::to_string(teamSize);
   string prompt = "Enter a selection for position " + posAsString
                  + "/" + teamSizeAsString + ": ";

   Menu rosterMenu(title, items, prompt);
   int menuSelection;
   ValidatedInput input;

   while (rosterPosition <= teamSize)
   {
      terminalClear();
      rosterMenu.print();
      menuSelection = rosterMenu.getSelection();

      if (menuSelection != -1)
      {
         addToRoster(roster, menuSelection, team);
         ++rosterPosition;
         posAsString = std::to_string(rosterPosition);
         prompt = "Enter a selection for position" + posAsString 
                  + "/" + teamSizeAsString + ": ";
         rosterMenu.setPrompt(prompt);
      }
   }

      terminalClear();
      cout << "Congratulations, all " << teamSize << " positions on your team"
           << " have been configured." << "\nYour roster:\n\n";

      roster.print();

      cout << "\n\nPress ENTER to return to the main menu...";
      input.fromKeyboard();
}



/*******************************************************************************
*    Function: addToRoster                                                     *
*                                                                              *
* Description: Allows the user to add an individual creature to its roster.    *
*                                                                              *
*      Inputs:   roster - CreatureQueue&                                       *
*              teamSize - int                                                  *
*                  char - team                                                 *
*                                                                              *
*     Outputs: void                                                            *
*******************************************************************************/
void addToRoster(CreatureQueue& roster, int menuSelection, char team)
{
   terminalClear();
   ValidatedInput input;
   CreatureType type = static_cast<CreatureType>(menuSelection);
   string name;

   cout << "Enter the name of your new creature: ";
   getline(cin, name);

   string* newName = new string(name);

   CreatureNode* newCreatureNode = new CreatureNode(newName, type, team);
   roster.push(newCreatureNode);

   cout << endl << newCreatureNode->creature->getTypeAsString() << " named " 
        << *(newCreatureNode->name) << " successfully added to team " << team
        << "\n\nPress ENTER to return to the roster selection...";
   input.fromKeyboard();
}



/*******************************************************************************
*    Function: printTeamConfigStatus                                           *
*                                                                              *
* Description: Prints configuration status of each team.                       *
*                                                                              *
*      Inputs: teamOneRoster - CreatureQueue&                                  *
*              teamOneRoster - CreatureQueue&                                  *
*                                                                              *
*     Outputs: void                                                            *
*******************************************************************************/
void printTeamConfigStatus(CreatureQueue& teamOneRoster, 
                           CreatureQueue& teamTwoRoster)
{
   cout << "Team 1: ";

   if (teamOneRoster.isEmpty())
      cout << "UNCONFIGURED";
   else
      cout << "CONFIGURED";

   cout << "\nTeam 2: ";

   if (teamTwoRoster.isEmpty())
      cout << "UNCONFIGURED\n";
   else
      cout << "CONFIGURED\n";
}

/*******************************************************************************
* Filename: testingSuite.cpp                                                   *
* Author:   Daniel Wilson                                                      *
* E-Mail:   wilsond3@oregonstate.edu                                           *
* Date:     27 May 2017                                                        *
*                                                                              *
* Description: Provides definitions for functions which are used to test the   *
*    stack and queue.                                                          *
*                                                                              *
*******************************************************************************/

#include "CreatureStack.hpp"
#include "CreatureQueue.hpp"
#include "testingSuite.hpp"
#include "ioutil.hpp"
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::cout;
using std::endl;
using std::string;



/*******************************************************************************
*    Function: testSuite                                                       *
*                                                                              *
* Description: The main interface to access the different testing functions.   *
*                                                                              *
*      Inputs: void                                                            *
*                                                                              *
*     Outputs: void                                                            *
*******************************************************************************/
void testSuite()
{
   static int numberOfNodes = 1000;

      // Initialize Testing Menu
   string title = "---====Fantasy-Battle Tournament Testing Suite====---";
   vector<string> items = {"Adding Creatures Stack -> Stack Destructor",
                           "Adding Creatures Queue -> Queue Destructor",
                           "Adding Creatures Queue -> Pop All to Stack",
                           "Adding Creatures Queue -> Push Popped Node",
                           "Adding Creatures Queue -> Push Popped Node -> Pop All to Stack",
                           "Set Number of Test Nodes",
                           "Return to Main Menu"};
   string prompt = "Enter a testing selection: ";
   Menu testingMenu(title, items, prompt);

   const int BACK_TO_MAIN_MENU = 7;
   int menuSelection;

   do
   {
      terminalClear();
      testingMenu.print();
      printNumberOfNodes(numberOfNodes);

      menuSelection = testingMenu.getSelection();

      switch (menuSelection)
      {
            // Loads five million CreatureNodes onto the CreatureStack
         case 1: testCreatureStack(numberOfNodes);
                 break;

            // Loads five million CreatureNodes into the CreatureQueue
         case 2: testCreatureQueue(numberOfNodes);
                 break;

            // Pops each node from queue, then pushes it onto stack
         case 3: testQueuePopToStack(numberOfNodes);
                 break;

            // Pops each node from queue, then pushes it to back of queue
         case 4: testPushPop(numberOfNodes);
                 break;

         case 5: testPushPopPushToStack(numberOfNodes);
                 break;

         case 6: setNumberOfTestNodes(numberOfNodes);
                 break;
      }
   
   } while (menuSelection != BACK_TO_MAIN_MENU);
}



/*******************************************************************************
*    Function: testQueuePopToStack                                             *
*                                                                              *
* Description: Tests filling up a queue and then popping all its nodes off onto*
*              the stack.                                                      *
*                                                                              *
*      Inputs: nodesToCreate - int                                             *
*                                                                              *
*     Outputs: void                                                            *
*******************************************************************************/
void testQueuePopToStack(int nodesToCreate)
{
   terminalClear();
   ValidatedInput input;
   CreatureQueue lineup;
   CreatureNode* newCreatureNode = nullptr;

   cout << "Adding " << nodesToCreate 
        << "      Vampires to the CreatureQueue\n";

   for (int i = 0; i < nodesToCreate; ++i)
   {
      newCreatureNode = new CreatureNode(new string("Drac"), 
                                         CreatureType::VAMPIRE, 
                                         'A');
      lineup.push(newCreatureNode);
   }

   cout << "Adding " << nodesToCreate 
        << "    Barbarians to the CreatureQueue\n";
   for (int i = 0; i < nodesToCreate; ++i)
   {
      newCreatureNode = new CreatureNode(new string("Conan"), 
                                         CreatureType::BARBARIAN, 
                                         'B');
      lineup.push(newCreatureNode);
   }

   cout << "Adding " << nodesToCreate 
        << "      Blue Men to the CreatureQueue\n";
   for (int i = 0; i < nodesToCreate; ++i)
   {
      newCreatureNode = new CreatureNode(new string("The Crew"), 
                                         CreatureType::BLUE_MEN, 
                                         'C');
      lineup.push(newCreatureNode);
   }

   cout << "Adding " << nodesToCreate 
        << "       Medusas to the CreatureQueue\n";
   for (int i = 0; i < nodesToCreate; ++i)
   {
      newCreatureNode = new CreatureNode(new string("Dime"), 
                                         CreatureType::MEDUSA, 
                                         'D');
      lineup.push(newCreatureNode);
   }

   cout << "Adding " << nodesToCreate 
        << " Harry Potters to the CreatureQueue\n";
   for (int i = 0; i < nodesToCreate; ++i)
   {
      newCreatureNode = new CreatureNode(new string("Mr. Radcliffe"), 
                                         CreatureType::HARRY_POTTER, 
                                         'E');
      lineup.push(newCreatureNode);
   }

   cout << "\nThere are " << lineup.getSize() 
        <<" creatures in the lineup.\n\n";

   cout << "Popping creatures off of CreatureQueue and adding to CreatureStack";
   CreatureStack deadpile;

   CreatureNode* poppedNode = nullptr;
   while ((poppedNode = lineup.pop()) != nullptr)
      deadpile.push(poppedNode);

   cout << "\nThere are " << lineup.getSize() 
        <<" creatures in the lineup.\n"
        << "There are " << deadpile.getSize() 
        <<" creatures in the deadpile.\n";

   cout << "\n\nPress ENTER to leave the bodies behind...";
   input.fromKeyboard();
}



/*******************************************************************************
*    Function: testCreatureStack                                               *
*                                                                              *
* Description: Tests filling up stack.                                         *
*                                                                              *
*      Inputs: nodesToCreate - int                                             *
*                                                                              *
*     Outputs: void                                                            *
*******************************************************************************/
void testCreatureStack(int nodesToCreate)
{
   terminalClear();
   ValidatedInput input;
   CreatureStack deadPile;
   CreatureNode* newCreatureNode = nullptr;

   cout << "Adding " << nodesToCreate 
        << "      Vampires to the CreatureStack\n";
   for (int i = 0; i < nodesToCreate; ++i)
   {
      newCreatureNode = new CreatureNode(new string("Drac"), 
                                         CreatureType::VAMPIRE, 
                                         'A');
      deadPile.push(newCreatureNode);
   }

   cout << "Adding " << nodesToCreate 
        << "    Barbarians to the CreatureStack\n";
   for (int i = 0; i < nodesToCreate; ++i)
   {
      newCreatureNode = new CreatureNode(new string("Conan"), 
                                         CreatureType::BARBARIAN, 
                                         'B');
      deadPile.push(newCreatureNode);
   }

   cout << "Adding " << nodesToCreate 
        << "      Blue Men to the CreatureStack\n";
   for (int i = 0; i < nodesToCreate; ++i)
   {
      newCreatureNode = new CreatureNode(new string("The Crew"), 
                                         CreatureType::BLUE_MEN, 
                                         'C');
      deadPile.push(newCreatureNode);
   }

   cout << "Adding " << nodesToCreate 
        << "       Medusas to the CreatureStack\n";
   for (int i = 0; i < nodesToCreate; ++i)
   {
      newCreatureNode = new CreatureNode(new string("Dime"), 
                                         CreatureType::MEDUSA, 
                                         'D');
      deadPile.push(newCreatureNode);
   }

   cout << "Adding " << nodesToCreate 
        << " Harry Potters to the CreatureStack\n";
   for (int i = 0; i < nodesToCreate; ++i)
   {
      newCreatureNode = new CreatureNode(new string("Mr. Radcliffe"), 
                                         CreatureType::HARRY_POTTER, 
                                         'E');
      deadPile.push(newCreatureNode);
   }

   cout << "\nThere are " << deadPile.getSize() 
        <<" creatures on the pile of the slain.";

   cout << "\n\nPress ENTER to burn the pile...";
   input.fromKeyboard();
}



/*******************************************************************************
*    Function: testCreatureQueue                                               *
*                                                                              *
* Description: Tests filling up a queue.                                       *
*                                                                              *
*      Inputs: nodesToCreate - int                                             *
*                                                                              *
*     Outputs: void                                                            *
*******************************************************************************/
void testCreatureQueue(int nodesToCreate)
{
   terminalClear();
   ValidatedInput input;
   CreatureQueue lineup;
   CreatureNode* newCreatureNode = nullptr;

   cout << "Adding " << nodesToCreate 
        << "      Vampires to the CreatureQueue\n";
   for (int i = 0; i < nodesToCreate; ++i)
   {
      newCreatureNode = new CreatureNode(new string("Drac"), 
                                         CreatureType::VAMPIRE, 
                                         'A');
      lineup.push(newCreatureNode);
   }

   cout << "Adding " << nodesToCreate 
        << "    Barbarians to the CreatureQueue\n";
   for (int i = 0; i < nodesToCreate; ++i)
   {
      newCreatureNode = new CreatureNode(new string("Conan"), 
                                         CreatureType::BARBARIAN, 
                                         'B');
      lineup.push(newCreatureNode);
   }

   cout << "Adding " << nodesToCreate 
        << "      Blue Men to the CreatureQueue\n";
   for (int i = 0; i < nodesToCreate; ++i)
   {
      newCreatureNode = new CreatureNode(new string("The Crew"), 
                                         CreatureType::BLUE_MEN, 
                                         'C');
      lineup.push(newCreatureNode);
   }

   cout << "Adding " << nodesToCreate 
        << "       Medusas to the CreatureQueue\n";
   for (int i = 0; i < nodesToCreate; ++i)
   {
      newCreatureNode = new CreatureNode(new string("Dime"), 
                                         CreatureType::MEDUSA, 
                                         'D');
      lineup.push(newCreatureNode);
   }

   cout << "Adding " << nodesToCreate 
        << " Harry Potters to the CreatureQueue\n";
   for (int i = 0; i < nodesToCreate; ++i)
   {
      newCreatureNode = new CreatureNode(new string("Mr. Radcliffe"), 
                                         CreatureType::HARRY_POTTER, 
                                         'E');
      lineup.push(newCreatureNode);
   }

   cout << "\nThere are " << lineup.getSize() 
        <<" creatures in the lineup.";

   cout << "\n\nPress ENTER to send the creatures off to free agency...";
   input.fromKeyboard();
}



/*******************************************************************************
*    Function: testPushPop                                                     *
*                                                                              *
* Description: Tests filling up a queue and then popping 20% off to push them  *
*              back on.                                                        *
*                                                                              *
*      Inputs: nodesToCreate - int                                             *
*                                                                              *
*     Outputs: void                                                            *
*******************************************************************************/
void testPushPop(int nodesToCreate)
{
   terminalClear();
   ValidatedInput input;
   CreatureQueue lineup;
   CreatureNode* newCreatureNode = nullptr;

   cout << "Adding " << nodesToCreate 
        << "      Vampires to the CreatureQueue\n";
   for (int i = 0; i < nodesToCreate; ++i)
   {
      newCreatureNode = new CreatureNode(new string("Drac"), 
                                         CreatureType::VAMPIRE, 
                                         'A');
      lineup.push(newCreatureNode);
   }

   cout << "Adding " << nodesToCreate 
        << "    Barbarians to the CreatureQueue\n";
   for (int i = 0; i < nodesToCreate; ++i)
   {
      newCreatureNode = new CreatureNode(new string("Conan"), 
                                         CreatureType::BARBARIAN, 
                                         'B');
      lineup.push(newCreatureNode);
   }

   cout << "Adding " << nodesToCreate 
        << "      Blue Men to the CreatureQueue\n";
   for (int i = 0; i < nodesToCreate; ++i)
   {
      newCreatureNode = new CreatureNode(new string("The Crew"), 
                                         CreatureType::BLUE_MEN, 
                                         'C');
      lineup.push(newCreatureNode);
   }

   cout << "Adding " << nodesToCreate 
        << "       Medusas to the CreatureQueue\n";
   for (int i = 0; i < nodesToCreate; ++i)
   {
      newCreatureNode = new CreatureNode(new string("Dime"), 
                                         CreatureType::MEDUSA, 
                                         'D');
      lineup.push(newCreatureNode);
   }

   cout << "Adding " << nodesToCreate 
        << " Harry Potters to the CreatureQueue\n";
   for (int i = 0; i < nodesToCreate; ++i)
   {
      newCreatureNode = new CreatureNode(new string("Mr. Radcliffe"), 
                                         CreatureType::HARRY_POTTER, 
                                         'E');
      lineup.push(newCreatureNode);
   }

   cout << "\nThere are " << lineup.getSize() 
        <<" creatures in the lineup.";

   cout << "\nPopping each node from queue, then pushing it to back...";

   for (int i = 0; i < nodesToCreate; ++i)
      lineup.push(lineup.pop());

   cout << "\nThere are now " << lineup.getSize() 
        <<" creatures in the lineup.";

   cout << "\n\nPress ENTER to throw out the recycling...";
   input.fromKeyboard();
}



/*******************************************************************************
*    Function: printNumberOfNodes                                              *
*                                                                              *
* Description: Prints the number of nodes to test on.                          *
*                                                                              *
*      Inputs: numberOfNodes - int                                             *
*                                                                              *
*     Outputs: void                                                            *
*******************************************************************************/
void printNumberOfNodes(int numberOfNodes)
{
      cout << "\nTesting # of Nodes: " << numberOfNodes << endl;
}



/*******************************************************************************
*    Function: setNumberOfTestNodes                                            *
*                                                                              *
* Description: Allows user to set the number of nodes to test on.              *
*                                                                              *
*      Inputs: numberOfNodes - int&                                            *
*                                                                              *
*     Outputs: void                                                            *
*******************************************************************************/
void setNumberOfTestNodes(int& numberOfNodes)
{
   terminalClear();
   ValidatedInput input;

   cout << "Enter the number of nodes to test on: ";
   input.fromKeyboard();

   while (!input.isInteger(UNSIGNED))
   {
      terminalClear();
      cout << "Enter the number of nodes to test on: ";
      input.fromKeyboard();
   }

   numberOfNodes = stoi(input.getInput());

   cout << "\n\nPress ENTER to go back to the testing suite...";
   input.fromKeyboard();
}



/*******************************************************************************
*    Function: testPushPopPushToStack                                          *
*                                                                              *
* Description: Tests creating a queue, pushing popped nodes to the back of the *
*              queue, and then popping all elements off of the queue and onto  *
*              the stack.                                                      *
*                                                                              *
*      Inputs: nodesToCreate - int                                             *
*                                                                              *
*     Outputs: void                                                            *
*******************************************************************************/
void testPushPopPushToStack(int nodesToCreate)
{
   terminalClear();
   ValidatedInput input;
   CreatureQueue lineup;
   CreatureNode* newCreatureNode = nullptr;

   cout << "Adding " << nodesToCreate 
        << "      Vampires to the CreatureQueue\n";
   for (int i = 0; i < nodesToCreate; ++i)
   {
      newCreatureNode = new CreatureNode(new string("Drac"), 
                                         CreatureType::VAMPIRE, 
                                         'A');
      lineup.push(newCreatureNode);
   }

   cout << "Adding " << nodesToCreate 
        << "    Barbarians to the CreatureQueue\n";
   for (int i = 0; i < nodesToCreate; ++i)
   {
      newCreatureNode = new CreatureNode(new string("Conan"), 
                                         CreatureType::BARBARIAN, 
                                         'B');
      lineup.push(newCreatureNode);
   }

   cout << "Adding " << nodesToCreate 
        << "      Blue Men to the CreatureQueue\n";
   for (int i = 0; i < nodesToCreate; ++i)
   {
      newCreatureNode = new CreatureNode(new string("The Crew"), 
                                         CreatureType::BLUE_MEN, 
                                         'C');
      lineup.push(newCreatureNode);
   }

   cout << "Adding " << nodesToCreate 
        << "       Medusas to the CreatureQueue\n";
   for (int i = 0; i < nodesToCreate; ++i)
   {
      newCreatureNode = new CreatureNode(new string("Dime"), 
                                         CreatureType::MEDUSA, 
                                         'D');
      lineup.push(newCreatureNode);
   }

   cout << "Adding " << nodesToCreate 
        << " Harry Potters to the CreatureQueue\n";
   for (int i = 0; i < nodesToCreate; ++i)
   {
      newCreatureNode = new CreatureNode(new string("Mr. Radcliffe"), 
                                         CreatureType::HARRY_POTTER, 
                                         'E');
      lineup.push(newCreatureNode);
   }

   cout << "\nThere are " << lineup.getSize() 
        <<" creatures in the lineup.";

   cout << "\nPopping each node from queue, then pushing it to back...";

   for (int i = 0; i < nodesToCreate; ++i)
      lineup.push(lineup.pop());

   cout << "\nThere are now " << lineup.getSize() 
        << " creatures in the lineup.\n";

   cout << "Popping creatures off of CreatureQueue and adding to CreatureStack";
   CreatureStack deadpile;

   CreatureNode* poppedNode = nullptr;
   while ((poppedNode = lineup.pop()) != nullptr)
      deadpile.push(poppedNode);

   cout << "\nThere are " << lineup.getSize() 
        << " creatures in the lineup.\n"
        << "There are " << deadpile.getSize() 
        << " creatures in the deadpile.\n";

   cout << "\n\nPress ENTER to throw out the recycling...";
   input.fromKeyboard();
}

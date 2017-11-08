/*******************************************************************************
* Filename: CreatureStack.cpp                                                  *
* Author:   Daniel Wilson                                                      *
* E-Mail:   wilsond3@oregonstate.edu                                           *
* Date:     24 May 2017                                                        *
*                                                                              *
* Description: Provides implementation for a linked-list stack that holds nodes*
*    which contain data regarding creatures, their name, team association, and *
*    the next node in the chain. This stack only needs to be able to add nodes *
*    as it will never pop any off. Any deleting of nodes is done in the        *
*    destructor. A method for printing all of the nodes is provided as well.   *
*                                                                              *
*******************************************************************************/

#include "CreatureStack.hpp"
#include <iostream>

using std::cout;
using std::endl;



/*******************************************************************************
*    Function: CreatureStack::CreatureStack                                    *
*                                                                              *
* Description: Default constructor. Sets sole pointer to nullptr.              *
*                                                                              *
*      Inputs: void                                                            *
*                                                                              *
*     Outputs: void                                                            *
*******************************************************************************/
CreatureStack::CreatureStack()
{
   head = nullptr;
}



/*******************************************************************************
*    Function: CreatureStack::~CreatureStack                                   *
*                                                                              *
* Description: Destructor. Deletes each node from the stack beginning with the *
*              head/top, until all the nodes have been removed.                *
*                                                                              *
*      Inputs: void                                                            *
*                                                                              *
*     Outputs: void                                                            *
*******************************************************************************/
CreatureStack::~CreatureStack()
{
   CreatureNode* garbage;

   while (head != nullptr)
   {
      garbage = head;
      head = head->next;
      delete garbage;
   }

   garbage = nullptr;
}



/*******************************************************************************
*    Function: CreatureStack::push                                             *
*                                                                              *
* Description: Adds a new CreatureNode to the head/top of the stack.           *
*                                                                              *
*      Inputs: newCreature - CreatureNode*                                     *
*                                                                              *
*     Outputs: void                                                            *
*******************************************************************************/
void CreatureStack::push(CreatureNode* newCreature)
{
   newCreature->next = head;
   head = newCreature;
}



/*******************************************************************************
*    Function: CreatureStack::print const                                      *
*                                                                              *
* Description: Prints the fields of each CreatureNode in the stack:            *
*              "Team A's Medusa named Billy Bob"                               *
*              "Team A's Blue Men named Little Nicky"                          *
*              "Team B's Vampire named Van"                                    *
*                                                                              *
*      Inputs: void                                                            *
*                                                                              *
*     Outputs: void                                                            *
*******************************************************************************/
void CreatureStack::print() const
{
   CreatureNode* nodeToPrint = head;

   while (nodeToPrint != nullptr)
   {
      cout << "Team " << nodeToPrint->team << "'s "
           << nodeToPrint->creature->getTypeAsString() << " named " 
           << *(nodeToPrint->name) << endl;

      nodeToPrint = nodeToPrint->next;
   }

   nodeToPrint = nullptr;
}




unsigned int CreatureStack::getSize() const
{
   CreatureNode* nodeToCount  = head;
   unsigned int numberOfNodes = 0;

   while (nodeToCount != nullptr)
   {
      ++numberOfNodes;
      nodeToCount = nodeToCount->next;
   }

   nodeToCount = nullptr;

   return numberOfNodes;
}
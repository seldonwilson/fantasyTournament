/*******************************************************************************
* Filename: CreatureQueue.cpp                                                  *
* Author:   Daniel Wilson                                                      *
* E-Mail:   wilsond3@oregonstate.edu                                           *
* Date:     27 May 2017                                                        *
*                                                                              *
* Description: Provides implementation for linked-list queue that holds nodes  *
*    which contain data regarding creatures, their name, team association, the *
*    front of the queue, and the back of the queue. When a node is popped off  *
*    the queue, a pointer to that node is returned. Any deleting of nodes is   *
*    done in the destructor. A method for printing all of the nodes is provided*
*    as well.                                                                  *
*                                                                              *
*******************************************************************************/

#include "CreatureQueue.hpp"
#include <iostream>

using std::cout;
using std::endl;


/*******************************************************************************
*    Function: CreatureQueue::CreatureQueue                                    *
*                                                                              *
* Description: Default constructor. Sets head and tail to nullptr.             *
*                                                                              *
*      Inputs: void                                                            *
*                                                                              *
*     Outputs: void                                                            *
*******************************************************************************/
CreatureQueue::CreatureQueue()
{
   head = nullptr;
   tail = nullptr;
}



/*******************************************************************************
*    Function: CreatureQueue::~CreatureQueue                                   *
*                                                                              *
* Description: Destructor. Deletes all nodes in the queue.                     *
*                                                                              *
*      Inputs: void                                                            *
*                                                                              *
*     Outputs: void                                                            *
*******************************************************************************/
CreatureQueue::~CreatureQueue()
{
   CreatureNode* garbage;

   while ((garbage = pop()) != nullptr)
      delete garbage;
}



/*******************************************************************************
*    Function: CreatureQueue::pop                                              *
*                                                                              *
* Description: Destructor. Deletes all nodes in the queue.                     *
*                                                                              *
*      Inputs: void                                                            *
*                                                                              *
*     Outputs: CreatureNode* - head node                                       *
*******************************************************************************/
CreatureNode* CreatureQueue::pop()
{
   if (isEmpty())
      return nullptr;
   else
   {
      CreatureNode* oldHead = head;
      head                  = head->next;
      oldHead->next         = nullptr;
      return oldHead;
   }
}



/*******************************************************************************
*    Function: CreatureQueue::push                                             *
*                                                                              *
* Description: Adds a CreatureNode* to the back of the queue.                  *
*                                                                              *
*      Inputs: newCreature - CreatureNode*                                     *
*                                                                              *
*     Outputs: void                                                            *
*******************************************************************************/
void CreatureQueue::push(CreatureNode* newCreature)
{
   if (isEmpty())
   {
      head = newCreature;
      tail = newCreature;
      head->next = nullptr;
   }

   else
   {
      newCreature->next = nullptr;
      tail->next        = newCreature;
      tail              = newCreature;
   }
}



/*******************************************************************************
*    Function: CreatureQueue::print const                                      *
*                                                                              *
* Description: Prints all the nodes in the queue.                              *
*                                                                              *
*      Inputs: void                                                            *
*                                                                              *
*     Outputs: void                                                            *
*******************************************************************************/
void CreatureQueue::print() const
{
   CreatureNode* nodeToPrint = head;

   while (nodeToPrint != nullptr)
   {
      cout << "Team " << nodeToPrint->team << "'s "
           << nodeToPrint->creature->getTypeAsString() << " named " 
           << *(nodeToPrint->name) << endl;

      nodeToPrint = nodeToPrint->next;
   }
}



/*******************************************************************************
*    Function: CreatureQueue::printNoTeam const                                *
*                                                                              *
* Description: Prints all the nodes in the queue w/out the team name.          *
*                                                                              *
*      Inputs: void                                                            *
*                                                                              *
*     Outputs: void                                                            *
*******************************************************************************/
void CreatureQueue::printNoTeam() const
{
   CreatureNode* nodeToPrint = head;

   while (nodeToPrint != nullptr)
   {
      cout << nodeToPrint->creature->getTypeAsString() << " named " 
           << *(nodeToPrint->name) << endl;

      nodeToPrint = nodeToPrint->next;
   }
}



/*******************************************************************************
*    Function: CreatureQueue::getSize const                                    *
*                                                                              *
* Description: Returns the number of elements in the queue.                    *
*                                                                              *
*      Inputs: void                                                            *
*                                                                              *
*     Outputs: unsigned int - number of elements in the queue                  *
*******************************************************************************/
unsigned int CreatureQueue::getSize() const
{
   CreatureNode* nodeToCount  = head;
   unsigned int numberOfNodes = 0;

   while (nodeToCount != nullptr)
   {
      ++numberOfNodes;
      nodeToCount = nodeToCount->next;
   }

   return numberOfNodes;
}

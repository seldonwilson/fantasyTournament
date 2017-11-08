/*******************************************************************************
* Filename: CreatureQueue.hpp                                                  *
* Author:   Daniel Wilson                                                      *
* E-Mail:   wilsond3@oregonstate.edu                                           *
* Date:     27 May 2017                                                        *
*                                                                              *
* Description: Provides the interface for a linked-list queue that holds nodes *
*    which contain data regarding creatures, their name, team association, the *
*    front of the queue, and the back of the queue. When a node is popped off  *
*    the queue, a pointer to that node is returned. Any deleting of nodes is   *
*    done in the destructor. A method for printing all of the nodes is provided*
*    as well.                                                                  *
*                                                                              *
*******************************************************************************/

#ifndef CREATURE_QUEUE_HPP
#define CREATURE_QUEUE_HPP

#include "CreatureNode.hpp"


class CreatureQueue
{
   private:
      CreatureNode* head;
      CreatureNode* tail;

   public:
      CreatureQueue();
      ~CreatureQueue();

      CreatureNode* pop();
      void push(CreatureNode* newCreature);
      void print() const;
      void printNoTeam() const;
      unsigned int getSize() const;
      bool isEmpty() const {return ((head == nullptr) ? true : false);}
};


#endif // CREATURE_QUEUE_HPP

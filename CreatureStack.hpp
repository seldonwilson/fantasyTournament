/*******************************************************************************
* Filename: CreatureStack.hpp                                                  *
* Author:   Daniel Wilson                                                      *
* E-Mail:   wilsond3@oregonstate.edu                                           *
* Date:     24 May 2017                                                        *
*                                                                              *
* Description: Provides the interface for a linked-list stack that holds nodes *
*    which contain data regarding creatures, their name, team association, and *
*    the next node in the chain. This stack only needs to be able to add nodes *
*    as it will never pop any off. Any deleting of nodes is done in the        *
*    destructor. A method for printing all of the nodes is provided as well.   *
*                                                                              *
*******************************************************************************/

#ifndef CREATURE_STACK_HPP
#define CREATURE_STACK_HPP

#include <string>
#include "CreatureNode.hpp"


class CreatureStack
{
   private:
      CreatureNode* head;

   public:
      CreatureStack();
      ~CreatureStack();

      void push(CreatureNode* newCreature);
      void print() const;
      unsigned int getSize() const;
};


#endif // CREATURE_STACK_HPP

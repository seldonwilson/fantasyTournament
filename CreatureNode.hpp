/*******************************************************************************
* Filename: CreatureNode.hpp                                                   *
* Author:   Daniel Wilson                                                      *
* E-Mail:   wilsond3@oregonstate.edu                                           *
* Date:     27 May 2017                                                        *
*                                                                              *
* Description: Provides declaration to a CreatureNode structure that holds a   *
*    pointer to a Creature, a pointer to that creature's name, the team that   *
*    creature belongs to, and a pointer to the next CreatureNode in the chain. *
*    This CreatureNode could be used in any singly-linked list.                *
*                                                                              *
*******************************************************************************/

#ifndef CREATURE_NODE_HPP
#define CREATURE_NODE_HPP

#include "Creatures.hpp" // Creature


struct CreatureNode
{
   CreatureNode* next;
   std::string*  name;
   Creature*     creature;
   char          team;

   CreatureNode(std::string* newName, CreatureType type, char myTeam)
   {
      next     = nullptr;
      name     = newName;
      creature = Creature::CreatureFactory(type);
      team     = myTeam;
   }
   ~CreatureNode()
   {
      delete name;
      delete creature;
      name     = nullptr;
      creature = nullptr;
      next     = nullptr;
   }
};

#endif // CREATURE_NODE_HPP

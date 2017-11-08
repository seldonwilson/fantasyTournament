/*******************************************************************************
* Filename: Die.hpp                                                            *
* Author:   Daniel Wilson                                                      *
* E-Mail:   wilsond3@oregonstate.edu                                           *
* Date:     2 May 2017                                                         *
*                                                                              *
* Description: Provides the interface to a class that represents a single die  *
*    with X faces, having values 1 through X. The class will provide methods to*
*    generate a random roll, along with the traditional suite of getters,      *
*    setters, and constructors.                                                *
*                                                                              *
*******************************************************************************/

#ifndef DIE_HPP
#define DIE_HPP


class Die
{
   private:
      unsigned short faces;

   public:
         // Constructors
      Die();
      Die(unsigned short faces);

         // Returns a random number between one and faces (0 if no faces)
      unsigned short roll() const;
         
         // Sets/Gets faces
      unsigned short getFaces() const;
      void setFaces(unsigned short faces);
};


#endif // DIE_HPP

/*******************************************************************************
* Filename: Die.cpp                                                            *
* Author:   Daniel Wilson                                                      *
* E-Mail:   wilsond3@oregonstate.edu                                           *
* Date:     2 May 2017                                                         *
*                                                                              *
* Description: Provides the implementation of a class that represents a single *
*    die with X faces, having values 1 through X. The class will provide       *
*    methods to generate a random roll, along with the traditional suite of    *
*    getters, setters, and constructors.                                       *
*                                                                              *
*******************************************************************************/

#include "Die.hpp" // Die::
#include <cstdlib> // srand(), rand()
#include <ctime>   // time()


/*******************************************************************************
*    Function: Die::Die                                                        *
*                                                                              *
* Description: Default constructor that seeds the random number generator and  *
*              sets the Die to have zero faces, which would only roll zeros.   *
*                                                                              *
*      Inputs: void                                                            *
*                                                                              *
*     Outputs: void                                                            *
*******************************************************************************/
Die::Die()
{
      // Seed RNG to current time
   srand(time(0));
      // Makes sure uninitialized die rolls a zero
   faces = 0;
}



/*******************************************************************************
*    Function: Die::Die                                                        *
*                                                                              *
* Description: Constructor that seeds the random number generator and assigns  *
*              parameter to the faces data member.                             *
*                                                                              *
*      Inputs: faces - unsigned int                                            *
*                                                                              *
*     Outputs: void                                                            *
*******************************************************************************/
Die::Die(unsigned short faces)
{
      // Seed RNG to current time
   srand(time(0));
   
   this->faces = faces;
}



/*******************************************************************************
*    Function: Die::roll const                                                 *
*                                                                              *
* Description: Returns a randomized value between one and the number of faces  *
*              on the Die. Returns a zero if the Die has no faces.             *
*                                                                              *
*      Inputs: void                                                            *
*                                                                              *
*     Outputs: unsigned int - the "rolled" number of the Die                   *
*******************************************************************************/
unsigned short Die::roll() const
{
      // If the die has faces
   if (faces)
      return rand() % faces + 1;
   else
      return 0;
}

/*******************************************************************************
******************************* GETTERS / SETTERS ******************************
*******************************************************************************/
unsigned short Die::getFaces() const
{
   return faces;
}


void Die::setFaces(unsigned short faces)
{
   this->faces = faces;
}

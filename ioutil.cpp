/*******************************************************************************
* Filename: ioutil.cpp                                                         *
* Author:   Daniel Wilson                                                      *
* E-Mail:   wilsond3@oregonstate.edu                                           *
* Date:     5 May 2017                                                         *
*                                                                              *
* Description: Provides the implementation of classes and methods that aid in  *
*    the collection of user input from a keyboard and displaying output to a   *
*    command line interface.                                                   *
*                                                                              *
*******************************************************************************/

#include "ioutil.hpp" // Menu, ValidatedInput, terminalClear()
#include <string>     // string
#include <iostream>   // cout, endl
#include <cstdio>     // printf()
#include <stdexcept>  // out_of_range

using std::cout;
using std::endl;
using std::out_of_range;


/*******************************************************************************
*    Function: Menu::Menu                                                      *
*                                                                              *
* Description: Default constructor. Sets data members to unitialized values so *
*              testing and debugging is simpler.                               *
*                                                                              *
*      Inputs: void                                                            *
*                                                                              *
*     Outputs: void                                                            *
*******************************************************************************/
Menu::Menu()
{
   title  = "UNINITIALIZED TITLE";
   prompt = "UNINITIALIZED PROMPT"; 
}



/*******************************************************************************
*    Function: Menu::Menu                                                      *
*                                                                              *
* Description: Constructor. Sets data members based on parameters passed in.   *
*                                                                              *
*      Inputs: title - const string&                                           *
*              items - const vector<string>&                                   *
*                                                                              *
*     Outputs: void                                                            *
*******************************************************************************/
Menu::Menu(const std::string& title, 
           const std::vector<std::string>& items,
           const std::string& prompt)
{
   this->title  = title;
   this->items  = items;
   this->prompt = prompt;
}



/*******************************************************************************
*    Function: Menu::print const                                               *
*                                                                              *
* Description: Method that prints the title and all of the items, each on a new*
*              line, with each item being prepended by its item number, for ex.*
*              Welcome to Tic-Tac-Toe                                          *
*              1. Play Game                                                    *
*              2. Configure Settings                                           *
*              3. Quit Game                                                    *
*                                                                              *
*      Inputs: void                                                            *
*                                                                              *
*     Outputs: void                                                            *
*******************************************************************************/
void Menu::print() const
{
   cout << title << endl;

   for (unsigned i = 0; i < items.size(); ++i)
      cout << i + 1 << ". " << items.at(i) << endl;
}



/*******************************************************************************
*    Function: Menu::changeItem const                                          *
*                                                                              *
* Description: Method that allows the user to change what a particular menu    *
*              says. This is useful if you want a menu item to change based on *
*              some variable being set.                                        *
*                                                                              *
*      Inputs:   index - int (index of item to change)                         *
*              newItem - const string&                                         *
*                                                                              *
*     Outputs: void                                                            *
*******************************************************************************/
void Menu::changeItem(int index, const std::string& newItem)
{
      // If the index is within a valid range
   if (index < static_cast<int>(items.size()) && index >= 0)
      items.at(index) = newItem;
}



/*******************************************************************************
*    Function: Menu::addItem                                                   *
*                                                                              *
* Description: Takes a string and pushes it back into the items vector.        *
*                                                                              *
*      Inputs: newItem - const string&                                         *
*                                                                              *
*     Outputs: void                                                            *
*******************************************************************************/
void Menu::addItem(const std::string& newItem)
{
   items.push_back(newItem);
}



/*******************************************************************************
*    Function: Menu::getSelection const                                        *
*                                                                              *
* Description: Returns a menu selection from the user. If the selection is not *
*              valid, then the method will return -1, otherwise, it returns a  *
*              valid menu selection.                                           *
*                                                                              *
*      Inputs: void                                                            *
*                                                                              *
*     Outputs: void                                                            *
*******************************************************************************/
int Menu::getSelection() const
{
   int selection = -1;

   cout << endl << prompt;
   ValidatedInput userInput;
   userInput.fromKeyboard();

   if (userInput.isInteger(UNSIGNED))
      selection = stoi(userInput.getInput());
   
   if (selection <= static_cast<int>(items.size()) && selection > 0)
      return selection;
   else
      return -1;
}



/******************
***** Setters *****
******************/
void Menu::setTitle(const std::string& title)
{
   this->title = title;
}


void Menu::setItems(const std::vector<std::string>& items)
{
   this->items.clear();
   this->items = items;
}


void Menu::setPrompt(const std::string& prompt)
{
   this->prompt = prompt;
}



/*******************************************************************************
*    Function: ValidatedInput::fromKeyboard                                    *
*                                                                              *
* Description: Read in keyboard input character by character from the terminal *
*              and stop reading after the user enters the '\n' character. The  *
*              newline character is not left in the keyboard buffer.           *
*                                                                              *
*      Inputs: void                                                            *
*                                                                              *
*     Outputs: void                                                            *
*******************************************************************************/
void ValidatedInput::fromKeyboard()
{
   char currentCharacter;

      // clear all old data from userInput
   input.clear();

   while ((currentCharacter = std::cin.get()) != '\n')
      input.push_back(currentCharacter);
}



/*******************************************************************************
*    Function: input::isInteger                                                *
*                                                                              *
* Description: Determines if userInput can represent an integer.               *
*                                                                              *
*      Inputs: isSigned - bool                                                 *
*                                                                              *
*     Outputs: bool - true if userInput contains numeric characters only       *
*******************************************************************************/
bool ValidatedInput::isInteger(bool isSigned) const
{
   unsigned int i = 0;

      // If the user hasn't entered any input
   if(!input.size())
      return false;

      // First character CAN be a '-' if we're looking for a signed integer
   else if (isSigned && input.at(i) == '-' && input.size() > 1)
      ++i;

   for (; i < input.size(); ++i)
   {
         // Does inputBuffer contain  a non-numeric value?
      if (input.at(i) < '0' || input.at(i) > '9')
         return false;
   }

   try
   {
      stoi(input);
   }
   catch (std::out_of_range)
   {
      return false;
   }

      // No invalid characters were found
   return true;
}



/*******************************************************************************
*    Function: input::isIntegerBetween                                         *
*                                                                              *
* Description: Determines if the input value is between low and highinclusive).*
*                                                                              *
*      Inputs:  low - int                                                      *
*              high - int                                                      *
*                                                                              *
*     Outputs: bool - true if input is a value from low through high.          *
*******************************************************************************/
bool ValidatedInput::isIntegerBetween(int low, int high) const
{
      // If value is not an integer, return false
   if (!isInteger(SIGNED))
      return false;

   int value;

      // Assign input to integer variable and return false if it's too big/small
   try
   {
      value = stoi(input);
   }
   catch (std::out_of_range)
   {
      return false;
   }

      // If integer value in input is between low and high, inclusive, it's true
   if (value >= low && value <= high)
      return true;
   else
      return false;
}



/*******************************************************************************
*    Function: input::isFloat                                                  *
*                                                                              *
* Description: Determines if userInput can represent a floating point number.  *
*                                                                              *
*      Inputs: isSigned - bool                                                 *
*                                                                              *
*     Outputs: bool - true if userInput contains numeric characters only       *
*******************************************************************************/
bool ValidatedInput::isFloat(bool isSigned) const
{
   unsigned int i = 0;

      // If the user hasn't entered any input
   if(!input.size())
      return false;

      // First character CAN be a '-' if we're looking for a signed integer
   else if (isSigned && input.at(i) == '-' && input.size() > 1)
      ++i;

   bool decimalSeen = false;

   for (; i < input.size(); ++i)
   {
         // If current character is a decimal point
      if (input.at(i) == '.')
      {
            // If this is the first decimal seen, it's okay
         if(!decimalSeen)
            decimalSeen = true;
            // More than one decimal has beem seen, not a floating point number
         else
            return false;
      }
         // Does inputBuffer contain  a non-numeric value?
      else if (input.at(i) < '0' || input.at(i) > '9')
         return false;
   }

      // No invalid characters were found
   return true;
}



/*******************************************************************************
*    Function: input::isYesOrNo                                                *
*                                                                              *
* Description: Returns true if input is a 'y' or 'n'. If capsAllowed is true,  *
*              then it will also return true on 'Y' or 'N'.                    *
*                                                                              *
*      Inputs: capsAllowed - bool                                              *
*                                                                              *
*     Outputs: void                                                            *
*******************************************************************************/
bool ValidatedInput::isYesOrNo(bool capsAllowed) const
{
      // If input has no characters
   if (!input.size())
      return false;
      // If input has more than a single character
   else if (input.size() > 1)
      return false;

      // input consists of a single character
   if (input.at(0) == 'y' || input.at(0) == 'n')
      return true;
   else if (capsAllowed && (input.at(0) == 'Y' || input.at(0) == 'N'))
      return true;
   
   else 
      return false;
}



/******************
***** Getters *****
******************/
std::string ValidatedInput::getInput() const
{
   return input;
}



/*******************************************************************************
*    Function: terminalClear                                                   *
*                                                                              *
* Description: Only works on *nix-systems. Clears the terminal window of any   *
*              displayed text.                                                 *
*                                                                              *
*      Inputs: void                                                            *
*                                                                              *
*     Outputs: void                                                            *
*******************************************************************************/
void terminalClear()
{
   std::printf("\033[2J\033[1;1H");
}

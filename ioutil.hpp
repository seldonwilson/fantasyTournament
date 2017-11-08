/*******************************************************************************
* Filename: ioutil.hpp                                                         *
* Author:   Daniel Wilson                                                      *
* E-Mail:   wilsond3@oregonstate.edu                                           *
* Date:     5 May 2017                                                         *
*                                                                              *
* Description: Provides the interface to classes and methods that aid in the   *
*    collection of user input from a keyboard and displaying output to a       *
*    command line interface.                                                   *
*                                                                              *
*******************************************************************************/

#ifndef IO_UTIL_HPP
#define IO_UTIL_HPP

#include <string>
#include <vector>

#define UNSIGNED false
#define SIGNED   true
#define NO_CAPS  false


class Menu
{
   private:
      std::string title;
      std::vector<std::string> items;
      std::string prompt;

   public:
         // Constructors
      Menu();
      Menu(const std::string&, 
           const std::vector<std::string>&, 
           const std::string&);

         // Prints the title and the menu items (w/ numbers in front)
      void print() const;
         // Replaces a current menu item with something else
      void changeItem(int, const std::string&);
         // Add an item to the end of the items vector
      void addItem(const std::string&);
         // Returns the menu selection from the user (-1 if invalid)
      int getSelection() const;

         // Setters
      void setTitle(const std::string&);
      void setItems(const std::vector<std::string>&);
      void setPrompt(const std::string&);
};



class ValidatedInput
{
   private:
      std::string input;

   public:
         // Stores keyboard input in userInput and stops at '\n'
      void fromKeyboard();
         // Returns if userInput contains a single integer w/ no whitespace
      bool isInteger(bool isSigned) const;
         // Returns true if the input value is between low and high (inclusive)
      bool isIntegerBetween(int low, int high) const;
      /* Returns if userInput contains a single floating point number with no
         whitespace
      */
      bool isFloat(bool isSigned) const;
         // Returns if userInput contains a 'y' or 'n'
      bool isYesOrNo(bool capsAllowed) const;
         // Getter for userInput userInput
      std::string getInput() const;
};



   // Uses *nix-specific commands to clear the screen
void terminalClear();


#endif // IO_UTIL_HPP

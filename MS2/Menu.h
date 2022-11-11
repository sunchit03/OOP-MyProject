/* ------------------------------------------------------
Citation and Sources
Final Project Milestone 2
Module: Menu
Filename: Menu.h
Version 1.0
Author	Sunchit Singh (169146214)
Revision History
-----------------------------------------------------------
Date      Reason
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------*/

#ifndef SDDS_MENU_H_
#define SDDS_MENU_H_
#include <iostream>
namespace sdds {
   const int MAX_NO_OF_ITEMS = 10;
   const int MAX_LENGTH = 50;
   const int INDENTATION = 4;


   class MenuItem {
      friend class Menu;

      char m_item[MAX_LENGTH + 1] = "";

      MenuItem() = default;
      MenuItem(const char* item);
      virtual ~MenuItem() {};
      std::ostream& display(std::ostream& coutRef = std::cout)const;
      MenuItem(const MenuItem&) = delete;
      void operator=(const MenuItem&) = delete;
   };


   class Menu {
      char m_title[MAX_LENGTH + 1];
      MenuItem m_mitem[MAX_NO_OF_ITEMS];
      int m_numOfItems = 0;
      int m_indent;
      bool isEmpty()const;

   public:
      Menu() = default;
      Menu(const char* title, int indent = 0);
      Menu(const Menu&) = delete;
      virtual ~Menu() {};
      void operator=(const Menu&) = delete;

      operator bool()const;
      
      std::ostream& display(std::ostream& coutRef = std::cout)const;
      Menu& operator=(const char* title);
      void add(const char* item);
      Menu& operator<<(const char* item);

      int run()const;
      operator int()const;

      void clear();
   };
}
#endif
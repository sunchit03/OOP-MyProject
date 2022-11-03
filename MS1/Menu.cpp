/* ------------------------------------------------------
Citation and Sources
Final Project Milestone 1
Module: Menu
Filename: Menu.cpp
Version 1.0
Author	Sunchit Singh (169146214)
Revision History
-----------------------------------------------------------
Date      Reason
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------*/

#include <iostream>
#include "Menu.h"
#include "Utils.h"

using namespace std;
namespace sdds {


   Menu::Menu(const char* title, int indent) {
      if (title) {
         strcpy(m_title, title, 50);
         m_indent = indent;
      }
      else {
         clear();
      }
   }

   Menu::operator bool() const {
      return m_title && m_title[0];
   }

   bool Menu::isEmpty() const {
      return !operator bool();
   }

   std::ostream& Menu::display(std::ostream& coutRef) const {
      if (isEmpty()) {
         coutRef << "Invalid Menu!" << endl;
      }
      else {
         for (int j = 0; j < m_indent * INDENTATION; j++) {
            coutRef << " ";
         }
         coutRef << m_title << endl;

         if (m_numOfItems == 0) {
            for (int j = 0; j < m_indent * INDENTATION; j++) {
               coutRef << " ";
            }
            coutRef << "No Items to display!" << endl;
         }
         else {
            for (int i = 0; i < m_numOfItems; i++) {

               for (int j = 0; j < m_indent * INDENTATION; j++) {
                  coutRef << " ";
               }

               coutRef << i + 1 << "- ";
               m_mitem[i].display();
            }

            for (int j = 0; j < m_indent * INDENTATION; j++) {
               coutRef << " ";
            }
            coutRef << "> ";
         }
      }
      return coutRef;
   }

   Menu& Menu::operator=(const char* title) {
      if (title) {
         strcpy(m_title, title, 50);
      }
      else {
         clear();
      }
      return *this;
   }


   void Menu::add(const char* item) {
      if (!item) {
         clear();
      }
      else if (!(m_numOfItems == MAX_NO_OF_ITEMS || isEmpty())) {
         strcpy(m_mitem[m_numOfItems].m_item, item);
         m_numOfItems++;
      }
   }

   Menu& Menu::operator<<(const char* item) {
      add(item);
      return *this;
   }

   int Menu::run() const{
      int selection = 0;
      display();
      if (m_numOfItems) {
         cin >> selection;

         do {
            if (cin.fail()) {
               
               cin.clear();
               cin.ignore(10000, '\n');
               cout << "Invalid Integer, try again: ";
               cin >> selection;
            }
            else if (selection < 1 || selection > m_numOfItems) {
               cout << "Invalid selection, try again: ";
               cin >> selection;
            }
         } while (cin.fail() || selection < 1 || selection > m_numOfItems);
         cin.ignore(1000, '\n');
      }
      return selection;
   }

   Menu::operator int() const {
      return run();
   }

   void Menu::clear() {
      strcpy(m_title, "");
      m_indent = 0;
      
      for (int i = 0; i < m_numOfItems; i++) {
         strcpy(m_mitem[i].m_item, "");
      }
      m_numOfItems = 0;
   }


   MenuItem::MenuItem(const char* item) {
      if (item) {
         strcpy(m_item, item, 50);
      }
   }

   std::ostream& MenuItem::display(std::ostream& coutRef) const {
      if (m_item && m_item[0]) {
         coutRef << m_item << endl;
      }
      return coutRef;
   }

}

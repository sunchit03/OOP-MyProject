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
         strcpy(m_title, "");
         m_indent = 0;
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
         if (m_numOfItems == 0) {
            coutRef << "No Items to display!" << endl;
         }
         else {
            coutRef << m_title << endl;

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
         strcpy(m_title, "");
      }
      return *this;
   }


   void Menu::add(const char* item) {
      if (!item) {
         strcpy(m_title, "");
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

         while (cin.fail() || selection < 1 || selection > m_numOfItems) {
            if (cin.fail()) {
               cin.ignore(1000, '\n');
               cout << "Invalid Integer, try again: ";
               cin >> selection;
            }

            if (selection < 1 || selection > m_numOfItems) {
               cout << "Invalid selection, try again: ";
               cin >> selection;
            }
         }
      }
      return selection;
   }

   Menu::operator int() const{
      return run();
   }


   std::ostream& MenuItem::display(std::ostream& coutRef) const {
      if (m_item && m_item[0]) {
         coutRef << m_item << endl;
      }
      return coutRef;
   }

}

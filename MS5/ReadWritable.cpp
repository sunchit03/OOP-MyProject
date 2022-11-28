/* ------------------------------------------------------
Citation and Sources
Final Project Milestone 5
Module: ReadWritable
Filename: ReadWritable.cpp
Version 1.0
Author	Sunchit Singh (169146214)
Revision History
-----------------------------------------------------------
Date      Reason
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------*/

#include "ReadWritable.h"

namespace sdds {

   ReadWritable::ReadWritable() {
      m_csv = false;
   }

   bool ReadWritable::isCsv() const{
      return m_csv;
   }

   void ReadWritable::setCsv(bool value) {
      m_csv = value;
   }


   std::ostream& operator<<(std::ostream& ostr, const ReadWritable& rightOperand) {
      return rightOperand.write(ostr);
   }

   std::istream& operator>>(std::istream& istr, ReadWritable& rightOperand) {
      return rightOperand.read(istr);
   }
}
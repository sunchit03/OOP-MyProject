/* ------------------------------------------------------
Citation and Sources
Final Project Milestone 3
Module: ReadWritable
Filename: ReadWritable.h
Version 1.0
Author	Sunchit Singh (169146214)
Revision History
-----------------------------------------------------------
Date      Reason
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------*/

#ifndef SDDS_READ_WRITABLE_H_
#define SDDS_READ_WRITABLE_H_
#include <iostream>
namespace sdds {
   class ReadWritable {
      bool csv;

   public:
      ReadWritable();
      virtual ~ReadWritable() {};

      bool isCsv() const;
      void setCsv(bool value);

      virtual std::ostream& write(std::ostream& ostr = std::cout)const = 0;
      virtual std::istream& read(std::istream& istr = std::cin) = 0;
   };

   std::ostream& operator<<(std::ostream& ostr, const ReadWritable& rightOperand);
   std::istream& operator>>(std::istream& istr, ReadWritable& rightOperand);
}

#endif
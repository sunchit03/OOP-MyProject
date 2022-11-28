/* ------------------------------------------------------
Citation and Sources
Final Project Milestone 5
Module: Motorcycle
Filename: Motorcycle.h
Version 1.0
Author	Sunchit Singh (169146214)
Revision History
-----------------------------------------------------------
Date      Reason
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------*/

#ifndef SDDS_MOTORCYCLE_H_
#define SDDS_MOTORCYLE_H_
#include "Vehicle.h"

namespace sdds {
   class Motorcycle : public Vehicle {
   private:
      bool m_sidecar{};

   public:
      Motorcycle();
      Motorcycle(const char* license, const char* makeModel);

      Motorcycle(const Motorcycle& toCopyFrom);
      Motorcycle& operator=(const Motorcycle& toCopyFrom);
      ~Motorcycle() {};

      std::ostream& writeType(std::ostream& ostr = std::cout)const;
      std::istream& read(std::istream& istr = std::cin);
      std::ostream& write(std::ostream& ostr = std::cout)const;
   };
}
#endif

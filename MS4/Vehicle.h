/* ------------------------------------------------------
Citation and Sources
Final Project Milestone 3
Module: Vehicle
Filename: Vehicle.h
Version 1.0
Author	Sunchit Singh (169146214)
Revision History
-----------------------------------------------------------
Date      Reason
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------*/

#ifndef SDDS_VEHICLE_H_
#define SDDS_VEHICLE_H_
#include "ReadWritable.h"
namespace sdds {

   class Vehicle: public ReadWritable {
      char m_licensePlate[8 + 1]{};
      char* m_makeModel{};
      unsigned int m_spot = 0;

   protected:
      void setEmpty();
      bool isEmpty()const;

      const char* getLicensePlate()const;
      const char* getMakeModel()const;
      int getParkingSpot()const;
      void setMakeModel(const char* makeModel);

   public:
      Vehicle();
      Vehicle(const char* license, const char* makeModel);

      Vehicle(const Vehicle& toCopyFrom);
      Vehicle& operator=(const Vehicle& toCopyFrom);
      virtual ~Vehicle();

      void setParkingSpot(int spot);

      bool operator==(const char* license)const;
      bool operator==(const Vehicle& rightOperand)const;

      std::istream& read(std::istream& istr = std::cin);
      virtual std::ostream& writeType(std::ostream& ostr = std::cout)const = 0;
      std::ostream& write(std::ostream& ostr = std::cout)const;
   };
}

#endif
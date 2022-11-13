#ifndef SDDS_VEHICLE_H_
#define SDDS_VEHICLE_H_
#include "ReadWritable.h"
namespace sdds {

   class Vehicle: public ReadWritable {
      char m_licensePlate[8 + 1];
      char* m_makeModel{};
      unsigned int m_spot = 0;

      void setEmpty();
      bool isEmpty()const;

      const char* getLicensePlate()const;
      const char* getMakeModel()const;
      int getParkingSpot()const;

   public:
      Vehicle();
      Vehicle(const char* license, const char* makeModel);

      Vehicle(const Vehicle& toCopyFrom);
      Vehicle& operator=(const Vehicle& toCopyFrom);
      ~Vehicle();

      void setMakeModel(const char* makeModel);
      void setParkingSpot(int spot);

      bool operator==(const char* license);
      bool operator==(Vehicle& rightOperand);

      std::istream& read(std::istream& istr = std::cin);
      virtual std::ostream& writeType(std::ostream& ostr = std::cout)const = 0;
      std::ostream& write(std::ostream& ostr = std::cout)const;
   };
}

#endif
#ifndef SDDS_VEHICLE_H_
#define SDDS_VEHICLE_H_
#include "ReadWritable.h"
namespace sdds {

   class Vehicle: public ReadWritable {
      char m_licensePlate[8 + 1] = "";
      char* m_makeModel{};
      unsigned int m_spot = 0;

   public:
      Vehicle();
      Vehicle(const char* license, const char* makeModel);

      Vehicle(Vehicle& toCopyFrom);
      Vehicle& operator=(Vehicle& toCopyFrom);

      void setEmpty();
      bool isEmpty()const;

      const char& getLicensePlate()const;
      const char& getMakeModel()const;

      void setMakeModel(const char* makeModel);

      int getParkingSpot()const;
      void setParkingSpot(int spot);
   };
}

#endif
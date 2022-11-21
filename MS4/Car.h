#ifndef SDDS_CAR_H_
#define SDDS_CAR_H_
#include "Vehicle.h"

namespace sdds {
   class Car: public Vehicle {
   private :
      bool m_carwash;

   public:
      Car();
      Car(const char* license, const char* makeModel);

      Car(const Car& toCopyFrom);
      Car& operator=(const Car& toCopyfrom);
      ~Car() {};

      std::ostream& writeType(std::ostream& ostr = std::cout)const;
      std::istream& read(std::istream& istr = std::cin);
      std::ostream& write(std::ostream& ostr = std::cout)const;
   };
}

#endif
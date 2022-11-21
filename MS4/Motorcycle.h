#ifndef SDDS_MOTORCYCLE_H_
#define SDDS_MOTORCYLE_H_
#include "Vehicle.h"

namespace sdds {
   class Motorcycle : public Vehicle {
   private:
      bool m_sidecar;

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

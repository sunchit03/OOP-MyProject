#include "ReadWritable.h"

namespace sdds {

   ReadWritable::ReadWritable() {
      csv = false;
   }

   bool ReadWritable::isCsv() const{
      return csv;
   }

   void ReadWritable::setCsv(bool value) {
      csv = value;
   }


   std::ostream& operator<<(std::ostream& ostr, ReadWritable& rightOperand) {
      return rightOperand.write(ostr);
   }

   std::istream& operator>>(std::istream& istr, ReadWritable& rightOperand) {
      return rightOperand.read(istr);
   }
}
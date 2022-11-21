#include <iostream>
#include "Car.h"
using namespace std;
namespace sdds {

   Car::Car(): Vehicle() {
      m_carwash = false;
   }

   Car::Car(const char* license, const char* makeModel): Vehicle(license, makeModel) {
      
      if (!(Vehicle::getLicensePlate() && Vehicle::getMakeModel())) {
         m_carwash = false;
      }
   }

   Car::Car(const Car& toCopyFrom): Vehicle(toCopyFrom) {
      m_carwash = toCopyFrom.m_carwash;
   }

   Car& Car::operator=(const Car& toCopyFrom) {
      if (this != &toCopyFrom) {
         Vehicle::operator=(toCopyFrom);
         m_carwash = toCopyFrom.m_carwash;
      }
      return *this;
   }

   std::ostream& Car::writeType(std::ostream& ostr) const {
      if (isCsv()) {
         ostr << "C,";
      }
      else {
         ostr << "Vehicle type: Car" << endl;
      }
      return ostr;
   }

   std::istream& Car::read(std::istream& istr) {
      if (isCsv()) {
         Vehicle::read(istr);
         istr >> m_carwash;
         istr.ignore(10000, '\n');
      }
      else {
         char response[10 + 1];
         cout << "Car information entry" << endl;
         Vehicle::read(istr);
         cout << "Carwash while parked? (Y)es/(N)o: ";
         istr.getline(response, 10, '\n');
         //istr.ignore(10000, '\n');
         
         while (!(strcmp(response, "Y") == 0 || strcmp(response, "y") == 0 || strcmp(response, "N") == 0 || strcmp(response, "n") == 0)) {
            //istr.clear();
            cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
            istr.getline(response, 10, '\n');
            //istr.ignore(10000, '\n');
         }

         if (strcmp(response, "Y") == 0 || strcmp(response, "y") == 0) {
            m_carwash = true;
         }
         else {
            m_carwash = false;
         }
      }
      return istr;
   }

   std::ostream& Car::write(std::ostream& ostr)const {
      if (isEmpty()) {
         ostr << "Invalid Car Object" << endl;
      }
      else {
         Vehicle::write(ostr);
         if (isCsv()) {
            ostr << m_carwash << endl;
         }
         else {
            if (m_carwash) {
               ostr << "With Carwash" << endl;
            }
            else {
               ostr << "Without Carwash" << endl;
            }
         }
      }
      return ostr;
   }

}
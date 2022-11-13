#include "Vehicle.h"

namespace sdds {

   Vehicle::Vehicle() {
      setEmpty();
   }

   Vehicle::Vehicle(const char* license, const char* makeModel) {
      if (license && strlen(license) >= 1 && strlen(license) <= 8 && makeModel && strlen(makeModel) > 2) {
         strcpy(m_licensePlate, license);

         m_makeModel = new char[strlen(makeModel) + 1];
         strcpy(m_makeModel, makeModel);

         m_spot = 0;
      }
      else {

      }
   }

   Vehicle::Vehicle(Vehicle& toCopyFrom) {
      operator=(toCopyFrom);
   }

   Vehicle& Vehicle::operator=(Vehicle& toCopyFrom) {
      if (this != &toCopyFrom) {
         strcpy(m_licensePlate, toCopyFrom.m_licensePlate);

         delete[] m_makeModel;
         m_makeModel = nullptr;
         m_makeModel = new char[strlen(toCopyFrom.m_makeModel) + 1];
         strcpy(m_makeModel, toCopyFrom.m_makeModel);

         m_spot = toCopyFrom.m_spot;
      }
   }

   void Vehicle::setEmpty() {
      strcpy(m_licensePlate, "");
      delete[] m_makeModel;
      m_makeModel = nullptr;
      m_spot = 0;
   }

   bool Vehicle::isEmpty() const{
      return !(m_licensePlate && strlen(m_licensePlate) >= 1 && strlen(m_licensePlate) <= 8 && m_makeModel && strlen(m_makeModel) > 2);
   }

   const char& Vehicle::getLicensePlate() const {
      return *m_licensePlate;
   }

   const char& Vehicle::getMakeModel() const {
      return *m_makeModel;
   }

   void Vehicle::setMakeModel(const char* makeModel) {
      if (makeModel && strlen(makeModel) > 2) {
         delete[] m_makeModel;
         m_makeModel = nullptr;
         m_makeModel = new char[strlen(makeModel) + 1];
         strcpy(m_makeModel, makeModel);
      }
      else {
         setEmpty();
      }
   }

   int Vehicle::getParkingSpot() const{
      return m_spot;
   }

   void Vehicle::setParkingSpot(int spot) {
      if (spot >= 0) {
         m_spot = spot;
      }
      else {
         setEmpty();
      }
   }
}
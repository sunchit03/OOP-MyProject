#include "Vehicle.h"
#include "Utils.h"
#include <iostream>

using namespace std;
namespace sdds {

   Vehicle::Vehicle() {
      setEmpty();
   }

   Vehicle::Vehicle(const char* license, const char* makeModel) {
      if (license && strlen(license) >= 1 && strlen(license) <= 8 && makeModel && strlen(makeModel) > 2) {
         strcpy(m_licensePlate, license);

         /*delete[] m_makeModel;
         m_makeModel = nullptr;*/
         m_makeModel = new char[strlen(makeModel) + 1];
         strcpy(m_makeModel, makeModel);

         m_spot = 0;
      }
      else {
         setEmpty();
      }
   }

   Vehicle::Vehicle(const Vehicle& toCopyFrom) {
      setEmpty();
      operator=(toCopyFrom);
   }

   Vehicle& Vehicle::operator=(const Vehicle& toCopyFrom) {
      if (this != &toCopyFrom) {
         setEmpty();
         strcpy(m_licensePlate, toCopyFrom.m_licensePlate);

         delete[] m_makeModel;
         m_makeModel = nullptr;
         m_makeModel = new char[strlen(toCopyFrom.m_makeModel) + 1];
         strcpy(m_makeModel, toCopyFrom.m_makeModel);

         m_spot = toCopyFrom.m_spot;
      }
      return *this;
   }

   Vehicle::~Vehicle() {
      delete[] m_makeModel;
      m_makeModel = nullptr;
   }

   void Vehicle::setEmpty() {
      strcpy(m_licensePlate, "");
      delete[] m_makeModel;
      m_makeModel = nullptr;
      m_spot = 0;
   }

   bool Vehicle::isEmpty() const{
      return !(m_licensePlate && strlen(m_licensePlate) >= 1 && strlen(m_licensePlate) <= 8 && m_makeModel && strlen(m_makeModel) >= 2);
   }

   const char* Vehicle::getLicensePlate() const {
      return m_licensePlate;
   }

   const char* Vehicle::getMakeModel() const {
      return m_makeModel;
   }

   void Vehicle::setMakeModel(const char* makeModel) {
      if (makeModel && strlen(makeModel) >= 2) {
         delete[] m_makeModel;
         m_makeModel = nullptr;
         m_makeModel = new char[strlen(makeModel) + 1];
         strcpy(m_makeModel, makeModel);
      }
      else {
         setEmpty();
      }
   }

   int Vehicle::getParkingSpot() const {
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

   bool Vehicle::operator==(const char* license) {
      bool retVal = false;
      if (license && strlen(license) >= 1 && strlen(license) <= 8) {
         char tempLicense[8 + 1]{};
         for (int i = 0; i < strlen(license); i++) {
            tempLicense[i] = tolower(license[i]);
         }
         trim(tempLicense);

         char temp_m_licensePlate[8 + 1]{};
         for (int i = 0; i < strlen(m_licensePlate); i++) {
            temp_m_licensePlate[i] = tolower(m_licensePlate[i]);
         }
         trim(temp_m_licensePlate);

         if (strcmp(temp_m_licensePlate, tempLicense) == 0) {
            retVal = true;
         }
      }
      return retVal;
   }

   bool Vehicle::operator==(Vehicle& rightOperand) {
      bool retVal = false;
      if (rightOperand.m_licensePlate && strlen(rightOperand.m_licensePlate) >= 1 && strlen(rightOperand.m_licensePlate) <= 8) {
         char tempLicense[8 + 1]{};
         for (int i = 0; i < strlen(rightOperand.m_licensePlate); i++) {
            tempLicense[i] = tolower(rightOperand.m_licensePlate[i]);
         }
         trim(tempLicense);

         char temp_m_licensePlate[8 + 1]{};
         for (int i = 0; i < strlen(m_licensePlate); i++) {
            temp_m_licensePlate[i] = tolower(m_licensePlate[i]);
         }
         trim(temp_m_licensePlate);

         if (strcmp(temp_m_licensePlate, tempLicense) == 0) {
            retVal = true;
         }
      }
      return retVal;
   }

   std::istream& Vehicle::read(std::istream& istr) {
      char tempMakeModel[60 + 1]{};
      if (isCsv()) {
         istr >> m_spot;
         istr.ignore(1, ',');
         istr.getline(m_licensePlate, 8, ',');
         for (int i = 0; i < strlen(m_licensePlate); i++) {
            m_licensePlate[i] = toupper(m_licensePlate[i]);
         }

         istr.getline(tempMakeModel, 60, ',');
         delete[] m_makeModel;
         m_makeModel = nullptr;
         m_makeModel = new char[strlen(tempMakeModel) + 1];
         strcpy(m_makeModel, tempMakeModel);
      }
      else {
         cout << "Enter Licence Plate Number: ";
         istr >> m_licensePlate;
         while (strlen(m_licensePlate) > 8) {
            cout << "Invalid Licence Plate, try again: ";
            strcpy(m_licensePlate, "");
            istr >> m_licensePlate;
         }
         for (int i = 0; i < strlen(m_licensePlate); i++) {
            m_licensePlate[i] = toupper(m_licensePlate[i]);
         }

         cout << "Enter Make and Model: ";
         istr >> tempMakeModel;
         while (!(strlen(tempMakeModel) >= 2 && strlen(tempMakeModel) <= 60)) {
            cout << "Invalid Make and model, try again: ";
            strcpy(tempMakeModel, "");
            istr >> tempMakeModel;
         }
         delete[] m_makeModel;
         m_makeModel = nullptr;
         m_makeModel = new char[strlen(tempMakeModel) + 1];
         strcpy(m_makeModel, tempMakeModel);
      }

      if (istr.fail()) {
         setEmpty();
      }
      return istr;
   }

   std::ostream& Vehicle::write(std::ostream& ostr) const {
      if (isEmpty()) {
         ostr << "Invalid Vehicle Object" << endl;
      }
      else {
         writeType(ostr);

         if (isCsv()) {
            ostr << getParkingSpot() << "," << getLicensePlate() << "," << getMakeModel() << ",";
         }
         else {
            ostr << "Parking Spot Number: ";
            if (m_spot == 0) {
               ostr << "N/A";
            }
            else {
               ostr << getParkingSpot();
            }
            ostr << endl;

            ostr << "Licence Plate: " << getLicensePlate() << endl;

            ostr << "Make and Model: " << getMakeModel() << endl;
         }
      }
      return ostr;
   }
}
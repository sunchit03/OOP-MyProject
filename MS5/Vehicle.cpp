/* ------------------------------------------------------
Citation and Sources
Final Project Milestone 5
Module: Vehicle
Filename: Vehicle.cpp
Version 1.0
Author	Sunchit Singh (169146214)
Revision History
-----------------------------------------------------------
Date      Reason
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------*/

#include <iostream>
#include "Vehicle.h"
#include "Utils.h"

using namespace std;
namespace sdds {

   Vehicle::Vehicle() {
      setEmpty();
   }

   Vehicle::Vehicle(const char* license, const char* makeModel) {
      if (license && strlen(license) >= 1 && strlen(license) <= 8 && makeModel && strlen(makeModel) > 2) {
         strcpy(m_licensePlate, license);

         m_makeModel = alcpy(makeModel);

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
      if (this != &toCopyFrom && !toCopyFrom.isEmpty()) {
         setEmpty();
         strcpy(m_licensePlate, toCopyFrom.m_licensePlate);

         delete[] m_makeModel;
         m_makeModel = nullptr;

         m_makeModel = alcpy(toCopyFrom.m_makeModel);

         m_spot = toCopyFrom.m_spot;

         setCsv(toCopyFrom.isCsv());
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

   int Vehicle::getParkingSpot() const {
      return m_spot;
   }

   void Vehicle::setMakeModel(const char* makeModel) {
      if (makeModel && strlen(makeModel) >= 2) {
         delete[] m_makeModel;
         m_makeModel = nullptr;

        m_makeModel = alcpy(makeModel);
      }
      else {
         setEmpty();
      }
   }

   void Vehicle::setParkingSpot(int spot) {
      if (spot >= 0) {
         m_spot = spot;
      }
      else {
         setEmpty();
      }
   }

   bool Vehicle::operator==(const char* license)const {
      bool retVal = false;
      if (license && strlen(license) >= 1 && strlen(license) <= 8) {
         char tempLicense[8 + 1]{};
         for (int i = 0; i < strlen(license); i++) {
            tempLicense[i] = toupper(license[i]);
         }

         if (strcmp(m_licensePlate, tempLicense) == 0) {
            retVal = true;
         }
      }
      return retVal;
   }

   bool Vehicle::operator==(const Vehicle& rightOperand)const {
      bool retVal = false;
      if (rightOperand.m_licensePlate && strlen(rightOperand.m_licensePlate) >= 1 && strlen(rightOperand.m_licensePlate) <= 8) {
         char tempLicense[8 + 1]{};
         for (int i = 0; i < strlen(rightOperand.m_licensePlate); i++) {
            tempLicense[i] = toupper(rightOperand.m_licensePlate[i]);
         }

         if (strcmp(m_licensePlate, tempLicense) == 0) {
            retVal = true;
         }
      }
      return retVal;
   }

   std::istream& Vehicle::read(std::istream& istr) {
      char tempMakeModel[60 + 1];
      int spot;
      if (isCsv()) {
         istr >> spot;
         if (!istr.fail()) {
            istr.ignore(1, ',');
            istr.getline(m_licensePlate, 8, ',');
            for (int i = 0; i < strlen(m_licensePlate); i++) {
               m_licensePlate[i] = toupper(m_licensePlate[i]);
            }

            istr.getline(tempMakeModel, 60, ',');

            setParkingSpot(spot);
            setMakeModel(tempMakeModel);
         }
      }
      else {
         char tempLicensePlate[50 + 1]{};

         cout << "Enter License Plate Number: ";
         istr.getline(tempLicensePlate, 50, '\n');
         while (strlen(tempLicensePlate) > 8) {
            cout << "Invalid License Plate, try again: ";
            strcpy(tempLicensePlate, "");
            istr.getline(tempLicensePlate, 50, '\n');
         }
         strcpy(m_licensePlate, tempLicensePlate);
         for (int i = 0; i < strlen(m_licensePlate); i++) {
            m_licensePlate[i] = toupper(m_licensePlate[i]);
         }

         cout << "Enter Make and Model: ";
         istr.getline(tempMakeModel, 60, '\n');
         while (!(strlen(tempMakeModel) >= 2 && strlen(tempMakeModel) <= 60)) {
            cout << "Invalid Make and model, try again: ";
            strcpy(tempMakeModel, "");
            istr.getline(tempMakeModel, 60, '\n');
         }

         setMakeModel(tempMakeModel);
      }

      if (istr.fail()) {
         istr.clear();
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

            ostr << "License Plate: " << getLicensePlate() << endl;

            ostr << "Make and Model: " << getMakeModel() << endl;
         }
      }
      return ostr;
   }
}
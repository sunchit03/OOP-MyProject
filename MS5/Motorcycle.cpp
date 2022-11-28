/* ------------------------------------------------------
Citation and Sources
Final Project Milestone 5
Module: Motorcycle
Filename: Motorcycle.cpp
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
#include "Motorcycle.h"
#include "Utils.h"
using namespace std;

namespace sdds {
   
   Motorcycle::Motorcycle(): Vehicle() {
      m_sidecar = false;
   }

   Motorcycle::Motorcycle(const char* license, const char* makeModel): Vehicle(license, makeModel) {
      if (!(Vehicle::getLicensePlate() && Vehicle::getMakeModel())) {
         m_sidecar = false;
      }
   }

   Motorcycle::Motorcycle(const Motorcycle& toCopyFrom): Vehicle(toCopyFrom) {
      m_sidecar = toCopyFrom.m_sidecar;
   }

   Motorcycle& Motorcycle::operator=(const Motorcycle& toCopyFrom) {
      if (this != &toCopyFrom) {
         Vehicle::operator=(toCopyFrom);
         m_sidecar = toCopyFrom.m_sidecar;
      }
      return *this;
   }

   std::ostream& Motorcycle::writeType(std::ostream& ostr)const {
      if (isCsv()) {
         ostr << "M,";
      }
      else {
         ostr << "Vehicle type: Motorcycle" << endl;
      }
      return ostr;
   }

   std::istream& Motorcycle::read(std::istream& istr) {
      if (isCsv()) {
         Vehicle::read(istr);
         istr >> m_sidecar;
         istr.ignore(10000, '\n');
      }
      else {
         char response[10 + 1];
         cout << endl << "Motorcycle information entry" << endl;
         Vehicle::read(istr);
         cout << "Does the Motorcycle have a side car? (Y)es/(N)o: ";
         istr.getline(response, 10, '\n');

         while (!(strcmp(response, "Y") == 0 || strcmp(response, "y") == 0 || strcmp(response, "N") == 0 || strcmp(response, "n") == 0)) {
            cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
            istr.getline(response, 10, '\n');
         }

         if (strcmp(response, "Y") == 0 || strcmp(response, "y") == 0) {
            m_sidecar = true;
         }
         else {
            m_sidecar = false;
         }
      }
      return istr;
   }

   std::ostream& Motorcycle::write(std::ostream& ostr)const {
      if (isEmpty()) {
         ostr << "Invalid Motorcycle Object" << endl;
      }
      else {
         Vehicle::write(ostr);
         if (isCsv()) {
            ostr << m_sidecar << endl;
         }
         else {
            if (m_sidecar) {
               ostr << "With Sidecar" << endl;
            }
         }
      }
      return ostr;
   }
}
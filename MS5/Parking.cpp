/* ------------------------------------------------------
Citation and Sources
Final Project Milestone 5
Module: Parking
Filename: Parking.cpp
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
#include <fstream>
#include "Parking.h"
using namespace std;
namespace sdds {

   Parking::Parking(const char* filename, int noOfSpots) {
      if (filename && filename[0] && noOfSpots >= 10 && noOfSpots <= MAX_NUMBER_OF_SPOTS) {

         m_filename = alcpy(filename);

         m_numOfSpots = noOfSpots;

         if (loadData()) {
            
            m_parking << "Park Vehicle" << "Return Vehicle" << "List Parked Vehicles" 
               << "Find Vehicle" << "Close Parking (End of day)" << "Exit Program";

            m_vehicle << "Car" << "Motorcycle" << "Cancel";
         }
         else {
            cout << "Error in data file" << endl;
            delete[] m_filename;
            m_filename = nullptr;
            m_parking.clear();
            m_vehicle.clear();
         }

      }
      else {
         cout << "Error in data file" << endl;
         delete[] m_filename;
         m_filename = nullptr;
         m_parking.clear();
         m_vehicle.clear();
      }
   }

   Parking::~Parking() {
      delete[] m_filename;
      m_filename = nullptr;
   }

   int Parking::run() {
      int retVal = 1;
      if (!isEmpty()) {
         bool done = false;
         while (!done) {
            parkingStatus();
            int selection = m_parking.run();
            switch (selection) {
            case 1:
               parkVehicle();
               pause();
               break;

            case 2:
               returnVehicle();
               pause();
               break;

            case 3:
               listVehicle();
               pause();
               break;

            case 4:
               findVehicle();
               pause();
               break;

            case 5:
               if (closeParking()) {
                  done = true;
               }
               else {
                  pause();
               }
               break;

            case 6:
               if (exitParking()) {
                  done = true;
               }
               else {
                  pause();
               }
            }
         }
         retVal = 0;
      }
      return retVal;
   }

   bool Parking::isEmpty() const{
      return !(m_filename && m_filename[0]);
   }

   void Parking::parkingStatus() const{
      cout << "****** Valet Parking ******" << endl;
      cout << "*****  Available spots: ";
      cout.setf(ios::left);
      cout.width(4);
      cout.fill(' ');
      cout << m_numOfSpots - m_numOfParkedVehicles;
      cout.unsetf(ios::left);
      cout << " *****" << endl;
   }

   void Parking::parkVehicle() {

      if (m_numOfParkedVehicles == m_numOfSpots) {
         cout << "Parking is full" << endl;
      }
      else {
         int selection = m_vehicle.run();
         Vehicle* sptr;
         switch (selection) {
         case 1:
            sptr = new Car;
            sptr->setCsv(false);
            cin >> *sptr;

            for (int i = 0; i < m_numOfSpots; i++) {
               if (!m_parkingSpots[i]) {
                  m_parkingSpots[i] = sptr;
                  sptr->setParkingSpot(i + 1);
               }
            }
            cout << endl << "Parking Ticket" << endl;
            cout << *sptr << endl;
            m_numOfParkedVehicles++;

            break;

         case 2:
            sptr = new Motorcycle;
            sptr->setCsv(false);
            cin >> *sptr;

            for (int i = 0; i < m_numOfSpots; i++) {
               if (!m_parkingSpots[i]) {
                  m_parkingSpots[i] = sptr;
                  sptr->setParkingSpot(i + 1);
               }
            }
            cout << endl << "Parking Ticket" << endl;
            cout << *sptr << endl;
            m_numOfParkedVehicles++;

            break;

         case 3:
            cout << "Parking Cancelled" << endl;
         }
      }
   }

   void Parking::returnVehicle() {
      cout << "Return Vehicle" << endl;

      char tempLicensePlate[50 + 1]{};

      cout << "Enter Licence Plate Number: ";
      cin.getline(tempLicensePlate, 50, '\n');
      while (strlen(tempLicensePlate) < 1 || strlen(tempLicensePlate) > 8) {
         cout << "Invalid License Plate, try again: ";
         strcpy(tempLicensePlate, "");
         cin.getline(tempLicensePlate, 50, '\n');
      }
      cout << endl;

      bool retVal = false;
      int index = -1;
      for (int i = 0; i < m_numOfSpots && !retVal; i++) {
         if (m_parkingSpots[i]) {
            retVal = m_parkingSpots[i]->operator==(tempLicensePlate);
            index = i;
         }
      }

      if (retVal) {
         cout << "Returning:" << endl;
         m_parkingSpots[index]->setCsv(false);
         cout << *m_parkingSpots[index] << endl;
         delete m_parkingSpots[index];
         m_parkingSpots[index] = nullptr;
         m_numOfParkedVehicles--;
      }
      else {
         for (int i = 0; i < strlen(tempLicensePlate); i++) {
            tempLicensePlate[i] = toupper(tempLicensePlate[i]);
         }
        cout << "License plate " << tempLicensePlate << " Not found" << endl << endl;
      }
   }

   void Parking::listVehicle() {

      cout << "*** List of parked vehicles ***" << endl;
      for (int i = 0; i < m_numOfSpots; i++) {
         if (m_parkingSpots[i]) {
            m_parkingSpots[i]->setCsv(false);
            cout << *m_parkingSpots[i];
            cout << "-------------------------------" << endl;
         }
      }
   }

   void Parking::findVehicle() {

      char tempLicensePlate[50 + 1]{};
      cout << "Vehicle Search" << endl;

      cout << "Enter Licence Plate Number: ";
      cin.getline(tempLicensePlate, 50, '\n');
      while (strlen(tempLicensePlate) < 1 || strlen(tempLicensePlate) > 8) {
         cout << "Invalid License Plate, try again: ";
         strcpy(tempLicensePlate, "");
         cin.getline(tempLicensePlate, 50, '\n');
      }
      cout << endl;

      bool retVal = false;
      int index = -1;
      for (int i = 0; i < m_numOfSpots && !retVal; i++) {
         if (m_parkingSpots[i]) {
            retVal = m_parkingSpots[i]->operator==(tempLicensePlate);
            index = i;
         }
      }

      if (retVal) {
         cout << "Vechicle found: " << endl;
         m_parkingSpots[index]->setCsv(false);
         cout << *m_parkingSpots[index] << endl;
      }
      else {
         for (int i = 0; i < strlen(tempLicensePlate); i++) {
            tempLicensePlate[i] = toupper(tempLicensePlate[i]);
         }
         cout << "License plate " << tempLicensePlate << " Not found" << endl << endl;
      }
   }

   bool Parking::closeParking() {
      bool retVal = false;
      if (m_numOfParkedVehicles == 0) {
         cout << "Closing Parking" << endl;
         retVal = true;
      }
      else {
         char selection[10 + 1];
         cout << "This will This will Remove and tow all remaining vehicles from the parking!!" << endl;
         cout << "Are you sure? (Y)es/(N)o: ";
         cin.getline(selection, 10, '\n');
         while (!(strcmp(selection, "Y") == 0 || strcmp(selection, "y") == 0 || strcmp(selection, "N") == 0 || strcmp(selection, "n") == 0)) {
            cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
            cin.getline(selection, 10, '\n');
         }

         if (strcmp(selection, "Y") == 0 || strcmp(selection, "y") == 0) {
            cout << "Closing Parking" << endl;

            for (int i = 0; i < m_numOfSpots && m_numOfParkedVehicles; i++) {
               if (m_parkingSpots[i]) {
                  m_parkingSpots[i]->setCsv(false);
                  cout << endl << "Towing request" << endl;
                  cout << "*********************" << endl;
                  cout << *m_parkingSpots[i];
                  delete m_parkingSpots[i];
                  m_parkingSpots[i] = nullptr;
                  m_numOfParkedVehicles--;
               }
            }
            if (m_numOfParkedVehicles == 0) {
               retVal = true;

               saveData();
            }
         }
         else {
            retVal = false;
         }
      }
      return retVal;
   }

   bool Parking::exitParking() {
      char selection[10 + 1];
      cout << "This will This will terminate the program!!" << endl;
      cout << "Are you sure? (Y)es/(N)o: ";
      cin.getline(selection, 10, '\n');
      while (!(strcmp(selection, "Y") == 0 || strcmp(selection, "y") == 0 || strcmp(selection, "N") == 0 || strcmp(selection, "n") == 0)) {
         cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
         cin.getline(selection, 10, '\n');
      }

      if (strcmp(selection, "Y") == 0 || strcmp(selection, "y") == 0) {
         cout << "Exiting program!" << endl;
         saveData();
      }
      return strcmp(selection, "Y") == 0 || strcmp(selection, "y") == 0;
   }

   bool Parking::loadData() {
      bool retVal = false;
      if (!isEmpty()) {

         ifstream file(m_filename);

         if (!file || isEmpty()) {
            retVal = true;
         }
         else {
            bool flag = true;
            Vehicle* sptr;

            while (file && flag && m_numOfParkedVehicles <= MAX_NUMBER_OF_SPOTS) {
               sptr = nullptr;
               char vehicleType = 'x';
               file.get(vehicleType);
               file.ignore();
               if (vehicleType == 'M' || vehicleType == 'C') {
                  if (vehicleType == 'M') {
                     sptr = new Motorcycle;
                  }
                  else if (vehicleType == 'C') {
                     sptr = new Car;
                  }

                  if (sptr) {
                     sptr->setCsv(true);
                     file >> *sptr;

                     if (sptr->getParkingSpot()) {
                        m_parkingSpots[sptr->getParkingSpot() - 1] = sptr;
                        m_numOfParkedVehicles++;
                        retVal = true;
                     }
                     else {
                        delete sptr;
                        sptr = nullptr;
                        retVal = false;
                     }
                  } 
                  else {
                     retVal = false;
                  }
               }
               else {
                  flag = false;
               }
            }
         }
      }
      return retVal;
   }

   void Parking::saveData() {

      ofstream file(m_filename);
      if (file) {
         for (int i = 0; i < m_numOfSpots; i++) {
            if (m_parkingSpots[i]) {
               m_parkingSpots[i]->setCsv(true);
               file << *m_parkingSpots[i];
               delete m_parkingSpots[i];
            }
         }
      }
   }
}
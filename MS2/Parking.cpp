/* ------------------------------------------------------
Citation and Sources
Final Project Milestone 2
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
#include "Parking.h"
using namespace std;
namespace sdds {

   Parking::Parking(const char* filename) {
      if (filename && filename[0]) {
         m_filename = new char[(strlen(filename)) + 1];
         strcpy(m_filename, filename);

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
               break;

            case 2:
               returnVehicle();
               break;

            case 3:
               listVehicle();
               break;

            case 4:
               findVehicle();
               break;

            case 5:
               if (closeParking()) {
                  done = true;
               }
               break;

            case 6:
               if (exitParking()) {
                  done = true;
               }
            }
         }
         retVal = 0;
      }
      return retVal;
   }

   bool Parking::isEmpty() {
      return !(m_filename && m_filename[0]);
   }

   void Parking::parkingStatus() {
      cout << "****** Valet Parking ******" << endl;
   }

   void Parking::parkVehicle() {
      int selection = m_vehicle.run();

      switch (selection) {
      case 1:
         cout << "---------------------------------" << endl;
         cout << "Parking Car" << endl;
         cout << "---------------------------------" << endl << endl;
         break;

      case 2:
         cout << "---------------------------------" << endl;
         cout << "Parking Motorcycle" << endl;
         cout << "---------------------------------" << endl << endl;
         break;

      case 3:
         cout << "---------------------------------" << endl;
         cout << "Cancelled parking" << endl;
         cout << "---------------------------------" << endl << endl;
      }
   }

   void Parking::returnVehicle() {
      cout << "---------------------------------" << endl;
      cout << "Returning Vehicle" << endl;
      cout << "---------------------------------" << endl << endl;
   }

   void Parking::listVehicle() {
      cout << "---------------------------------" << endl;
      cout << "Listing Parked Vehicles" << endl;
      cout << "---------------------------------" << endl << endl;
   }

   void Parking::findVehicle() {
      cout << "---------------------------------" << endl;
      cout << "Finding a Vehicle" << endl;
      cout << "---------------------------------" << endl << endl;
   }

   bool Parking::closeParking() {
      char selection[10 + 1];
      cout << "This will close the parking; All the vehicles will be removed!" << endl;
      cout << "Are you sure? (Y)es/(N)o: ";
      cin.getline(selection, 10, '\n');
      while (!(strcmp(selection, "Y") == 0 || strcmp(selection, "y") == 0 || strcmp(selection, "N") == 0 || strcmp(selection, "n") == 0)) {
         cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
         cin >> selection;
      }

      if (strcmp(selection, "Y") == 0 || strcmp(selection, "y") == 0) {
         cout << "Ending application!" << endl;
      }
      return strcmp(selection, "Y") == 0 || strcmp(selection, "y") == 0;
   }

   bool Parking::exitParking() {
      char selection[10 + 1];
      cout << "This will terminate the application and save the data!" << endl;
      cout << "Are you sure? (Y)es/(N)o: ";
      cin.getline(selection, 10, '\n');
      while (!(strcmp(selection, "Y") == 0 || strcmp(selection, "y") == 0 || strcmp(selection, "N") == 0 || strcmp(selection, "n") == 0)) {
         cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
         cin >> selection;
      }

      if (strcmp(selection, "Y") == 0 || strcmp(selection, "y") == 0) {
         cout << "Exiting application!" << endl;
         saveData();
      }
      return strcmp(selection, "Y") == 0 || strcmp(selection, "y") == 0;
   }

   bool Parking::loadData() {
      bool retVal = false;
      if (!isEmpty()) {
         cout << "---------------------------------" << endl;
         cout << "loading data from " << m_filename << endl;
         cout << "---------------------------------" << endl << endl;
         retVal = true;
      }
      return retVal;
   }

   void Parking::saveData() {
      cout << "---------------------------------" << endl;
      cout << "Saving data into " << m_filename << endl;
      cout << "---------------------------------" << endl << endl;
   }
}
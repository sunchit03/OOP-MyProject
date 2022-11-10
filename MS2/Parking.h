#ifndef SDDS_PARKING_H_
#define SDDS_PARKING_H_
#include "Menu.h"
#include "Utils.h"
namespace sdds {
   class Parking {
   private:
      char* m_filename{};
      Menu m_parking{ "Parking Menu, select an action:", 0};
      Menu m_vehicle{ "Select type of the vehicle:", 1 };

      bool isEmpty();

      void parkingStatus();

      void parkVehicle();
      void returnVehicle();
      void listVehicle();
      void findVehicle();
      bool closeParking();
      bool exitParking();

      bool loadData();
      void saveData();

   public:
      Parking(const char* filename);
      ~Parking();

      Parking(Parking&) = delete;
      void operator=(Parking&) = delete;

      int run();
   };
}

#endif
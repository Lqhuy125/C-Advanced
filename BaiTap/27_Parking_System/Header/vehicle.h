#ifndef __VEHICLE
#define __VEHICLE

#include <position.h>
#include <parking_slot.h>
#include <navigation.h>
#include <iostream> 
#include <vector>
class Vehicle
{
    private:
        string licensePlate; //Bien so xe
        //Dimensions SIZE;
        VehicleType type;
    public:
        Vehicle(VehicleType vehicleType, string license) : type(vehicleType), licensePlate(license){};

        string getLicensePlate();
        void setLicensePlate(string license);
        // Dimensions getSize();

        //Tim vi tri trong gan nhat
        ParkingSlot* findParkingSlot(vector<vector<ParkingSlot>> parkingSlots);
        //Phuong thuc di chuyen
        //bool nagitive(ParkingSlot *slot);
        //Phuong thuc do xe
        bool park(ParkingSlot *slot);
        VehicleType getVehicleType();
};


#endif
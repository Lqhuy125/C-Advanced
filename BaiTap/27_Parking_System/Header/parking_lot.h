#ifndef __PARKING_LOT
#define __PARKING_LOT

#include <position.h>
#include <parking_slot.h>
#include <navigation.h>
#include <iostream>
#include <vector>

using namespace std;

class ParkingLot {
    private:
        vector<vector<ParkingSlot>> slots;
        int distance; //Khoang cach giua cac vi tri

    public:
        ParkingLot(vector<vector<ParkingSlot>> slots, int distance) : slots(slots), distance(distance) {}

        //Lay ra tong vi tri con trong
        int checkAvailableSlots();
        //Cap nhat vi tri do
        bool updateSlotStatus(const Position& pos, bool status);
        //lay ra tong vi tri
        int getTotalSlots();
        //Lay vi tri giua hai cho do xe
        int getDistance();
        //Lay thong tin tai vi tri
        int getInforSlot();
        //Lay ra bai dau xe
        vector<vector<ParkingSlot>> &getSlots() { return slots;}
        // static ParkingLot& getInstance() {
        //     static ParkingLot distance;
        //     return distance;
        // }
        
};


#endif
#ifndef __NAVIGATION
#define __NAVIGATION

#include <iostream>
#include <position.h>
#include <parking_slot.h>
#include <parking_lot.h>
#include <vehicle.h>
#include <vector>
#include <math.h>

using namespace std;



class NavigationSystem
{
private:
    const vector<vector<ParkingSlot>> &parkingMap; //Danh sach vi tri đỗ
    Position currentPos;            //Vi tri bat dau
    VehicleType VEHICLE_TYPE;       //Loai phương tiện
public:
    ParkingSlot &destination;       //Vi trí đích đến
    
    NavigationSystem(ParkingSlot& destination, 
            const vector<vector<ParkingSlot>>& parkingSlots, 
            VehicleType vehicleType, Position startPos) : 
            destination(destination), 
            parkingMap(parkingSlots), 
            VEHICLE_TYPE(vehicleType), 
            currentPos(startPos){}
    //Tinh toan lo trinh 
    vector<Position> calculateRoute();
    //huong dan di chuyen
    void guideMovement(ParkingSlot& destination);
    //Set vi tri hien tai
    void setCurrentPossition(Position pos);
    //Get vi tri hien tai
    Position getCurrentPosition();
    void getmap();
    // Lấy giá trị của position của destination
    // Position getDestinationPosition();
    double getDistance();
    int getMoveDistance(int distance);
    
};

#endif
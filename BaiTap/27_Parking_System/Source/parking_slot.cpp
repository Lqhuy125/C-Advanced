#include <parking_slot.h>
//=============================================================Dimensions
float Dimensions::getLength(){
    return length;
}
float Dimensions::getWidth(){
    return width;
}
//=============================================================ParkingSlot
bool ParkingSlot::checkStatus(){
    return isOccupied;
}
void ParkingSlot::updateStatus(bool status){
    isOccupied = status;
}
VehicleType ParkingSlot::getSlotType(){
    return slotType;
}
int ParkingSlot::getSlotNumber(){
    return slotNumber;
}
Dimensions ParkingSlot::getSize(){
    return Slotsize;
}
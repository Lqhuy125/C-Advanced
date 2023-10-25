#include <parking_lot.h>

//=============================================================ParkingLot
int ParkingLot::checkAvailableSlots(){
    int availableCount = 0;
        for (const vector<ParkingSlot>& row : slots) {
            for (const ParkingSlot& slot : row) {
                if (!slot.isOccupied) {
                    availableCount++;
                }
            }
        }
        return availableCount;
}
bool ParkingLot::updateSlotStatus(const Position& pos, bool status){
    int row = pos.x;
    int col = pos.y;

    if (row >= 0 && row < slots.size() && col >= 0 && col < slots[row].size()) {
        slots[row][col].isOccupied = status;
        return true;
    }
    return false;
}
int ParkingLot::getTotalSlots(){
    int total = 0;
    for (const vector<ParkingSlot>& row : slots) {
        total += row.size();
    }
    return total;
}
int ParkingLot::getDistance(){
    return distance;
}
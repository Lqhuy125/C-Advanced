#include <iostream>
#include <vector>

using namespace std;

class Dimensions
{
private:
    float length;
    float width;
public:
    Dimensions(float l, float w) : length(l), width(w) {};

    float getLength();
    float getWidth();
};
float Dimensions::getLength(){
    return length;
}
float Dimensions::getWidth(){
    return width;
}

typedef enum{   //se Code o file vehicle.h
    MOTOBIKE,
    CAR
} VehicleType;

class ParkingSlot
{
private:
    bool isOccupied;        //Trạng thái vị trí đỗ
    VehicleType slotType;   //Loại vị trí(xe máy, ô tô, ...)
    int slotNumber;         //STT của xe đó
    Dimensions size;
public:
    ParkingSlot(VehicleType type, int number, float l, float w) : isOccupied(false), slotType(type), slotNumber(number), size(l,w) {};

    
    bool checkStatus();
    void updateStatus(bool status);
    VehicleType getSlotType();
    int getSlotNumber();

    Dimensions getSize();
};
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
    return size;
}
class ParkingLot{
    private:
        vector<ParkingSlot> slots;

    public:
        ParkingLot(int numberof_of_slot){
            for (int i = 0; i < numberof_of_slot; i++) {
                ParkingSlot slot(MOTOBIKE, i, 1.0, 1.0);
                slots.push_back(slot);
            }
        }

        //Ktra vi tri trong
        int checkAvailableSlots();
        bool updateSlotStatus(int slot_index, bool status);
        int getTotalSlots();

        //Kiemtra vi tri đỗ
        
};
int ParkingLot::checkAvailableSlots(){
    int count = 0;
        for (ParkingSlot& item : slots) {
            if (!item.checkStatus()) {
                count++;
            }
        }
    return count;
}
bool ParkingLot::updateSlotStatus(int slot_index, bool status){
    if (slot_index >= 0 && slot_index < slots.size()) {
        slots[slot_index].updateStatus(status);
        return true;
    }
    return false;
}
int ParkingLot::getTotalSlots(){
    return slots.size();
}

int main(int argc, char const *argv[])
{
    ParkingSlot carslot(CAR, 5, 1.2,2.3);

    // cout<<"Position: "<< carslot.getSlotNumber() <<endl;

    // if(carslot.getSlotType() == CAR){
    //     cout << "Car\n";
    // }
    // else if(carslot.getSlotType() == MOTOBIKE){
    //     cout << "MOTOBIKE\n";
    // }

    // cout << (carslot.checkStatus() ? "Dang duoc chiem\n" : "Dang trong") << endl;

    // carslot.updateStatus(true);

    // cout << (carslot.checkStatus() ? "Dang duoc chiem\n" : "Dang trong") << endl;
    
    ParkingLot myParking(10);

    cout << "Tong so vi tri do: " << myParking.getTotalSlots() << endl;
    cout << "So vi tri trong: " << myParking.checkAvailableSlots() << endl;

    myParking.updateSlotStatus(5, true);
    cout << "Sau khi mot o to do o vi tri 5\n";
    cout << "So vi tri trong: " << myParking.checkAvailableSlots() << endl;
    return 0;
}
 
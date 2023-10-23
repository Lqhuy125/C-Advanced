// #include <iostream>

// using namespace std;

// typedef enum{   //se Code o file vehicle.h
//     MOTOBIKE,
//     CAR
// } VehicleType;

// class ParkingSlot
// {
// private:
//     bool isOccupied;        //Trạng thái vị trí đỗ
//     VehicleType slotType;   //Loại vị trí(xe máy, ô tô, ...)
//     int slotNumber;         //STT của xe đó
// public:
//     ParkingSlot(VehicleType type, int number) : isOccupied(false), slotType(type), slotNumber(number) {};

//     bool checkStatus();
//     void updateStatus(bool status);
//     VehicleType getSlotType();
//     int getSlotNumber();
// };
// bool ParkingSlot::checkStatus(){
//     return isOccupied;
// }
// void ParkingSlot::updateStatus(bool status){
//     isOccupied = status;
// }
// VehicleType ParkingSlot::getSlotType(){
//     return slotType;
// }
// int ParkingSlot::getSlotNumber(){
//     return slotNumber;
// }

// int main(int argc, char const *argv[])
// {
//     ParkingSlot carslot(CAR, 5);

//     cout<<"Position: "<< carslot.getSlotNumber() <<endl;

//     if(carslot.getSlotType() == CAR){
//         cout << "Car\n";
//     }
//     else if(carslot.getSlotType() == MOTOBIKE){
//         cout << "MOTOBIKE\n";
//     }

//     cout << (carslot.checkStatus() ? "Dang duoc chiem\n" : "Dang trong") << endl;

//     carslot.updateStatus(true);

//     cout << (carslot.checkStatus() ? "Dang duoc chiem\n" : "Dang trong") << endl;
//     return 0;
// }

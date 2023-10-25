#include <position.h>
#include <parking_slot.h>
#include <parking_lot.h>
#include <navigation.h>
#include <vehicle.h>


using namespace std;

int main(int argc, char const *argv[])
{
    //Tao ra 9 vi tri do xe
    vector <vector<ParkingSlot>> slots = {
        {ParkingSlot(MOTOBIKE, 1, Dimensions(2.5, 1)), ParkingSlot(bike, 2, Dimensions(2.5, 1)), ParkingSlot(MOTOBIKE, 3, Dimensions(2.5, 1))},
        {ParkingSlot(CAR, 4, Dimensions(6.8, 4.5)), ParkingSlot(CAR, 5, Dimensions(6.8, 4.5)), ParkingSlot(CAR, 6, Dimensions(6.8, 4.5))},
        {ParkingSlot(CAR, 7, Dimensions(6.8, 4.5)), ParkingSlot(CAR, 8, Dimensions(6.8, 4.5)), ParkingSlot(CAR, 9, Dimensions(6.8, 4.5))}
    };
    //=================================================Test ParkingSlot=====================================
    // ParkingSlot carslot(CAR, 5, Dimensions(2.5, 1));
    // cout<<"Position: "<< carslot.getSlotNumber() <<endl;
    // if(carslot.getSlotType() == CAR)
    //     cout << "Car\n";
    // else if(carslot.getSlotType() == MOTOBIKE)
    //     cout << "MOTOBIKE\n";
    // cout << (carslot.checkStatus() ? "Dang duoc chiem\n" : "Dang trong") << endl;
    // carslot.updateStatus(true);
    // cout << (carslot.checkStatus() ? "Dang duoc chiem\n" : "Dang trong") << endl;
    //=================================================Test Parkinglot=====================================
    //Tao 1 bai do xe gom cac vi tri tren, gia su moi vi tri cach nhau 10m
    ParkingLot parkingLot(slots,5);
    // cout << "Distance: "<<parkingLot.getDistance() << endl;
    // cout << "Total slot: " << parkingLot.getTotalSlots() << endl;
    // cout << "So slot con trong: " << parkingLot.checkAvailableSlots() << endl;
    //Gia su update vi tri 1,0 va 1,1
    parkingLot.updateSlotStatus(Position(1,0), false);
    parkingLot.updateSlotStatus(Position(1,1), true);
    // cout << "So slot con trong: " << parkingLot.checkAvailableSlots() << endl;
    //=================================================Test Vehicle=====================================
    //Tao 1 car
    Vehicle myVehicle(CAR, "abc123");
    // cout << "VehicleType: " << myVehicle.getVehicalType() << endl;
    // cout << "LicensePlate: " << myVehicle.getLicensePlate() << endl;
    //Lay ra cac vi tri trong bai dau xe
    vector<vector<ParkingSlot>> slotOfParkingLot = parkingLot.getSlots();
    //Test check getSlots Success
    // for (const vector<ParkingSlot>& row : slotOfParkingLot) {
    //     for (const ParkingSlot& slot : row) {
    //         // In các thông tin về vị trí đỗ xe (các thuộc tính của ParkingSlot) bằng cout
    //         cout << "Slot Type: " << slot.slotType << ", Occupied: " << slot.isOccupied << ", Slot Number: " << slot.slotNumber << ", ... " << endl;
    //     }
    // }
    //Tim cho do tuong ung voi loai phuong tien va kiem tra trang thai con trong
    ParkingSlot *suitableSlot = myVehicle.findParkingSlot(slotOfParkingLot);
    //suitableSlot Nhan gia tri thanh cong

    if(suitableSlot){
        //Da tim thay vi tri do gan nhat
        cout << "Nearest vacant position found" << endl;
        
        //Vi tri ban dau (x,y)
        NavigationSystem navigationSystem(*suitableSlot, slotOfParkingLot, 
                                        myVehicle.getVehicleType(), Position(2,2));
        cout << "Destination Position:" << navigationSystem.destination.getSlotNumber() << endl;
        //Hien thi map
        //T: vi tri can den
        //x: vi tri loai xe khac
        //1: da chiem cho
        //0: còn trống
        
        cout << "map of the packing lot" << endl;
        navigationSystem.getmap();

        //huong dan duong di
        cout << " direction to the packing location " << endl;
        navigationSystem.guideMovement(*suitableSlot);
        cout << " Distance away: " << navigationSystem.getMoveDistance(parkingLot.getDistance()) << "(m)" << endl;
    }
    else{
        cout << "Khong tim thay vi tri phu hop\n";
    }
}

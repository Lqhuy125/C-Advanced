#include <vehicle.h>

string Vehicle::getLicensePlate(){
    return licensePlate;
}
void Vehicle::setLicensePlate(string license){
    licensePlate = license;
}
// Dimensions Vehicle::getSize(){
//     return SIZE;
// }
ParkingSlot* Vehicle::findParkingSlot(vector<vector<ParkingSlot>> parkingSlots){
    for (const vector<ParkingSlot>& row : parkingSlots) {
        for (const ParkingSlot& slot : row) {
            if (!slot.isOccupied && slot.slotType == getVehicleType()) {
                cout << "Position suitable Slot: "<<slot.slotNumber << endl;
                return const_cast<ParkingSlot*>(&slot);
            }
        }
    }
    return nullptr;
}
// bool Vehicle::nagitive(ParkingSlot *slot){
// }
bool Vehicle::park(ParkingSlot *slot){
}
// string Vehicle::getVehicalType(){
//     string type_name = "";
//     if(type == 1) type_name ="CAR";
//     else if( type == 0) type_name="Motobike";
//     return type_name;
// }

VehicleType Vehicle::getVehicleType(){
    return type;
}
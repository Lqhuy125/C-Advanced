#include <navigation.h>

int count = 0;

double NavigationSystem::getDistance() {

}
int NavigationSystem::getMoveDistance(int distance) {
    int totalDistance = count * distance;
    return totalDistance;
}

//Set vi tri hien tai
void NavigationSystem::setCurrentPossition(Position pos) {
    currentPos = pos;
}
//Get vi tri hien tai
Position NavigationSystem::getCurrentPosition(){
    return currentPos;
}
void NavigationSystem::getmap(){
    int numRows = parkingMap.size(); // Số hàng
    int numCols = (numRows > 0) ? parkingMap[0].size() : 0;

    int suitable = destination.slotNumber;
    int row = (suitable - 1) / numCols;
    int col = (suitable - 1) % numCols;

    for (int i = 0; i < parkingMap.size(); i++) {
        for (int j = 0; j < parkingMap[i].size(); j++) {
            if (row == i && col == j)
                cout << "T "; // Vị trí đích đến
            else if (parkingMap[i][j].isOccupied)
                cout << "1 "; // Đã chiếm chỗ đỗ
            else if (parkingMap[i][j].slotType != VEHICLE_TYPE)
                cout << "x "; // Loại xe khác
            else
                cout << "0 "; // Còn trống
        }
        cout << endl;
    }
}

//test
void NavigationSystem::guideMovement(ParkingSlot& destination) {

    int targetPosx = -1;
    int targetPosy = -1;
    
    int numRows = parkingMap.size(); // Số hàng
    int numCols = (numRows > 0) ? parkingMap[0].size() : 0;

    int suitable = destination.slotNumber;
    int row = (suitable - 1) / numCols;
    int col = (suitable - 1) % numCols;
    for (int i = 0; i < parkingMap.size(); i++) {
        for (int j = 0; j < parkingMap[i].size(); j++) {
            if (row == i && col == j)
            {
                targetPosx=i;
                targetPosy=j;
            }
        }
    }
    Position targetPos;
    targetPos.x = targetPosx;
    targetPos.y = targetPosy;

    vector<string> directions;
    int currentX = currentPos.x;
    int currentY = currentPos.y;
    cout << "Begin pos: " << currentPos.x << " " << currentPos.y << endl;
    cout << "Target pos: " << targetPos.x << " " << targetPos.y << endl;
     
    while (currentPos.x != targetPos.x || currentPos.y != targetPos.y) {
        
        if (currentPos.x < targetPos.x) {
            count++;
            currentPos.x += 1;
            cout <<"turn down:  "<<"("<<currentPos.x<<", "<<currentPos.y<<")"<<endl;
        }
        else if (currentPos.x > targetPos.x) {
            count++;
            currentPos.x -= 1;
            cout <<"turn up:    "<<"("<<currentPos.x<<", "<<currentPos.y<<")"<<endl;
        }
        if (currentPos.y < targetPos.y) {
            count++;
            currentPos.y += 1;
            cout <<"turn right: "<<"("<<currentPos.x<<", "<<currentPos.y<<")"<<endl;
        }
        else if (currentPos.y > targetPos.y) {
            count++;
            currentPos.y -= 1;
            cout <<"turn left:  "<<"("<<currentPos.x<<", "<<currentPos.y<<")"<<endl;
        }
    }
    
}
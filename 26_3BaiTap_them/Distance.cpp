#include <iostream>
#include <cmath>
#include <math.h>

using namespace std;

#define EARTH_RADIUS 6371

class GPSPoint{
    private:
        double LATITUDE; //vi do -90, 90
        double LONGITUDE;  //kinh do -180, 180
    public:
        void input(double latitude, double longitude);
        bool isValid(double latitude, double longitude);
        double toRadians(double degree);
        double distanceTo(GPSPoint& other);
};
void GPSPoint::input(double latitude, double longitude){
    LATITUDE = latitude;
    LONGITUDE = longitude;
}
bool GPSPoint::isValid(double latitude, double longitude){
    return latitude >= -90 && latitude <= 90 && longitude <= 180 && longitude >= -180;
}
double GPSPoint::toRadians(double degree){
    return degree * 3.14 / 180;
}
double GPSPoint::distanceTo(GPSPoint& other){
    double latitude1 = toRadians(LATITUDE);
    double longitude1 = toRadians(LONGITUDE);
    double latitude2 = toRadians(other.LATITUDE);
    double longitude2 = toRadians(other.LONGITUDE);

    double dis_lat = abs(latitude2 - latitude1);
    double dis_lon = abs(longitude2 - longitude1);
    double hav = sin(dis_lat / 2) * sin(dis_lat / 2) + cos(latitude1) * cos(latitude2) * sin(dis_lon / 2) * sin(dis_lon / 2);
    double d = 2 * EARTH_RADIUS * asin (sqrt(hav));

    return d;
}
int main(){

    GPSPoint pointA, pointB;
    int latitude, longitude;

    do{
        cout << "Enter coordinates for point A:\n";
        cout << "Enter latitude: "; cin >> latitude;
        cout << "Enter longitude: "; cin >> longitude;
        pointA.input(latitude,longitude);
        if (!pointA.isValid(latitude, longitude)) cout << "Wrong value! Enter again: \n";
    } while (!pointA.isValid(latitude, longitude));

    do{
        cout << "Enter coordinates for point B:\n";
        cout << "Enter latitude: "; cin >> latitude;
        cout << "Enter longitude: "; cin >> longitude;
        pointB.input(latitude,longitude);
        if (!pointB.isValid(latitude, longitude)) cout << "Wrong value! Enter again: \n";
    } while (!pointB.isValid(latitude, longitude));

    cout << "Distance between 2 points is: " << pointA.distanceTo(pointB) << "km";

}
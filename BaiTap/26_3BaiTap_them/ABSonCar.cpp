#include <iostream>

using namespace std;

class Wheel{
    private:
        int SPEED;
    public:
        void set_Speed(int speed);
        int get_speed();     
};
void Wheel::set_Speed(int speed){
    SPEED = speed;
}
int Wheel::get_speed(){
    return SPEED;
}

class Car{
    private:
        int BASE_WEIGHT=1000;
        int CUSTOMER_WEIGT=0;
        Wheel carWheel;
    public:
        void set_baseWeight(int baseWeight);
        void add_customer(int customer_weight);
        int get_total_weight();
        Wheel& get_Wheel();
};
void Car::set_baseWeight(int baseWeight){
    BASE_WEIGHT = baseWeight;
}
void Car::add_customer(int customer_weight){
    CUSTOMER_WEIGT += customer_weight;
}
int Car::get_total_weight(){
    return BASE_WEIGHT+CUSTOMER_WEIGT;
}
Wheel& Car::get_Wheel() {
    return carWheel;
}
class ABS{
    private:
        Car &car;
    public:
        ABS(Car &c) : car(c) {}
        void applyBrakes();
};
void ABS::applyBrakes() {
    double wheelSpeed = car.get_Wheel().get_speed();
    if (wheelSpeed < 10) 
        cout << "Warning: wheel is locking up. Adjusting brake force based on car weight:"<< car.get_total_weight() << endl;
    else
        cout << "Phanh hoat dong binh thuong" << endl;
}
int main(){
    Car car;
    ABS abs_Sys(car);

    car.get_Wheel().set_Speed(15);
    abs_Sys.applyBrakes();

    car.add_customer(70);
    car.get_Wheel().set_Speed(9);
    abs_Sys.applyBrakes();
}
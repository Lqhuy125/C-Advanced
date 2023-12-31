#include <iostream>

using namespace std;

typedef enum Direction{
    CLOCK_WISE, 
    COUNTER_CLOCK_WISE
} Direction;

class DCMotor
{
    private:
        double VOLTAGE;
        double MAX_CURRENT;
        double SPEED;
        Direction DIRECTION;
        bool isRunning;
    public:
        DCMotor(double vol, double max_cur) : VOLTAGE(vol), MAX_CURRENT(max_cur) {};
        void set_Speed(double speed){
            SPEED  = speed;
        };
        int getSpeed(){
            return SPEED;
        }
        void set_Direction(Direction direction){
            DIRECTION = direction;
        };
        Direction get_Direction(){
            return DIRECTION;
        }
        double get_max_cur(){
            return MAX_CURRENT;
        }
        void Start(){
            isRunning = true;
            cout << "Motor started ";
        };
        void Stop(){
            isRunning = false;
            cout << "Motor stopped\n";
        };
};

class FeedbackSystem{
    private:
        DCMotor &dcmotor;
    public:
        FeedbackSystem(DCMotor& motor) : dcmotor(motor) {};
        bool overloadDetected(double cur){
            return cur > dcmotor.get_max_cur();
        };
        bool overheatDetected(double heat){
            return heat > 70;
        };
};

class DCMotorController
{
    private:
        DCMotor DCMOTOR;
        FeedbackSystem FEEDBACKSYSTEM; 
    public:
        DCMotorController(double voltage, double maxcurrent) : DCMOTOR(voltage, maxcurrent), FEEDBACKSYSTEM(DCMOTOR) {};
        void controlMotor(double CurrentFeedback, double TemperatureFeedback){
            if(FEEDBACKSYSTEM.overloadDetected(CurrentFeedback) || FEEDBACKSYSTEM.overheatDetected(TemperatureFeedback)){
                cout << "Issue detected. ";
                DCMOTOR.Stop();
            }
            else{
                string dir = "";
                DCMOTOR.Start();
                if (DCMOTOR.get_Direction() == 0)
                        dir = "CLOCK_WISE";
                else if(DCMOTOR.get_Direction() == 1)
                        dir = "COUNTER_CLOCK_WISE";
                cout << "at " << DCMOTOR.getSpeed() << "RPM and Direction: " << dir << endl;
            }
        };
        void setMotorSpeed(double speed){
            DCMOTOR.set_Speed(speed);
        };
        void setMotorDirection(Direction dir){
            DCMOTOR.set_Direction(dir);
        };
};
int main()
{
    DCMotorController motorController(12.0, 1.5);

    motorController.setMotorDirection(COUNTER_CLOCK_WISE);//Set motor quay theo chieu kim dong ho
    motorController.setMotorSpeed(1200); //set speed of motor 1000 rpm

    double currentFeedback = 1.6; // >1.5 overload
    double temperatureFeedback = 7;

    motorController.controlMotor(currentFeedback, temperatureFeedback);

    return 0;
}




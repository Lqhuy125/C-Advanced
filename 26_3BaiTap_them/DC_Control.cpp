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
        DCMotor(double vol, double max_cur);
        void set_Speed(double speed){
            SPEED  = speed;
        };
        int getSpeed(){
            return SPEED;
        }
        void set_Direction(Direction direction){
            DIRECTION = direction;
        };
        void Start(){
            isRunning = true;
            cout << "Motor started ";
        };
        void Stop(){
            isRunning = false;
            cout << "Motor stopped\n";
        };
};

class FeedbackSystem
{
    private:

        DCMotor dcmotor;
        double CURRENT_FEEDBACK;
        double TEMPERATURE_FEEDBACK;
    public:
        FeedbackSystem(/* args */);
        bool overloadDetected(){
            return CURRENT_FEEDBACK > 1.5;
        };
        bool overheatDetected(){
            return TEMPERATURE_FEEDBACK > 7.5;
        };
};

class DCMotorController
{
    private:
        DCMotor DCMOTOR;
        FeedbackSystem FEEDBACKSYSTEM; 
    public:
        DCMotorController(double voltage, double maxcurrent) : DCMOTOR(voltage, maxcurrent) {};
        void controlMotor(double CurrentFeedback, double TemperatureFeedback){
            if(CurrentFeedback > DCMOTOR.MAX_CURRENT || TemperatureFeedback > 8.0){
                DCMOTOR.Stop();
                cout << "Issue detected.\n";
            }
            else{
                DCMOTOR.Start();
                cout << "at " << DCMOTOR.getSpeed();
            }
        };
        void setMotorDirection(Direction direction){
            
        };
        void setMotorSpeed(double speed){

        };
};

int main(int argc, char const *argv[])
{
    DCMotorController motorController(12.0, 5.0);

    motorController.setMotorDirection(CLOCK_WISE);//Set motor quay theo chieu kim dong ho
    motorController.setMotorSpeed(1000); //set speed of motor 1000 rpm

    double currentFeedback = 1.6;
    double temperatureFeedback = 7.5;

    motorController.controlMotor(currentFeedback, temperatureFeedback);

    return 0;
}




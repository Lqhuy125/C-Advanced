#include <class.h>

Customer::Customer(int id, string cusName, string cusPhone, string cusAddress){
    NAME = cusName;
    PHONE_NUMBER = cusPhone;
    ADDRESS = cusAddress;
    idRoom = id;
}
vector<bookHistory> &Customer::getBookingHistorys(){ return History;};
void Customer::setName(string cusName){
    NAME = cusName;
}
void Customer::setPhoneNumber(string cusPhone){
    PHONE_NUMBER = cusPhone;
}
void Customer::setAddress(string cusAddress){
    ADDRESS = cusAddress;
}
string Customer::getName(){
    return NAME;
}
string Customer::getPhoneNumber(){
    return PHONE_NUMBER;
}
string Customer::getAddress(){
    return ADDRESS;
}
int Customer::get_ID_Room(){
    return idRoom;
}

Room::Room(int room_number){
    ROOM_NUMBER = room_number;
    IS_BOOKED = false;
    IS_CLEANED = true;
}
int Room::getRoomNumber(){ 
    return ROOM_NUMBER; 
}
bool Room::Get_Reserved_Room(){
    return this->IS_BOOKED;
}
//Check xem phong do co san de thue hay khong
bool Room::isAvailable(){
    return !IS_BOOKED && IS_CLEANED;
}
void Room::bookRoom(){
    IS_BOOKED = true;
    IS_CLEANED = false;
}
void Room::checkOut(){
    IS_BOOKED = false;
}

int Employee::get_ID(){ return ID;}
string Employee::get_Name() { return NAME;}
string Employee::get_PhoneNumber() { return PHONE_NUMBER; }
JobPosition Employee::get_Position() { return POSITION; }
Schedule Employee::get_Schedule() { return SCHEDULE;}
void Employee::set_Name(string name){
    NAME = name;
}
void Employee::set_PhoneNumber(string phonenumber){
    PHONE_NUMBER = phonenumber;
}
void Employee::set_Position(JobPosition position){
    POSITION = position;
}
void Employee::set_Schedule(Schedule schedule){
    SCHEDULE = schedule;
}

void User::set_Usename(string name){
    USENAME = name;
}
void User::set_Password(string pass){
    PASSWORD = pass;
}
void User::set_ID(int id){
    ID = id;
}
int User::get_ID() { return ID; }
string User::get_Usename(){ return USENAME; }
string User::get_Password() { return PASSWORD; }

bool User::authenticate(string inputUsename, string inputPassword){
    bool checkSignUp = (inputUsename == USENAME && inputPassword == PASSWORD);
    return checkSignUp;
}
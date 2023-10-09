#include <iostream>
#include <list>
#include <string>

using namespace std;

class Dish{
    private:
        int ID;
        string NAME;
        int PRICE;
    public:
        Dish(string name, int price);
        int getID() {return ID;}
        void setName(string name){ NAME = name;}
        string getName(){ return NAME;}
        void setPrice(int price){ PRICE = price;}
        int getPrice() {return PRICE;}
        void getInformation();
};

class Table{
    private:   
        bool STATUS;
        int  NUMBERTABLE;
    public:
    Table(int numbertable, bool status);
    void setNumberTable(int numbertable) { NUMBERTABLE = numbertable; }
    void setStatus(bool status) { STATUS = status; }
    bool getStatus(){ return STATUS; }
    int getNumberTable(){ return NUMBERTABLE; }
};

class Manager{
    private:
        list <Dish> DATABASE_DISH;
        int NUMBER_OF_TABLE;
    public:
        void setNumberOfTable();
        int getNumberofTable() { return NUMBER_OF_TABLE; };
        void menuManagement();
        void addDish();
        // void updateDish();
        // void deleteDish();
        void displayListDish();
};

class Staff{
    
};

class Choice_Rule{
    private:
        Manager manager;
        Staff staff;
    public:
        void choice_rule();
};



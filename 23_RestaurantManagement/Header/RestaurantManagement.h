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
        int getID();
        void setName(string name);
        string getName();
        void setPrice(int price);
        int getPrice();
        void getInformation();
};

class Table{
    public:   
        bool STATUS;
        int  NUMBER_TABLE;
        list<Dish> dishList;
        typedef struct{
            Dish dish;
            int number_of_dishes;
        }typeDish;

        list <typeDish> DISH_IN_TABLE;

    public:
        Table();
        Table(int numbertable, bool status, list<Dish> dishList);
        //void setNumberTable(int numbertable) { NUMBER_TABLE = numbertable; }
        void setStatus(bool status);
        bool getStatus();
        int getNumberTable();
        
        //list<typeDish> getDishonTable(){ return DISH_IN_TABLE; };
        void addDish_table();
        void updateDish_table();
        void deleteDish_table();
        void listDish_table();//(bool fromMenu);
        void billPayment_table();
};

class Manager{
    private:
        int NUMBER_OF_TABLES;
    public:
        Manager();
        list <Dish> DATABASE_DISH; ////Nen o private
        
        void setNumberOfTable();
        int getNumberofTable();
        list <Dish> getDatabaseDish();
        void addDish();
        void updateDish();
        void deleteDish();
        void displayListDish(bool status);
        void listDish_manager();

        void menuManager();
};

class Staff{
    public: //nen la private
        int table_Number;
        list<Table> DATABASE_TABLE; 
        list<Dish> DATABASE_DISH;
    public: 
        Staff();
        Staff(int number_of_table , list<Dish>database_dish);
        void setManagerValues(int numberofTable, list<Dish> listDish) {
            table_Number = numberofTable;
            DATABASE_DISH = listDish;
        }
        void menuStaff();
        void listDish_staff();
};

class Choice_Rule{
    private:
        
    public:
        Choice_Rule();
        Manager manager;    //Nen o private
        Staff staff;        //Nen o private
        void choice_rule();
};



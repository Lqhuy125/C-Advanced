#include "RestaurantManagement.h"

/* 
    Contructor: Dish
    Discription: Constructor khoi tao phan tu con moi cua class
    Parameter: name: name of dish
                price: price of dish
 */
//=====================================================DISH==========================================
Dish::Dish(string name, int price){
    static int id=100;
    ID = id;
    id++;
    NAME = name;
    PRICE = price;    
}
int Dish::getID(){
    return ID;
}
string Dish::getName(){
    return NAME;
}
int Dish::getPrice(){
    return PRICE;
}
void Dish::setName(string name){
    NAME = name;
}
void Dish::setPrice(int price){
    PRICE = price;
}
void Dish::getInformation(){
    cout << getID() << "\t" << getName() << "\t" << getPrice() << endl;
}

//=====================================================TABLE==========================================
Table :: Table(){

}
Table :: Table(int tableNumber, bool status, list<Dish> _dishList){
    NUMBER_TABLE = tableNumber;
    STATUS = status;
    dishList = _dishList;
}
bool Table :: getStatus()
{ 
    return STATUS; 
}
void Table :: setStatus(bool status)
{ 
    STATUS = status; 
}
int Table :: getNumberTable()
{ 
    return NUMBER_TABLE; 
}

void Table :: addDish_table(){
    for (auto temp : dishList)
    {
        temp.getInformation();
    }
    int ID;
    cout << "Enter Dish ID to serve: ";
    cin >> ID;
    int dishQuantity;
    cout << "Enter quantity: ";
    cin >> dishQuantity;
    cout<<"------------------------------------------------"<<endl;
    bool found = false;
    for (Dish temp : dishList) {
        if (temp.getID() == ID) {
            typeDish new_dish;
            new_dish.dish = temp;
            new_dish.number_of_dishes = dishQuantity;
            DISH_IN_TABLE.push_back(new_dish);

            setStatus(false); 

            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Dish with ID " << ID << " not found.\n";
    }
}
void Table :: listDish_table(){
    cout<<"Tabble number: "<<getNumberTable()<<endl;
    for(typeDish item : DISH_IN_TABLE){
        item.dish.getInformation();
        cout<<"number_of_dishes: "<<item.number_of_dishes<<endl;
    }
}
//=====================================================MANAGER==========================================
Manager::Manager(){
}
/*  
    Method: menuManagement
*/
void Manager::menuManager(){
    int options;
    while(1){
        cout << "____________________________________" << endl;
        cout<<"Press 1 to set number of table\n";
        cout<<"Press 2 to add dish\n";
        cout<<"Press 3 to update dish\n";
        cout<<"Press 4 to delete dish\n";
        cout<<"Press 5 to display list dish\n";
        cout<<"Press 0 to exit mode Management\n";
        cout<<"Enter option: ";
        
        do{
            cin>>options;
            if(options < 0 || options > 5) cout<<"Invalid choice! Please re-enter: ";
        } while(options < 0 || options > 5);

        switch(options){
            case 1:
                setNumberOfTable();
                break;
            case 2:
                addDish();
                break;
            case 3:
                updateDish();
                break;
            case 4:
                deleteDish();
                break;
            case 5:
                displayListDish(true);
                break;
            case 0:
                cout<<getNumberofTable()<<endl;
                return;
        }
    }
}
/*
    Method: setNumberOfTable
    Description: This method set number of table 
    Input:
        number_of_table: number of table
    Output: none
*/
// int number_of_table=0;
void Manager::setNumberOfTable(list<Table> & listofTable){
    cout<<"Enter the number of table: ";
    cin>>NUMBER_OF_TABLES;
    for (int i = 1; i <= NUMBER_OF_TABLES; i++)
    {
        Table x(i+1);
        listofTable.push_back(x);
    }
    //in thong tin bàn
    cout<<"Successful change!"<<endl<<endl;
    cout<<"*****************************************"<<endl;
}
int Manager::getNumberofTable()
{ 
    return this->NUMBER_OF_TABLES; 
}
list <Dish> Manager::getDatabaseDish()
{ 
    return this->DATABASE_DISH; 
}
/* 
    method: Add dish
 */
void Manager::addDish(){
    
    while(1){
        int key;
        string name;
        int price;
        int choice;

        cout << "1. To add dish\n";
        cout << "0. return option\n";
        cout << "Enter option: ";
        
        do{
            cin>>key;
            if(key>1 || key<0) cout<<"Invalid choice! Please re-enter: \n";
        } while(key>1 || key<0);

        if(key == 0) return;
        
        cout << "===================================" << endl;
        cout << "Enter dish information \n";
        cout << "Enter dish name: ";
        cin >> name;
        cout << "Enter dish price: ";
        cin >> price;
        Dish dish = Dish(name, price);
        DATABASE_DISH.push_back(dish);
        cout<<"ID: "<<dish.getID()<<"\t\tName: "<<dish.getName()<<"\tPrice: "<<dish.getPrice()<<endl;
        
        do{
            cout << "===================================" << endl;
            cout << "1. Continue add dish\n";
            cout << "0. return option\n";
            cout << "Enter option: ";
            cin >> choice;
            if(choice>1 || choice<0) cout<<"Invalid choice! Please re-enter: \n";
        } while(choice>1 || choice <0);

        if(choice == 0) return;
    }
}
void Manager::updateDish(){
    //Check empty
    int check = 0;
    int id;
    string new_name;
    int new_price;
    int check_not_finded=0;

    for(Dish item : DATABASE_DISH){
        check++;
    }
    if(check != 0){
        //full
        listDish_manager();
    }
    else{
        cout<<"List Empty\n";
        return;
    } 
    
    cout<<"Enter dish ID to update: ";
    cin>>id;
    
    for(Dish &it : DATABASE_DISH){
        if(it.getID() == id){
            cout <<"Enter dish information to update\n";
            cout << "Enter new dish name: ";
            cin >> new_name;
            cout << "Enter new dish price: ";
            cin >> new_price;

            it.setName(new_name);
            it.setPrice(new_price);
        }
        else 
            check_not_finded++;

        if(check_not_finded==DATABASE_DISH.size()) 
            cout<<"Dish not found id: "<< id << endl;
    }
}
void Manager::deleteDish(){
    int choice;
    int id;
    int check = 0;
    int option;
    listDish_manager();
    cout << "1. To delete dish\n";
    cout << "0. return option\n";
    cout << "Enter option: ";
    do{
        cin >> choice;
        if(choice>1 || choice<0) cout<<"Invalid choice! Please re-enter: ";
    } while(choice>1 || choice <0);

    if(choice == 0) return;

    while(1){
        

        repeat_delete:
        cout<<"Enter the dish ID to delete: ";
        cin>>id;
        list<Dish>::iterator position = DATABASE_DISH.begin();
        for(Dish item : DATABASE_DISH){
            
            if(id == item.getID()){
                DATABASE_DISH.erase(position);
                listDish_manager();
                cout << "Successfully erased: \n";
                cout << "1. Continue delete\n";
                cout << "0. return option\n";
                cout << "Enter option: ";
                do{
                    cin >> option;
                    if(option>1 || option<0) cout<<"Invalid choice! Please re-enter: ";
                } while(option>1 || option <0);

                if(option == 0) return; 
                else{
                    if(DATABASE_DISH.size()==0){
                        cout << "List disd empty!\n";
                        return;
                    }
                    goto repeat_delete;
                } 
            }
            position++;
            check++;
        }

        if(check == DATABASE_DISH.size()) cout << "ID does not exist\n";
        
    }
}
void Manager::displayListDish(bool status){
    int choice;
    while(1){
        int check = 0;
        for(Dish item : DATABASE_DISH){
            check++;
        }
        if(check != 0){
            //full
            listDish_manager();
        }
        else{
            cout<<"List Empty\n";
            return;
        }

        if(status){
            do{
                cout << "Enter 0 to return option: ";
                cin >> choice;
                if(choice != 0){
                    cout << "Invalid choice! Please re-enter\n";
                }
            } while( choice != 0);

            if(choice == 0) return;
        }
    }
}
void Manager :: listDish_manager(){
    cout<<"=======================================\n";
    cout<<"STT\t"<<"ID\t"<<"Name\t"<<"Price\n";
    int i=1;
    for(Dish item : DATABASE_DISH){
        cout << i << "\t";
        item.getInformation();
        i++;
    }
}
//=====================================================STAFF==========================================
Staff::Staff(int number_of_table , list<Dish>database_dish){
    
    if(number_of_table == 0 && database_dish.size() == 0){
        cout << "Staff do not have information, please transfer data to management! \n";
    }
    // add table
    else{
        for(int i=1; i<=number_of_table; i++){
        Table Table(i, false, database_dish);
        DATABASE_TABLE.push_back(Table);
    }
    // coppy list dish from class Manager
    DATABASE_DISH.assign(database_dish.begin(), database_dish.end());
    }
}
void Staff :: listDish_staff(){
    cout<<"=======================================\n";
    cout<<"STT\t"<<"ID\t"<<"Name\t"<<"Price\n";
    int i=1;
    for(Dish item : DATABASE_DISH){
        cout << i << "\t";
        item.getInformation();
        i++;
    }
}
Staff::Staff( int _table_Number , list<Dish> _listDish)
{
    table_Number = _table_Number;
    for(int i = 0; i < _table_Number; i++)
    {
        Table table(i, false, _listDish);
        DATABASE_TABLE.push_back(table);
    }
}
/* 
    Method: menuStaff
 */
Staff::Staff(){

}
int manager_getNumberofTable;
void Staff::menuStaff(){
    int id_table;
    cout<<"Enter id table to access: ";
    cin>>id_table;

    //manager.listDish();
    if(id_table<1 || id_table>manager_getNumberofTable){
        cout<< "ID table does exist!\n";
    }
    else{
        for(Table &table : DATABASE_TABLE){
            if(table.getNumberTable() == id_table){
                
                int options;
                while(1){
                    cout << "____________________________________" << endl;
                    cout << "You chose the table with ID: " << id_table << endl;
                    cout << "1. Add Dish to table" << endl;
                    cout << "2. Update Dish to table" << endl;
                    cout << "3. Delete Dish to table" << endl;
                    cout << "4. List Dish to table" << endl;
                    cout << "5. Bill Payment of table" << endl;
                    cout << "0. Return Option" << endl;
                    cout << "Enter option: ";

                    do{
                        cin>>options;
                        if(options < 0 || options > 5) 
                            cout<<"Invalid choice! Please re-enter: ";
                    } while(options < 0 || options > 5);

                    switch(options){
                    case 1:
                        table.addDish_table();
                        break;
                    case 2:
                        table.updateDish_table();
                        break;
                    case 3:
                        table.deleteDish_table()
                        break;
                    case 4:
                        table.listDish_table();
                        break;
                    case 5:
                        table.billPayment_table();
                        break;
                    case 0:
                        //cout<<getNumberofTable()<<endl;
                        return;
                    }
                }
            }
        }
    }     
}
/* 
    Method: choice_rule
 */
void Choice_Rule::choice_rule(){

    while(1){
        int options;
        cout << "===================================" << endl;
        cout << " MAIN MENU RESTAURANT" << endl;
        cout << "1. Manager" << endl;
        cout << "2. Staff" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter options: ";

        do{
            cin>>options;
            if(options <0 || options > 2) cout<<"Invalid choice! Please re-enter: ";
        } while(options <0 || options > 2);

        switch(options){
            case 0:
                return;
            case 1:
                cout << "You chose Manager!\n";
                //cout<<manager.getNumberofTable()<<endl;
                manager.menuManager(); 
                
                break;
            case 2:
                cout << "You chose Staff!\n";
                staff.setManagerValues(manager.getNumberofTable(), manager.getDatabaseDish());
                cout<<staff.table_Number;
                staff.listDish_staff();
                staff.menuStaff();
                break;
        }
    }
}
Choice_Rule::Choice_Rule(){
    manager =  Manager();
    staff = Staff();
}

#include "RestaurantManagement.h"

/* 
    Contructor: Dish
    Discription: Constructor khoi tao phan tu con moi cua class
    Parameter: name: name of dish
                price: price of dish
 */
Dish::Dish(string name, int price){
    static int id=100;
    ID = id;
    id++;
    NAME = name;
    PRICE = price;    
}
void Dish::getInformation(){
    cout <<"Id: " << getID() << " || Name: " << getName() << " || Price: " << getPrice() << endl;
}
/*  
    Method: menuManagement
*/
void Manager::menuManagement(){
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
        cin>>options;

        do{
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
                break;
            case 4:
                break;
            case 5:
                displayListDish();
                break;
            case 0:
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
void Manager::setNumberOfTable(){
    
    do{
        int key;

        do{
            cout<<"---------------------------------------------------------"<<endl;
            cout<<"Press 1 to set number of table"<<endl;
            cout<<"Press 2 to get number of table"<<endl;
            cout<<"Press 0 to back"<<endl;
            cout<<"Enter options: ";
            
            cin>>key;

            if(key>2 || key<0) cout<<"Invalid choice! Please re-enter: \n";
        } while (key>2 || key<0);


        if(key==1){
            int number_of_table;
            cout<<"Set number of table for restaurant: ";
            cin>>number_of_table;
            NUMBER_OF_TABLE = number_of_table;
            cout<<"Successfully enter!\n";
            return;
        }
        if(key==0){
            return;
        }
        if(key==2){
            cout<< "Number of table: "<<getNumberofTable()<<endl;
            return;
        }
    } while(1);
}

/* 
    method: Add dish
 */
void Manager::addDish(){
    
    while(1){
        string name_dish;
        int price;
        cout << "===================================" << endl;
        cout << "Enter dish information \n";
        cout << "Enter dish name\n ";
        cin >> name_dish;
        cout << "Enter dish price\n";
        cin >> price;
        Dish dish = Dish(name_dish, price);
        DATABASE_DISH.push_back(dish);
        dish.getInformation();
        int choice;
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
void Manager::displayListDish(){
    int choice;
    int i = 1;
    while(1){
        cout << "display dish list\n";
        cout<<"STT\t"<<"ID\t"<<"Name\t"<<"Price\n";
        for(Dish item : DATABASE_DISH){
            cout << i << ". ";
            item.getInformation();
            i++;
        }

        do{
            cout << "Enter 0 to return option\n";
            cin >> choice;
            if(choice != 0){
                cout << "Invalid choice! Please re-enter\n";
            }
        } while( choice != 0);

        if(choice == 0) return;
    }
}

/* 
    Method: choice_rule
 */
void Choice_Rule:: choice_rule(){

    while(1){
        int options;
        cout << "===================================" << endl;
        cout << " MAIN MENU RESTAURANT" << endl;
        cout << "1. Manager" << endl;
        cout << "2. Staff" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter options: ";
        cin>>options;

        do{
            if(options <0 || options > 2) cout<<"Invalid choice! Please re-enter: ";
        } while(options <0 || options > 2);

        switch(options){
            case 0:
                return;
            case 1:
                cout << "You chose Manager!\n";
                manager.menuManagement(); 
                break;
            case 2:
                cout << "You chose Staff!\n";
               //staff.();
                break;
        }
    }
}

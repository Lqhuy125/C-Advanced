#include "RestaurantManagement.h"

int main()
{
    Dish dish1 = Dish("com", 5000);
    Dish dish2 = Dish("ga", 10000);

    Choice_Rule choice;
    choice.manager.DATABASE_DISH.push_back(dish1);
    choice.manager.DATABASE_DISH.push_back(dish2);
    
    choice.choice_rule();
        
    return 0;
}

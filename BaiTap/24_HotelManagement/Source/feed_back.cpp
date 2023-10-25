#include <feed_back.h>

void Feedback(vector<Feedback_info> & listof_Feedback){
    int key;
    string name;
    string feedback;
    while (1)
    {
        system("cls");
        cout<<"====FEEDBACK AND EVALUATION===="<<endl<<endl;
        cout<<"Enter your name: "; cin >> name;
        
        cout<<"Enter your feeddback: "; cin >> feedback;
        double mark;
        cout<<"Enter your rating: "; 
        do
        {
            cin >> mark;
            if(mark > 10) cout << "Diem khong vuot qua 10\n. Enter again: ";
        } while (mark > 10);
        Feedback_info temp(name,feedback,mark);
        listof_Feedback.push_back(temp);
        cout<<"Your response has been noted. Thank you for using our service!!!"<<endl;
        do
        {
            cout<<"1. Continue."<<endl<<"0. Back."<<endl;
            cout<<"Enter your choose: "; cin >> key;
        } while (key > 1);
        if(key == 0) return;
    }
}
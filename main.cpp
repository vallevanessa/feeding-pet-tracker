#include <iostream>
#include <fstream>
#include <string>

using namespace std;



int option(){
    int op;

    cout << "What would you like to do today?" << endl;
    cout << "1. Add to my feeding schedule" << endl;
    cout << "2. See my feeding schedule" << endl;
    cout << "3. Clear my list" << endl;
    cout << "4. Exit" << endl;

    cout << "Please select an option: ";
    cin >> op;

    while(op != 1 && op != 2 && op !=3 && op != 4){
        cout << "Invalid option. Select 1, 2, or 3: ";
        cin >> op;
    }

    return op;
}


int make(int op){

    string scheduleFile = "schedule.txt";
    fstream newfile;

    if(op == 1){

        newfile.open(scheduleFile, ios_base::app);

        if(newfile.is_open()){

            cin.ignore(256, '\n'); 
            string time;
            string food;

            cout << "Enter time: ";
            getline(cin, time);

     
            cout << "Enter food: ";
            getline(cin, food);
            

            newfile << time << " " << food << "\n";



        }
        newfile.close();

        
    }




    if (op == 2){

            newfile.open(scheduleFile, ios::in);

            cout << "FEEDING TRACKING: " << endl;
            cout << "-------------------" << endl;

            if(newfile.is_open()){
                string tp;
                while(getline(newfile, tp)){
                    cout << tp << endl;
                }
                newfile.close();
            }

            cout << "-------------------" << endl;


    }

    if(op ==3){
        ofstream newfile;
        newfile.open("schedule.txt", ofstream::out | ofstream::trunc);
        newfile.close();

    }

    return option();
    

}


int main(){


    cout << "Is it time to feed your pet again?" << endl;

    int x = option();

    while(x != 4){
        x = make(x);
    }

    cout << "Check back in later!" << endl;



    return 0;
}

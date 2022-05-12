//Main.cpp

#include <bits/stdc++.h>
#include <vector>
using namespace std;

#include "functions.cpp"





int main()
{

    while (1)
    {
        get_data();

        cout<<"--------------------------------++++-----------------------------";
        cout<<endl;
        cout <<"\nchoose the operation you want"<<endl<<"\n1.Register\n2.Login\n3.Change Password\n4.Exit\n"<<endl;
        cout<<"--------------------------------++++-----------------------------\n";
        string chosen_opperation;
        cin >> chosen_opperation;
        cin.ignore();
        cout << "\n";
        check_operation(chosen_opperation);
        int choice = stoi(chosen_opperation);
        cin.ignore();
        //for (int i=0 ; i<data.size();i++ ) cout<<data[i].id<<" "<<data[i].pasword<<" "<<data[i].Email<<" "<<data[i].Phone<<" "<<endl;
        if (choice == 4)
        {
            cout << "Thank you for using our program :)\n";
            break;
        }
        if (choice>=1 && choice<4)
        {

            if (choice == 1)
            {

                UserData();
            }

            if (choice == 2)
            {

                login();

            }
            if (choice == 3)
            {

            }


        }
        //gets the user back to choose the operation if he enters a wrong input
        else
        {
            cout << "Sorry, your input is invalid. Please try again ! " << endl;
            main();
            cout << "\n";
        }
put_data();
}
return 0;
}


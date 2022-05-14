// FCAI - Structured Programming - 2022 - Assignment 4
//Program Name : LOGIN system
// Program Description : saves user's data as login systems using a file of txt to save those data
// Author1 :  Mohamed Ashraf Fahim         ID:20210329       Group: A
// Author2 :  Momen Mostafa Mabrouk        ID:20210416       Group: A
// Author3 :  Mariam Esmat Ahmed           ID:20211091       Group: A
// ver4 of Date : 14th of May 2022
//section 9,10


#include <bits/stdc++.h>
#include <vector>
#include "functions.cpp"
using namespace std;


int main()
{

    while (1)
    {
        get_data();

        cout<<"\n--------------------------------++++-----------------------------";
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
                change_password();
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


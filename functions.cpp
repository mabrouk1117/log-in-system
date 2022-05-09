#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <vector>
#include "log_in_system.h"

using namespace std;

typedef struct{
    string id ;
    string Email;
    string pasword;

}user;

vector<user> data ;



fstream my_file;

string file_name = "users.txt" ;

string text;

stringstream line;

istream &operator>> (stringstream &in, user& x  ){
        in>>x.id>>x.pasword>>x.Email;
        return in;
}

void get_data(){
    int ctr = 0;
    my_file.open(file_name, ios::in);
    while (getline(my_file , text)){
        data.push_back(user());
        ctr++;
    }
    my_file.close();
    my_file.open(file_name, ios::in);

    for (int i=0 ; i<ctr ; i++){
        getline(my_file,text);
        line << text;
        line>>data[i];
    }

}


void put_data(){
    my_file.close();
    my_file.open(file_name, ios::out);
    for (int i=0 ; i<data.size();i++ )
        my_file<<data[i].id<<" "<<data[i].pasword<<" "<<data[i].Email<<" "<<endl;

    my_file.close();


}


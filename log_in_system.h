//log_in_system.h

#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <vector>
#include <regex>


using namespace std;

int ctr=0;
fstream my_file;

string file_name = "users.txt" ;

string text;

stringstream line;


typedef struct
{
    string id ;
    string Email;
    string Phone;
    string pasword;

}user;


void check_operation(string& number);


void get_data();

void put_data();

bool valid_UserName(string& username);

bool valid_email(string& email);

bool valid_phone(string& phone);

istream &operator>> (stringstream &in, user& x  );

string PassWord();

void UserData();

void login();




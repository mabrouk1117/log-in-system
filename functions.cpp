#include <conio.h>
#include "log_in_system.h"

using namespace std;

vector<user>data;

istream &operator>> (stringstream &in, user& x  )
{
        in>>x.id>>x.pasword>>x.Email>>x.Phone;

}

void check_operation(string& number)
{
    //takes the chosen opertaion as a string
    string chosen_opperation;
    //loops through that string
    for (int i = 0; i < number.length(); i++)
    {
        //if i is a digit it is appeanded
        if (isdigit(number[i]))
        {
            chosen_opperation.push_back(number[i]);
        }
    }
    //lenght of the string is not the same anymore it means that it icnulded a letter
    if (chosen_opperation.length() != number.length())
    {
        //ask the user to enter a new chioce
        cout << "Invalid input, please try again: ";
        cin >> number;
        cin.ignore();
        //re-apply the same function
        check_operation(number);
    }
}


void get_data()
{
    // vector<user>data;
    int ctr = 0;
    my_file.open(file_name, ios::in);
    while (getline(my_file , text))
    {
        data.push_back(user());
        ctr++;
    }
    my_file.close();
    my_file.open(file_name, ios::in);

    for (int i=0 ; i<ctr ; i++)
    {
        getline(my_file,text);
        line << text;
        line>>data[i];
        line.str("");
        line.clear();

    }
    my_file.close();

}

void put_data()
{
    // vector<user>data;
    my_file.close();
    my_file.open(file_name, ios::out);
    for (int i=0 ; i<data.size();i++ )
        my_file<<data[i].id<<" "<<data[i].pasword<<" "<<data[i].Email<<" "<<data[i].Phone<<" "<<endl;

    my_file.close();


}

bool valid_phone(string& phone)
{
    regex check("01([0]|[1]|[2]|[5])([0-9]{8})");
    return regex_match(phone, check);
}


bool valid_email(string& email)
{
    regex check("([_]?[a-zA-Z0-9]+[_.]?[a-zA-Z]*[0-9]*[_.]?[a-zA-Z]*[0-9]*)+\\@([a-zA-Z])+\\.(com)");
    return regex_match(email, check);
}

bool valid_UserName(string& username)
{
    regex check("[_a-zA-Z]+");
    return regex_match(username, check);
}

string PassWord()
{
string pass="",pass2="";
char c;

cout<<"\nPlease Enter a Strong Password\nA strong password has at least eight characters using One or more of each of the following:\n"
<<"lower-case letters,upper-case letters,numbers, special symbols"
<<"\n\nHINT: Lookalike characters protect your password against glimpses. Examples:\n"
<< "O as in Oscar and the number 0\nLower-case l and upper-case I"<<endl;

// loop condition: get a character, while it isn't a newline (end of password), then...
while ((c=_getch()) != 13)
{

// put it onto the back of the password
// output a '*' character
    if ( c =='\b')
    {
        pass.pop_back();
        putch('\b');
        putch(' ');
        putch('\b');
    }
    else{

    pass.push_back(c);
    _putch('*');
    }
}

cout<<"confirm password :  ";
while ((c=_getch()) != 13)
{

// put it onto the back of the password
// output a '*' character
    if ( c =='\b')
    {
        pass2.pop_back();
        putch('\b');
        putch(' ');
        putch('\b');
    }
    else{

    pass2.push_back(c);
    _putch('*');
    }
}
if (pass == pass2) return pass;

return PassWord();

}

void UserData()
{
    // vector<user>data;
    string temp;
    int x = 0;
    data.push_back(user());


 //Taking user name
    while(1)
    {
    x=0;
    cout<<"\nEnter Username: ";
    cin>>temp;
    for(int i =0 ; i<data.size();i++)
    {
        if(temp==data[i].id)
        {
            cout<<"this username is already taken";

           x=1;
           break;
        }

    }
    if (x==1)
        continue;

    if(valid_UserName(temp)==0)
    {
       cout<<"this user is in invalid form";

       continue;
    }
    break;
    }

    data[data.size()-1].id=temp;



  //Taking user's Email
     while(1)
    {

    x=0;
    cout<<"\nEnter your E-Mail: ";
    cin>>temp;
    for(int i =0 ; i<data.size();i++)
    {
        if(temp==data[i].Email)
        {
            cout<<"this E-Mail is already used";

             x=1;
            break;
        }
    }
    if (x==1)
        continue;
        if(valid_email(temp)==0)
        {
            cout<<"this Email is invalid";
            continue;
        }
    break;
    }
    data[data.size()-1].Email=temp;


   //Taking user's phone number
    while(1)
    {
        cout<<endl<<"enter phone: ";
        cin>>temp;

       if(valid_phone(temp)==0)
        {
            cout<<"this number is incorrect";
            continue;
        }
       break;
    }

    data[data.size()-1].Phone=temp;


    //PASSWORD
    temp=PassWord();
    data[data.size()-1].pasword=temp;


}

int ctr=0;
void login()
{
    char c;
    // vector<user>data;
   string tempId , tempPass;
    int x=0;

    cout<<"\nPlease enter your username: ";
    cin>>tempId;

    for(int i =0 ; i<data.size();i++)
    {

        if(tempId==data[i].id)
        {
             cout<<"\nPlease enter your Password: ";
            while ((c=_getch()) != 13)
            {

            // put it onto the back of the password
            // output a '*' character
                if ( c =='\b')
                {
                    tempPass.pop_back();
                    putch('\b');
                    putch(' ');
                    putch('\b');
                }
                else{
                tempPass.push_back(c);
                _putch('*');
                }
            }
             if(tempPass==data[i].pasword)
                {

                    cout<<"\nSuccessful login , welcome "<< tempId<<endl;
                }
                else
                {
                    cout<<"\nFailed login. Try again!"<<endl;
                    ctr++;
                    if(ctr>=3)
                    {
                        cout<<"\nyou're not allowed to login"<<endl;

                    }
                    else
                        login();
                }
        }


    }

}



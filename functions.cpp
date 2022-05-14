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
        //line.clear();

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

bool strongPass(string pass){
    int ctr=0;
    if(pass.size() <8  || pass.size() >30 ) return 0;
    for (int i=0 ; i < pass.size() ;i++){
        if ( islower(pass[i]))
            ctr++;
        else if ( isupper(pass[i]))
            ctr+=2;
        else if (isdigit(pass[i]))
            ctr+=3;
        else
            ctr+=4;
    }
    if ( ctr==pass.size() || ctr==2*pass.size() || ctr==3*pass.size() || ctr==4*pass.size() )
        return 0;
    else return 1;

}

string coverPassword(){
    char c;
    string pass;
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
    return pass;



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

    cout<<"\nPlease Enter a Strong Password\nA strong password has at least eight characters and max 30 characters using two or more of each of the following:\n"
        <<"lower-case letters,upper-case letters,numbers, special symbols"
        <<"\n\nHINT: Lookalike characters protect your password against glimpses. Examples:\n"
        << "O as in Oscar and the number 0\nLower-case l and upper-case I"<<endl<<"enter password :  ";

    while(1){
        pass=coverPassword();
        if (strongPass(pass)==1)
            break;
        cout<<"\nyou entered a weak password\n\n";
    }
    cout<<"\nconfirm password :  ";
    pass2 = coverPassword();
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
        cout<<"\nTo have a valid username you can only use litters (upper/lower case) and ( _ )";
        cout<<"\nEnter Username: ";
        cin>>temp;
        for(int i =0 ; i<data.size();i++)
        {
            if(temp==data[i].id)
            {
                cout<<"\nOps!! this username is already taken,try a new one"<<endl;

                x=1;
                break;
            }

        }
        if (x==1)
            continue;

        if(valid_UserName(temp)==0)
        {
            cout<<"\nthis user is in invalid form";

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
                cout<<"\nThis E-Mail address is already used";

                x=1;
                break;
            }
        }
        if (x==1)
            continue;
        if(valid_email(temp)==0)
        {
            cout<<"\nthis Email is in invalid form";
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
    for (int i=0 ; i<temp.size();i++ ) temp[i]+=(2*i);
    data[data.size()-1].pasword=temp;


}

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
            tempPass = coverPassword() ;
            for (int i=0 ; i<tempPass.size();i++ ) tempPass[i]+=(2*i);

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

void change_password()
{
    char c;
    // vector<user>data;
    string tempId , tempPass ,newPass;
    int x=0;

    cout<<"\nPlease enter your username: ";
    cin>>tempId;

    for(int i =0 ; i<data.size();i++)
    {

        if(tempId==data[i].id)
        {
            cout<<"\nPlease enter your OLd Password: ";
            tempPass = coverPassword();
            for (int j=0 ; j<tempPass.size();j++ ) tempPass[j]+=(2*j);

            if(tempPass==data[i].pasword)
            {

   newPass = PassWord();
    for (int j=0 ; j<newPass.size();j++ ) newPass[j]+=(2*j);
   data[i].pasword=newPass;
            }
            else
            {
                cout<<"\nYour old password is wrong"<<endl;
                ctr++;
                if(ctr>=3)
                {
                    cout<<"\nyou're not allowed to login"<<endl;

                }
                else
                    change_password();
            }
        }


    }




}

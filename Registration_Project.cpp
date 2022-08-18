#include<iostream>
#include<fstream>
#include<string.h>
#include<conio.h>
using namespace std;

void login();
void registration();
void forget();
void del();
int main()
{
    int c;
    cout<<"\t\t\t_________________________________________\n\n\n";
    cout<<"\t\t\t________Welcome To Login Page____________\n\n\n";
    cout<<"\t\t\t_________________MENU____________________\n\n\n";
    cout<<"\t\t\t                                          \n\n";
    cout<<"\t   _                                      _ \n";
    cout<<"\t1.| Press 1 for Login:                     |\n";
    cout<<"\t  |                                        |\n";
    cout<<"\t2.| Press 2 for Register:                  |\n";
    cout<<"\t  |                                        |\n";
    cout<<"\t3.| Press 3 for forgot Your Password:      |\n";
    cout<<"\t  |                                        |\n";
    cout<<"\t4.| Press 4 for Delete Your Account:       |\n";
    cout<<"\t  |                                        |\n";
    cout<<"\t5.| Press 5 for Exit:                      |\n";
    cout<<"\t  |                                        |\n";
    cout<<"\t   -                                      -\n";
    cout<<endl<<"\n\t Please Enter Your Choice:-    ";
    cin>>c;
    cout<<endl;
    switch(c)
    {
    case 1:
        login();
        break;
    case 2:
        registration();
        break;
    case 3:
        forget();
        break;
    case 4:
        del();
        break;
    case 5:
        cout<<"\n\t\t Thank you for Visiting us:  \n\n";
        main();
    default:
        system("cls");
        cout<<"\n\n\t Please Select The Valid Choice: \n\n\n";
        main();
    }
    getch();
}
void login()
{
    int count;
    string userid,password,id,pass;
    system("cls");
    cout<<"\n\n\t\t\t Please Enter The UserName And Password:   \n";
    cout<<"\n\n\t\t\t  USERNAME:-     ";
    cin>>userid;
    cout<<"\n\n\t\t\t Enter Your Password:   ";
    cout<<"\n\n\t\t\t  PASSWORD:-     ";
    cin>>password;
    ifstream input("record.txt");
    while(input>>id>>pass)
    {
        if(id==userid && pass==password)
        {
            count=1;
            system("cls");
        }
    }
    input.close();
    if(count==1)
    {
        cout<<"\n\n\t Login Successful! Thanks For Logging:  \n\n\n";
        main();
    }
    else{
        cout<<"\n\n\t Logging Error, Please Check Your UserName and Password:  \n\n\n";
        main();
    }
}

void registration()
{
    string ruserid,rpassword,rid,rpass;
    system("cls");
    cout<<"\n\n\t\t\t  Enter The UserName:    ";
    cin>>ruserid;
    cout<<"\n\n\t\t\t  Enter The Password:    ";
    cin>>rpassword;
    ofstream f1("record.txt",ios::app);
    f1<<ruserid<<' '<<rpassword<<endl;
    system("cls");
    cout<<"\n\n\t\t\t | Your Registration Is Successful:  |\n\n\n\n" ;
    main();
}

void forget()
{
    int option;
    system("cls");
    cout<<"\n\n\t\t Forgot Your Password, !:Don't Worries:!, We are Here For You!    \n";
    cout<<"\n\t\t |:-                                         -:|\n";
    cout<<"\n\t\t |  Press1. to Search Your ID by UserName:     |\n";
    cout<<"\n\t\t |  Press2. to Go Back to Main Menu:           |\n";
    cout<<"\n\t\t |:_                                         _:|\n";
    cout<<"\n\n\t Enter Your Choice: ";
    cin>>option;
    switch(option)
    {
    case 1:{
        int count=0;
        string suser,sid,spass;
        cout<<"\n\t\t Enter the UserName You have Remembered:  ";
        cin>>suser;
        ifstream f2("record.txt");
        while(f2>>sid>>spass)
        {
            if(sid==suser)
            {
                count=1;
            }
        }
        f2.close();
        if(count==1){
            cout<<"\n\n\t\t Well Your Account Is Match!\n\n\t\t  Let's Enjoy:   ";;
            cout<<"\n\n\t\t Your Password is:    "<<spass<<"\n\n\n";
            main();
        }
        else{
            cout<<endl<<"\n\n\t\t Sorry!  Your Account Does not Exist!  \n\n\n";
            main();
        }
        break;
    }
    case 2:{
        main();
        cout<<"\n\n\n\n\n";}
    default:
    cout<<"\n\n\t\t    Wrong Choice!  Please try Again:  "<<endl;
    forget();
   }
}

void del()
{
    int count;
    string duserid,dpassword,did,dpass;
    system("cls");
    cout<<"\n  Enter Your UserName(ID):   ";
    cin>>duserid;
    cout<<"\n  Password:  ";
    cin>>dpassword;
    ifstream f3("record.txt");
    while(f3>>did>>dpass)
    {
        if(did==duserid && dpass==dpassword)
        {
            count=1;
            system("cls");
        }
    }
    f3.close();
    if(count==1)
    {
        remove("record.txt");
        cout<<"\n Thank You for Your journey!\n";
        cout<<"\n \"Now You are No Longer WIth Us:\" \n\n\n";
        main();
    }
    else{
        cout<<"\nYour ID and PASSWORD Does not Match with Our Record!:\n\n\n";
        main();
    }
}


#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <Windows.h>
using namespace std;

string username, un, line, filename1, password;
int offset, choice, status, lgin = 0, uppernum, lowernum, special, digitnum;
char password1[50], response;

bool IsLoggedIn() {
    string username,password,pw,un;
    char password1;
    int lgin = 0, wrong = 0;
    cout << "Please enter your username:"<<endl;
    cin >> username;
    ifstream read(username + ".txt");
    getline(read, un);
    getline(read, pw);
    if (un != username) {                           
            cout << "User couldn't found." << endl;
            return 0;
    }
    else {
       
        cout << "Please enter your password:"<<endl;
        cin >> password;
        
        if (pw == password) {
            lgin += 1;
            return true;
        }
        else {
            cout << "Wrong password."<<endl;
            return 0;

        }
    }

}
int action() {
    cout << "Please choose an action" << endl;
    cout << "Registration(1)" << endl;
    cout << "Login(2)" << endl;
    cout << "Delete the user(3)" << endl;
    cout << "Exit(4)" << endl;
    cin >> choice;
    return 0;
}

int main()
{
    action();

    if (choice == 1) {
        cout << "Please select a username:" << endl;
        cin >> username;
        ifstream read(username + ".txt");
        getline(read, un);
        if (username==un){
            cout << "User is already exists."<<endl;
            cout << "Do you want to make another action[Y/N]:"<<endl;
            cin >> response;
            if (response == 'Y' || response == 'y') {
                main();
            }
            else if (response == 'N' || response == 'n') {
                return 0;
            }
        }
        else {
            cout << "Please select a password:" << endl;
            cin >> password;
            strcpy_s(password1, password.c_str());
            ofstream Myfile(username + ".txt");
            Myfile << username << endl << password;
            Myfile.close();
            cout << "Do you want to make another action[Y/N]:"<<endl;
            cin >> response;
            if (response == 'Y' || response == 'y') {
                main();
            }
            else if (response == 'N' || response == 'n') {
                return 0;
            }
        }
        
    }
    else if (choice == 2) {
        if (lgin == 0) {
            bool status = IsLoggedIn();
            if (!status) {
                cout << "Login failed!" << endl;
                cout << "Do you want to make another action[Y/N]:"<<endl;
                cin >> response;
                if (response == 'Y' || response == 'y') {
                    main();
                }
                else if (response == 'N' || response == 'n') {
                    return 0;
                }

            }
            else {
                cout << "Successfully logged in!" << endl;
                lgin +=1;
                cout << "Do you want to make another action[Y/N]:"<<endl;
                cin >> response;
                if (response == 'Y' || response == 'y') {
                    main();
                }
                else if (response == 'N' || response == 'n') {

                    return 0;
                }
            }
        }
        else {
            cout << "You are already logged in. Please restart the program for another user login."<<endl; 
            main();
        }
       
      
    }
    else if(choice==3) {
        cout << "Enter the username wanted to delete:" << endl;
        cin >> username;
        filename1 = (username + ".txt");
        int n = filename1.length();
        char filename[50];
        ifstream read(username + ".txt");
        getline(read, un);
        if (un != username) {
            cout << "User doesn't exist or already has been deleted."<<endl;
            cout << "Do you want to make another action[Y/N]:"<<endl;
            cin >> response;
            if (response == 'Y' || response == 'y') {
                main();
            }
            else if (response == 'N' || response == 'n') {
                return 0;
            }
            read.close();
        }
        else {
            strcpy_s(filename, filename1.c_str());
            read.close();
            remove(filename);
            cout << "User successfully deleted!"<<endl;
            cout << "Do you want to make another action[Y/N]:"<<endl;
            cin >> response;
            if (response == 'Y' || response == 'y') {
                main();
            }
            else if (response == 'N' || response == 'n') {
                return 0;
            }
        }
       
    }
}



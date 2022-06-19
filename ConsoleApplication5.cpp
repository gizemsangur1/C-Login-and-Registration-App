#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool IsLoggedIn() {
    string username,password,pw,un;
    cout << "Please enter your username:";
    cin >> username;
    ifstream read(username + ".txt");
    getline(read, un);
    getline(read, pw);
    if (un != username) {
        cout << "User couldn't found.Please try again."<<endl;
        IsLoggedIn();
    }
    else {
       
        cout << "Please enter your passowrd:";
        cin >> password;
        return true;
    }

}

int main()
{
    string username, un;
    int offset;
    string line;
    string password;
    int choice;
    int status;
    string filename1;
    char response;

    cout << "Please choose an action"<<endl;
    cout << "Registration(1)"<<endl;
    cout << "Login(2)"<<endl;
    cout << "Delete the user(3)" << endl;
    cin >> choice;
    if (choice == 1) {
        cout << "Please select a username:" << endl;
        cin >> username;
        ifstream read(username + ".txt");
        getline(read, un);
        if (username==un){
            cout << "User is already exists.";
            cout << "Do you want to make another action[Y/N]:";
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
            ofstream Myfile(username + ".txt");
            Myfile << username << endl << password;
            Myfile.close();
            cout << "Do you want to make another action[Y/N]:";
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
        bool status = IsLoggedIn();
        if (!status) {
            cout << "Login failed!"<<endl;
            cout << "Do you want to make another action[Y/N]:";
            cin >> response;
            if (response == 'Y' || response == 'y') {
                main();
            }
            else if (response == 'N' || response == 'n') {
                return 0;
            }
            
        }
        else {
            cout << "Successfully logged in!"<<endl;
            cout << "Do you want to make another action[Y/N]:";
            cin >> response;
            if (response == 'Y' || response == 'y') {
                main();
            }
            else if (response == 'N' || response == 'n') {
                return 0;
            }
        }
    }
    else if(choice==3) {
        cout << "Enter the username wanted to delete:" << endl;
        cin >> username;
        filename1 = (username + ".txt");
        int n = filename1.length();
        char filename[50];
        strcpy_s(filename, filename1.c_str());
        remove(filename);
        cout << "User successfully deleted!";
        cout << "Do you want to make another action[Y/N]:";
        cin >> response;
        if (response == 'Y' || response == 'y') {
            main();
        }
        else if (response == 'N' || response == 'n') {
            return 0;
        }
    }
}



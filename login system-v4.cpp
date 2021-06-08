#include <iostream>
#include <fstream>
#include <vector>
#include <windows.h>
using namespace std;

/*
 * splits a long string into pieces with delimiter
 * returns the vector array of seperated strings
 */
vector<string> split(string str, char dl)
{
    string word = "";
    vector<string> substr_list;

    // adding delimiter at the end of the string
    str = str + dl;
    int l = str.size();

    // traversing 'str' from left to right
    for (int i = 0; i < l; i++)
    {
        // adding character when no delimiter is spotted
        if (str[i] != dl)
            word = word + str[i];

        else
        {
            // push the word to array if not empty
            if ((int)word.size() != 0)
                substr_list.push_back(word);

            // reset the word after pushing it to array
            word = "";
        }
    }

    return substr_list;
}

/*
 * Reads login data from database
 * takes input from user and compares them
 * it recurses until a successful login
 */
void login()
{
    string name, pass, buffer, temp;
    ifstream log("database01.txt");
    // leaving the program if log file doesn't exists
    if (!log)
    {
        cout << "Can't read log file!" << endl;
        exit(0);
    }

    // taking input from the user
    cout << "LOGIN HERE ---------- " << endl;
    cout << "Username: ";
    cin >> name;
    cout << "Password: ";
    cin >> pass;

    // scanning the log file line by line
    while (getline(log, temp))
    {
        // getting the username part
        buffer = split(temp, ',')[0];

        if (buffer == name)
        {
            // getting the password part
            buffer = split(temp, ',')[1];

            if (buffer == pass)
            {
                system("cls");
                cout << "Login Successfull!" << endl;
                // leaving the revursion after login
                return;
            }
        }
    }

    log.close(); // closing the file
    system("cls");
    cout << "Invalid UserID or Password.\n";

    // recursing the function for another attempt
    login();
}

int main()
{
    // clearing the terminal
    system("cls");

    // login function will recurse until a valid attempt
    login();

    // stopping the terminal
    system("pause");
    return 0;
}
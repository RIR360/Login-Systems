#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <windows.h>
#include <conio.h>
#include <ctime>
#include <cstdlib>
using namespace std;

typedef struct user
{
    string firstname;
    string lastname;
    string username;
    string password;
} User;

// directly encrypts using a simple algorithm
void encrypt(string &str, int key)
{
    int len = str.size();
    for (int i = 0; i < len; i++)
    {
        if (i % 2 == 0)
        {
            str[i] = (char) (str[i] + key);
        }
        else 
        {
            str[i] = (char) (str[i] + len);
        }
    }
}

// returns decrypted version of the string using the reverse algorithm
string decrypt(string str, int key)
{
    string out = str;
    int len = str.size();
    for (int i = 0; i < len; i++)
    {
        if (i % 2 == 0)
        {
            out[i] = (char) (out[i] - key);
        }
        else 
        {
            out[i] = (char) (out[i] - len);
        }
    }
    return out;
}

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
 * Scans the database file to find the user
 * shows information about the user
 */
void show_user_info(string userID)
{
    string buffer, temp;
    // reading the database file
    ifstream database("database03.txt");
    if (!database)
    {
        cout << "Error: Can't access log file!" << endl;
        exit(0);
    }

    // scanning the file to find the user
    while (getline(database, temp))
    {
        buffer = split(temp, ',')[0];
        if (userID == buffer)
        {
            system("cls");
            cout << "Name: ";
            cout << split(temp, ',')[1] << " " << split(temp, ',')[2]<< endl;
            cout << "Username: @" << userID << endl;
            return;
        }
    }
    database.close();
    cout << "Didn't find any info for @" << userID << endl;
}

/*
 * Scans the content file avialable
 * prints the content to the stdout
 */
void show_content()
{
    string buffer;

    // reading the content file
    ifstream content("content.txt");
    if (!content)
    {
        cout << "Error: Can't access content file." << endl;
        exit(0);
    }

    // printing the content of the file
    system("cls");
    while (getline(content, buffer))
    {
        cout << buffer << endl;
    }

    content.close();
}

/*
 * Reads login data from database
 * takes input from user
 * reads password and key from the database
 * decrypts the password with the key and compares
 * it recurses until a successful login
 */
void login()
{
    string buffer, temp;
    User person;

    // reading log file
    ifstream log("database03.txt");
    if (!log)
    {
        cout << "Can't access log file!" << endl;
        exit(0);
    }

    // taking inputs from the user
    cout << "LOGIN HERE ---------- " << endl;
    cout << "Username: ";
    cin >> person.username;
    cout << "Password: ";
    cin >> person.password;

    // scanning the log file line by line
    while (getline(log, temp))
    {
        // getting the username part
        buffer = split(temp, ',')[0];
        if (person.username == buffer)
        {
            // getting the key
            stringstream s_temp(split(temp, ',')[4]);
            int k = 0;
            s_temp >> k; // string to integer

            // getting the decrypted password
            buffer = decrypt(split(temp, ',')[3], k);

            if (person.password == buffer)
            {
                system("cls");
                cout << "Login Successfull!" << endl;

                // showing user details
                show_user_info(person.username);
                cout << "Press a key to progress..." << endl;
                getch();

                // showing the content and return
                system("cls");
                show_content();
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

/*
 * Takes user information from stdin
 * checks if the user is already exists
 * generates a key and encrypts the password
 * writes the information to the database
 */
void registration()
{
    string buffer, temp;
    User person;

    // taking inputs from the user
    cout << "REGISTER HERE ---------- " << endl;
    cout << "Firstname: ";
    cin >> person.firstname;
    cout << "Lastname: ";
    cin >> person.lastname;
    cout << "Username: ";
    cin >> person.username;
    cout << "Password: ";
    cin >> person.password;

    // reading database
    ifstream log_details("database03.txt");
    if (!log_details)
    {
        cout << "Can't access log file!" << endl;
        exit(0);
    }

    // scanning the file to check if the same user exists already
    while (getline(log_details, temp))
    {
        buffer = split(temp, ',')[0];
        if (person.username == buffer)
        {
            system("cls");
            cout << "User already exists!" << endl;
            // recursing the process for another attempt
            registration();
        }
    }
    log_details.close();

    // appending to database
    ofstream log("database03.txt", ios_base::app);
    if (!log)
    {
        cout << "Can't access log file!" << endl;
        exit(0);
    }

    // writing info into database
    log << person.username << ",";
    log << person.firstname << ",";
    log << person.lastname << ",";

    // generating random encrption key
    srand(time(0));
    int key = 1 + (rand() % 100); // random value from 1 to 100
    
    encrypt(person.password, key);

    log << person.password << ",";
    log << key << endl;

    show_user_info(person.username);
    cout << "Registration Successful!" << endl;
    log.close();
}

int main()
{
    // clearing the terminal
    system("cls");

    int choice;
    cout << "Enter 0 to Login." << endl;
    cout << "Enter 1 to Register." << endl;
    cin >> choice;

    // determining which process to start
    if (choice == 0)
        login();

    else if (choice == 1)
        registration();

    else
        cout << "Your choice was not valid.\n";

    // stopping the terminal
    system("pause");
    return 0;
}
#include <stdio.h>
#include <string.h>
#include <windows.h>
#define  SMALL 50
int logged = 0; // login status

typedef struct User
{
    char username[SMALL];
    char password[SMALL];
} User;

/* 
 * Shows a prompt/text to the stdout
 * takes a string from stdin and store it into an array
 */
void get_string(char prompt[], char *str)
{
    printf("%s", prompt);
    scanf("%s", str);
}

/*
 * contains login data of several users
 * takes username and password from stdin
 * compares the username and password with all users avialable in the database
 * shows the username after successful login
 */
void login()
{
    char name[SMALL], pass[SMALL];
    int users = 3; // total users
    User log_data[users];

    // storing login database into the structures
    strcpy(log_data[0].username, "rir");
    strcpy(log_data[0].password, "qwer");
    strcpy(log_data[1].username, "bob");
    strcpy(log_data[1].password, "asdf");
    strcpy(log_data[2].username, "alice");
    strcpy(log_data[2].password, "123");


    // taking inputs from the user
    printf("= = = = LOGIN = = = =\n");
    get_string("Username: ", name);
    get_string("Password: ", pass);

    // loops through all the stored users
    int i;
    for (i = 0; i < users; i++)
    {
        if (!strcmp(name, log_data[i].username))
        {
            if (!strcmp(pass, log_data[i].password))
            {
                system("cls");
                printf("Login Successful!\n");
                printf("@%s\n", name);
                // leaving the function after login
                logged = 1;
                return;
            }
        }
    }

    system("cls");
    printf("!Incorrect UserID or Password\n");
    // failed to login
    logged = 0;
}

int main()
{
    // clearing the terminal
    system("cls");

    while (1)
    {
        login();
        // leaving the loop when login is successful.
        if (logged) break;
    }

    // stopping the terminal
    system("pause");
    return 0;
}
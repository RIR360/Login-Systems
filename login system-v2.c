#include <stdio.h>
#include <string.h>
#include <windows.h>
#define  SMALL 50
char main_pass[SMALL] = "qwerty99";
int logged = 0; // login status

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
 * Takes username and password from stdin
 * compares the password with main pass
 * shows the username after successful login
 */
void login()
{
    char user[SMALL], pass[SMALL];

    // taking inputs from the user
    printf("= = = = LOGIN = = = =\n");
    get_string("Username: ", user);
    get_string("Password: ", pass);
    
    if (!strcmp(main_pass, pass))
    {
        system("cls");
        printf("Login Successful!\n");
        printf("@%s\n", user);
        // logged true
        logged = 1;
    }
    else
    {
        system("cls");
        printf("!Incorrect Password\n");
        // logged false
        logged = 0;
    }
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
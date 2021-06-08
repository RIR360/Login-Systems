#include <stdio.h>
#include <string.h>
#include <windows.h>
#define SMALL 50
char main_pass[SMALL] = "qwerty99";

/* 
 * Shows a prompt/text to the stdout
 * takes a string from stdin and store it into an array
 */
void get_string(char prompt[], char *str)
{
    printf("%s", prompt);
    scanf("%s", str);
}

int main()
{
    char user[SMALL], pass[SMALL];

    // taking inputs from the user
    get_string("Username: ", user);
    get_string("Password: ", pass);

    if (!strcmp(main_pass, pass))
        printf("Login Successful!\n");
    else
        printf("!Incorrect Password\n");

    // stopping the terminal
    system("pause");
    return 0;
}
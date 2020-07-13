#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Ask the name of the user
    string name = get_string("What is your name?\n");

    // Print a hello message whit the name of the user
    printf("hello, %s\n", name);
}
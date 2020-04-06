#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // ask for name
    string name = get_string("qual seu nome?\n");
    // say "hello + name"
    printf("hello, %s\n", name);
}

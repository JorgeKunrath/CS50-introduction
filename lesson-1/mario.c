#include <cs50.h>
#include <stdio.h>

int how_many_lines(void);

int main(void)
{
    int b = how_many_lines();
    // printf("you asked for %i lines and you gonna have it ;)\n", b );
    // you know your auto-code-review is pretty boring ;-;

    // repeat counter
    int rpt = 1;

    // build each row
    for (int i = 0; i < b; i++)
    {
        // spaces
        // define spaces equal to blocks less the many times they are reapeated (incremented in the end; starts with one)
        int s = b - rpt; //3
        
        // blocks
        // define how much blocks build in that line (user input - spaces)
        int block = b - s; //3

        // build the blank spaces
        for (int xs = s; xs > 0; xs--)
        {
            printf(" ");
        }

        // build the line itself
        for (int x = block; x > 0; x--)
        {
            printf("#");
        }

        // build the gap (2 spaces)
        printf("  ");

        // build the second part of the line
        for (int x = block; x > 0; x--)
        {
            printf("#");
        }

        // break line
        printf("\n");

        rpt++;
    }
}

// ask how many lines to build with #
int how_many_lines(void)
{
    int lines;
    do
    {
        lines = get_int("how many lines? ");
        if (lines < 1 || lines > 8)
        {
            printf("lines has to be between 1 and 8\n");
        }
    }
    while (lines < 1 || lines > 8);
    return lines;
}

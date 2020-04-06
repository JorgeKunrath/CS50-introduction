#include <cs50.h>
#include <stdio.h>
#include <math.h>

// OK ask for a change (float input)
// OK multiply and round by 100 (floats become int)
// OK subtract the value by the greatest coin and increment, repeat
// OK repeat for each other coin
// OK answer that for the customer

float what_change();

int main(void)
{
    // ask for change (in dolars)
    float dolars = what_change();
    // printf("dolars: %f\n", dolars);

    // transform to cents
    int cents = round(dolars * 100);
    // printf("cents: %i\n", cents);

    // --------------------------------------
    // DIVIDERS
    // --------------------------------------
    int q = 25;
    int d = 10;
    int n = 5;
    int p = 1;

    int qc = 0;
    int dc = 0;
    int nc = 0;
    int pc = 0;

    int next = cents;

    // quarters 25
    while (next >= q)
    {
        next = next - q;
        qc++;
        // printf("qc: %i\n", qc);
    }

    // dimes 10
    while (next >= d)
    {
        next = next - d;
        dc++;
        // printf("dc: %i\n", dc);
    }

    // nickles 5
    while (next >= n)
    {
        next = next - n;
        nc++;
        // printf("nc: %i\n", nc);
    }

    // p 1
    while (next >= p)
    {
        next = next - p;
        pc++;
        // printf("pc: %i\n", pc);
    }
    
    int totalcoins = qc + dc + nc + pc;

    printf("%i\n", totalcoins);


    // printf("end next: %i\n", next);
    // printf("%i\n", qc);
    // printf("%i\n", dc);
    // printf("%i\n", nc);
    // printf("%i\n", pc);
}

// ask for change (float input)
float what_change()
{
    float change;
    do
    {
        change = get_float("What is your change? ");
    }
    while (change <= 0);
    return change;
}

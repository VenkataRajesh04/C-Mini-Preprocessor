// macro handler

#include<stdio.h>

#define A 10
#define B A
#define C B

int main()
{
    printf("A = %d\n", A);
    printf("B = %d\n", B);
    printf("C = %d\n", C);

    return 0;
}

/*
#include<stdio.h>
#define NUM 10
#define PI 3.14
#define MSG 10
int main()
{
    printf("NUM = %d\n", NUM);
    printf("PI = %.2f\n", PI);
    printf("MSG = %d\n", MSG);

    return 0;
}
*/


/*
#include<stdio.h>
//#define NUM 10
#define SQUARE(x) ((x)*(x))
#define CUBE(x) ((x)*(x)*(x))
//#define SREE 60
int main()
{
int a=5;
printf("Number = %d\n",a);
printf("Square = %d\n",SQUARE(a));
printf("Cube = %d\n",CUBE(a));
return 0;
}
*/

//file inclusion

/*

#include<stdio.h>
#include "header.h"
int main()
{
    display();
    return 0;
}

*/

/*

#include<stdio.h>
#include "header.h"

int main()
{
    display();
    return 0;
}

*/

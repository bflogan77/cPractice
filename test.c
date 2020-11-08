#include <stdio.h>
#include <stdlib.h>

int main()
{
    enum day {
        saturday,
        sunday,
        monday,
        tuesday,
        weds,
        thurs,
        fri
    } workday;

    int a = 0;
    enum day weekend;

    weekend = (enum day)a;

    printf("weekend:%d", weekend);
    end: printf("this program executed the code at \'end\'");
    return 0;
}
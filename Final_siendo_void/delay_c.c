#include <stdlib.h>
#include <time.h>

void delay(int time){
    // Converting time into milli_seconds
    int milli_seconds = 1000 * time;

    // Stroing start time
    clock_t start_time = clock();

    // looping till required time is not acheived
    while (clock() < start_time + milli_seconds);
}

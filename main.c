#include <stdio.h>
#include <stdbool.h>
/**
 * @author: Tanvir Singh
 * @version: April 4, 2021
 * @description: C program to calculate the date of Easter.
 */
int main() {
    int G;  //Golden Number (19-year Metonic cycle)
    int Y = 2021;  //Year

    int C;  //Century Number
    int X;  //Number of years in which leap year was dropped

    int Z;  //Special correction designed to synchronize easter with the moon's orbit

    int D;  //Sunday
    int E;  //epact "E"

    int N;  //Day
    int M;  //Month
    /*
     * First computing the golden number
     */
    G = (Y % 19) + 1;

    /*
     * When Y is not multiple of 100, C is the century number
     */
    C = (Y / 100) + 1;

    /*
     * X and Z are the corrections
     * X is the number of years, such as 1900, in which leap year was dropped in order to keep in step with sum.
     */
    X = ((3*C) / 4) - 12;

    /*
     * Z is special correction designed to synchronize Easter with the moon's orbit.
     */
    Z = (((8*C) + 5) / 25) - 5;

    /*
     * Fins Sunday
     */
    D = ((5 * Y) / 4) - X - 10;

    /*
     * Find the "epact" E
     */
    E = ((11 * G) + 20 + Z - X) % 30;

    bool full_moon_flag = false;

    /*
     * If E = 25 an golder number G is greater than 11, or if E = 24, then increase E by one.
     * "epact" specifies when a full moon occurs
     */
    if( ((E == 25) && (G > 11)) || (E == 24)){
        E += 1;
        full_moon_flag = true;
    }

    /*
     * Find full moon
     */
    N = 44 - E;

    /*
     * If N is less than 21 then add 30 to N
     * (Easter is supposedly the "first Sunday following the first full moon which occurs on or after March 21."
     * Perturbations in the moon's orbit do not make this strictly true, but we are here concerned with the "calendar moon" rather than the actual moon.
     * Ths Nth of March is a calendar full moon.
     */
    if(N < 21){
        N += 30;
    }

    /*
     * Advance to Sunday
     */
    N = N + 7 - ((D + N) % 7);

    /*
     * Get month
     * If N is greater than 31, the month M is 4 and day N is (N - 31)
     * otherwise the month M is 3 and the day is N.
     */
    if(N > 31){
        M = 4;
        N = (N - 31);
    }else{
        M = 3;
        N = N;
    }

    printf("Day %d\n", N);
    printf("Month: %d\n", M);
    printf("Year: %d\n", Y);

    return 0;
}

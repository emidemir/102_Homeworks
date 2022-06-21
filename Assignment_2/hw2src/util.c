#include <stdio.h>
#include "util.h"
#include <math.h>

/* Example decision tree - see the HW2 description 
int dt0(int t, double p, double h, int s, int w) {
    int r = 0;
    if (t>35 && w!=3) r = 1;
    else if (t<=35 && s==0) r = 1;
    return r;
}*/

char dt1a(double PL, double PW)
{
    char result;

    if (PL > 2.45)
    {
        if (PW <= 1.75)
        {
            if (PL < 4.95)
            {
                if (PW < 1.65)
                result = 'y';
                else
                result = 'v';
            }
            else 
            result = 'v';
        }
        else
        result = 'v';
    }
    else
    result = 's';

    return (result);    
}

char dt1b(double PL, double PW)
{
    char result;
    if (PL > 2.55)
    {
        if (PW > 1.69)
        {
            if (PL > 4.85)
            result = 'v';
            else
            result = 'y';
        }
        else 
        result = 'v';
    }
    else
    result = 's';

    return (result);
}

double dt2a(double x1, double x2, double x3, int a, int b)
{
    double result;
    if (x1 < 31.5)
    {
        if (x2 > -2.5)
        result = 5.0;

        else
        {
            if (x1 >= x2 -0.1 && x1 <= x2 + 0.1)
            result = 2.1;

            else
            result = -1.1;
        }

    }

    else
    {
        if (x3 >= -1 && x3 <= 2)
        result = 1.4;

        else 
        {
            if (a == 1 && b == 1)
            result = -2.23;

            else
            result = 11;

        }
    }

    return (result);
}

double dt2b(double x1, double x2, double x3, int a, int b)
{
    double result;

    if (x1 > 12 && x1 < 22)
    {
        if (x3 > (5/3))
        result = -2.0;

        else
        {
            if (x3 >= x1-0.1 && x3 <= x1 + 0.1)
            result = 1.01;

            else
            result = -8;
        }

    }

    else
    {
        if (a == 1 && b == 1)
        result = -1;

        else
        {
            if (x2 >= -1 && x2 <= 2)
            result = -(1/7);

            else
            result = (sqrt(2.0) / 3);
        }
    }
    return (result);
}

char dt3a(double boy, double kilo, int mizah, int karakter, int hava)
{
    char result;

    if (boy >1.80)
    result = 'a';

    else if (boy > 1.70 && boy < 1.80)
    {
        if (kilo < 85)
        {
            if (mizah == 0)
            result = 'c';

            else
            {
                if (karakter == 1)
                result = 'c';

                else if (karakter == 2)
                result = 'd';

                else if (karakter == 4)
                result = 'e';

                else if (karakter == 3)
                {
                    if (hava  == 1)
                    result = 'f';

                    else if (hava == 2)
                    result = 'g';

                    else 
                    result = 'd';
                }

                else if (karakter == 5)
                {
                    if (hava == 1)
                    result = 'c';

                    else if (hava == 3)
                    result = 'l';

                    else
                    result = 'k';
                }

            }

        }

        else
        result = 'b';

    }

    else 
    {
        if (kilo <70)
        {
            if (karakter == 1)
            {
                if (hava == 1)
                result = 'f';

                else if(hava == 2)
                result = 'c';

                result = 'k';
            }

            else if (karakter == 2)
            result = 'd';

            else if (karakter == 3)
            result = 'k';

            else if (karakter == 4)
            {
                if (hava == 2)
                result = 's';

                else if (hava == 3)
                result = 'e';

                else
                result = 'b';
            }

            else if (karakter == 5)
            result = 'l';
        }
        else
        result = 'b';
    }
    return (result);
}

char dt3b(double boy, double kilo, int mizah, int karakter, int hava)
{
    char result;
    if (hava == 2) // SUNNY
    {
        if (karakter == 1)
        {
            if (boy > 1.80)
            {
                if (kilo > 90)
                    result = 'b';
                else
                {
                    if (mizah == 0) //
                    result = 'l';
                    else
                    result = 'c';
                }

            }

            else
            {
                if (kilo > 75)
                result = 'b';

                else
                {
                    if (mizah == 0) //pes
                    result = 's';
                    else
                    result = 'g';
                }
                
                

            }

        }
        else if (karakter == 2)
        result = 'k';

        else if (karakter == 4)
        {
            if (boy < 1.80)
            {
                if (kilo < 75)
                {
                    if (mizah == 0)
                    result = 's';
                    
                    else
                    result = 'd';

                }
                else
                result =  'b';
            }

            else
            {
                if (kilo > 90)
                result = 'b';
                else
                result = 'a';
            }
        }

        else
        result = 'c';


    }

    else if (hava == 1) //SNOW
    {
        if (mizah == 0)
        result = 'l';
        else
        result = 'd';

    }
    
    else if (hava == 3) // CLOUDY
    result = 'e';

    else if (hava == 4) //WINDY
    result = 'e';

    else if (hava == 5) // RAINY
    result = 'e';

    return (result);
}
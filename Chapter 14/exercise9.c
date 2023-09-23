/* exercise9.c -- Chapter 14 */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>         /* for exit() */
#include "exercise9_head.h"

int main(void)
{
    struct seat aircraft[FLIGHTS][SEATS] = {
        {   /* 1 */
            { 1,    true, false,    {"Ivan",    "Ivanov"}       }, 
            { 2,    true, false,    {"Oleg",    "Olegov"}       }, 
            { 3,    false, false,   {"Sidor",   "Sidorov"}      }, 
            { 4,    true, true,     {"Maria",   "Lazarina"}     }, 
            { 5,    false, false,   {"Prokofy", "Prokofiev"}    }, 
            { 6,    true, true,     {"Trand",   "Trandov"}      }, 
            { 7,    false, false,   {"Chris",   "Christov"}     }, 
            { 8,    true, true,     {"Tuvat",   "Tuvatin"}      }, 
            { 9,    false, false,   {"Orel",    "Orlov"}        }, 
            { 10,   true, true,     {"Bell",    "Belov"}        }, 
            { 11,   true, true,     {"Red",     "Redkov"}       }, 
            { 12,   false, false,   {"Sav",     "Savostyanov"}  },  
        }, 
        {   /* 2 */
            { 1,    true, true,     {"Ivan",    "Ivanov"}       }, 
            { 2,    true, false,    {"Oleg",    "Olegov"}       }, 
            { 3,    false, false,   {"Sidor",   "Sidorov"}      }, 
            { 4,    true, true,     {"Maria",   "Lazarina"}     }, 
            { 5,    false, false,   {"Prokofy", "Prokofiev"}    }, 
            { 6,    true, true,     {"Trand",   "Trandov"}      }, 
            { 7,    false, false,   {"Chris",   "Christov"}     }, 
            { 8,    true, true,     {"Tuvat",   "Tuvatin"}      }, 
            { 9,    false, false,   {"Orel",    "Orlov"}        }, 
            { 10,   true, false,    {"Bell",    "Belov"}        }, 
            { 11,   true, true,     {"Red",     "Redkov"}       }, 
            { 12,   false, false,   {"Sav",     "Savostyanov"}  },  
        },
        {   /* 3 */
            { 1,    true, false,    {"Ivan",    "Ivanov"}       }, 
            { 2,    true, true,     {"Oleg",    "Olegov"}       }, 
            { 3,    false, false,   {"Sidor",   "Sidorov"}      }, 
            { 4,    true, true,     {"Maria",   "Lazarina"}     }, 
            { 5,    false, false,   {"Prokofy", "Prokofiev"}    }, 
            { 6,    true, true,     {"Trand",   "Trandov"}      }, 
            { 7,    false, false,   {"Chris",   "Christov"}     }, 
            { 8,    true, true,     {"Tuvat",   "Tuvatin"}      }, 
            { 9,    false, false,   {"Orel",    "Orlov"}        }, 
            { 10,   true, true,     {"Bell",    "Belov"}        }, 
            { 11,   true, false,    {"Red",     "Redkov"}       }, 
            { 12,   false, false,   {"Sav",     "Savostyanov"}  },  
        }, 
        {   /* 4 */
            { 1,    true, true,     {"Ivan",    "Ivanov"}       }, 
            { 2,    true, false,    {"Oleg",    "Olegov"}       }, 
            { 3,    false, false,   {"Sidor",   "Sidorov"}      }, 
            { 4,    true, true,     {"Maria",   "Lazarina"}     }, 
            { 5,    false, false,   {"Prokofy", "Prokofiev"}    }, 
            { 6,    true, true,     {"Trand",   "Trandov"}      }, 
            { 7,    false, false,   {"Chris",   "Christov"}     }, 
            { 8,    true, true,     {"Tuvat",   "Tuvatin"}      }, 
            { 9,    false, false,   {"Orel",    "Orlov"}        }, 
            { 10,   true, true,     {"Bell",    "Belov"}        }, 
            { 11,   true, false,    {"Red",     "Redkov"}       }, 
            { 12,   false, false,   {"Sav",     "Savostyanov"}  },  
        }
    };
    int flights[FLIGHTS] = {102, 311, 444, 519};
    int choice1;
    char choice2;
    FILE * fp;
    int i;
    struct seat * p_air;

    if ((fp = fopen("aircraft2.dat", "r+b")) == NULL)           /* correct mode (good)! */
    {
        fputs("There is no \"aircraft.dat\" file in this directory.\n", stderr);
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < FLIGHTS; i++)
    {
        printf("Flight number: %d\n", flights[i]);  /* head of the table */
        output_from_file(aircraft[i], SEATS, fp);   /* or 1 operator with (FLIGHTS * SEATS) ??? */
        putchar('\n');
    }

    while ((choice1 = showmenu1()) != 0)
    {
        switch (choice1)
        {
            case 102: p_air = aircraft[0];
                break;
            case 311: p_air = aircraft[1];
                break;
            case 444: p_air = aircraft[2];
                break;
            case 519: p_air = aircraft[3];
                break;
            default : puts("Error 1");
        }
        
        printf("Flight number: %d\n", choice1);
        while ((choice2 = showmenu2()) != 'g')
        {
            switch (choice2)
            {
                case 'a' : show_free_num(p_air, SEATS);
                    break;
                case 'b' : show_free_list(p_air, SEATS);
                    break;
                case 'c' : show_book_alph(p_air, SEATS);
                    break;
                case 'd' : book_seat(p_air, SEATS);
                    break;
                case 'e' : confirm_book(p_air, SEATS);
                    break;
                case 'f' : cancel_book(p_air, SEATS);
                    break;
                default : puts("Error 2");
            }
        }
    }
    
    rewind(fp);
    for (i = 0; i < FLIGHTS; i++)
    {
        printf("Flight number: %d\n", flights[i]);  /* head of the table */
        output_to_file(aircraft[i], SEATS, fp);
        putchar('\n');
    }
    fclose(fp);
    puts("The program has been completed.");
    
    return 0;
}

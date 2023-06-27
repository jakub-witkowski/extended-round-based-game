#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

#define MAP_SIZE_X 32
#define MAP_SIZE_Y 32

typedef struct {
    char affiliation[2];
    char unit_type[2];
    int unit_id;
    int x_coord;
    int y_coord;
    int current_stamina;
    int remaining_movement;
    int attack_count;
    char is_base_busy[2];
} au;

void load_status(char fname[], int* u, long* g, au a[])
{
    /* variables used to store data read from status.txt */
    const int length = 24;
    char input[length];
    int letters = 0;
    int digits = 0;
    int spaces = 0;
    long gold = 0;

    FILE * fptr;

    fptr = fopen(fname, "r");

    /* store individual lines of status.txt as strings and scan them based on their format */
    while (fgets(input, length, fptr) != NULL)
    {
        for (int i = 0; input[i] != '\n'; i++)
        {
            if (isupper(input[i]))
            {
                letters++;
            }
            if (isblank(input[i]))
            {
                spaces++;
            }       
            if (isdigit(input[i]))
            {
                digits++;
            }
        }

        if (letters == 0 && digits >= 1 && spaces == 0)
        {
            sscanf(input, "%ld", &gold);
            *g = gold;

            letters = 0;
            digits = 0;
            spaces = 0;
        }

        if (letters >= 2 && spaces == 6)
        {
            sscanf(input, "%s %s %d %d %d %d %s", a[*u].affiliation, a[*u].unit_type, &a[*u].unit_id, &a[*u].x_coord, &a[*u].y_coord, &a[*u].current_stamina, a[*u].is_base_busy);
            (*u)++;
        
            letters = 0;
            spaces = 0;
        }

        if (letters == 2 && spaces == 5)
        {
            sscanf(input, "%s %s %d %d %d %d", a[*u].affiliation, a[*u].unit_type, &a[*u].unit_id, &a[*u].x_coord, &a[*u].y_coord, &a[*u].current_stamina);
            (*u)++;

            letters = 0;
            spaces = 0;
        }

        letters = 0;
        digits = 0;
        spaces = 0;
    }

    fclose(fptr);

    /* movement points counter set */
    for (int i = 0; i < *u; i++)
    {
        if (strcmp(a[i].unit_type, "K") == 0)
            a[i].remaining_movement = 5;
        else if (strcmp(a[i].unit_type, "B") == 0) // bases cannot move
            a[i].remaining_movement = 0;
        else
            a[i].remaining_movement = 2;
    }

    /* attack counter set to 1 */
    for (int i = 0; i < *u; i++)
    {
        if (strcmp(a[i].unit_type, "B") == 0) // bases cannot attack
            a[i].attack_count = 0;
        else
            a[i].attack_count = 1;
    }

}
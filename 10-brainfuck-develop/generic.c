/* This is a translation of generic.bf, generated by bftoc.py (by Paul Kaefer)
 * It was generated on Thursday, January 05, 2023 at 10:58PM
 */

#include <stdio.h>

void main(void)
{
    int size = 1000;
    int tape[size];
    int i = 0;

    /* Clearing the tape (array) */
    for (i=0; i<size; i++)
        tape[i] = 0;

    int ptr = 0;

    tape[ptr] += 8;
    while (tape[ptr] != 0)
    {
        ptr += 1;
        tape[ptr] += 1;
        ptr += 1;
        tape[ptr] += 4;
        ptr -= 2;
        tape[ptr] -= 1;
    }
    ptr += 1;
    tape[ptr] += 2;
    ptr += 2;
    tape[ptr] += 1;
    ptr -= 1;
    while (tape[ptr] != 0)
    {
        tape[ptr] -= 1;
        while (tape[ptr] != 0)
        {
            ptr += 2;
            tape[ptr] += 1;
            ptr -= 2;
            tape[ptr] -= 1;
        }
        tape[ptr] += 1;
        ptr += 2;
    }
    ptr += 1;
    tape[ptr] += 1;
    while (tape[ptr] != 0)
    {
        tape[ptr] -= 1;
        ptr -= 3;
        while (tape[ptr] != 0)
        {
            tape[ptr] -= 1;
            ptr += 1;
            while (tape[ptr] != 0)
            {
                tape[ptr] += 1;
                while (tape[ptr] != 0)
                {
                    tape[ptr] -= 1;
                }
                tape[ptr] += 1;
                ptr += 1;
                tape[ptr] += 2;
                ptr += 3;
                tape[ptr] -= 1;
                ptr -= 2;
            }
            ptr -= 1;
            while (tape[ptr] != 0)
            {
                ptr -= 1;
            }
            ptr += 2;
            tape[ptr] += 6;
            while (tape[ptr] != 0)
            {
                ptr -= 2;
                tape[ptr] += 5;
                ptr += 2;
                tape[ptr] -= 1;
            }
            tape[ptr] += 1;
            ptr -= 2;
            tape[ptr] += 2;
            printf("%c",tape[ptr]);
            while (tape[ptr] != 0)
            {
                tape[ptr] -= 1;
            }
            ptr -= 2;
        }
        ptr += 1;
        printf("%c",tape[ptr]);
        ptr += 1;
        tape[ptr] += 1;
        while (tape[ptr] != 0)
        {
            ptr += 2;
        }
        ptr += 1;
        tape[ptr] += 1;
    }

}


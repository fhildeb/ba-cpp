//Einbeziehen von Headerdateien
#include <stdio.h>
#include <stdlib.h>

int main(){
int x = 1;
int y = 1;
int q;
q = (y >= 0) ? ((x >= 0) ? 1:2) : ((x >= 0) ? 4 : 3);

printf("q: %d", q);
}
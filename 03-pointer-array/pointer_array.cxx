#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <getopt.h>
#include <string.h>

using namespace std;

int main ()
{
	 
	// Aufgabe 1
	int i = 5;
	int* p = &i;
	int** pp = &p;
	int*& pr = p;
	int**& ppr = pp;	
	
	// Aufgabe 2
	int** z = NULL;
	
	cout << z; 				
	cout << &z; 				
	cout << *z;				
	cout << *(*z);			
	cout << (*(&(*(&z))));
	cout << (&(*(&(*z))));
	cout << (*(*(&(*z))));
	
	cout << "\n Aufgabe 3" <<endl;	

	// Aufgabe 3 + 4
	int arry[2] = {0,1};
	int* arryp = &arry[1];
	int** arrypp = &arryp;
	
	cout << **arrypp <<endl;	
	cout << (**(((&arry))+sizeof(arry[1]))) <<endl;
	
	for(int i = 0; i < (sizeof(arry)/sizeof(arry[0])); i++){
	cout << arry[i] <<endl;	
	}
	
	cout << "\n Aufgabe 5" <<endl;
	
	// Aufgabe 5
	int arry2 [3][4][2] ={
									{
										{4,0},
										{5,5},
										{1,5},
										{2,0}							
									},
									{
										{5,3},
										{9,2},
										{7,5},
										{4,1},						
									},
									{
										{6,3},
										{4,0},
										{1,6},
										{6,8},						
									}
								};
								
	int* p_arry2 = &arry2[0][0][0];
	p_arry2 = p_arry2 + 13;
								
	cout << arry2[1][2][0]	<< endl;
	cout << *p_arry2 << endl;
}

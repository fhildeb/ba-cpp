#include <iostream>
#include "tools.h"
#include <fstream>

using namespace std;

int main ()
{
  cout << myFunction(4, 5) << endl;
	
	// Umleiten von COUT
	std::ofstream ofs ("test.txt", std::ofstream::out);
   ofs << "text";
   ofs.close();

// Aufgabe 1
int i = 5;				              // Wert
int* p = &i;			              // Zeiger auf Adresse des Wertes
int** pp = &p;			            // Zeigers der auf Zeiger auf Adresse des Wertes
int*& pr = p;			              // Referenz auf Zeiger auf Adresse des Wertes
int**& ppr = pp;		            // Referenz auf Zeiger auf Zeiger auf Adresse des Wertes
  
cout << i << endl;	            // 5
cout << p << endl;	            // Addresse 0x1111...
cout << pp << endl;	            // Addresse 0x2222...
cout << pr << endl;	            // Addresse 0x1111... Gleich wie p
cout << ppr << endl;	          // Addresse 0x2222... Gleich wie pp

// Aufgabe 2
int j= 8;							          // Wert
int* o = &j;						        // Zeiger auf Adresse
int** z = &o;						        // Zeiger auf Zeiger auf Adresse des Wertes

cout << "werte" << endl;
cout << j << endl;				      // 8
cout << o << endl;				      // Adresse 0x3333...
cout << "los" << endl;
cout << z << endl; 				      // Adresse 0x4444...
cout << &z << endl; 				    // Adresse 0x5555...
cout << *z << endl;				      // Adresse 0x3333... 	(Adresse vom Zeiger auf Wert)
cout << *(*z) << endl;			    // 8 						      (Dereferenzierter Wert)
cout << (*(&(*(&z)))) <<endl;	  // Adresse 0x4444...	kürzt sich weg
cout << (&(*(&(*z)))) <<endl;	  // Adresse 0x4444...	kürzt sich weg
cout << (*(*(&(*z)))) << endl;  // 8						      (Dereferenzierter Wert)
															  // --> **z
  
  return 0; // alles ok
  
}

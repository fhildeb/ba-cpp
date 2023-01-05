//Einbeziehen von Headerdateien
#include <iostream>


using namespace std;

int main(){
int d[4][4] = {{11,12,13,14},
               {21,22,23,24},
               {31,32,33,34},
               {41,42,43,44}};
               
	for(int y = 0; y < 4; y++) {
			for(int x = (y==0) ? 1 : 0; x < 4; x=x + (x != (y-1) ? 1 : 2))  
  
    		cout << d[y][x] << " ";
  			cout << endl;
	} // for
return 0;
}
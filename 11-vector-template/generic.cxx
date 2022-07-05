#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

template<typename T>  T determine_max(T a, const T b)
{
  if(a > b) return a;

  return b;
} // max


//Aufgabe 2
template<typename T> void sort(T* arr, const int n)
{
	for(int i=0; i < n; i++)
	{
		for(int j=i+1; j < n; j++)
		{
			if(arr[j+1] > arr[j])
			{
				T temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}					
		}	
	}	  
} //sort

template <typename T, int dimension> class Vector
{
protected:
  T comp[dimension];

public: 
  Vector() {
  	for(int j=0; j < dimension; j++){
      comp[j] = 0;
   }
  };

  Vector operator+ (Vector& rV) {
    Vector* p_v = new Vector<T, dimension>;
	for(int h = 0; h < dimension; h++){
    p_v->comp[h] = comp[h] + rV.comp[h];
	}
    return *p_v;
  };

  T& operator[] (int i) {return comp[i];};

  operator float() {
    float sum = 0;
	for(int k = 0; k < dimension; k++)    
    sum += comp[k]*comp[k];
    return sqrt(sum);    
  };
  
  void print() {
  	for(int g = 0; g < dimension; g++){
    cout << comp[g] << " "<< endl;
 }
  };
};

int main (int argc, char **argv, char **envp)
{
  
  Vector<int, 4> vec_a;
  vec_a[0] = 1;
  vec_a[1] = 2;
  vec_a[2] = 3;
  vec_a[3] = 4;

  Vector<int, 4> vec_b;
  vec_b[0] = 2;
  vec_b[1] = 3;
  vec_b[2] = 4;
  vec_b[3] = 5;

  Vector<int, 4> vec_c;

  vec_c = vec_a+vec_b;
  
  cout << "Vektor C:" << endl;
  vec_c.print();
  cout << "\n" << endl;
  
  cout << "Vektoren Float (a-b-c):" << endl;
  cout << (float)vec_a << endl;
  cout << (float)vec_b << endl;
  cout << (float)vec_c << endl;  
  
  Vector<int, 4> vec_array[3];
  vec_array[0] = vec_a;
  vec_array[1] = vec_b;
  vec_array[2] = vec_c;

	sort(vec_array, 2); 
  
  cout << "\nAufgabe 2:" << endl;
  for(int r = 0; r < 3; r++){
    vec_array[r].print();
    cout << "\n" << endl;
  }

  return 0; // alles ok
}

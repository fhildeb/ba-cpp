#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>

using namespace std;

class Fibonacci
{
private:
  long start;
  long cache_n;
  long cache_result;

public:
  Fibonacci() {start = 1; cache_n = -1;};
  
  long calc(long i) {

    if(i < 3) return start;

    if(i == cache_n) return cache_result;
    
    long result = calc(i-1)+calc(i-2);

    if((cache_n < 0) || (cache_n < i)) {
      cache_n = i;
      cache_result = result;
    } // if
    
    return result;
  };
};

int main (int argc, char **argv, char **envp)
{
  Fibonacci my_fibo;
  
  for(int i = 1; i < 10; i++)
    cout << my_fibo.calc(i) << endl;

  return 0; // alles ok
}

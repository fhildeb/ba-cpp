#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

class Fahrzeug
{
public:
  Fahrzeug() {};
  virtual void advance(){cout << "Fahrzeug bewegt sich" << endl;};
};

class Auto : public Fahrzeug
{
public:
  Auto() {};

 void advance() override {cout << "brumm, brumm" << endl;};
};

int main (int argc, char **argv, char **envp)
{
  Auto     my_auto;
  Fahrzeug my_fahrzeug = my_auto;
  my_auto.advance();
  my_fahrzeug.advance();
  
 if (dynamic_cast<Fahrzeug*>(&my_auto)) {
      cout << "Auto ist Fahrzeug" << endl;
   }  
  
  return 0; // alles ok
}

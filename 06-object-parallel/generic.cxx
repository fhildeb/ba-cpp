#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <pthread.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

using namespace std;

class MyClass {

protected:
  int       interations;
  bool      finished;

public:
  MyClass(int n) : interations(n) {finished = false;};

  void Process();
  void WaitFinished();
  static void* Run(void* pointer);
  
}; // class MyClass

void* MyClass::Run(void* pointer)
{
  ((MyClass*)pointer)->Process();
};
  
void MyClass::Process()
{
  for(int i = 0; i < interations; i++) {

    // wait 0 sec and up to 5 x 100.000.000 ns
    // (note: 1.000.000.000 = 1 sec)

    timespec wait_time{0, 100000000 * (rand() % 5)};

    nanosleep(&wait_time, NULL);

    cout << "." << flush;

  } // for

  finished = true;
} // MyClass::Process


void MyClass::WaitFinished()
{
  while(finished == false) {
  } // while
} // MyClass::WaitFinished

int main (int argc, char **argv, char **envp)
{
  MyClass meineKlasse(15);

  pthread_t processThread;
  pthread_create(&processThread, NULL, MyClass::Run, (void*)&meineKlasse);
  
  meineKlasse.WaitFinished();
  pthread_join(processThread, NULL);

  cout << "fertig" << endl;

  return 0; // alles ok
}

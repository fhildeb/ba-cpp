#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <memory>

using namespace std;

class myTest
{
	public:
		weak_ptr<myTest> p_obj;	
	
protected:
  int no;
  
public:
  myTest(int n) {no = n; cout << "Object Nr. " << no << " wurde erzeugt" << endl;};
  ~myTest() {cout << "Objekt Nr. " << no << " wurde gelöscht" << endl;};

  void WhoAreYou() {cout << "Ich bin Objekt Nr. " << no << endl;};
}; // class myTest

using namespace std;

int main (int argc, char **argv, char **envp)
{
  cout << "Hello world!" << endl;
  myTest(5);

	shared_ptr<myTest> p_obj_1(new myTest(1));
	shared_ptr<myTest> p_obj_2(new myTest(2));
	
	p_obj_1->p_obj = p_obj_2;
	p_obj_2->p_obj = p_obj_1;  
	// Viel Output:	
	// shared_ptr<shared_ptr<myTest> >pp_obj(&p_obj);
	
	// Hello world!
	// Object Nr. 5 wurde erzeugt
	// Object Nr. 5 wurde gelöscht
	// Object Nr. 1 wurde erzeugt
	// Object Nr. 2 wurde erzeugt
	// Object Nr. 2 wurde gelöscht
	// Object Nr. 1 wurde gelöscht
	
  return 0; // alles ok
}

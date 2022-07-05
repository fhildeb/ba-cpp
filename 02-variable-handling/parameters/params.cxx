#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <getopt.h>
#include <string.h>

using namespace std;

void printHelptext()
{
  cout << "usage: ucopbit [options] filename" << endl << endl;
  cout << "-h     : this text" << endl;
  cout << "-r     : recursive mode" << endl;
  cout << "-b     : binary mode" << endl;
  cout << "-p PWD : password mode with PWD as password" << endl;
}

int main (int argc, char **argv, char **envp)
{
  bool recursive_mode = false;
  bool binary_mode = false;
  bool password_mode = false;

  char password[80];
	char c;
	while ((c = getopt (argc, argv, "hp:rb")) > 0){

  switch(c){
  {
		case 'h':
			printHelptext();
			break;
		case 'r':
			recursive_mode = true;
			break;
		case 'b':
			binary_mode = true;
			break;
		case 'p':
			password_mode = true;
			strcpy(password,optarg);
			break;  
		default:
		cerr << "Dieser Fall wurde nicht berücksichtigt" << endl;
		return 1;
  }
  }
  }

  cout << endl << "ucopbit - useless comandline options-parsing but ignoring tool" << endl << endl;

  if(binary_mode)
    cout << "binary mode is on" << endl;

  if(recursive_mode)
    cout << "recursive mode is on" << endl;

  if(password_mode)
    cout << "using password-mode with password: " << password << endl;


  return 0;
}

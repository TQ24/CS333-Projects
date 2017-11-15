/* Project 6
 * Part 2: File I/O and String in C++
 * Task1-2: Read files.
 * Tracy Quan
 *
 * Write and read files
 */

#include <iostream>
#include <fstream>  // the class declarations for file stream objects
#include <stdlib.h>
#include <string.h>
#include <conio.h>

using namespace std;

main(){
  ofstream file;         // create a file var
  file.open("file.txt");      // open a file
  file<<"Hello file\n"<< 24 << "Project 6";   // write to it
  file.close();               // close it

  char a[10];
  char b[10];
  char c[10];
  int x;
  ifstream file2;
  file2.open("file.txt");
  file2>>a>>b>>x>>c;
  cout<<a<<" "<<b<<" "<<x<<" "<<c;

  // ----------------------------
  // read file
  ifstream ifile;
  char s[100], fname[20];
  cout<<"\nEnter file name to read and display: ";
  cin>>fname;
  ifile.open(fname);
  if(!ifile){
    cout<<"Error in opening file.";
    getch();
    exit(0);
  }
  while (ifile.eof()==0){
    ifile>>s;
    cout<<s<<" ";
  }
  cout<<"\n";
  ifile.close();
  getch();

}

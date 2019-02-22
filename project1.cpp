//
//  main.cpp
//  Hello World
//
//  Created by Matt Garcia on 2/7/19.
//  Copyright © 2019 Matt Garcia. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string.h>
#include <iomanip>
using namespace std;


struct PERSON{
    char name[20];
    float balance;
};





 int getSize()
{
 string fname;
int N=0;
ifstream inData;
inData.open("data.txt");

 while (getline(inData,fname))
{
    N++; // counter
}

inData.close();
return N;
}

PERSON &fillArray(PERSON P[], int N){

  string fname;
  string lname;
  string fullname;

  int i = 0;

  ifstream inData;
  inData.open("data.txt");

  while (!inData.eof())
  {
    inData >> fname >> lname;
    inData >> P[i].balance;
    fullname = fname + " " + lname;
    strcpy(P[i].name, fullname.c_str());
    i++;
  }
  inData.close();
  return P[N];


}

void findRichest(PERSON P[], int N){
  PERSON temp[N];
  int person = 0;
  float max;
  int name = 0;
  for (int i=0; i < N; i++)
  {
    temp[i].balance= P[i].balance;
  }
  max= temp[0].balance;
  for (int j = 0; j < N; j++)
  {
    if (max < temp[j].balance)
    {
      max = temp[j].balance;
      name = j;
    }
  }


  cout << "The customer with maximum balance is " << P[name].name << endl;
}

void deposit( string custName, PERSON P[], int N){
  int money;
  cout << "Enter your full name to deposit money: ";
  getline(cin, custName);
  for (int i=0; i < N; i++)
  {
  if (custName== P[i].name){
  cout << custName << ", how much would you like to deposit? ";
  cin >> money;
  P[i].balance=P[i].balance +money;
  cout << "Now your new balance is " << P[i].balance << endl;
}
}

}

void Display(PERSON P[], int N){
cout << "Name:                Balance: \n";
cout << "------------------------------ \n";

for (int i=0; i<N; i++){
  cout << P[i].name << " " << fixed << setprecision(2) << P[i].balance << endl;
}


}

void NewCopy( string file, PERSON P[], int N){


  ofstream inData;
  inData.open(file);

  for(int i=0; i < N; i++)
  {
    inData << P[i].name << " " << fixed << setprecision(2) << P[i].balance << endl;

  }
  inData.close();

}





int main()
{

  string name;
   int N= getSize();
   PERSON P[N];
   fillArray(P, N);
   Display(P, N);
   findRichest(P, N);
   deposit(name, P, N);
   NewCopy("data.txt",P,N);

    return 0;
}

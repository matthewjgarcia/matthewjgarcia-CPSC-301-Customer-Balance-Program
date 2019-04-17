//
//  main.cpp
//  Hello World
//
//  Created by Matt Garcia on 2/7/19.
// Section 2
//  Copyright © 2019 Matt Garcia. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string.h>
#include <iomanip>
#include <cstring>
#include <stdio.h>

using namespace std;


struct PERSON{
    char name[20];
    float balance;
};


void printmenu() {
    cout << "Please enter a choice:" << endl;
    cout << "1. Display records"<< endl;
    cout << "2. Deposit funds"<< endl;
    cout << "3. Find Highest Balance" << endl;
    cout << "4. Update records" << endl;
    cout << "5. Exit the program" << endl;
}





 int getSize()
{
 string t;
 int N=0;
 ifstream inData;
 inData.open("data.txt");

 while (!inData.eof())
{
  getline(inData, t);
  N++; // counter
}
N--; // without this i couldnt get it to run right so tried this and it worked
inData.close();

return N;
}

PERSON * readData(int & N)
{
  N = getSize();
  ifstream inData;
  string firstName= "";
  string lastName= "";
  string t="";
  PERSON *P = nullptr;
  P = new PERSON[N];

  inData.open("data.txt");

  for (int i = 0; i < N; i++){
    inData >> firstName;
    inData >> lastName;
    inData >> P[i].balance;
    getline(inData, t);
    strncpy(P[i].name, firstName.c_str(), 9);
    strncat(P[i].name, " ", 1);
    strncat(P[i].name, lastName.c_str(), 10);
  }
  inData.close();
  return P;

}




void findRichest(PERSON P[], int N){

  int temp = 0; // used to compare to the balance of the employees
  int hPaid = 0; // initializes the highest paid will be used when setting up highest paid

  for (int i = 0; i < N; i++) // go through the file
  {
    if (P[i].balance > temp) // changes the richest
    {
      temp = P[i].balance;
      hPaid = i;
    }
  }
  cout << "Highest balance: " << P[hPaid].name << endl; // prints out who is the highest paid


}

void deposit(PERSON P[], int N, string custName, float amount){
  for (int i=0; i < N; i++) // goes through the code and searches for the name
  {
  if (custName== P[i].name){
  P[i].balance=P[i].balance +amount; // changes the balance to be the added amount
  cout << "Now your new balance is " << P[i].balance << endl; // output the final balance
}
}

}

void Display(int N, PERSON P[]){
cout << "Name:                Balance: \n"; // just have this for visuals
cout << "------------------------------ \n";
for (int i=0; i<N; i++){
  cout << P[i].name << " " << fixed << setprecision(2) << P[i].balance << endl; //output the name and balance
}


}

void NewCopy( string file, PERSON P[], int N){


  ofstream inData;
  inData.open(file);

  for(int i=0; i < N; i++)
  {
    inData << P[i].name << " " << fixed << setprecision(2) << P[i].balance << endl;
// this is to change the values in the file
  }
  inData.close();

}

void helpDeposit(int N, PERSON P[]){
  int count = 1;
  float amount = 0;
  string name = "";
  cout << "Enter Name: ";
  cin.ignore();
  getline(cin, name); // would not work without either of these
  for (int i = 0; i < N; i++){
    if (name == P[i].name){ // compares the name entered to the name in the file
      cout << "Deposit: ";
      cin >> amount; // asks the user to put in an amount to deposit
      deposit(P, N, name, amount); //calls the function to do the hard work
    }
    else
      count++;

  }
  if (count > N)
  cout << "Record not found" << endl;
}





int main()
{
  string name;
  int N =0;
  int choice;
  PERSON *P = nullptr;
  P = readData(N);
  string inData= "data.txt";
   do
   {
       printmenu();
       cout << "Enter a number" << endl;
       cin >> choice;
       switch(choice)
       {
           case 1:
               Display(N, P);
               break;

           case 2:
               helpDeposit(N,P);
               break;

           case 3:
               findRichest(P, N);
               break;

           case 4:
               NewCopy(inData,P, N);
               break;

           case 5:
               NewCopy(inData,P,N);
               break;

           default:
               cout << "Invalid entry" << endl;
               break;
       }
       cout << endl;
  } while(choice != 5);
    return 0;
}

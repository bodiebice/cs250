#include <iostream>
#include <iomanip>
#include <cmath>
#include "Loan.h"
using namespace std;

double gA();
double gR();
double gY();
void toTerminal(Loan);

int main()
{
  double a,r,y;
  a = gA();
  r = gR();
  y = gY();
  Loan mortgage(a,r,y);
  toTerminal(mortgage);
  

  return 0;
}

double gA()
{
  double a;
  cout<<"Enter the mortgage amount: ";
  cin>>a;
  while (cin.fail() == true)
    {
      cout<<"invalid value."<<endl;
      cin.clear();
      cin.ignore(std::numeric_limits<int>::max(),'\n');
      cin>>a;
    }
  return a;
}

double gR()
{
  double r;
  cout<<"Enter the mortgage rate: ";
  cin>>r;
  while (cin.fail() == true)
    {
      cout<<"invalid value."<<endl;
      cin.clear();
      cin.ignore(std::numeric_limits<int>::max(),'\n');
      cin>>r;
    }
  return r;
}

double gY()
{
  double y;
  cout<<"Enter the mortgage term length (in years): ";
  cin>>y;
  while (cin.fail() == true)
    {
      cout<<"invalid value."<<endl;
      cin.clear();
      cin.ignore(std::numeric_limits<int>::max(),'\n');
      cin>>y;
    }
  return y;
}

void toTerminal(Loan mortgage)
{
  double payment = mortgage.getPayment();
  double totalpaid = mortgage.getTotalPaid();

  cout<<"The monthly payment for this mortgage is $"<<payment<<" and the total you will pay for this mortgage is $"<<totalpaid<<endl;

  return;
}
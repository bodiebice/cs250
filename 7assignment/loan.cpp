#include <iostream>
#include <iomanip>
#include "Loan.h"
using namespace std;

Loan::Loan()
{
  amount = 0;
  rate = 0;
  years = 0;
}

Loan::Loan(double a, double r, double y)
{
  amount = a;
  rate = r;
  years = y;
}

void Loan::setAmount(double a)
{
  amount = a;
}

void Loan::setRate(double r)
{
  rate = r;
}

void Loan::setYears(double y)
{
  years = y;
}

double Loan::getAmount()const
{
  return amount;
}

double Loan::getRate()const
{
  return rate;
}

double Loan::getYears()const
{
  return years;
}

double Loan::getPayment()const
{
  double payment;
  int term;
  term = (1+rate/12)^(12*years);
  payment = (amount*(rate/12)*term) / term - 1;
  return payment;
}



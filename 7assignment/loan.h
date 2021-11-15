#ifndef LOAN_H
#define LOAN_H

class Loan
{
  private:
    double amount;
    double rate;
    double years;

  public:
    Loan();
    Loan(double a, double r, double y);

    void setAmount(double a);
    void setRate(double r);
    void setYears(double y);

    double getAmount()const;
    double getRate()const;
    double getYears()const;

    double getPayment()const;
    double getTotalPaid()const;

  
};
#endif
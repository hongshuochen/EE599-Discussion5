#include <iostream>
#include <string>

using namespace std;
class Rational 
{ 
public:
  int numerator; 
  int denominator;
  Rational(int numerator, int denominator);
  Rational(const Rational &secondRational);
  Rational& operator=(const Rational &secondRational);
  int compareTo(const Rational& secondRational) const;
  Rational add(const Rational& secondRational) const;
  Rational subtract(const Rational& secondRational) const;
  string toString() const;
  
  bool operator<(const Rational &secondRational) const;
  Rational operator+(const Rational &secondRational) const;
  Rational operator+(const int num) const;
  Rational& operator+=(const Rational &secondRational);
  Rational& operator++();
  Rational operator++(int dummy);

  Rational& operator--();
  Rational operator--(int dummy);
  Rational operator/(int s) const;
  bool operator==(const Rational &secondRational) const;
};

Rational::Rational(int numerator, int denominator)
{
  this->numerator = numerator;
  this->denominator = denominator;
}
Rational::Rational(const Rational &secondRational)
{
    numerator = secondRational.numerator;
    denominator = secondRational.denominator;
}
Rational& Rational::operator=(const Rational &secondRational)
{
    numerator = secondRational.numerator;
    denominator = secondRational.denominator;
    return *this;
}

Rational Rational::add(const Rational& secondRational) const
{
  int n = numerator * secondRational.denominator + denominator * secondRational.numerator;
  int d = denominator * secondRational.denominator;
  return Rational(n, d);
}

string Rational::toString() const
{
  string s;
  s = to_string(numerator) + "/" + to_string(denominator);
  return s;
}

Rational Rational::subtract(const Rational& secondRational) const
{
  int n = numerator * secondRational.denominator
    - denominator * secondRational.numerator;
  int d = denominator * secondRational.denominator;
  return Rational(n, d);
}

int Rational::compareTo(const Rational& secondRational) const
{
  Rational temp = subtract(secondRational);
  if (temp.numerator < 0)
    return -1;
  else if (temp.numerator == 0)
    return 0;
  else
    return 1;
}

bool Rational::operator<(const Rational &secondRational) const
{
  return compareTo(secondRational) < 0;
}

Rational Rational::operator+(const Rational &secondRational) const
{
  return add(secondRational);
}

Rational Rational::operator+(int s) const
{
  int n = numerator + s*denominator;
  return Rational(n, denominator);
}

Rational& Rational::operator+=(const Rational &secondRational)
{
  *this = add(secondRational); 
  return *this;
}
// Prefix increment
Rational& Rational::operator++()
{
  numerator += denominator;
  return *this;
}
// Postfix increment
Rational Rational::operator++(int dummy)
{
  Rational temp(numerator, denominator);
  numerator += denominator;
  return temp;
}

Rational& Rational::operator--()
{

}

Rational Rational::operator--(int dummy)
{

}

bool Rational::operator==(const Rational &secondRational) const
{

}

Rational Rational::operator/(int s) const
{

}
int main() {
  Rational r1(4, 2);
  Rational r2(2, 3);
  cout << "r1 < r2 is " << (r1.operator<(r2) ? "true" : "false");
  cout << "\nr1 < r2 is " << ((r1 < r2) ? "true" : "false");
  cout << "\nr2 < r1 is " << (r2.operator<(r1) ? "true" : "false");
  cout << endl;
}
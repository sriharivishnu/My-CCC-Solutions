//Solution by Srihari Vishnu
//CCC 2012 J1
#include <iostream>
using namespace std;

int main() {
  int l, s;
  scanf("%d%d", &l, &s);
  if (s <= l) printf("Congratulations, you are within the speed limit!");
  else if (s-l <= 20) printf("You are speeding and your fine is $100.");
  else if (s-l <= 30) printf("You are speeding and your fine is $270.");
  else printf("You are speeding and your fine is $500.");
  
}

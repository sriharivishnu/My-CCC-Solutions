//Solution by Srihari Vishnu
//CCC 2012 S2 : Aromatic Numbers
//Straightforward Implementation and Math

#include <iostream>
#include <string>
#include <unordered_map>
//3M1D2C
using namespace std;
int main() {
  string num;
  unordered_map<string, int> values ({{"I",1}, {"V",5}, {"X",10}, {"L",50}, {"C",100}, {"D",500}, {"M",1000}});
  int total = 0;
  cin >> num;
  
  for (int i = 0; i < num.length(); i+=2) {
    if ((i + 2 < num.length()) && values[string(1,num[i+1])] < values[string(1,num[i+3])]) {
      total -= stoi(string(1,num[i]))*values[string(1,num[i+1])];
    }
    else {
      total += stoi(string(1,num[i]))*values[string(1,num[i+1])];
    }
      
  }
  cout << total;
}

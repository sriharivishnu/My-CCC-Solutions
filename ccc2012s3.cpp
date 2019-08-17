//Solution by Srihari Vishnu
//CCC 2012 S3 : Absolutely Acidic
//Sort and then compare using tie breakers

//CASE 1: Two highest frequencies
//CASE 2: Multiple with highest frequency. 
//CASE 3: Multiple second highest frequency


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Reading {
  int value;
  int freq;

  bool operator > (const Reading& obj) const {
    if (freq == obj.freq) {
      return (value > obj.value);
    }
    return (freq > obj.freq);
  }
};

int main() {
  int n,x;
  int readings[1001];
  vector<Reading> frequencies;

  fill(readings, readings+1001, 0);

  cin >> n;
  for (int i =0; i < n; i++) {
    cin >> x;
    readings[x] += 1;
  }
  for (int t = 0; t < 1001; t++) {
    Reading temp = Reading();
    temp.freq = readings[t];
    temp.value = t;
    frequencies.push_back(temp);
  }
  sort(frequencies.begin(), frequencies.end(), greater<Reading>());

  //CASE 1
  if (frequencies[0].freq != frequencies[1].freq && frequencies[1].freq != frequencies[2].freq) {
    cout << abs(frequencies[0].value-frequencies[1].value);
  }
  //CASE 2
  else if (frequencies[0].freq == frequencies[1].freq) {
    int i = 1;
    while (frequencies[i].freq == frequencies[0].freq) {
      i++;
    }
    i -= 1;
    cout << abs(frequencies[0].value - frequencies[i].value);
  }
  //CASE 3
  else {
    int i = 2;
    while (frequencies[i].freq == frequencies[1].freq) {
      i++;
    }
    i -= 1;
    cout << max(abs(frequencies[0].value - frequencies[i].value), abs(frequencies[0].value - frequencies[1].value));
  }
}

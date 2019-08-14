#Solution by Srihari Vishnu
#CCC 2007 S3 : Friends
#Each node has at most one connection, simple search


#include <iostream>
#include <vector>

using namespace std;

int search(int arr[],int x, int y) {
  int i = x;
  int counter = 0;
  while (arr[i] != y && counter >= 0) {
    counter += 1;
    if (arr[i] == -1 || arr[i] == x) {
      counter = -1;
    }
    i = arr[i];
  }
  return counter;
}
int main() {
  int n, x, y;
  int graph[9999];
  fill(graph,graph+9999,-1);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    graph[x] = y;
  }
  cin >> x >> y;
  while (x != 0 && y != 0) {
    int a = search(graph,x,y);
    if (a == -1) {
      cout << "No" << endl;
    } else {
      cout << "Yes " << a << endl;
    }
    cin >> x >> y;
  }
  
}

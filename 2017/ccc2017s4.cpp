// CCC 2017 S4 : Minimum Cost Flow
// Solution by Srihari Vishnu
// This took a lot of work! 
// Use Kruskal's to calculate MST of graph
// Use the maximum weighted edge of the MST to recompute the MST, now considering the Enhancer
// Notice that the enhancer must zero one of the active edges not in the previous MST in order to 
// at most decrease the day cost by 1.
// Used disjoint set with path compression and weighted union to optimize Kruskal's

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;
struct Edge {
  int x,y;
  int w;
  bool original;
  Edge (int x, int y, int w, bool original) {
    this->x = x;
    this->y = y;
    this->w = w;
    this->original = original;
  }
};
bool operator<(const Edge a, const Edge b) {
  if (a.w!=b.w) {
    return a.w < b.w;
  }
  if (a.original && !b.original) {
    return true;
  } else {
    return false;
  }
}
void init(int arr[],int size[],int n) {
  for (int i =1; i<n+1; i++) {
    arr[i]=i;
    size[i]=1;
  }
}
int root(int arr[], int x) {
  int i = x;
  while (i != arr[i]) {
    arr[i] = arr[arr[i]];
    i = arr[i];
  }
  return i;
}
void performUnion(int arr[],int size[], int x, int y) {
  int root_x = root(arr,x);
  int root_y = root(arr,y);
  if (size[root_x]<size[root_y]) {
    arr[root_x] = root_y;
    size[root_y] += size[root_x];
  } else {
    arr[root_y] = root_x;
    size[root_x] += size[root_y];
  }
}
bool find(int arr[], int x, int y) {
  return root(arr,x) == root(arr,y);
}
int main() {
  int n,m,d;
  int x,y,w;
  int days = 0, c =0;
  vector <Edge> edges;
  scanf("%d%d%d",&n,&m,&d);
  for (int i = 0; i<m;i++) {
    scanf("%d%d%d",&x,&y,&w);
    if (i < n-1) {
      edges.push_back(Edge(x,y,w,true));
    } else {
      edges.push_back(Edge(x,y,w,false));
    }
  }
  sort(edges.begin(),edges.end());
  int connected[n+1];
  int size[n+1];
  init(connected,size,n);
  Edge maxEdge(-1,-1,-1,false);
  for (int i =0; i< edges.size(); i++) {
    if (c >= n-1) {
      break;
    }
    Edge t = edges[i];
    if (!find(connected,t.x,t.y)) {
      performUnion(connected,size,t.x,t.y);
      if (!t.original) {
        days++;
      }
      maxEdge = t;
      c++;
    }
  }
  init(connected,size,n);
  if (!maxEdge.original) {
    for (int e =0; e<edges.size(); e++) {
      Edge edge = edges[e];
      if (!find(connected,edge.x,edge.y)) {
        if (edge.w<maxEdge.w || ((edge.w == maxEdge.w) && edge.original)){
          performUnion(connected,size, edge.x, edge.y);
        }
        else if (edge.original && edge.w <= d) {
          days -=1;
          break;
        }
      }
    }
  }
  printf("%d",days);
}

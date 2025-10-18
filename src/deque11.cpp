#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void find(deque<int> q)
{
  deque<int>::iterator itr;
  itr = find(q.begin(), q.end(), 2);
  if(itr != q.end())
  {
    cout << "Found";
  }
  else
  {
    cout << "Not Found";
  }
}
int main() 
{
  deque<int> q;
  
  q.push_back(1);
  q.push_back(2);
  q.push_back(3);
  q.push_back(4);
  q.push_back(5);
  
  find(q);
  return 0;
}

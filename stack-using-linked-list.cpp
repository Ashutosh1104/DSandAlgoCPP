#include<iostream>
using namespace std;
#include "stack-using-linked-list.h"

int main(){
  Linkstack <int> newStack;
  for(unsigned long long int i=0;i<134217 ;i++){
    int r  = rand()%1000;
    newStack.push(r);
  }  
  while(!newStack.IsEmpty()){
    newStack.pop();
  }
}


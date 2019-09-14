#include<iostream>
#include<string.h>
using namespace std;
#include <ctime>
#include "stack-using-array.h"

int main(){
  ArrayStack <int> newStack;
  for(unsigned long long int i=0;i<134217728 ;i++){
    // In case of int the max size of array stack i can make is of lenght 134217728 using repeated doubling and realloc
    int r  = rand()%1000;
    newStack.push(r);
  }  
  while(!newStack.IsEmpty()){
    newStack.pop();
  }
}


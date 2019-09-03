#include <cstdlib>
#include <ctime>
#include <cstring>
#include <iostream>
#include <random>
using namespace std;

#include "weighted-quick-union.h"

int main()
{
  int start = time(nullptr);
  unsigned int N;
  unsigned long int total_els, iter = 0;
  float probability;
  N=1000;
  total_els = N * N;
  unsigned int *rand_hash = new unsigned int[total_els];

  // Added 2 because last 2 elements will be treated as virtual top and bottom respectively.
  WQuickUnionUF U1(total_els + 2);
  unsigned long int v_top = total_els;
  unsigned long int v_bottom = total_els + 1;

  memset(rand_hash, 0, total_els);
  const int min = 0;
  const int max = total_els;
  mt19937 generator(time(nullptr));//Mkae this seeding better than this 
  uniform_int_distribution<int> distribution(min,max);
  while (1)
  {
    unsigned long int r  = distribution(generator); 
    if (!rand_hash[r])
    {
      rand_hash[r] = 1;
      iter++;

      // Top connection
      if (r < N)
        U1.Union(v_top, r);
      else if (rand_hash[r - N])
        U1.Union(r - N, r);

      // Botton connection
      if (r + N > total_els - 1)
        U1.Union(v_bottom, r);
      else if (rand_hash[r + N])
        U1.Union(r + N, r);

      // Left connection
      if (r % N > 0 && rand_hash[r - 1] == 1)
        U1.Union(r - 1, r);

      // Right connection
      if (r % N < N - 1 && rand_hash[r + 1] == 1)
        U1.Union(r + 1, r);

      probability = (double)iter / (double)total_els;
      if (probability > 0.5 && U1.connected(v_top, v_bottom))
        break;
    }
  }
  delete[] rand_hash;

  cout<<iter<<"  "<<total_els;
  probability = (double)iter / (double)total_els;
  cout << probability << endl;

  int end = time(nullptr);
  cout << end - start << endl;

  return 0;
}


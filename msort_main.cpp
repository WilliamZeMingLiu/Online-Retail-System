#include "msort.h"

using namespace std;

struct Comp1 {
  bool operator()(int a, int b)
  {
  	return a > b;
  }
};

int main(int argc, char* argv[])
{
  vector<int> list = {5,7,89,3,4,43,32,6,2,1,78,54,1093,4938,4847,3238,483,93,28};
  Comp1 comp;
  mergesort<int,Comp1>(list, comp);

  for(unsigned i=0; i < list.size(); i++)
  {
  	cout << list[i] << endl;
  }
  return 0;
}
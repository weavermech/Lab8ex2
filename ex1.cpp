/*--------------------------------------------------------------------------*/

#include <stdlib.h>

#include <iostream>
using namespace std;
              
#include "LList.h"
#include "StringC.h"



int main(int argc, char* argv[])
{
  ListC<StringC>    list;
  StringC           st;
  
  while (cin >> st) list.InsFirst(st);
  
  IterC<StringC> it(list);
  int j;
  for (j=0, it.First(); it.IsElem(); it.Next(), j++) {
    cout << j << " : " << it.Data() << endl;
  }
}

/*--------------------------------------------------------------------------*/


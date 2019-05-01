/*--------------------------------------------------------------------------*/

#include <iostream>
using namespace std;

#include <stdlib.h>
#include "LList.h"
#include <string>



int main()
{
	ListC<string> list;
	string st;

	while (cin >> st)
	{
		cout << st << endl;
		list.InsFirst(st);
	}

	IterC<string> it(list);
	int j;
	for (j=0, it.First(); it.IsElem(); it.Next(), j++)
	{
		cout << j << " : " << it.Data() << endl;
	}

	exit(0);
}

/*--------------------------------------------------------------------------*/


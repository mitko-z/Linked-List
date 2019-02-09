#include <iostream>
#include "LinkedList.h"

using namespace std;





int main()
{
	linkedList aList;

	aList.add(0);
	aList.add(1);
	aList.add(2);

	aList.removeAt(0);

	for (int i = 0; i < aList.size(); i++)
	{
		cout << aList.at(i) << endl;
	}

	return 0;
}
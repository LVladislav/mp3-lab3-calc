#include "TStack.h"
#include <ctype.h>
#include <string.h>
#include "Prot.h"

int main()
{

	char str[100];
	cout << "Input: ";
	cin >> str;
	char out[100];
	bool flag = OPZ(str,out);
	if (flag == false)
	{
		cout << "Error!\n";
		return 1;
	}

	int rezout = Calc(out);
	cout << rezout << endl;
	return 0;
}
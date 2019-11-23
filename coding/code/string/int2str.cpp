#include <iostream>
#include <stdlib.h>
using namespace std;

void int2str(int n, char *str)
{
	int num = n > 0 ? n : -n;
	if (str == nullptr)
		return;

	char buf[10] = " ";
	int i = 0, j = 0;
	while(num)
	{
		buf[i++] = num % 10 + '0';
		num /= 10;
	}
	
	int len = n > 0 ? i : ++i;
	str[len] = '\0';
	if (n < 0)
	{
		j = 1;
		str[0] = '-';
	}

	for (; j < len; ++j)
	{
		str[j] = buf[len - 1 - j];
	}
}

int main(int argc, char* argv[]) {
	int n = -123;
	cout << n << endl;
	char str[10] = " ";
	cout << str << endl;
	int2str(n, str);
	cout << str << endl;
	system("pause");
}


#include <iostream>
#include <stdlib.h>
using namespace std;

char *strcpy(char *strDst, char *strSrc)  // ���� char* ��Ŀ���ǿ�����ʽʹ��
{
	if (strDst == nullptr || strSrc == nullptr)
		return nullptr;

	char *strDstCopy = strDst;
	while ((*strDst++ = *strSrc++) != '\0');
	return strDstCopy;
}


int main(int argc, char* argv[]) {

	char str[10] = "-123";
	char dst[10] = "abcdef";
	cout << dst << endl;
	strcpy(dst, str);
	cout << dst << endl;
	system("pause");
}


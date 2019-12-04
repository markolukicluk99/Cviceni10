#include "pch.h"
#include <iostream>
#include "tchar.h"
#include <ctype.h>

FILE* s;
char retazec[200];
char output[50] = "Pismen je:";
char* point = retazec;

int pismena = 0;
int cisla = 0;
int sz = 1;

int _tmain(int argc, _TCHAR* argv[])
{
	fopen_s(&s, "vstup.txt", "r+");
	printf("%p\n", s);
	if (s == NULL) {
		fopen_s(&s, "vstup.txt", "w+");
	}

	fgets(point, 4096, s);
	fseek(s, 0L, SEEK_END);
	sz = ftell(s);
	fseek(s, 0L, SEEK_SET);

	for (*point; *point != 0 && sz != 0; *point++) {
		if (isalpha(*point)) {
			pismena++;
		}
		if (isdigit(*point)) {
			cisla++;
		}
	}
	printf("Pismen je:%d a cisel:%d\n", pismena, cisla);

	fclose(s);


	fopen_s(&s, "vystup.txt", "w+");
	fprintf(s, "Pismen je:%d a cisel:%d\n", pismena, cisla);
	fclose(s);

	return 0;
}

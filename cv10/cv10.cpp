#include "pch.h"
#include <iostream>
#include "tchar.h"

FILE *s;

char prostor[200];
char output[50] = "Pismen je:";
char *point = prostor;
 
int pismena = 0; 
int cisla = 0;
int sz = 1;

int _tmain(int argc, _TCHAR* argv[])
{
	// navigace do .txt souboru, pozivam r+ abychom soubor precetli	fopen_s(&s, "vstup.txt", "r+");
	printf("%p\n", s);
	if (s == NULL) {
		fopen_s(&s, "vstup.txt", "w+");
	}

	fgets(point, 4096, s);
	fseek(s, 0L, SEEK_END);
	sz = ftell(s);
	fseek(s, 0L, SEEK_SET);

	
	//pocet pismen a cisel
	for (*point; *point != 0 && sz != 0; *point++) {
		if (isalpha(*point)) {
			pismena++;
		}
		if (isdigit(*point)) {
			cisla++;
		}
	}


	//   ***TISK***
	printf("Pocet pismen je:%d a pocet cisel:%d\n", pismena, cisla);

	fclose(s);


	fopen_s(&s, "vystup.txt", "w+");
	fprintf(s, "Pocet pismen je:%d a pocet cisel:%d\n", pismena, cisla);
	fclose(s);

	return 0;

	//Marko Lukic 221282 BPC-TLI03 BPC-PC1
}
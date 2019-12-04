#include "pch.h"
#include <iostream>
#include "tchar.h"
#include <ctype.h>
#include <string.h>

FILE* s;
char retazec[200];
char output[50] = "Pismen je:";
char* point = retazec;

int pismena = 0;
int i, pissmena, nejdelsi = 0, nejdelsipozice = 0;
int cisla = 0;
int sz = 1;

int _tmain(int argc, _TCHAR* argv[])
{
			/*   Otevreni textoveho souboru    */	fopen_s(&s, "vstup.txt", "r+");
	printf("%p\n", s);
	if (s == NULL) {
		fopen_s(&s, "vstup.txt", "w+");
	}

	fgets(point, 4096, s);
	fseek(s, 0L, SEEK_END);
	sz = ftell(s);
	fseek(s, 0L, SEEK_SET);

	
	
	/*   Urceni pocet cisel ve vete, a pocet cislic    */
	for (*point; *point != 0 && sz != 0; *point++) {
		if (isalpha(*point)) {
			pismena++;
		}
		if (isdigit(*point)) {
			cisla++;
		}
	}



	/*   Nejdelsi slovo a jeho delka    */
	for (i = 0; retazec[i] != '\0'; i++) {
		for (pissmena = 0; retazec[i] != '\0' && retazec[i] != ' '; i++) {
			pissmena++;
		}
		if (pissmena > nejdelsi) {
			nejdelsi = pissmena;
			nejdelsipozice = i - nejdelsi;
		}
	}

	
	
	/****** TISK *******/

	printf("Nejdelsi slovo: %d pismen, '%.*s'\n", nejdelsi, nejdelsi, retazec + nejdelsipozice);

	printf("Pismen je:%d a cisel:%d\n", pismena, cisla);

	fclose(s);



	/* Zapis vysledku do souboru vystup.txt a jeho tisk */

	fopen_s(&s, "vystup.txt", "w+");

	fprintf(s, "Pismen je:%d a cisel:%d\n", pismena, cisla);

	fclose(s);

	return 0;


	/*Marko Lukic  ID: 221282, Skupina: BPC-TLI03, Cviceni: Streda 17h*/


}

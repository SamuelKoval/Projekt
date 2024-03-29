#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable: 4996)
/*
Program, ktor� bude pracova� s fragmentom DNA sekvencie, zap�san�m v s�bore DNAsekvencia.txt. 
Tento s�bor obsahuje p�smen� ozna�uj�ce nukleotidy z abecedy X = {A, C, G, T}, 
pri�om tieto m��u by� zap�san� mal�mi alebo ve�k�mi p�smenami. 
Predpokladajte, �e v s�bore m��e by� zap�san� fragmet obsahuj�ci najviac 10 000 nukleotidov (znakov).
Program bude vykon�va� pr�kazy na��tan� zo �tandardn�ho vstupu. Ka�d� pr�kaz bude predstavova� vstup kde pri funkciach je kratky komentar
, ktora funkcia co robi.
*/

char OpakujucisaNukleoid(char *pole)		//Najdenie najdlhsich usekov opakujuceho sa jedneho nukleoidu		
{
	int pomocna = 1, max = 0;
	for (int i = 0; i < strlen(pole) - 1; i++)
	{
		if (pole[i] == pole[i + 1])
			pomocna++;
		else
		{
			if (pomocna > max)
			{
				max = pomocna;
			}
			pomocna = 1;
		}

	}
	int j;
	printf("Najdlhsie useky opakujucich sa nukleotidov: %d\n", max);
	for (int k = 0; k < strlen(pole); k++)
	{
		for (j = k + 1; j < k + max; j++)
		{
			if (pole[k] != pole[j])
				break;
		}

		if (j == k + max)
		{
			printf("%c %d ", pole[k], k + 1);
			printf("\n");
		}
	}
}

char VlozeniePodsekvencie(char *pole)		//Vlozenie podsekvencie do originalnej DNA
{
	sub[1000];
	int position, length, c = 0;

	printf("Zadaj string\n");
	gets(string);

	printf("Zadaj poziciu a dlzku stringu\n");
	scanf("%d%d", &position, &length);

	while (c < length) {
		sub[c] = string[position + c - 1];
		c++;
	}
	sub[c] = '\0';

	printf("Pozadovany retazec je: \"%s\"\n", sub);

	return 0;
}
char Podsekvencia(char *pole)		//Vyskyt zvolenej podsekvencie
{
	char *pismenko;
	int pocet;
	int  i, j, temp, k;
	scanf("%d", &pocet);
	pismenko = (char*)malloc(pocet * sizeof(char));
	scanf("%s", pismenko);
	pismenko[pocet] = '\0';
	int pomocne = strlen(pismenko);
	int dlzka = strlen(pole);
	for (i = 0; pole[i] != '\0'; i++)
	{
		j = 0;
		if ((pole[i] == pismenko[j]) || (pole[i] == pismenko[j] - 32) || (pole[i] == pismenko[j] + 32))
		{
			temp = i + 1;
			while (pole[i] == pismenko[j] || (pole[i] == pismenko[j] - 32) || (pole[i] == pismenko[j] + 32))
			{
				i++;
				j++;
			}

			if (pismenko[j] == '\0')
			{
				printf("%d ", temp);
				if ((temp - 4) < 0)
					printf("-");
				else
				{
					if (pole[temp - 4] > 'Z')
						printf("%c", (pole[temp - 4] - 32));
					else
						printf("%c", pole[temp - 4]);
				}

				if ((temp - 3) < 0)
					printf("-");
				else
				{
					if (pole[temp - 3] > 'Z')
						printf("%c", (pole[temp - 3] - 32));
					else
						printf("%c", pole[temp - 3]);
				}

				if ((temp - 2) < 0)
					printf("-");
				else
				{
					if (pole[temp - 2] > 'Z')
						printf("%c", (pole[temp - 2] - 32));
					else
						printf("%c", pole[temp - 2]);
				}


				for (k = temp - 1; k < temp + pomocne - 1; k++) {
					if (pole[k] > 'Z')
						printf("%c", (pole[k] - 32));
					else
						printf("%c", pole[k]);
				}
				printf("%c", pole[k]);
				if (k >= dlzka)
					printf("-");
				else
				{
					if (pole[k] > 'Z')
						printf("%c", (pole[k] - 32));
					else
						printf("%c", pole[k]);
				}
				if (k + 1 >= dlzka)
					printf("-");
				else
				{
					if (pole[k + 1] > 'Z')
						printf("%c", (pole[k + 1] - 32));
					else
						printf("%c", pole[k + 1]);
				}

				if (k + 2 >= dlzka)
					printf("-");
				else
				{
					if (pole[k + 2] > 'Z')
						printf("%c", (pole[k + 2] - 32));
					else
						printf("%c", pole[k + 2]);
				}

				printf("\n");


			}
			else
			{
				i = temp;
				temp = 0;
			}
		}
	}

	if (temp == 0)
		printf("The substring is not present in given string\n");
	free(pismenko);
}





char Histogram(char *pole)		//Vypis histogramu(pocet nukloidov)
{
	int a = 0, c = 0, g = 0, t = 0;
	int i = strlen(pole);
	for (int j = 0; j < i; j++)
	{
		if (pole[j] == 'a' || pole[j] == 'A')
			a++;
		else if (pole[j] == 'c' || pole[j] == 'C')
			c++;
		else if (pole[j] == 'g' || pole[j] == 'G')
			g++;
		else if (pole[j] == 't' || pole[j] == 'T')
			t++;
	}
	printf("A: %d\n C: %d\n G: %d\n T: %d\n", a, c, g, t);
}

char Vypis(char *pole)		//Vypis sekvencie ktora sa nacitala || ktora bola poupravena
{
	int a, b;
	scanf("%d %d", &a, &b);
	if (!pole)
	{
		printf("Pole nebolo nacitane");
	}
	for (a; a < b; a++)
	{
		printf("%c", pole[a - 1]);
	}
}

int Nacitanie(char *pole)		//Nacitanie do dynamickeho pola, kde sa kontroluju Pismena ci sedia.
{
	int pomocna = 0;
	char pismenko;
	FILE *f;
	f = fopen("DNAsekvencia.txt", "r");

	if (f == NULL)
	{
		printf("Neotvoreny subor");
		return 1;
	}
	while (fscanf(f, "%c", &pismenko) > 0)
	{
		if ((pismenko == 'A' || pismenko == 'a') || (pismenko == 'C' || pismenko == 'c') || (pismenko == 'T' || pismenko == 't') || (pismenko == 'G' || pismenko == 'g'))
		{
			pole[pomocna++] = pismenko;

		}

		else
		{
			printf("Sekvencia nesplna podmienky");
			return 1;
		}
	}
	pole[pomocna] = '\0';
	fclose(f);
	return 0;
}

int main()		//Main kde sa volaju vsetky funkcie
{
	char vstup;
	char *pole;
	pole = (char*)malloc(10000 * sizeof(char));
	while (scanf("%c", &vstup) > 0)
	{
		switch (vstup)
			case 'nacitanie':
				if (Nacitanie(pole) == 0)
					printf("Sekvenciu sa podarilo nacitat\n");
			case 'vypis':
				Vypis(pole);
			case 'histogram':
				Histogram(pole);
			case 'podsekvencia':
				Podsekvencia(pole);
			case 'vlozpod':
				VlozeniePodsekvencie(pole);
			case 'koniec':
				free(pole);
				break;
			case 'opakovanien':
				OpakujucisaNukleoid(pole);

	}

	return 0;
}
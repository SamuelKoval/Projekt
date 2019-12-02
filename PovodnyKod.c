#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable: 4996)


char o(char *pole)
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

char l(char *pole)
{
	char c[10000];
	int p = 0, r = 0, i = 0;
	int t = 0;
	int x, g, s, n, o;
	char b[1000];
	scanf("%s", &b);
	scanf("%d", &p);
	r = strlen(pole);
	n = strlen(b);
	i = 0;

	while (i <= r)
	{
		c[i] = pole[i];
		i++;
	}
	s = n + r;
	o = p + n;

	for (i = p; i < s; i++)
	{
		x = c[i];
		if (t < n)
		{
			pole[i] = b[t];
			t = t + 1;
		}
		pole[o] = x;
		o = o + 1;
	}

	printf("%s", pole);
}
char p(char *pole)
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





char h(char *pole)
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
	printf("A: %d\n", a);
	printf("C: %d\n", c);
	printf("G: %d\n", g);
	printf("T: %d\n", t);
}

char v(char *pole)
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

int n(char *pole)
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

int main()
{
	char vstup;
	char *pole;
	pole = (char*)malloc(10000 * sizeof(char));
	while (scanf("%c", &vstup) > 0)
	{
		if (vstup == 'n')
		{
			if (n(pole) == 0)
				printf("Sekvenciu sa podarilo nacitat\n");
		}
		else if (vstup == 'v')
		{
			v(pole);
		}
		else if (vstup == 'h')
		{
			h(pole);
		}
		else if (vstup == 'p')
		{
			p(pole);
		}
		else if (vstup == 'l')
		{
			l(pole);
		}
		else if (vstup == 'k')
		{
			free(pole);
			break;
		}
		else if (vstup == 'o')
		{
			o(pole);
		}
	}

	return 0;
}
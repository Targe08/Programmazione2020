#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int intero_casuale(int minimo, int massimo) {
  return minimo + (rand() % (massimo - minimo + 1));
}

typedef char Parola[31];

typedef struct {
  char lettera; // campo carattere
  int indovinata; // flag
} LetteraSegreta; 

typedef struct {
  LetteraSegreta lettereSegrete[30]; // mettiamo 30 perchè confrontando i char il terminatore non ci interessa
  int lunghezza; 
} ParolaSegreta;

ParolaSegreta nuovaParolaSegreta(char s[]) {
  int i; // con un contatore scorriamo la stringa passata come parametro 
  ParolaSegreta ps;
  ps.lunghezza = 0;
  i = 0;
  while (s[i] != '\0') { // fino a che la stringa passata all'indice i non abbia il terminatore
    ps.lunghezza++; // se abbiamo letto un campo valido 
    ps.lettereSegrete[i].lettera = s[i]; // s[i] è il carattere appena letto
    ps.lettereSegrete[i].indovinata = 0;
    i++;
  }
  return ps;
}

void stampaParolaSegreta(ParolaSegreta ps) { // parametro: la parola segreta da stampare
  int i;
  for (i = 0; i < ps.lunghezza; i++)
    if (ps.lettereSegrete[i].indovinata == 1) // se è stata indovinata 
      printf("%c ", ps.lettereSegrete[i].lettera);
    else
      printf("_ ");
}

int contiene(ParolaSegreta *pps, char c) { // puntatore a parola segreta e un carattere da cercare nella parola 
  int i; // contatore
  int trovata = 0;

  for (i = 0; i < pps->lunghezza; i++) { // -> equivale a dire (*puntatore).campo
    if (c == pps->lettereSegrete[i].lettera) { /* cofrontiamo c con la lettera della lettera segreta
    all'indice che stiamo considerando. */
      pps->lettereSegrete[i].indovinata = 1;
      trovata = 1;
    }
  }
  return trovata;
}

int completamente_indovinata(ParolaSegreta ps) {
  int i;
  for (i = 0; i < ps.lunghezza; i++) {
    if (!ps.lettereSegrete[i].indovinata)
      return 0;
  }
  return 1;
}

Parola parole[100000];
int numero_parole = 0;

void parolaCasuale(Parola pc) {
  // generare numero casuale fro 0 e numero_parole-1
  int numero_casuale = intero_casuale(0, numero_parole - 1);
  strcpy(pc, parole[numero_casuale]);
}

int main() {
  FILE* fp;
  Parola p;
  ParolaSegreta ps;
  char lettera[2]; /* rappresentiamo la lettera da leggere come stringa di 2 caratteri 
  perchè la scanf %c legge anche i caratteri bianchi */
  int vite = 5;

  srand(time(NULL));

  if ((fp = fopen("words.italian.txt", "rt")) == NULL) {
    printf("Errore apertura words.italian.txt\n");
    exit(1);
  }

  // ... operazioni su file
  // map da file a array
  while (fscanf(fp, "%s", p) == 1) {
    strcpy(parole[numero_parole], p);
    numero_parole++;
  }

  if (fclose(fp) != 0) {
    printf("Errore chiusura file\n");
    exit(2);
  }
  parolaCasuale(p);
  ps = nuovaParolaSegreta(p);

  do {
    stampaParolaSegreta(ps);
    printf("\n");
    scanf("%s", lettera); // scanf perchè non leggiamo da FILE ma da tastiera

    if (!contiene(&ps, lettera[0])) {
      vite--;
      printf("Vite: %d\n", vite);
    }
  } while (vite > 0 && !completamente_indovinata(ps));

  if (completamente_indovinata(ps))
    printf("Hai vinto!\n");
  else
    printf("Hai perso!\n");

  printf("La parola era %s\n", p);
  return 0;
}

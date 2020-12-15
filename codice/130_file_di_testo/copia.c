#include <stdio.h>
#include <stdlib.h> // per usare la funzione exit
#include <string.h> // per utilizzare strcmp per le stringhe

#define DIM 30 // non si mette il ;

int main() {
  FILE* fp; // contiene tutte le informazioni per interagire con il file
  char parola[DIM]; // variabile stringa

  // apertura file;
  fp = fopen("prova.txt", "wt"); // aprire un file, come parametro ha il nome del file

  if (fp == NULL) {
    printf("Impossibile aprire il file prova.txt.\n");
    exit(1);
  }

  // operazioni di scrittura su file
  do {
    scanf("%s", parola);     
    if (strcmp(parola, "FINE") != 0)
      fprintf(fp, "%s ", parola); // il puntatore al file dove vogliamo scrivere
  } while (strcmp(parola, "FINE") != 0); // per confrontare 2 stringhe, finchè non esce la parola FINE rimani nel ciclo
  fprintf(fp, "\n"); // manda a capo nel file di testo

  // chiudiamo il file
  if (fclose(fp) != 0) {
    printf("Errore nella chiusura del file\n");
    exit(2);
  }
  return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE* fp; // variabile che useremo per accedere al file
  char nomefile[50]; // array
  char c; // variabile per leggere il carattere

  printf("Quale file vuoi aprire? ");
  scanf("%s", nomefile);

  if ((fp = fopen(nomefile, "rt")) == NULL) {          // controllo obbligatorio 
    printf("Errore nell'apertura di %s\n", nomefile);
    exit(6);
  }

  /* while (!feof (fp)) {    finchè non sono alla fine del file 
    fscanf(fp, "%c", &c); 
    printf("%c", c);
  }
  */ 
  // in questo modo alla fine del testo viene stampato un. di troppo 
  
  while (fscanf(fp, "%c", &c) == 1) { // la fscanf restituisce 1 fino a quando riesce a leggere un carattere
    printf("%c", c);
  }

  if (fclose(fp) != 0) { // se è andato tutto bene il valore restituito deve essere uguale a 0 
    printf("Errore nella chiusura del file\n"); 
    exit(25); 
  }
  printf("\n");

  return 0;
}
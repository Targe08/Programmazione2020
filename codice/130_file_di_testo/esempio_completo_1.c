// il programma non stampa nulla

#include <stdio.h>
#include <stdlib.h>

// tipo di dato che leggiamo dal file
typedef struct // informazioni che messe insieme definiscono una persona
{
  char cognome[31];
  char nome[31];
  char sesso[2];
  int anno_nascita;
} Persona;

int main()
{
  Persona persone[100]; // gli elementi sono di tipo persona
  int dl; // la dimemnsione logica dipende da quante persone sono scritte nel file people.txt
  FILE *fp; // per accedere al file di testo
  // apertura file
  if ((fp = fopen("people.txt", "rt")) == NULL) {
  
    printf("Errore apertura people.txt\n");
    exit(1);
  }
  // lettura informazioni da file e salvataggio nell'array
  dl = 0;

  while (fscanf(fp, "%s%s%s%d", persone[dl].cognome, persone[dl]. /* rimaniamo nel ciclo fino a che la fscanf restituisce 
  il numero corrispondente al numero di elementi che ci aspettiamo di leggere*/
  nome,persone[dl].sesso, &persone[dl].anno_nascita) == 4) // premettiamo l'operatore di indirizzo perchè dato_nascita non è un array
  // == 4 è la condizione di permanenza che ci dice che tutto è andato bene (il valore di ritorno è 4)
  dl++;

  // chiusura del file
  if (fclose(fp) != 0)
  {
    printf("Errore chiusura file\n");
    exit(2);
  }
  return 0;
}
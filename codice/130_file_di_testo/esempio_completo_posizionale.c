// posizionale: le informazioni testuali iniziano e finiscono sempre nella stessa posizione 

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char cognome[11];
  char nome[11];
  char sesso;
  int anno_nascita;
} Persona;

int main() {
  FILE* fp;   // puntatiore a file             
  Persona persone[100];
  int dl;

  if ((fp = fopen("people-pos.txt", "rt")) == 0) {
    printf("Errore apertura people-pos.txt\n");
    exit(1); 
  }
  dl = 0;

  while (fscanf(fp, "%10c%10c%c%d\n", persone[dl].cognome, persone[dl].
  nome, &persone[dl].sesso, &persone[dl].anno_nascita) == 4) { // sesso e anno di nascita sono degli scalari

  persone[dl].cognome[10] = '\0'; // dobbiamo azzerare il cognome e il nome 
  persone[dl].nome[10] = '\0';
    dl++;
  }

  fclose(fp);
  return 0;
}
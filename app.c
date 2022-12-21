#include <stdio.h>
#include <stdlib.h>

struct Etudiant {
  int numCarte;
  char nom[10];
  char prenom[10];
  char dateN[10];
  char address[50];
  float notes[13];
  float coef[13];
  float moyenne;
  struct Etudiant *next;
};
typedef struct Etudiant *etudiants;

struct Etudiant *ajout(struct Etudiant *etudiant, int numCarte, char nom[10],
                       char prenom[10], char dateN[10], char address[10],
                       int notes[13], int coef[13], float moyenne) {

  struct Etudiant *nouvelEtudiant;
  nouvelEtudiant = (struct Etudiant *)malloc(sizeof(struct Etudiant));
  nouvelEtudiant->numCarte = numCarte;
  nouvelEtudiant->nom[10] = nom[10];
  nouvelEtudiant->prenom[10] = prenom[10];
  nouvelEtudiant->dateN[10] = dateN[10];
  nouvelEtudiant->address[50] = address[50];
  nouvelEtudiant->notes[13] = notes[13];
  nouvelEtudiant->coef[13] = coef[13];
  nouvelEtudiant->moyenne = moyenne;
  nouvelEtudiant->next = NULL;

  if (etudiant == NULL) {
    return nouvelEtudiant;
  } else {
    struct Etudiant *temp = etudiant;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = nouvelEtudiant;
    return etudiant;
  }
}

void affichage(struct Etudiant *etudiant) {
  struct Etudiant *temp;
  temp = etudiant;

  while (temp != NULL) {
    printf("%d", temp->numCarte);
    printf("%s", temp->nom);
    printf("%s", temp->prenom);
    printf("%s", temp->dateN);
    printf("%s", temp->address);
    printf("%f", temp->notes);
    printf("%f", temp->coef);
    printf("%f", temp->moyenne);
    temp = temp->next;
  }
  printf("\n");
}

void main() {
  int i;
  int fin = 1;
  char choix;
  struct Etudiant *etudiants;
  int numCarte;
  char nom[10];
  char prenom[10];
  char dateN[10];
  char address[20];
  int notes[13];
  int coef[13];
  float moyenne;

  do {
    printf("tapez le numero de la tache\n");
    printf("1- Ajout\n");
    printf("2- Suppression\n");
    printf("3- Affichage\n");
    printf("4- Calcul moyenne\n");
    printf("5- affichage avec la mention\n");
    printf("appuyer sur q pour quitter");
    printf("entrer votre choix");
    scanf("%c", &choix);
    switch (choix) {

    case '1':
      printf("donner le numero de la carte etudiant\n");
      scanf("%d", &numCarte);
      printf("donner le nom\n");
      scanf("%s", nom);
      printf("donner le prenom\n");
      scanf("%s", prenom);
      printf("donner la date de naissance\n");
      scanf("%s", dateN);
      printf("donner l\'addresse \n");
      scanf("%s", address);
      printf("donner les notes\n");
      for (i = 0; i < 13; i++) {
        printf("note %d\n", i);
        scanf("%f", &notes[i]);
      }
      printf("donner les coefficients: \n");
      for (i = 0; i < 13; i++) {
        printf("coef %d:\n", i);
        scanf("%f", &coef[i]);
      }
      etudiants = ajout(etudiants, numCarte, nom, prenom, dateN, address, notes,
                        coef, moyenne);
      break;

    case '2':
      printf("suppression();\n");
      break;
    case '3':
      affichage(etudiants);
      break;
    case '4':
      printf("calculMoy();\n");
      break;
    case '5':
      printf("mention();\n");
      break;
    default:
      break;
    }
  } while (1);
}

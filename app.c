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

void creationEtudiant(struct Etudiant *etudiants) {
  int i;
  etudiants = (struct Etudiant *)malloc(sizeof(struct Etudiant));
  printf("donner le numero de la carte etudiant \n");
  scanf("%d", &etudiants->numCarte);
  printf("donner le nom: \n");
  scanf("%s", etudiants->nom);
  printf("donner le prenom: \n");
  scanf("%s", etudiants->prenom);
  printf("donner la date de naissiance: \n");
  scanf("%s", etudiants->dateN);
  printf("donner l adresse: \n");
  scanf("%s", etudiants->address);
  printf("donner les notes: \n");
  for (i = 0; i < 13; i++) {
    printf("donner la note %d\n", i);
    scanf("%f", &etudiants->notes[i]);
  }
  printf("donner respectivement les coefficients\n");
  for (i = 0; i < 13; i++) {
    printf("donner le coefficient %d\n", i);
    scanf("%f", &etudiants->coef[i]);
  }
  etudiants->next = NULL;
}
void ajoutEtudiants(struct Etudiant *etudiant) {
  struct Etudiant *nouvelEtudiant;
  nouvelEtudiant = (struct Etudiant *)malloc(sizeof(struct Etudiant));
  creationEtudiant(nouvelEtudiant);
  nouvelEtudiant->next = etudiant;
  nouvelEtudiant = etudiant;
}

void affichage(struct Etudiant *etudiant) {
  struct Etudiant *nouvelEtudiant;
  int i;
  nouvelEtudiant = etudiant;
  if (nouvelEtudiant == NULL) {
    printf("liste des etudiants est vide");
  } else {
    while (nouvelEtudiant != NULL) {
      printf("numero de la carte: %d\n", nouvelEtudiant->numCarte);
      printf("nom: %s\n", nouvelEtudiant->nom);
      printf("prenom: %s\n", nouvelEtudiant->prenom);
      printf("date de naissance: %s\n", nouvelEtudiant->dateN);
      printf("addresse: %s\n", nouvelEtudiant->address);
      printf("notes matieres: \n");
      for (i = 0; i < 13; i++) {
        printf("note %d: %f\n", i, nouvelEtudiant->notes[i]);
      }
      printf("les coefficients respectivement au notes:\n");
      for (i = 0; i < 13; i++) {
        printf("coefficient %d: %f", i, nouvelEtudiant->coef[i]);
      }

      nouvelEtudiant = nouvelEtudiant->next;
    }
  }
}

void main() {
  char choix;
  struct Etudiant *etudiants;
  printf("tapez le numero de la tache\n");
  printf("1- Ajout\n");
  printf("2- Suppression\n");
  printf("3- Affichage\n");
  printf("4- Calcul moyenne\n");
  printf("5- affichage avec la mention\n");
  printf("appuyer sur CTRL+C pour quitter");
  printf("entrer votre choix");
  do {
    printf("tapez le numéro de la tache:\n");
    scanf("%c", &choix);
    switch (choix) {

    case '1':
      ajoutEtudiants(etudiants);
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

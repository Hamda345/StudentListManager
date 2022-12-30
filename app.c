#include <stdio.h>
#include <stdlib.h>
#define nb 5

typedef struct date {
  int dd;
  int mm;
  int yy;
} date;
int test_date(date *date) {

  // date* current = (date*)malloc(sizeof(date));
  // get_current_date(current);
  if (date->yy < 1 || date->dd < 1 || date->dd > 31 || date->mm < 1 ||
      date->mm > 12) { // add a condition for max date using current date
    return -1;
  }
  if (date->mm == 2 && date->dd == 29) {
    if (date->yy % 4 != 0) {
      return -1;
    }
    if (date->yy % 100 == 0) {
      if (date->yy % 400 == 0)
        return 1;
      else
        return -1;
    }
    if (date->mm == 2 && date->dd == 28) {
      return 1;
    } else if (date->mm == 1 || date->mm == 3 || date->mm == 5 ||
               date->mm == 7 || date->mm == 8 || date->mm == 10 ||
               date->mm == 12) {
      return 1;
    } else {
      if (date->dd <= 30) {
        return 1;
      }
    }
  }
}

struct Etudiant {
  int numCarte;
  char nom[10];
  char prenom[10];
  date dateN;
  char address[50];
  float notes[13];
  float coef[13];
  float moyenne;
  struct Etudiant *next;
};
struct Etudiant *Letudiant;

struct Etudiant *creationEtudiant(struct Etudiant *etudiants) {
  int i;
  etudiants = (struct Etudiant *)malloc(sizeof(struct Etudiant));
  printf("donner le numero de la carte etudiant:  ");
  scanf("%d", &etudiants->numCarte);
  printf("donner le nom:  ");
  scanf("%s", etudiants->nom);
  printf("donner le prenom:  ");
  scanf("%s", etudiants->prenom);
  printf("donner la date de naissiance dans le format dd/mm/yy:   ");
  scanf("%d/%d/%d", &etudiants->dateN.dd, &etudiants->dateN.mm,
        &etudiants->dateN.yy);
  while (test_date(&etudiants->dateN) == -1) {
    printf("veuillez respectez le format de la date (dd/mm/yy) \n");
    scanf("%d/%d/%d", &etudiants->dateN.dd, &etudiants->dateN.mm,
          &etudiants->dateN.yy);
  }
  printf("donner l adresse:  ");
  scanf("%s", etudiants->address);
  printf("donner les notes:   \n");
  for (i = 0; i < nb; i++) {
    printf("donner la note %d  ", i);
    scanf("%f", &etudiants->notes[i]);
  }
  printf("donner respectivement les coefficients\n");
  for (i = 0; i < nb; i++) {
    printf("donner le coefficient %d   ", i);
    scanf("%f", &etudiants->coef[i]);
  }
  // etudiants->next = NULL;
  return etudiants;
}
struct Etudiant *ajoutEtudiants(struct Etudiant *letudiant) {
  struct Etudiant *nouvelEtudiant;
  nouvelEtudiant = creationEtudiant(nouvelEtudiant);
  nouvelEtudiant->next = letudiant;
  // letudiant = nouvelEtudiant;
  return nouvelEtudiant;
}

void affichage(struct Etudiant *etudiant) {
  struct Etudiant *nouvelEtudiant;
  int i;
  nouvelEtudiant = etudiant;
  if (nouvelEtudiant->next == NULL) {
    printf("liste des etudiants est vide\n");
  } else {
    while (nouvelEtudiant != NULL) {
      printf("numero de la carte: %d\n", nouvelEtudiant->numCarte);
      printf("nom: %s\n", nouvelEtudiant->nom);
      printf("prenom: %s\n", nouvelEtudiant->prenom);
      printf("date de naissance: %d/%d/%d\n", nouvelEtudiant->dateN.dd,
             nouvelEtudiant->dateN.mm, nouvelEtudiant->dateN.yy);
      printf("addresse: %s\n", nouvelEtudiant->address);
      printf("notes matieres: \n");
      for (i = 0; i < nb; i++) {
        printf("note %d: %f\n", i, nouvelEtudiant->notes[i]);
      }
      printf("les coefficients respectivement au notes:\n");
      for (i = 0; i < nb; i++) {
        printf("coefficient %d: %f\n", i, nouvelEtudiant->coef[i]);
      }
      nouvelEtudiant = nouvelEtudiant->next;
    }
  }
  printf("\n");
}
void Supprimer(struct Etudiant *letudiant, int numCarte) {
  struct Etudiant *temp, *precedent;
  temp = letudiant;
  if (temp != NULL && temp->numCarte == numCarte) {
    letudiant = temp->next;
    free(temp);
    // return;
  }

  while (temp != NULL && temp->numCarte != numCarte) {
    precedent = temp;
    temp = temp->next;
  }

  if (temp == NULL) {
    return;
  }
  precedent->next = temp->next;

  free(temp);
}

float CalculMoy(struct Etudiant *letudiant, int numCarte) {
  struct Etudiant *temp = letudiant;
  float moyenne;
  float somme = 0;
  int i, j;
  if (temp != NULL && temp->numCarte == numCarte) {
    for (i = 0; i < nb; i++) {
      for (j = 0; j < nb; j++) {
        somme = somme + (temp->notes[i] * temp->coef[j]);
      }
      moyenne = somme / 20;
    }

    temp->moyenne = moyenne;
    letudiant = temp;
    return moyenne;
  }
}

void mention(struct Etudiant *etudiant, int numCarte) {
  struct Etudiant *temp = etudiant;

  if (temp->numCarte == numCarte) {
    if (temp->moyenne >= 18) {
      printf("Excellent \n");
    } else if (temp->moyenne >= 16 && temp->moyenne <= 18) {
      printf("Trés Bien\n");
    } else if (temp->moyenne >= 14 && temp->moyenne <= 16) {
      printf("Bien\n");
    } else if (temp->moyenne <= 14 && temp->moyenne >= 12) {
      printf("Assez bien\n");
    } else if (temp->moyenne <= 12 && temp->moyenne >= 10) {
      printf("passable\n");
    } else {
      printf("Non Admis\n");
    }
  }
}

void main() {
  char choix;
  int numCarte;
  float moyenne;
  struct Etudiant *etudiants;
  printf("tapez le numero de la tache\n");
  printf("1** Ajout\n");
  printf("2** SUPPRESSION\n");
  printf("3** AFFICHAGE\n");
  printf("4** CALCUL MOYENNE\n");
  printf("5** AFFICHAGE AVEC LA MENTION\n");
  printf("6** QUITTER\n");
  printf("entrer votre choix");
  do {
    printf("tapez le numéro de la tache: ");
    scanf("%c", &choix);
    switch (choix) {

    case '1':
      etudiants = ajoutEtudiants(etudiants);
      break;

    case '2':
      printf("donner le numéro de carte de l etudiant à supprimer: ");
      scanf("%d", &numCarte);
      Supprimer(etudiants, numCarte);
      break;
    case '3':
      affichage(etudiants);
      break;
    case '4':
      printf(
          "donner le numéro de la carte etudiant pour calculer la moyenne: ");
      scanf("%d", &numCarte);
      moyenne = CalculMoy(etudiants, numCarte);
      printf("moyenne de l etudiant %d: %f", numCarte, moyenne);
      break;
    case '5':
      mention(etudiants, numCarte);
      break;
    case '6':
      exit(0);
    default:
      break;
    }
  } while (1);
}

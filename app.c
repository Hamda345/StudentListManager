#include <stdio.h>
#include <stdlib.h>
#define nb 5

typedef struct date {
  int dd; // entier le jour
  int mm; // entier pour le mois
  int yy; // entier pour l'année
} date;   // definir une structure date qui contient 3 entiers pour le jour, le
          // mois et l'année
int test_date(date *date) { // creation d'une fontion test_date pour retenir -1
                            // comme resultat en cas d'une format de date fausse

  if (date->yy < 1 || date->dd < 1 || date->dd > 31 || date->mm < 1 ||
      date->mm > 12) { // ajout d'une condition pour le max d'une date
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
  int numCarte;     // entier pour le numéro de la carte étudiant
  char nom[10];     // chaine de caractères pour le nom
  char prenom[10];  // chaine de caractère pour le prénom
  date dateN;       // structure de type date pour le format de la date
  char address[50]; // chaine de caractères pour l'addresse
  float notes[13];  // tableau d'entiers pour les notes
  float coef[13];   // tableau d'entiers pour les coefficients respectivement à
                    // les notes
  float moyenne;    // un réelle pour la moyenne
  struct Etudiant
      *next; // structure de type Etudaint pour pointer sur l'élément suivant
}; // creation d'une structure qui contient les coordonnées d'un étudiant est
   // qui pointe sur une structure suivance de meme type de structure
struct Etudiant *Letudiant;

struct Etudiant *creationEtudiant(
    struct Etudiant
        *etudiants) { // fonction pour la saisie des coordonnées des étudiants
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
  } // creation d'une boucle infinie qui arret sous condition que le format de
    // la date est vraie
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
struct Etudiant *
ajoutEtudiants(struct Etudiant *letudiant) { // fontion pour ajouter un étudiant
                                             // à la liste des étudants
  struct Etudiant *nouvelEtudiant; // creation d'un nouvel element qui est vide
  nouvelEtudiant =
      creationEtudiant(nouvelEtudiant); // aperler la fonction de creation
                                        // étduaint pour remplir les coordonnées
  nouvelEtudiant->next =
      letudiant; // le nouvel element pointe sur le premier element de la liste
  return nouvelEtudiant; // renvoyer la valeur de nouvel élément
}

void affichage(struct Etudiant *etudiant) {
  struct Etudiant *nouvelEtudiant; // créer un nouvel element
  int i; // creer un entier pour le parcours d'un tableau des notes
  nouvelEtudiant =
      etudiant; // le nouvel element est égal à la liste des étudiant
  if (nouvelEtudiant->next == NULL) { // condition pour une liste vide
    printf("liste des etudiants est vide\n");
  } else {
    while (nouvelEtudiant !=
           NULL) { // faire une boucle infinie qui s'arrete sur la condtion où
                   // le nouvel element est null
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
      nouvelEtudiant =
          nouvelEtudiant
              ->next; // aprés l'affichage des coordonnées de l'element
                      // (étudiant) la valeur de nouvel élément recoit la valeur
                      // suivante pour faire le parcours
    }
  }
  printf("\n");
}
void Supprimer(struct Etudiant *letudiant,
               int numCarte) { // fontion pour supprimer un element (étudiant)
                               // par sa numéro de la carte étudiant
  struct Etudiant *temp, *precedent; // creation de 2 listes de type étudiant
                                     // qui sont des pointeurs
  temp = letudiant; // la liste temp recoit la valeur de la liste entrée comme
                    // paramètre
  if (temp != NULL &&
      temp->numCarte ==
          numCarte) { // si le liste temp n'est pas vide et la variable numCarte
                      // (numéro de la carte étudiant) est égale à la numCarte
                      // entrée comme paramètre
    letudiant = temp->next; // l'element 1 de la liste letudiant recoit
                            // l'élément suivant de la liste temp
    free(temp);             // vider la liste temp
    // return;
  }

  while (temp != NULL &&
         temp->numCarte !=
             numCarte) { // faire une boucle infinie qui arrete sur la condition
                         // que temp est nulle numéro de la carte entrée est
                         // égale la numéro de la carte de l'élement
    precedent = temp; // la liste précédent recoit la valeur de la liste temp
    temp = temp->next; // l'élément 1 de la liste temp recoit l'élément suivant
                       // de la liste (dernier)
  }

  if (temp == NULL) { // si liste temp est vide la fonction arrete
    return;
  }
  precedent->next = temp->next; // l'élément suivant de la liste temp pointe sur
                                // l'élément suivant de la liste precedent

  free(temp); // vider temp
}

float CalculMoy(struct Etudiant *letudiant, int numCarte) {
  struct Etudiant *temp = letudiant; // creation de 2 listes de type étudiant
  float moyenne;                     // creation d'une varible mooyenne
  float somme = 0;                   // creation d'une variable somme
  int i, j;                          // creation de deux variables entiers
  if (temp != NULL &&
      temp->numCarte ==
          numCarte) { // si la liste temp n'est pas vide et le numéro de carte
                      // de liste temp égale à la numéro de la carte entrée par
                      // l'utilisateur
    for (i = 0; i < nb; i++) {
      for (j = 0; j < nb; j++) {
        somme = somme +
                (temp->notes[i] * temp->coef[j]); // calculer la somme des notes
      }
      moyenne = somme / nb; // calculer la moyenne
    }

    temp->moyenne = moyenne; // la variable moyenne de la liste recoit la valeur
                             // de moyenne calculée
    letudiant = temp; // la liste letudaint (entrée comme paramètre) recoit la
                      // liste temp
    return moyenne;   // renvoyer la valeur de moyenne
  }
}

void mention(struct Etudiant *etudiant, int numCarte) {
  struct Etudiant *temp = etudiant; // creer une liste temp qui est égale à la
                                    // liste etudiant entrée comme parametre

  if (temp->numCarte ==
      numCarte) { // si le numéro de carte étudiant est égale à la numéro de la
                  // carte entrée par l'utilisateur
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
  } // afficher une mention correspent à la plage de la moyenne
}

void main() {
  char choix; // créer une variable de type caractère pour le saisie de choix
  int numCarte; // créer une variable pour la selection d'un élément de la liste
                // Etudiant à partir de numéro de la carte
  float moyenne; // créer une variable moyenne pour l'affichage de la moyenne
  struct Etudiant *etudiants; // creation d'une liste vide
  printf("tapez le numero de la tache\n");
  printf("1** Ajout\n");
  printf("2** SUPPRESSION\n");
  printf("3** AFFICHAGE\n");
  printf("4** CALCUL MOYENNE\n");
  printf("5** AFFICHAGE AVEC LA MENTION\n");
  printf("6** QUITTER\n");
  printf("entrer votre choix"); // afficher la liste des opération que
                                // l'utilisateur peut faire
  do { // creer une boucle infinie pour que le programme ne quitte pas aprés
       // chaque opération
    printf("tapez le numéro de la tache: ");
    scanf("%c", &choix); // la variable choix doit etre saisie par l'utilisateur
    switch (choix) {

    case '1': // si le valeur entrée par l'utilisateur est '1' faire cette tache
      etudiants =
          ajoutEtudiants(etudiants); // ajouter un étudiant à la liste en
                                     // utlisant la fontion ajoutEtudiants()
      break; // arret de linstruction apres qui se termine

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
      exit(0); // si l'utlisateur entre une valeur '6' la programme s'arrete
    default:
      break;
    }
  } while (1);
}

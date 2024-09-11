#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int annee;
    int mois;
    int jour;
} date;

typedef struct {
    int id;
    char nom[50];
    char prenom[50];
    date date_de_naissance;
    char departement[50];
    float moyenne_general;
} Etudient;

int c = 0;
int choix, a, m, j, i,idd,existe;
float n;
Etudient T[1000];

int date_valide(int annee, int mois, int jour) {
    if (mois < 1 || mois > 12 || jour < 1 || jour > 31) return 0;
    if (mois == 2) {
        if (annee % 4 == 0 && (annee % 100 != 0 || annee % 400 == 0)) {
            if (jour > 29) return 0;
        } else {
            if (jour > 28) return 0;
        }
    } else if (mois == 4 || mois == 6 || mois == 9 || mois == 11) {
        if (jour > 30) return 0;
    }
    return 1;
}

void ajouter_etudient() {

    printf("Entrer le ID  de L'etudient: ");
    scanf("%d", &idd);
    do {
        existe = 0;
        for (i = 0; i < c; i++) {
            if (T[i].id == idd) {
                existe = 1;
                printf("Le ID est deja existe ! Entrer un autre id: ");
                scanf("%d", &idd);
                break;
            }
        }
    } while (existe==1);
    T[c].id = idd;

    printf("Entrer le nom de L'etudient : ");
    scanf(" %[^\n]s", T[c].nom);

    printf("Entrer le Prenom de L'etudient : ");
    scanf(" %[^\n]s", T[c].prenom);

    printf("Entrer la date de naissance  de L'etudient: ");
    printf("Entrer l'annee : ");
    scanf("%d", &a);
    do {
        if (a <= 2007) {
            T[c].date_de_naissance.annee = a;
        } else {
            printf("L'etudient doit etre +18ans pour entrer a l'universite !\n");
            scanf("%d", &a);
        }
    } while (a > 2007);

    printf("Entrer le mois : ");
    scanf("%d", &m);
    do {
        if (m >= 1 && m <= 12) {
            T[c].date_de_naissance.mois = m;
        } else {
            printf("Le Mois doit etre Entre 1 et 12\n");
            scanf("%d", &m);
        }
    } while (m < 1 || m > 12);

    printf("Entrer le jour : ");
    scanf("%d", &j);
    do {
        if (date_valide(T[c].date_de_naissance.annee, T[c].date_de_naissance.mois, j)==1) {
            T[c].date_de_naissance.jour = j;
            break;
        } else {
            printf("Le jour incorrect !\n");
            scanf("%d", &j);
        }
    } while (date_valide(T[c].date_de_naissance.annee, T[c].date_de_naissance.mois, j)==0);
    T[c].date_de_naissance.jour = j;

    printf("Entrer la departement de L'etudient : 1- Math 2- Informatique 3- Economie 4-Comptabilite ");
    scanf("%d", &choix);
    do {
        if (choix == 1) {
            strcpy(T[c].departement, "Math");
        } else if (choix == 2) {
            strcpy(T[c].departement, "Informatique");
        } else if (choix == 3) {
            strcpy(T[c].departement, "Economie");
        } else if (choix == 4) {
            strcpy(T[c].departement, "Comptabilite");
        } else {
            printf("Entrer un nombre entre 1 et 4 ! \n");
        }
    } while (choix < 1 || choix > 4);

    printf("Entrer la note general de l'etudient : ");
    scanf("%f", &n);
    do {
        if (n >= 0 && n <= 20) {
            T[c].moyenne_general = n;
        } else {
            printf("La moyenne general doit etre entre 0 et 20 !\n");
            scanf("%f", &n);
        }
    } while (n < 0 || n > 20);
    c++;
}

void ajouter_des_etudients() {
    printf("Combien d'etudiants veux-tu saisir : ");
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        ajouter_etudient();
    }
}

void afficher_etudient(int indice) {
    printf("L'id d'etudient : %d\n", T[indice].id);
    printf("Le nom d'etudient : %s\n", T[indice].nom);
    printf("Le prenom d'etudient : %s\n", T[indice].prenom);
    printf("La date de naissance d'etudient : %d - %d - %d\n", T[indice].date_de_naissance.annee, T[indice].date_de_naissance.mois, T[indice].date_de_naissance.jour);
    printf("La departement d'etudient : %s\n", T[indice].departement);
    printf("La note general d'etudient : %.2f\n", T[indice].moyenne_general);
}

void afficher_tout_etudient() {
    for (int i = 0; i < c; i++) {
        afficher_etudient(i);
    }
}

void modifier_etudient() {
      int d,cho,ddd,test=1;

      printf("Que ce que vous vouler modifier : \n");
      printf("1- Modifier ID : \n");
      printf("2- Modifier Nom : \n");
      printf("3 -Modifier Prenom : \n");
      printf("4- Modifier La date de naissnace : \n");
      printf("5- Modifier La Departement : \n");
      printf("6- Modifier La Note general: \n");
      printf("0- Quitte ! \n");
      scanf("%d",&cho);


      switch(cho){
         case 1 :
                printf("Entrer id de etudient a modifier : ");
                scanf("%d",&d);
                for(int i=0;i<c;i++){
                if(T[i].id==d){
                test = 0;
                 printf("Entrer le nouveau ID  de L'etudient: ");
                 scanf("%d", &ddd);
                        do {
                         existe = 0;
                           for (int j = 0; j < c; j++) {
                           if (T[j].id == ddd) {
                           existe = 1;
                           printf("Le ID est deja existe ! Entrer un autre id: ");
                           scanf("%d", &ddd);
                           break;
                          }
                        }
                       } while (existe==1);
                       T[i].id=ddd;
                }
                if(test==1){
                    printf("Aucun etudient par ce id \n");
                }
                }
                 break;

         case 2 :
                printf("Entrer id de etudient a modifier : ");
                scanf("%d",&d);
                for(int i=0;i<c;i++){
                if(T[i].id==d){
                    test=0;
                printf("Entrer le nouveau nom : ");
                scanf(" %[^\n]s", T[i].nom);
               }
               }
                if(test==1){
                printf("Aucun etudient par ce id \n");
               }
                break;
         case 3 :
                printf("Entrer id de etudient a modifier : ");
                scanf("%d",&d);
                for(int i=0;i<c;i++){
                if(T[i].id==d){
                        test=0;
                printf("Entrer le nouveau prenom : ");
                scanf(" %[^\n]s", T[i].prenom);
                 }
                }
                if(test==1){
                printf("Aucun etudient par ce id \n");
                 }
            break;
         case 4 :
                printf("Entrer id de etudient a modifier : ");
                scanf("%d",&d);
             for(int i=0;i<c;i++){
              if(T[i].id==d){
                    test=0;
            printf("Entrer la nouvelle date de naissance : ");
            printf("Entrer l'annee : ");
            scanf("%d", &a);
            do {
                if (a <= 2007) {
                    T[i].date_de_naissance.annee = a;
                } else {
                    printf("L'etudient doit etre +18ans pour entrer a l'universite !\n");
                    scanf("%d",&a);
                }
            } while (a > 2007);

            printf("Entrer le mois : ");
            scanf("%d", &m);
            do {
                if (m >= 1 && m <= 12) {
                    T[i].date_de_naissance.mois = m;
                } else {
                    printf("Le Mois doit etre Entre 1 et 12\n");
                    scanf("%d", &m);
                }
            } while (m < 1 || m > 12);

            printf("Entrer le jour : ");
            scanf("%d", &j);

            do {
                if (date_valide(T[i].date_de_naissance.annee, T[i].date_de_naissance.mois, j)==1) {
                    T[i].date_de_naissance.jour = j;
                } else {
                    printf("Le jour incorrect !\n");
                    scanf("%d", &j);
                }
            } while (date_valide(T[i].date_de_naissance.annee, T[i].date_de_naissance.mois, j)==0);
              }
             }
             if(test==1){
                printf("Aucun etudient par ce id \n");
                 }
                 break;
         case 5 :
                printf("Entrer id de etudient a modifier : ");
                scanf("%d",&d);
                for(int i=0;i<c;i++){
                if(T[i].id==d){
                    test=0;
                 printf("Entrer la departement de L'etudient : 1- Math 2- Informatique 3- Economie 4-Comptabilite ");
                 scanf("%d", &choix);
                do {
                if (choix == 1) {
                    strcpy(T[i].departement, "Math");
                } else if (choix == 2) {
                    strcpy(T[i].departement, "Informatique");
                } else if (choix == 3) {
                    strcpy(T[i].departement, "Economie");
                } else if (choix == 4) {
                    strcpy(T[i].departement, "Comptabilite");
                } else {
                    printf("Entrer un nombre entre 1 et 4 ! \n");
                }
            } while (choix < 1 || choix > 4);
              }
            }
            if(test==1){
                printf("Aucun etudient par ce id \n");
                 }
                 break;
         case 6 :
                printf("Entrer id de etudient a modifier : ");
                scanf("%d",&d);
                for(int i=0;i<c;i++){
              if(T[i].id==d){
                    test=0;
            printf("Entrer la nouvelle note general : ");
            scanf("%f", &n);
            do {
                if (n >= 0 && n <= 20) {
                    T[i].moyenne_general = n;
                } else {
                    printf("La moyenne general doit etre entre 0 et 20 !\n");
                    scanf("%f", &n);
                }
            } while (n < 0 || n > 20);
           }
          }
          if(test==1){
                printf("Aucun etudient par ce id \n");
                 }
                 break;
         case 0 :
            break;

         default :
            printf("Aucun choix !");
        }
      }


void supprimer_etudient() {
    int d;
    printf("Entrer l'id d'etudient a supprimer : ");
    scanf("%d", &d);
    for (i = 0; i < c; i++) {
        if (T[i].id == d) {
            for (int j = i; j < c - 1; j++) {
                T[j] = T[j + 1];
            }
            c--;
            break;
        }
    }
}

void tri_moyenne(){
    Etudient tmp;
    for (int i = 0; i < c - 1; i++) {
        for (int j = i + 1; j < c; j++) {
            if (T[i].moyenne_general < T[j].moyenne_general) {
                tmp = T[i];
                T[i] = T[j];
                T[j] = tmp;
            }
        }
    }
}

void tri_nom_AZ(){
    Etudient tmp;
    for (int i = 0; i < c - 1; i++) {
        for (int j = i + 1; j < c; j++) {
            if (strcmp(T[i].nom, T[j].nom) > 0) {
                tmp = T[i];
                T[i] = T[j];
                T[j] = tmp;
            }
        }
    }
}

void tri_nom_ZA(){
    Etudient tmp;
    for (int i = 0; i < c - 1; i++) {
        for (int j = i + 1; j < c; j++) {
            if (strcmp(T[i].nom, T[j].nom) < 0) {
                tmp = T[i];
                T[i] = T[j];
                T[j] = tmp;
            }
        }
    }
}

void moyenne_general_departament() {
    float moyenne_math = 0, conteur_math = 0;
    float moyenne_informatique = 0, conteur_informatique = 0;
    float moyenne_economie = 0, conteur_economie = 0;
    float moyenne_comptabilite = 0, conteur_comptabilite = 0;

    for (int i = 0; i < c; i++) {
        if (strcmp(T[i].departement, "Math") == 0) {
            conteur_math += 1;
            moyenne_math += T[i].moyenne_general;
        }
        if (strcmp(T[i].departement, "Informatique") == 0) {
            conteur_informatique += 1;
            moyenne_informatique += T[i].moyenne_general;
        }
        if (strcmp(T[i].departement, "Economie") == 0) {
            conteur_economie += 1;
            moyenne_economie += T[i].moyenne_general;
        }
        if (strcmp(T[i].departement, "Comptabilite") == 0) {
            conteur_comptabilite += 1;
            moyenne_comptabilite += T[i].moyenne_general;
        }
    }

    if (conteur_math > 0) printf("La moyenne general de la departement de Math est %.2f\n", moyenne_math / conteur_math);
    if (conteur_informatique > 0) printf("La moyenne general de la departement d'Informatique est %.2f\n", moyenne_informatique / conteur_informatique);
    if (conteur_economie > 0) printf("La moyenne general de la departement d'Economie est %.2f\n", moyenne_economie / conteur_economie);
    if (conteur_comptabilite > 0) printf("La moyenne general de la departement de Comptabilite est %.2f\n", moyenne_comptabilite / conteur_comptabilite);
}

void afficher_nbr_etudient() {
    printf("Le nombre total d'etudiants dans l'université est : %d\n", c);
}

void affiche_nbr_etudient_departement() {
    int conteur_math = 0, conteur_informatique = 0, conteur_economie = 0, conteur_comptabilite = 0;
    for (int i = 0; i < c; i++) {
        if (strcmp(T[i].departement, "Math") == 0) {
            conteur_math += 1;
        }
        if (strcmp(T[i].departement, "Informatique") == 0) {
            conteur_informatique += 1;
        }
        if (strcmp(T[i].departement, "Economie") == 0) {
            conteur_economie += 1;
        }
        if (strcmp(T[i].departement, "Comptabilite") == 0) {
            conteur_comptabilite += 1;
        }
    }
    printf("Nombre d'etudiants dans la departement de Math : %d\n", conteur_math);
    printf("Nombre d'etudiants dans la departement d'Informatique : %d\n", conteur_informatique);
    printf("Nombre d'etudiants dans la departement d'Economie : %d\n", conteur_economie);
    printf("Nombre d'etudiants dans la departement de Comptabilite : %d\n", conteur_comptabilite);
}

void affiche_etudient_seuil() {
    float seuil;
    printf("Entrer le seuil : ");
    scanf("%f", &seuil);
    for (int i = 0; i < c; i++) {
        if (T[i].moyenne_general >= seuil) {
            afficher_etudient(i);
        }
    }
}

void affiche_3_etudiants() {
    tri_moyenne();
    if (c > 0) {
        printf("L'Etudiant 1 : %s %s %.2f\n", T[0].nom, T[0].prenom, T[0].moyenne_general);
    }
    if (c > 1) {
        printf("L'Etudiant 2 : %s %s %.2f\n", T[1].nom, T[1].prenom, T[1].moyenne_general);
    }
    if (c > 2) {
        printf("L'Etudiant 3 : %s %s %.2f\n", T[2].nom, T[2].prenom, T[2].moyenne_general);
    }
}

void affiche_etudient_reussi() {
    int conteur_math = 0, conteur_informatique = 0, conteur_economie = 0, conteur_comptabilite = 0;
    for (int i = 0; i < c; i++) {
        if (strcmp(T[i].departement, "Math") == 0 && T[i].moyenne_general >= 10) {
            conteur_math += 1;
        }
        if (strcmp(T[i].departement, "Informatique") == 0 && T[i].moyenne_general >= 10) {
            conteur_informatique += 1;
        }
        if (strcmp(T[i].departement, "Economie") == 0 && T[i].moyenne_general >= 10) {
            conteur_economie += 1;
        }
        if (strcmp(T[i].departement, "Comptabilite") == 0 && T[i].moyenne_general >= 10) {
            conteur_comptabilite += 1;
        }
    }
    printf("Nombre d'etudiants reussis dans la departement de Math : %d\n", conteur_math);
    printf("Nombre d'etudiants reussis dans la departement d'Informatique : %d\n", conteur_informatique);
    printf("Nombre d'etudiants reussis dans la departement d'Economie : %d\n", conteur_economie);
    printf("Nombre d'etudiants reussis dans la departement de Comptabilite : %d\n", conteur_comptabilite);
}

void afficher_etudient_10() {
    for (int i = 0; i < c; i++) {
        if (T[i].moyenne_general >= 10) {
            afficher_etudient(i);
        }
    }
}
void supprimercmd(){
   system("pause");
   system("cls");
}

int main() {
    int choix,ch;

    do{
        printf("Menu :\n");
        printf("1.  Ajouter des etudiants\n");
        printf("2.  Modifier un etudiant\n");
        printf("3.  Supprimer un etudiant\n");
        printf("4.  Afficher tous les etudiants\n");
        printf("5.  Les Fonction de Statistique\n");
        printf("6.  Les Fonction de Triage\n");
        printf("0. Quitter\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                ajouter_des_etudients();
                break;
            case 2:
                modifier_etudient();
                break;
            case 3:
                supprimer_etudient();
                break;
            case 4:
                afficher_tout_etudient();
                break;
            case 5:
                 printf("1.  Afficher les etudiants ayant une moyenne au dessu d'un seuil\n");
                 printf("2.  Afficher les 3 meilleurs etudiants\n");
                 printf("3.  Afficher les moyennes generales par departement\n");
                 printf("4.  Afficher le nombre total d'etudiants\n");
                 printf("5.  Afficher le nombre d'etudiants par departement\n");
                 printf("6.  Afficher les etudiants ayant une moyenne >= 10\n");
                 printf("7.  Afficher le nombre d'etudiants ayant reussi par departement\n");
                 scanf("%d",&ch);
                switch(ch){
                case 1 :
                affiche_etudient_seuil();
                break;

                case 2:
                affiche_3_etudiants();
                break;
                case 3:
                moyenne_general_departament();
                break;
                case 4:
                afficher_nbr_etudient();
                break;
                case 5:
                affiche_nbr_etudient_departement();
                break;
                case 6:
                afficher_etudient_10();
                break;
                case 7:
                affiche_etudient_reussi();
                break;
                 }
                 break;
            case 6 :
                 printf("Trier les etudients en ordre alphabetic A-Z\n");
                 printf("Trier les etudients en ordre disalphabetic Z-A\n");
                 printf("Trier les etudients par moyenne general \n");
                 scanf("%d",ch);
                 switch(ch){
                 case 1 :
                    tri_nom_AZ();
                    break;
                 case 2 :
                    tri_nom_ZA();
                    break;
                 case 3 :
                    tri_moyenne();
                    break;

                 }
                    break;
                 case 0:
                    break;
            default:
                printf("Choix invalide !\n");
                break;
        }
        supprimercmd();
    }while(choix != 0);

    return 0;
}

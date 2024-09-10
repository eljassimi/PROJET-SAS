#include <stdio.h>
#include <stdlib.h>

typedef struct{
int annee;
int mois;
int jour;
}date;

typedef struct {
    int id;
    char nom[50];
    char prenom[50];
    date date_de_naissance;
    char departement[50];
    float moyenne_general;

}Etudient;

int c=0;
int choise,a,m,j; float n;
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

 void ajouter_etudient(){

     printf("Entrer L'ID  de L'etudient: ");
     scanf("%d",&T[c].id);

     printf("Entrer le nom de L'etudient : ");
     scanf("%[^\n]s",T[c].nom);

     printf("Entrer le Prenom de L'etudient : ");
     scanf("%[^\n]s",T[c].prenom);

     printf("Entrer la date de naissance  de L'etudient: ");
     printf("Entrer l'annee : ");
     scanf("%d",&a);
      do{
         if(a <= 2007){
            T[c].date_de_naissance.annee = a;
            }else {
                printf("L'etudient doit etre +18ans pour entrer a l'universite !");
            }
     }while(a>2007);

     printf("Entrer le mois : ");
     scanf("%d",&m);
      do{
         if(m>=1 && m<=12){
            T[c].date_de_naissance.mois = m;
            }else {
                printf("Le Mois doit etre Entre 1 et 12");
                 scanf("%d",&m);
            }
     }while(m<1 && m>12);

     printf("Entrer le jour : ");
     scanf("%d",&j);
     do{
        if(date_valide(T[c].date_de_naissance.annee,T[c].date_de_naissance.mois,j)){
            T[c].date_de_naissance.jour = j;
            }else {
                printf("Le jour incorrect !");
                 scanf("%d",&j);
            }
     }while(date_valide(T[c].date_de_naissance.annee,T[c].date_de_naissance.mois,j)==0);

     printf("Entrer la departement de L'etudient : 1- Math 2- Informatique 3- Economie 4-Comptabilite ");
     scanf("%d",&choise);

     do{

        if(i==1){
            strcpy(T[c].departement,"Math");
        }
        if(choise == 2){
        strcpy(T[c].departement,"Informatique");
     }
     if (choise == 3){
        strcpy(T[c].departement,"Economie");
     }
     if(choise == 4){
        strcpy(T[c].departement,"Comptabilite");
     }
     else{
        Printf("Entrer un nombre entre 1 et 4 ! \n");
     }

     }while(choise != 1 && choise != 2 && choise != 3 && choise != 1);

        printf("Entrer la note general de l'etudient : ");
        scanf("%f",&n);

        do {
            if(n>=0 && n<=20){
                    T[c].moyenne_general = n;

            }
            else {
                Printf("La moyenne general doit etre entre 0 et 20 !\n");
                scanf("%f",&n);
            }
        }while(n<0 && n>20);


     c++;
 }

 void ajouter_des_etudients(){
   printf("combien de etudient tu veux saisir : ");
   int m;
   scanf("%d",&m);
   for(int i=0;i<m;i++){
    ajouter_etudient();
    }
 }


 void afficher_etudient(int indice){

        printf("L'id d'etudient : %d\n",T[i].id);
        printf("Le nom d'etudient : %s\n",T[i].nom);
        printf("Le prenom d'etudient : %s\n",T[i].prenom);
        printf("La date de naissance d'etudient : %d - %d - %d\n",T[i].date_de_naissance.annee,T[i].date_de_naissance.mois,T[i].date_de_naissance.jour);
        printf("La departement d'etudient : %s\n",T[i].departement);
        printf("La note general d'etudient : %s\n",T[i].moyenne_general);

 }

 void afficher_tout_etudient(){
   for(int i=0;i<c;i++){
     afficher_etudient(i);
   }
 }

void Modifer_etudient(){
     int d;

     printf("Entrer l'id d'etudient a modifier : ");
     scanf("%d",&d);

     for(i=0;i<c;i++){
        if(T[i].id==d){

           printf("Entrer le nouveau id : ");
           scanf("%d",&T[i].id);

           printf("Entrer le nouveau nom : ");
           scanf("%[^\n]s",T[i].nom);

           printf("Entrer le nouveau prenom : ");
           scanf("%[^\n]s",T[i].prenom);

           printf("Entrer le nouvelle sate de naissance : ");
           printf("Entrer l'annee : ");
           scanf("%d",&a);
            do{
              if(a <= 2007){
               T[i].date_de_naissance.annee = a;
                  }else {
                printf("L'etudient doit etre +18ans pour entrer a l'universite !");
                    }
              }while(a>2007);


           printf("Entrer le mois : ");
            scanf("%d",&m);
                do{
                  if(m>=1 && m<=12){
                    T[i].date_de_naissance.mois = m;
                   }else {
                      printf("Le Mois doit etre Entre 1 et 12");
                       scanf("%d",&m);
                     }
                     }while(m<1 && m>12);


           printf("Entrer le jour : ");
            scanf("%d",&j);
                do{
                if(date_valide(T[i].date_de_naissance.annee,T[i].date_de_naissance.mois,j)){
                    T[i].date_de_naissance.jour = j;
                 }else {
                     printf("Le jour incorrect !");
                     scanf("%d",&j);
                        }
                    }while(date_valide(T[i].date_de_naissance.annee,T[i].date_de_naissance.mois,j)==0);


           printf("Entrer la departement de L'etudient : 1- Math 2- Informatique 3- Economie 4-Comptabilite ");
           scanf("%d",&choise);
            do{

             if(i==1){
            strcpy(T[c].departement,"Math");
               }
             if(choise == 2){
             strcpy(T[c].departement,"Informatique");
              }
             if (choise == 3){
             strcpy(T[c].departement,"Economie");
                 }
            if(choise == 4){
             strcpy(T[c].departement,"Comptabilite");
             }
            else{
             Printf("Entrer un nombre entre 1 et 4 ! \n");
             }
           }while(choise != 1 && choise != 2 && choise != 3 && choise != 1);


           printf(" Entrer la nouvelle note general : ");
           scanf("%f",&n);
             do {
            if(n>=0 && n<=20){
                    T[c].moyenne_general = n;

            }
            else {
                Printf("La moyenne general doit etre entre 0 et 20 !\n");
                scanf("%f",&n);
            }
            }while(n<0 && n>20);

        }
     }
}

void supprimer_etudient(){

     int d;
     printf("Entrer l'id d'etudient a modifier : ");
     scanf("%d",&d);
     for(i=0;i<c-1;i++){
        if(T[i].id==d){
                T[i]=T[i+1];
        }
     }
}

void moyene_general_departament(){
    int moyenne_math=0,conteur_math=0,moyenne_informatique=0,conteur_informatique=0;
    int moyenne_economie=0,conteur_economie=0,moyenne_comptabilite=0,conteur_comptabilite=0;
     for(int i=0;i<c;i++){
            if(strcmp(T[i].departement,"Math")==0){
                conteur_math += 1;
                moyenne_math=moyenne_math+T[i].moyenne_general;
            }
            if(strcmp(T[i].departement,"Informatique")==0){
                conteur_informatique += 1;
                moyenne_informatique=moyenne_informatique+T[i].moyenne_general;
            }
            if(strcmp(T[i].departement,"Economie")==0){
                conteur_economie += 1;
                moyenne_economie=moyenne_economie+T[i].moyenne_general;
            }
            if(strcmp(T[i].departement,"Comptabilite")==0){
                conteur_comptabilite += 1;
                moyenne_comptabilite=moyenne_comptabilite+T[i].moyenne_general;
            }

     }
     printf("La moyenne general de la departement de math est %d\n";moyenne_math/conteur_math);
     printf("La moyenne general de la departement de Informatique est %d\n";moyenne_informatique/conteur_informatique);
     printf("La moyenne general de la departement de Economie est %d\n";moyenne_economie/conteur_economie);
     printf("La moyenne general de la departement de Comptabilite est %d\n";moyenne_comptabilite/conteur_comptabilite);
}


int main()
{

    return 0;
}

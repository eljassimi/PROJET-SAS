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
Etudient T[1000];

 void ajouter_etudient(){

     printf("Entrer L'ID  de L'etudient: ");
     scanf("%d",&T[c].id);
     printf("Entrer le nom de L'etudient : ");
     scanf("%[^\n]s",T[c].nom);
     printf("Entrer le Prenom de L'etudient : ");
     scanf("%[^\n]s",T[c].prenom);
     printf("Entrer la date de naissance  de L'etudient: ");
     printf("Entrer l'annee : ");
     scanf("%d",&T[c].date_de_naissance.annee);
     printf("Entrer le mois : ");
     scanf("%d",&T[c].date_de_naissance.mois);
     printf("Entrer le jour : ");
     scanf("%d",&T[c].date_de_naissance.jour);
     printf("Entrer la departement de L'etudient : ");
     scanf("%[^\n]s",T[c].departement);
     printf("Entrer la note general de l'etudient : ");
     scanf("%f",&T[c].moyenne_general);

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
           scanf("%d",&T[i].date_de_naissance.annee);
           printf("Entrer le mois : ");
           scanf("%d",&T[i].date_de_naissance.mois);
           printf("Entrer le jour : ");
           scanf("%d",&T[i].date_de_naissance.jour);

           printf("Entrer la nouvelle departement : ");
           scanf("%[^\n]s",T[i].departement);

           printf(" Entrer la nouvelle note general : ");
           scanf("%f",T[i].moyenne_general);

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










int main()
{

    return 0;
}

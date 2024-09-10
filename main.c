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
     int choise,a,m,j; float n;
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
         if(a<2007){
            T[c].date_de_naissance.annee = a
            }else {
                printf("")

            }


     }while(a>2007)
     scanf("%d",&T[c].date_de_naissance.annee);
     printf("Entrer le mois : ");
     scanf("%d",&T[c].date_de_naissance.mois);
     printf("Entrer le jour : ");
     scanf("%d",&T[c].date_de_naissance.jour);
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
        scanf("%f",&T[c].moyenne_general);

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

    return 0;
}

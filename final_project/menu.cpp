#include<iostream>
#include<string>
#include"menu.h"
#include<iomanip>
using namespace std;


char SaisieReponse()
{
	char rep;
	do{
		cout<<endl<<"Voulez-vous continuer?(Y/N)";
		cin>>rep;
	}while(toupper(rep) != 'Y' && toupper(rep) != 'N');
	cout<<endl<<endl;
	return rep;
}


int menuPrincipal()
{
    int choix;
    cout<<"1. Gestion des formateurs"<<endl;
	cout<<"2. Gestion des formations"<<endl;
    cout<<"3. Gestion des materiels"<<endl;
	cout<<"4. Gestion des salles"<<endl;
	cout<<"5. Gestion des etudiants"<<endl;
	cout<<"6. Planning"<<endl;
	cout<<"7. vider l'ecran"<<endl<<endl;

	//do{
		cin>>choix;
	//}while((choix>7)||(choix<1));
		

	return choix;
}



int menuFormateurs()
{
    int choix;
    cout<<"\t 1. Afficher les formateurs"<<endl;
    cout<<"\t 2. Ajouter un formateur ( formateur responsable )"<<endl;
    cout<<"\t 3. Supprimer un formateur ( formateur responsable )"<<endl;
    cout<<"\t 4. Modifier un formateur ( formateur responsable & formateur)"<<endl;
	cout<<"\t 5. Enregistrer toutes les donnees"<<endl;
	cout<<"\t 6. vider l'ecran"<<endl;

	do{
		cin>>choix;
	}while((choix>6)||(choix<1));

	return choix;
}



int menuSalles()
{
    int choix;
    cout<<"\t 1. Afficher les salles"<<endl;
    cout<<"\t 2. Ajouter une salle( formateur responsable )"<<endl;
    cout<<"\t 3. Supprimer une salle( formateur responsable )"<<endl;
    cout<<"\t 4. Modifier une salle( formateur responsable )"<<endl;
	cout<<"\t 5. Enregistrer toutes les donnees"<<endl;
	cout<<"\t 6. vider l'ecran"<<endl;

	do{
		cin>>choix;
	}while((choix>6)||(choix<1));

	return choix;
}


int menuMateriels(){
    int choix;
    cout<<"\t 1. Afficher les materiels"<<endl;
    cout<<"\t 2. Ajouter un materiel ( formateur responsable ) "<<endl;
    cout<<"\t 3. Supprimer un materiel ( formateur responsable )"<<endl;
    cout<<"\t 4. Modifier un materiel ( formateur responsable )"<<endl;
	cout<<"\t 5. Enregistrer toutes les donnees"<<endl;
	cout<<"\t 6. vider l'ecran"<<endl;

	do{
		cin>>choix;
	}while((choix>6)||(choix<1));

	return choix;
}


int menuFormations(){
    int choix;
    cout<<"\t 1. Ajouter une formations ( formateur )"<<endl;
	cout<<"\t 2. Supprimer une formation ( formateur )"<<endl;
    cout<<"\t 3. Modifier une formation ( formateur )"<<endl;
    cout<<"\t 4. Ajouter du materiel a une formation ( formateur )"<<endl;
    cout<<"\t 5. Supprimer du materiel a une formation ( formateur )"<<endl;
	cout<<"\t 6. Enregistrer toutes les donnees"<<endl;
	cout<<"\t 7. vider l'ecran"<<endl;

	do{
		cin>>choix;
	}while((choix>7)||(choix<1));

	return choix;
}


int menuPlanning()
{
    int choix;
    cout<<"\t 1. Afficher le planning"<<endl;
	do{
		cin>>choix;
	}while(choix!=1);

	return choix;
}


int menuEtudiants()
{
    int choix;
    cout<<"\t 1. Afficher les formation"<<endl;
	cout<<"\t 2. Inscription a une formation"<<endl;
    cout<<"\t 3. Desinscription d'une formation"<<endl;
    cout<<"\t 4. Afficher les etudiants d'une formation"<<endl;
	cout<<"\t 5. Enregistre toutes les donnees"<<endl;
	cout<<"\t 6. vider l'ecran"<<endl;

	do{
		cin>>choix;
	}while((choix>6)||(choix<1));

	return choix;
}
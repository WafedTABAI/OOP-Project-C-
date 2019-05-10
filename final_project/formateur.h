#include<iostream>
#include<string>
#include<vector>
#include"formation.h"

using namespace std;

class formateur
{   public:
	string code;
	int CIN;
	string nom;
	string prenom;
	vector <formation*> tab;  
	bool responsable;
public:

	formateur(void){}
	formateur(const formateur&);
	~formateur();
	void saisir();
	void afficher(salles, materiels);
	//void ajouter(salles&,materiels&); //appele alternativement en formateurs.h pour eviter le conflits d'ID : verification d'ID
	int modifier();
	void supprimer(salles&,materiels&); 	

	//surcharge:
	friend ostream& operator<<(ostream&,formateur&);
	friend ostream& operator<<(ostream&,formateur*);
	friend istream& operator>>(istream&,formateur&);
	friend istream& operator>>(istream&,formateur*);
	void chargement();


	
};
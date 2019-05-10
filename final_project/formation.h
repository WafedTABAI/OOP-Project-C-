#include<iostream>
#include<string>
#include"salles.h"
#include"materiels.h"
#include"etudiant.h"

using namespace std;


class formation
{   public:
    string nom;
	string id;
	
	
	vector<etudiant> tab;
public:
	formation(void){}
	~formation();
	formation(const formation&); 
	bool saisir(salles&, materiels&); 
	void afficher(salles, materiels);
	void afficherjusteformation();
	void ajoutermateriel(salles& , materiels&); 
	void ajouteretudiant(salles);
	void modifier(salles&);  
	void supprimermateriel(materiels&);
	void supprimeretudiant();
	void afficheretudiant();

	// surcharge:
	friend ostream& operator<<(ostream&,formation&);
	friend ostream& operator<<(ostream&,formation*);
	friend istream& operator>>(istream&,formation&);
	friend istream& operator>>(istream&,formation*);

	

	
};
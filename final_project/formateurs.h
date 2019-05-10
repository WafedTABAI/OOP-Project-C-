#include<iostream>
#include<string>
#include<vector>
#include"formateur.h"
using namespace std;

class formateurs
{   public:
	vector <formateur*> tab;
	salles salle;
	materiels mat;

public:
	//formateurs:
	formateurs(void){};
	formateurs(const formateurs&);
	~formateurs();
	
	//menu formateur:
	void afficherformateurs();
	void ajouterformateur(); //formateur responsable
    void modifierformateur();
	void supprimerformateur(); //formateur responsable

	//menu salles:
	void affichersalles(); 
	void ajoutersalle(); //FR
	void supprimersalle(); //FR
	void modifiersalle(); //FR

	//menu materiels
	void affichermateriels();
	void ajoutermateriel(); //FR 
	void supprimermateriel(); //FR
	void modifiermateriel(); //FR

	//menu formation:
	void ajouterformation(); 
	void supprimerformation();
	void modifierformation();
	void ajoutermaterielformation();
	void supprimermaterielformation();
	//void afficherformation();
	

	//menu etudiant:
	void planningformation();
	void ajouteretudiantformation();
	void supprimeretudiantformation(); //etudiant
	void afficheretudiantsformation();

	//menu calendrier:
	void planning();
	bool datevalide(int ,int ,int );
	bool bissextile(int );
	
	
	//surcharge:
	friend ostream& operator<<(ostream&,formateurs&);
	friend ostream& operator<<(ostream&,formateurs*);
	friend istream& operator>>(istream&,formateurs&);
	friend istream& operator>>(istream&,formateurs*);
	void chargement();
	


};
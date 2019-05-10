#include<iostream>
#include<string>
#include<vector>
#include"reservation.h"
using namespace std;

class salle
{
public:
    int num;
	int capacite;
	vector <reservation> tab;

public:
	salle(void){}
	salle(const salle&);
	~salle();
	void saisir();
	void afficher();
	bool ajouter(reservation r);
	int modifier(); //retourne le nouveau num de la salle pour verification dans salles
	void supprimer();

	

	//les setteurs:
	void setreservation( reservation r){ tab.push_back(r);}
	void dessetreservation ( int i) { tab.erase(tab.begin()+i);}
	
	//surcharge:
	friend ostream& operator<<(ostream&,salle&);
	friend istream& operator>>(istream&,salle&);
	friend ostream& operator<<(ostream&,salle*);
	friend istream& operator>>(istream&,salle*);

};



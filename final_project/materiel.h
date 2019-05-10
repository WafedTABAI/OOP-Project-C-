#include<iostream>
#include<string>
#include"reservation.h"
#include<vector>
using namespace std;

class materiel
{    public:

	string nom;
	vector <reservation> tab;  

    public:
		materiel(void){}
		materiel(const materiel&);
		~materiel();
		void saisir();
		void afficher();  
		bool ajouter(reservation r);
		string modifier();
		void supprimer();

	

	//les setteurs:
	void setreservation( reservation r){ tab.push_back(r);}
	void dessetreservation ( int i) { tab.erase(tab.begin()+i);}

	//surcharge:
	friend ostream& operator<<(ostream&,materiel&);
	friend istream& operator>>(istream&,materiel&);
	friend ostream& operator<<(ostream&,materiel*);
	friend istream& operator>>(istream&,materiel*);


};
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include"materiel.h"
using namespace std;

class materiels
{
public:

	vector <materiel*> tab;

public:
	materiels(void){};
	materiels(const materiels&);
	~materiels();
	void afficher();
    void ajouter();
	void modifier();
	void supprimer();

	friend ostream& operator<<(ostream&,materiels&);
	friend ostream& operator<<(ostream&,materiels*);
	friend istream& operator>>(istream&,materiels&);
	friend istream& operator>>(istream&,materiels*);

	void chargement();


};
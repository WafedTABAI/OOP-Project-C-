#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include"salle.h"
using namespace std;

class salles
{
public:
vector <salle*> tab;

public:
	salles(void){};
	salles(const salles&);
	~salles(void);
	void afficher();
    void ajouter();
	void modifier();
	void supprimer();

	//surcharge
	friend ostream& operator<<(ostream&,salles&);
	friend ostream& operator<<(ostream&,salles*);
	friend istream& operator>>(istream&,salles&);
	friend istream& operator>>(istream&,salles*);
	void chargement();

};
#ifndef reservation_H_INCLUDED 
#define reservation_H_INCLUDED
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class reservation

{   
	struct date
{
	int jour;
	int mois;
	int annee;
};
struct heures
{
	int heure;
	int minute;
	
};
public:
	date date;
	heures heuredebut;
	heures heurefin;
	string formation;
    string id;
public:
     
	reservation(void){}
	bool saisir();
	void afficher();
	bool modifier();
	bool reservationvalide(reservation);
	
	bool datevalide(int,int,int);
	bool bissextile(int);
	bool heurevalide(heures,heures);
	friend ostream& operator<< (ostream&,reservation&);
	friend istream& operator>> (istream&,reservation&);

	
};
#endif
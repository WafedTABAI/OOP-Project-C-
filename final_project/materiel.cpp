#include<conio.h>
#include"materiel.h"
#include<iomanip>

materiel::~materiel()
{
tab.clear();
}

materiel::materiel(const materiel& m)


{   
	reservation *r;
	this->nom=m.nom;
	for(unsigned int i=0;i<m.tab.size();i++)
		if(typeid(m.tab[i])==typeid(reservation))
		{
		r=new reservation(m.tab[i]);
		tab.push_back(*r);}
}


void materiel::saisir()
{   bool tr=false;

    do
	{
	cout<< "Donnez le nom du materiel: "<<endl;
	cin>>nom;
	for( unsigned int i=0;i<nom.size();i++)
	{
     if( int(toupper(nom.at(i)) ) >=65 && int(toupper(nom.at(i)) ) <= 90)
		 tr=true;
	 break;
	} 

	if(tr==false) cout<<"Nom de materiel non-valide!"<<endl;
	}
	while(tr==false);

}

void materiel::afficher()
{   
	
	cout<<"Nom du materiel: "<<nom<<endl;

	/*if (tab.size()>0)
	{
	cout<<"Affichage des reservations: "<<endl;
	for(unsigned int i=0;i<tab.size();i++)
	{   cout<<"Reservation "<<i<<": ";
		tab[i].afficher();
	}
	}*/
}
bool materiel::ajouter(reservation r)
{  
	bool tr=true;
	
	cout<<"Ajout d'une reservation: "<<endl;
	
	
	for(unsigned int i=0;i<tab.size();i++)
	{
	if ( r.reservationvalide(tab[i])==false)
	{
		tr=false;
	    cout<<"Ce materiel est deja reserve a cette heure"<<endl;
		break;
	}
	}
	

	if (tr)
	{
		tab.push_back(r);
		cout<<"Ajout de reservation effectue!"<<endl;
	}
	else
	cout<<"Reservation non-effectuee!"<<endl;

	return tr;
}
void materiel::supprimer()
{  
	unsigned int ind;
	if(tab.size()>0)
	{
	cout<<"Donnez l'indice de la reservation a supprimer"<<endl;
	cin>>ind;
	if(ind>=0 && ind<tab.size())
	{
	tab.erase(tab.begin()+ind);
	cout<<"Suppression de reservation effectuee!"<<endl;
	}
	else
	cout<<"Indice non-valide!"<<endl<<"Supression non-effectuee!"<<endl;
	}
	else
		cout<<"Aucune reservation a supprimer!"<<endl;
}





string materiel::modifier()

{   char x;
    bool tr=false;
	cout<<"Voulez-vous modifier le nom du materiel"<<endl<<"(Y/N)?"<<endl;
	cin>>x;
	while ( toupper(x)!='Y' && toupper(x)!='N')
	{
    cout<<"(Y/N)?"<<endl;
	cin>>x;
	}
     
	if (toupper(x)=='Y')
	{   do
	{
		 cout<<"Nom: ";
	cin>>nom;
		for(unsigned int i=0;i<nom.size();i++)
     if( int(toupper(nom.at(i)) ) >=65 && int(toupper(nom.at(i)) ) <= 90)
		 tr=true;
		if(tr==false) cout<<"Nom de materiel non-valide!"<<endl;
	}while ( tr==false);
	}

	
	
		cout<<"Voulez-vous modifier les reservations du materiel"<<endl<<"(Y/N)?"<<endl;
	cin>>x;
	while ( toupper(x)!='Y' && toupper(x)!='N')
	{
    cout<<"(Y/N)?"<<endl;
	cin>>x;
	}
     
	if (toupper(x)=='Y')
	{  
		
	if(tab.size()>0)
	{unsigned int ind;
	for(unsigned int i=0;i<tab.size();i++)
		tab[i].afficher();
	cout<<"Donnez l'indice de la reservation a modifier"<<endl;
	cin>>ind;
	
	if(ind>=0 && ind<tab.size())
	{ reservation r=tab[ind];
	tr=r.modifier();
	if(tr)
	for( unsigned int i=0;i<=tab.size();i++)
	{   if (i==ind) continue;
		if (tab[i].reservationvalide(r)==false)
		   {
         tr=false;
		 break;}
	}
	if (tr) tab[ind]=r;
	else cout<<"Le materiel est deja reserve a cette heure!"<<endl<<"Modification de la reservation non-effectuee!"<<endl;
	}
	else
	{
	cout<<"Indice non-valide!"<<endl<<"Modification non-effectuee!"<<endl;
	
	}
	}
	else
		cout<<"Aucune reservation a modifier!"<<endl;
	}


	
	return nom;

}


// surcharge:
istream& operator>>(istream&  in,materiel& m)
{
	
	bool tr=false;

    do
	{
	cout<< "Donnez le nom du materiel: "<<endl;
	in>>m.nom;
	for( unsigned int i=0;i<m.nom.size();i++)
	{
     if( int(toupper(m.nom.at(i)) ) >=65 && int(toupper(m.nom.at(i)) ) <= 90)
		 tr=true;
	 break;
	} 

	if(tr==false) cout<<"Nom de materiel non-valide!"<<endl;
	}
	while(tr==false);
	return in;
}

ostream& operator<<(ostream& out,materiel& m)
{
	out<<m.nom<<endl;
	return out;
	
}

istream& operator>>(istream&  in,materiel* m)
{
	
 
	in>>m->nom;

	return in;
}

ostream& operator<<(ostream& out,materiel* m)
{
	out<<m->nom<<endl;
	return out;
	
}


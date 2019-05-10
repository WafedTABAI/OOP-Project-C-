#include"salle.h"
#include<iomanip>
#include<typeinfo>

using namespace std;


salle::~salle()
{
tab.clear();
}


salle::salle(const salle &s)
{   
	reservation *r;
	this->num=s.num;
	this->capacite=s.capacite;
	for(unsigned int i=0;i<s.tab.size();i++)
		if(typeid(s.tab[i])==typeid(reservation))
		{
		r=new reservation(s.tab[i]);
		tab.push_back(*r);}
}


void salle::saisir()
{   
	do
	{
	cout<<"Donnez le numero de la salle "<<endl;
	cin>>num;
	 if (num<=0)
       {  cout<<"Numero de salle non-valide!"<<endl;
	   
	   }
	}
	while(num<=0);
	do
	{
	cout<<"Donnez la capacite de la salle"<<endl;
	cin>>capacite;
	 if (capacite<=0)
       {  cout<<"Capacite de salle non-valide!"<<endl;
	  
	   }
	}
	while(capacite<=0);	
	
}


void salle::afficher()
{
	
	cout<<endl<<"Numero de la salle: "<<num<<endl;
	cout<<"Capacite de la salle: "<<capacite<<endl;
	if (tab.size()>0)
	{
	cout<<"Affichage des reservations: "<<endl;
	for(unsigned int i=0;i<tab.size();i++)
	{   cout<<"Reservation "<<i<<": ";
		tab[i].afficher();
	}
	}
	else cout<<"Aucune reservation pour cette salle!"<<endl<<endl;
}


bool salle::ajouter(reservation r)
{   bool tr=true;
      
	cout<<"Ajout d'une reservation: "<<endl;
	
	
	 for(unsigned int i=0;i<tab.size();i++)
	{
	if ( r.reservationvalide(tab[i])==false)
	{
		tr=false;
	    cout<<"La salle est deja reservee a cette heure"<<endl;
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



void salle::supprimer()
{
	
	if(tab.size()>0)
	{unsigned int ind;
	 for(unsigned int i=0;i<tab.size();i++)
		 tab[i].afficher();
	 do
	 {
	cout<<"Donnez l'indice de la reservation a supprimer"<<endl;
	cin>>ind;
	if(ind>=0 && ind<tab.size())
	{
	tab.erase(tab.begin()+ind);
	cout<<"Suppression de reservation effetuee!"<<endl;
	}
	else
	cout<<"Indice non-valide!"<<endl<<"Supression non-effectuee!"<<endl;
	 }while (!(ind>=0 && ind<tab.size()));
	}
	else
		cout<<"Aucune reservation a supprimer!"<<endl;
}



int salle::modifier()

{   char x;
    bool tr=false;
	
	cout<<"Voulez-vous modifier le numero de la salle"<<endl<<"(Y/N)?"<<endl;
	cin>>x;
	while ( toupper(x)!='Y' && toupper(x)!='N')
	{
    cout<<"(Y/N)?"<<endl;
	cin>>x;
	}
     
	if (toupper(x)=='Y')
	{do
	{
    cout<<"Numero: "; 
	cin>>num;
	if(num<=0) cout<<"Numero de salle de valide!"<<endl;
	} while ( num<=0);
	}	
	
	cout<<"Voulez-vous modifier la capacite de la salle"<<endl<<"(Y/N)?"<<endl;
	cin>>x;
	while ( toupper(x)!='Y' && toupper(x)!='N')
	{
    cout<<"(Y/N)?"<<endl;
	cin>>x;
	}
     
	if (toupper(x)=='Y')
	{   do
	{
		 cout<<"Capacite: ";
	cin>>capacite;
	if ( capacite<=0) cout<<"Capacite de salle non-valide!"<<endl;
	}while  ( capacite<=0);
	}
	

	//if( capacite>=0)
	    
		cout<<"Voulez-vous modifier les reservations de la salle"<<endl<<"(Y/N)?"<<endl;
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
	cout<<"Donnez l'indice de la reservation a modifier: "<<endl;
	cin>>ind;
	if(ind>=0 && ind<tab.size())
	{reservation r=tab[ind];
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
	else cout<<"La salle est deja reservee a cette heure!"<<endl<<"Modification de la reservation non-effectuee!"<<endl;
	}
	else
	{
	cout<<"Indice non-valide!"<<endl<<"Modification non-effectuee!"<<endl;
	tr=false;
	}
	}
	else
		cout<<"Aucune reservation a modifier!"<<endl;
	
	}

   return num;

}


ostream& operator<<(ostream& out,salle& s)
{
	out<<setw(10)<<s.num<<setw(10)<<s.capacite<<endl;
	if (s.tab.size()>0)
	{
	out<<"Affichage des reservations: "<<endl;
	for(unsigned int i=0;i<s.tab.size();i++)
	{   cout<<"Reservation "<<i<<": ";
	    out<<s.tab[i];
	}
	}
	return out;


}
istream& operator>>(istream& in,salle* s)
{
	/*do
	{
	cout<<"Donnez le numero de la salle "<<endl;*/
	in>>s->num;
	 /*if (s->num<=0)
       {  cout<<"Numero de salle non-valide!"<<endl;
	   
	   }
	}
	while(s->num<=0);
	do
	{
	cout<<"Donnez la capacite de la salle"<<endl;*/
	in>>s->capacite;
	/* if (s->capacite<=0)
       {  cout<<"Capacite de salle non-valide!"<<endl;
	  
	   }
	}
	while(s->capacite<=0);	*/
	return in;

}
ostream& operator<<(ostream& out,salle* s)
{  
	out<<setw(10)<<s->num<<setw(10)<<s->capacite<<endl;
	
	if (s->tab.size()>0)
	{
	out<<"Affichage des reservations: "<<endl;
	for(unsigned int i=0;i<s->tab.size();i++)
	{   cout<<"Reservation "<<i<<": ";
	    out<<s->tab[i];
	}
	}
	return out;


}
istream& operator>>(istream& in,salle& s)
{
	do
	{
	cout<<"Donnez le numero de la salle "<<endl;
	in>>s.num;
	 if (s.num<=0)
       {  cout<<"Numero de salle non-valide!"<<endl;
	   
	   }
	}
	while(s.num<=0);
	do
	{
	cout<<"Donnez la capacite de la salle"<<endl;
	in>>s.capacite;
	 if (s.capacite<=0)
       {  cout<<"Capacite de salle non-valide!"<<endl;
	  
	   }
	}
	while(s.capacite<=0);	
	return in;

}

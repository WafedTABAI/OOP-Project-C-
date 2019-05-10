#include"formation.h"
#include<iomanip>


formation::~formation(){
	tab.clear();}



formation::formation(const formation& f)
{
	nom=f.nom;
	id=f.id;
	for(unsigned int i=0;i<f.tab.size();i++)
		tab.push_back(f.tab[i]);

}


bool formation::saisir(salles& salle, materiels &mat )
{     char z;
	int x;
	string y;
	bool tr=false;
	bool tr1=true;
	bool tr2=true;
	bool tr3=false;

	reservation r;



	cout<<endl;
	salle.afficher();
	if(salle.tab.size()>0)
	{ tr3=true;
	do
	{
	do
	{
	cout<<"Donnez le numero de la salle a reserver: "<<endl;
	cin>>x;
	for ( unsigned int i=0;i<salle.tab.size();i++)
	  if (x == salle.tab[i]->num)
        { x=i;
		  tr=true;
		  break;
	    }
	  if(tr==false) cout<<"Numero de salle inexistant!"<<endl;
	}
	while (tr==false);
	r.saisir();

	tr1=salle.tab[x]->ajouter(r); //hnai
	if(tr1)
	{
	nom=r.formation;
	id=r.id;
	}
	}
	while( tr1==false);

	mat.afficher();
	if(mat.tab.size()>0)
	{
	tr=false;
	do
	{
	cout<<"Voulez-vous reserver un materiel pour la formation?"<<endl<<"(Y/N)?"<<endl;
	cin>>z;
	while ( toupper(z)!='Y' && toupper(z)!='N')
	{
    cout<<"(Y/N)?"<<endl;
	cin>>z;
	}

	if (toupper(z)=='Y')
	{
	
    do
	{ 
	cout<<"Donnez le nom du materiel a reserver: "<<endl;
	cin>>y;

	tr=false;
	unsigned int i=0;
	while( tr==false && i<mat.tab.size())
	{
		if (y == mat.tab[i]->nom)

         { 
		  tr=true;
		  mat.tab[i]->ajouter(r);
	
		  }
		
		i++;
		
	}
	if(tr==false) cout<<"Materiel inexistant!"<<endl;

	
	} while(tr==false);
	}
	
	
	} while (toupper(z)!='N');
	}
	

	}
	else cout<<"Reservation impossible!";

	
	
	cout<<endl;
	
	return tr3;
}


void formation::afficherjusteformation()
{
	cout<<endl<<"Formation: "<<nom<<endl;
	cout<<"ID: "<<id<<endl;

}
	


void formation::afficher(salles salle, materiels mat)
{   int z=0;
	cout<<endl<<"Formation: "<<nom<<endl;
	cout<<"ID: "<<id<<endl;
	for( unsigned int i=0;i<salle.tab.size();i++)
	for( unsigned int j=0; j<salle.tab[i]->tab.size();j++)
			
			if (salle.tab[i]->tab[j].id== id)
			{ cout<<"Salle reservee: "<<salle.tab[i]->num<<endl;
			  goto etiquette1;
	         }
		
etiquette1:	
	for( unsigned int i=0;i<mat.tab.size();i++)
		for( unsigned int j=0; j<mat.tab[i]->tab.size();j++)
			{if (mat.tab[i]->tab[j].id== id)
			z++;
             }
			if(z>0)
			{   cout<<"Materiel reserve: ";
				for( unsigned int i=0;i<mat.tab.size();i++)
		for( unsigned int j=0; j<mat.tab[i]->tab.size();j++)
			if (mat.tab[i]->tab[j].id== id)
				cout<<mat.tab[i]->nom<<" | ";
			}

			if(z>0) cout<<endl;
			
			for( unsigned int i=0;i<salle.tab.size();i++)
		for( unsigned int j=0; j<salle.tab[i]->tab.size();j++)
			if (salle.tab[i]->tab[j].id== id)
			{ salle.tab[i]->tab[j].afficher();}
			cout<<endl;
  }  
	


void formation::ajoutermateriel(salles& salle, materiels& mat)
{ bool tr,tr1;
int x,t,w;
string y;
char z;
reservation r;

cout<<endl<<"Ajout d'un materiel a reserver: "<<endl;
	mat.afficher();
	for( unsigned int i=0;i<salle.tab.size();i++)
		for( unsigned int j=0; j<salle.tab[i]->tab.size();j++)
			if (salle.tab[i]->tab[j].id== id)
			{ x=i;
	          t=j;
			  goto etiquette1;
	         }
	
etiquette1: 
	r=salle.tab[x]->tab[t];
	
	do
	{
	
	cout<<"Donnez le nom du materiel a reserver: "<<endl;
	cin>>y;
	for ( unsigned int i=0;i<mat.tab.size();i++)
	  if (y == mat.tab[i]->nom)
        { w=i;
		  tr=true;
		  break;
	    }
	  if(tr==false) cout<<"Materiel inexistant!"<<endl;
	  else tr1=mat.tab[w]->ajouter(r);

	  if(tr1==false) cout<<"Materiel deja reserve a cette heure!"<<endl;

	cout<<"Voulez-vous reserver un autre materiel pour la formation?"<<endl<<"(Y/N)?"<<endl;
	cin>>z;
	while ( toupper(z)!='Y' && toupper(z)!='N')
	{
    cout<<"(Y/N)?"<<endl;
	cin>>z;
	}
	}
	while ( toupper(z)!='N');
	cout<<endl;
}



void formation::supprimermateriel(materiels& mat)
{ string y;
int t=0;
bool tr=false;

	cout<<endl;
for( unsigned int i=0;i<mat.tab.size();i++)
		for( unsigned int j=0; j<mat.tab[i]->tab.size();j++)
			{if (mat.tab[i]->tab[j].id== id)
			t++;
             }
		if(t==0) cout<<"Aucun materiel reserve a supprimer!"<<endl;
		else
		{    cout<<"Liste du materiel reserve: ";
			for( unsigned int i=0;i<mat.tab.size();i++)
		for( unsigned int j=0; j<mat.tab[i]->tab.size();j++)
			if (mat.tab[i]->tab[j].id== id)
				cout<<mat.tab[i]->nom<<" | ";

			cout<<endl<<"Donnez le nom du materiel dont vous voulez supprimer la reservation: "<<endl;
			cin>>y;
			 for( unsigned int i=0;i<mat.tab.size();i++)
		for( unsigned int j=0; j<mat.tab[i]->tab.size();j++)
			if (mat.tab[i]->tab[j].id== id && mat.tab[i]->nom==y)
				{tr=true;
			 mat.tab[i]->dessetreservation(j);}
             }
			if(tr==false) cout<<"Aucun materiel de ce nom est reserve!"<<endl;
		}




void formation::modifier(salles& salle)
{bool tr=false;
     
	char x;
	string s;
	reservation r;



	cout<<"Voulez-vous modifier le nom de la formation"<<endl<<"(Y/N)?"<<endl;
	cin>>x;
	while ( toupper(x)!='Y' && toupper(x)!='N')
	{
    cout<<"(Y/N)?"<<endl;
	cin>>x;
	}
	if (toupper(x)=='Y')
	{

	do
	{
	cout<<"Donnez le nouveau nom de la formation: ";
    cin>>s;
	for( unsigned int i=0;i<s.size();i++)
	{
     if( int(toupper(s.at(i)) ) >=65 && int(toupper(s.at(i)) ) <= 90)
		 tr=true;
	 break;
	} 

	if(tr==false) cout<<"Nom de formation non-valide!"<<endl;
	else { nom=s; cout<<"Modification du nom de la formation effectuee!"<<endl; }
	} while (tr==false);
	}

	cout<<"Voulez-vous changer la salle a reserver?"<<endl<<"(Y/N)?"<<endl;
	cin>>x;

	while ( toupper(x)!='Y' && toupper(x)!='N')
	{
    cout<<"(Y/N)?"<<endl;
	cin>>x;
	}
	if (toupper(x)=='Y')
	{   tr=false;
		do
	{
		do
	{
		salle.afficher();
		cout<<"Donnez le numero de la nouvelle salle a reserver: "<<endl;
	cin>>x;
	for ( unsigned int i=0;i<salle.tab.size();i++)
	  if (x == salle.tab[i]->num)
        { x=i;
		  tr=true;
		  break;
	    }
	  if(tr==false) cout<<"Numero de salle inexistant!"<<endl;
	} while ( tr==false);
	 
		  for( unsigned int i=0;i<salle.tab.size();i++)
		for( unsigned int j=0; j<salle.tab[i]->tab.size();j++)
			if (salle.tab[i]->tab[j].id== id)
			{ r=salle.tab[i]->tab[j];
		    
              }
		  for( unsigned int j=0; j<salle.tab[x]->tab.size();j++)
			if ( salle.tab[x]->tab[j].reservationvalide(r) ==false )
				tr=false;

		  if(tr==false) cout<<"Cette salle est deja reservee a cette heure!"<<endl;
		  else 
		  {
			  for( unsigned int i=0;i<salle.tab.size();i++)
		for( unsigned int j=0; j<salle.tab[i]->tab.size();j++)
			if (salle.tab[i]->tab[j].id== id)
			{ 
		     salle.tab[i]->dessetreservation(j);
              }
			salle.tab[x]->setreservation(r);
		  }
	}while ( tr==false);
	}

				
}







void formation::ajouteretudiant(salles salle)

{  etudiant e;
  unsigned int x;
   bool tr=true;
   

   for( unsigned int i=0;i<salle.tab.size();i++)
		for( unsigned int j=0; j<salle.tab[i]->tab.size();j++)
			if (salle.tab[i]->tab[j].id== id)
				x=salle.tab[i]->capacite;
   if ( tab.size()< x)
   {
	   e.saisir();
	    for( unsigned int i=0;i<tab.size();i++)
			if( tab[i].CIN == e.CIN)
			  {	cout<<"Vous etes deja inscrits a cette formation!"<<endl;
		        tr=false;
		     }
		if (tr)
		{
   tab.push_back(e);
   cout<<"Inscription effectuee!"<<endl;
		}
   }

   else cout<<endl<<"Formation pleine, vous ne pouvez plus vous inscrire a cette formation!"<<endl;
   
   

}


void formation::supprimeretudiant()

{  int x,y;
   bool tr=false;
	if(tab.size()>0)
	{
	cout<<"Donnez votre CIN: "<<endl;
	cin>>x;
	cout<<"Donnez votre code: "<<endl;
	cin>>y;

	for(unsigned int i=0;i<tab.size();i++)
		if( tab[i].CIN==x && tab[i].code==y )
	      {  x=i;
			tr=true;
			break;}

	if (tr)
		{tab.erase(tab.begin()+x);
	cout<<"Desinscription effectuee!"<<endl;}
	
	else cout<<"Identifiants incorrectes!"<<endl;
	}
	else cout<<"Aucun inscription n'est faite dans cette formation!"<<endl;

}


void formation::afficheretudiant()
{
	if(tab.size()>0)
	{
		for(unsigned int i=0;i<tab.size();i++)
			tab[i].afficher();

	}
	else cout<<endl<<"Aucun eleve inscrit a cette formation!"<<endl;
}


ostream& operator<<(ostream& out,formation& f)
{   
	out<<setw(10)<<f.nom<<setw(10)<<f.id<<endl;
	
	return out;
}
ostream& operator<<(ostream& out,formation* f)
{   

	out<<setw(10)<<f->nom<<setw(10)<<f->id<<endl;
	return out;
}

istream& operator>>(istream& in ,formation&f)
{
	cout<<" donner le nom de formation"<<endl;
	in>>f.nom;
	cout<<" donner l' ID de la formation"<<endl;
	in>>f.id;
		
		cout<<endl;
	
	
	return in;
}
istream& operator>>(istream& in ,formation*f)
{
	
	in>>f->nom;
	in>>f->id;	
		cout<<endl;
	
	return in;
}


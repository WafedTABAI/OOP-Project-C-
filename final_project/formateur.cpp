#include"formateur.h"
#include<typeinfo>
#include<iomanip>

formateur::formateur(const formateur &f)
{   
	formation* forma;
	this->code=f.code;
	this->nom=f.nom;
	this->prenom=f.prenom;
	for(unsigned int i=0;i<f.tab.size();i++)
		{forma=new formation(*f.tab[i]);
	tab.push_back(forma);}
	this->responsable=responsable;
}	
		
formateur::~formateur()
{
	for(unsigned int i=0;i<tab.size();i++)
	delete tab[i];
	tab.clear();
}


void formateur::afficher(salles salle, materiels mat)
{
	cout<<"Nom : "<<nom<<endl;
	cout<<"Prenom : "<<prenom<<endl;
	cout<<"CIN : "<<CIN<<endl;
	//cout<<"Code: "<<code<<endl;
	
	if(responsable==true) cout <<"Statut: Formateur responsable!"<<endl;
	else cout<<"Statut: Formateur normal!"<<endl;
	if(tab.size()>0)
	{ cout<<"Formations prises en charge: "<<endl;
	for(unsigned int i=0;i<tab.size();i++)
		tab[i]->afficherjusteformation();
	}
	else cout<<"Aucune formation prise en charge!"<<endl;

	cout<<endl;
}
void formateur::saisir()
{   
	
	cout<<"Saisie des informations personnelles: "<<endl;
	cout<<"Nom: "<<endl;
	cin>>nom;
	cout<<"Prenom: "<<endl;
	cin>>prenom;
	/*do
	{*/
	cout<<"CIN: "<<endl;
	cin>>CIN;
	//}while(CIN/10000000==0);
	cout<<"Code d'identification: "<<endl;
	cin>>code;
	
}
/*void formateur::ajouter(salles& salle, materiels& mat)
{

	formation *f=new formation();
	f->saisir(salle,mat);

	tab.push_back(f);
	
}*/
void formateur::supprimer(salles& salle, materiels& mat)
{    int x;
     bool tr=false;
	string s;

	
	
	if(tab.size()>0)
	{
		for( unsigned int i=0;i<tab.size();i++)
		tab[i]->afficher(salle,mat);

	cout<<endl<<"Donnez l'ID de la formation a annuler: "<<endl;
	cin>>s;


	for( unsigned int i=0;i<tab.size();i++)
		if( tab[i]->id==s)
		{x=i;
	     tr=true;
	       break;}

	 if (tr)
	 {      
		 
			 for( unsigned int j=0;j<salle.tab.size();j++)
	           for( unsigned int k=0;k<salle.tab[j]->tab.size();k++)
                       if( salle.tab[j]->tab[k].id==s)
					   {   salle.tab[j]->dessetreservation(k);
						   break;}
			             
						 for( unsigned int j=0;j<mat.tab.size();j++)
	                    for( unsigned int k=0;k<mat.tab[j]->tab.size();k++)
                       if( mat.tab[j]->tab[k].id==s)
					   {   mat.tab[j]->dessetreservation(k);
						   }
					   

						 tab.erase(tab.begin()+x);
	 }
	 else cout<<"ID inexistant!"<<endl;
	}
	else cout<<endl<<"Aucune formation prevue a annuler!"<<endl;
}




int formateur::modifier()
{   string s;
	//int z;
	char x;
	bool tr=false;



	cout<<"Voulez-vous modifier votre nom et prenom?"<<endl<<"(Y/N)?"<<endl;
	cin>>x;
	while ( toupper(x)!='Y' && toupper(x)!='N')
	{
    cout<<"(Y/N)?"<<endl;
	cin>>x;
	}
	if (toupper(x)=='Y')
	{cout<<"Donnez votre nom: "<<endl;
	cin>>nom;
	cout<<"Donnez votre prenom: "<<endl;
	cin>>prenom;
	}


	cout<<"Voulez-vous modifier votre CIN?"<<endl<<"(Y/N)?"<<endl;
	cin>>x;
	while ( toupper(x)!='Y' && toupper(x)!='N')
	{
    cout<<"(Y/N)?"<<endl;
	cin>>x;
	}
	if (toupper(x)=='Y')
	{
	cout<<"Donnez votre nouvelle CIN: "<<endl;
	cin>>CIN;
	}

	cout<<"Voulez-vous modifier votre code d'identification?"<<endl<<"(Y/N)?"<<endl;
	cin>>x;
	while ( toupper(x)!='Y' && toupper(x)!='N')
	{
    cout<<"(Y/N)?"<<endl;
	cin>>x;
	}
	if (toupper(x)=='Y')
	{
      cout<<"Donnez votre nouveau code d'identification: "<<endl;
	  cin>>code;
	}
	/*
	cout<<"Voulez-vous modifier une formation?"<<endl<<"(Y/N)?"<<endl;
	cin>>x;
	while ( toupper(x)!='Y' && toupper(x)!='N')
	{
    cout<<"(Y/N)?"<<endl;
	cin>>x;
	}
	if (toupper(x)=='Y')
	{   if (tab.size()>0)
	{
		for( unsigned int i=0;i<tab.size();i++)
		{
			cout<<"Nom de la formation: "<<tab[i]->nom<<" ID: "<<tab[i]->id<<endl;
			
		}

		cout<<"Donnez l'ID de la formation a modifie: "<<endl;
		cin>>s;

		for( unsigned int i=0;i<tab.size();i++)
		if(tab[i]->id==s)
		   { tr=true;
		      z=i;
			  break;}
		
		if(tr)
			tab[z]->modifier(salle);
		else cout<<"ID inexistante!"<<endl;

	}

	else cout<<"Aucune formation a modifier!"<<endl;
	}*/

	return CIN;

}



ostream& operator<<(ostream& out,formateur&f)
{
	out<<setw(10)<<f.nom<<setw(10)<<f.prenom<<setw(10)<<f.CIN<<setw(10)<<f.code<<endl;
	/*for(unsigned int i=0;i<f.tab.size();i++)
		out<<f.tab[i];
	cout<<endl;*/
	return out;
}

istream& operator>>(istream& in,formateur&f)
{
	
	cout<<"Saisie des informations personnelles: "<<endl;
	cout<<"Donnez votre nom: "<<endl;
	in>>f.nom;
	cout<<"Donnez votre prenom: "<<endl;
	in>>f.prenom;
	cout<<"Donnez votre CIN: "<<endl;
	in>>f.CIN;
	cout<<"Donnez votre code d'identification: "<<endl;
	in>>f.code;
	
	return in;
	
}
istream& operator>>(istream& in,formateur *f)
{
	
	
	in>>f->nom;
	
	in>>f->prenom;
	
	in>>f->CIN;
	
	in>>f->code;
	return in;
	
}

ostream& operator<<(ostream& out,formateur *f)
{
	out<<setw(10)<<f->nom<<setw(10)<<f->prenom<<setw(10)<<f->CIN<<setw(10)<<f->code<<endl;
	/*cout<<setw(10)<<"NOM"<<setw(10)<<"ID"<<endl;
	for(unsigned int i=0;i<f->tab.size();i++)
		out<<f->tab[i];*/
	cout<<endl;
	return out;
}

void formateur::chargement()
{
	ifstream f;
	f.open("d:\\formateur.txt");
	while(1)
	{ 
		formation *m=new formation();
		f>>m;
		if(f.eof()) break;
		this->tab.push_back(m);
		f>>nom;
	    f>>prenom;
	    f>>CIN;
	    f>>code;

		
	}
	
	f.close();
	cout<<"chargement de donnees effectue"<<endl;
}

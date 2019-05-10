#include"materiels.h"
#include<typeinfo>
#include<iomanip>
materiels::materiels(const materiels& ms)
{
	materiel *f;
	for(unsigned int i=0;i<ms.tab.size();i++)
	{if(typeid(*ms.tab[i])==typeid(materiel)){
 	     f=new materiel(*ms.tab[i]);
		 tab.push_back(f);}
	}
}
void materiels::ajouter()
{  bool tr;
	materiel *m=new materiel();
	cout<<"Ajout d'un materiel: "<<endl;
		do
		{tr=true;            //hnaiiiiii*******************
		m->saisir();
	for ( unsigned int i=0;i<tab.size();i++)
	  if (m->nom== tab[i]->nom)
        { 
		  tr=false;
		  break;
	    }

  if(tr)	tab.push_back(m);
  else cout<<"Nom de materiel existant, ajout non-effectue!"<<endl; //hnai************************
		}while(tr==false);
}
void materiels::afficher()
{   if(tab.size()>0)
      {cout<<"Affichage du materiel disponible: "<<endl;
	for(unsigned int i=0;i<tab.size();i++)
		tab[i]->afficher();
       }
else cout<<"Aucun materiel a afficher!"<<endl;
}
void materiels::modifier()
{   unsigned int ind;
    bool tr=false;
    string nm;
	materiel* m;
	cout<<"Donnez le nom du materiel a modifier: "<<endl;
  cin>>nm;
  for ( unsigned int i=0;i<tab.size();i++)
	  if (nm == tab[i]->nom)
        { ind=i;
		  tr=true;
		  break;
	    }
	  
  if(tr)
	  {m= tab[ind];
       m->modifier();
	   for ( unsigned int i=0;i<tab.size();i++)
	   {  if(ind ==i) continue;
	       if ( m->nom==tab[i]->nom)
         { tr=false;
		   break;}
	   }
	   if (tr)
	   { tab[ind]=m;
	     cout<<"Modification effectuee!"<<endl;

	   }
	   else cout<<"Nom de materiel deja existant, modification non-effectuee!"<<endl;

       }
  else cout<<"Materiel inexistant!"<<endl;

}
void materiels::supprimer()
{   int ind;
	bool tr=false;
	string nm;
	cout<<"Donnez le nom du materiel a supprimer: "<<endl;
	cin>>nm;
	for ( unsigned int i=0;i<tab.size();i++)
	  if (nm == tab[i]->nom)
	  {   
		  ind=i;
		  tr=true;
		  break;
	  }
	if(tr) 
	{   cout<<"Le materiel "<<tab[ind]->nom<<" a ete supprime!"<<endl;
			tab.erase(tab.begin()+ind);
	}
	else cout<<"Nom de materiel inexistant!"<<endl;
}

materiels::~materiels()
{
	for(unsigned int i=0;i<tab.size();i++)
	delete tab[i];
	tab.clear();
}



//surcharge
istream& operator>>(istream& in,materiels& ms)
{

	bool tr;
	materiel *m=new materiel();
	cout<<"Ajout d'un materiel: "<<endl;
	do{ tr=true;
		m->saisir();
	for ( unsigned int i=0;i<ms.tab.size();i++)
	  if (m->nom== ms.tab[i]->nom)
        { 
		  tr=false;
		  break;
	    }

  if(tr)	ms.tab.push_back(m);
  else cout<<"Nom de materiel existant, ajout non-effectue!"<<endl;
	} while(tr==false);
  return in;
}
ostream& operator<<(ostream& out,materiels& ms)
{
	
	for(int i=0;i<ms.tab.size();i++)
	{
		out<<*ms.tab[i];
	}
	
		return out;
}
ostream& operator<<(ostream& out,materiels* ms)
{
	
	for(int i=0;i<ms->tab.size();i++)
	{
		out<<*ms->tab[i];
	}

		return out;
}


istream& operator>>(istream& in,materiels* ms)
{   
	bool tr;
	materiel *m=new materiel();
	do{ tr=true;
		in>>*m;
	for ( unsigned int i=0;i<ms->tab.size();i++)
	  if (m->nom== ms->tab[i]->nom)
        { 
		  tr=false;
		  break;
	    }

  if(tr) ms->tab.push_back(m);
	} while(tr==false);

  return in;

}

void materiels::chargement()
{
	ifstream f;
	f.open("d:\\materiels.txt");
	while(1)
	{ 
		materiel *m=new materiel();
		f>>m;
		if(f.eof()) break;
		this->tab.push_back(m);
	}
	f.close();
	cout<<"chargement de donnees materiels effectue!"<<endl;

}
/*void materiels::enregistrer()
{
	ofstream f;
	f.open("d::\\materiels.txt");
	for(int i=0;i<tab.size();i++)
		f<<*tab[i];
	f.close();
	system("cls");
	cout<<"ok bb "<<endl;

}*/
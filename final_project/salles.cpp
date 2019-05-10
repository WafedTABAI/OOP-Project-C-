#include"salles.h"
#include<typeinfo>
#include<iomanip>
salles::salles(const salles& sl)
{
	salle *s;
	for(unsigned int i=0;i<sl.tab.size();i++)
	{if(typeid(*sl.tab[i])==typeid(salle)){
 	     s=new salle(*sl.tab[i]);
		 tab.push_back(s);}
    }
}



void salles::ajouter()
{  bool tr=true;
	salle *s=new salle();
	    cout<<"Ajout d'une salle: "<<endl;
		s->saisir();
		for ( unsigned int i=0;i<tab.size();i++)
	  if (s->num == tab[i]->num)
        { 
		  tr=false;
		  break;
	    }

  if(tr)	tab.push_back(s);
  else cout<<"Numero de salle existant, ajout non-effectue!"<<endl;
}


void salles::afficher()
{   if (tab.size()>0)
{   cout<<"Affichage des salles disponibles: "<<endl;
	for(unsigned int i=0;i<tab.size();i++)
		tab[i]->afficher();
}
else cout<<"Aucune salle a afficher!"<<endl;
}



void salles::modifier()
{ unsigned int ind;
bool tr=false;
salle* s;
	/*salle *s=new salle();
	for(unsigned int i=0;i<tab.size();i++)
		s->modifier();*/
  cout<<"Donnez le numero de la salle a modifier: "<<endl;
  cin>>ind;
  for ( unsigned int i=0;i<tab.size();i++)
	  if (ind == tab[i]->num)
        { ind=i;
		  tr=true;
		  break;
	    }
	  
  if(tr)
	  {
		  s=tab[ind];
           s->modifier();
	      for ( unsigned int i=0;i<tab.size();i++)
	     {if (ind == i) continue;
	      if( s->num==tab[i]->num)
			{  tr=false;
		  break;}
	      }
      if(tr) 
		  {tab[ind]=s;
	  cout<<"Modification effectuee!"<<endl;}
	  else cout<<"Numero de salle deja existant, modification non-effectuee!"<<endl;
      }

  else cout<<"Numero de salle inexistant!"<<endl;

}


void salles::supprimer()
{   bool tr=false;
	unsigned int ind;
	cout<<"Donnez le numero de la salle a supprimer: "<<endl;
	cin>>ind;
	for ( unsigned int i=0;i<tab.size();i++)
	  if (ind == tab[i]->num)
	  {   ind=i;
		  tr=true;
		  break;
	  }
	if(tr) 
	{   cout<<"Salle numero "<<tab[ind]->num<<" supprimee!"<<endl;
			tab.erase(tab.begin()+ind);
	}
	else cout<<"Numero de salle inexistant!"<<endl;
}



salles::~salles()
{
	for(unsigned int i=0;i<tab.size();i++)
	delete tab[i];
	tab.clear();
}


/*void salles::enregistrementsalles(salles s)

{         

   s.settab(gettab());
	

}*/




ostream& operator<<(ostream& out,salles& sls)
{  
	cout<<setw(10)<<"NUM"<<setw(10)<<"Capacite"<<endl;
	for(int i=0;i<sls.tab.size();i++)
	{
		out<<*sls.tab[i];
	}
	
		return out;

}
ostream& operator<<(ostream& out,salles* sls)
{
	for(int i=0;i<sls->tab.size();i++)
	{
		out<<*sls->tab[i];
	}
	
		return out;

}


istream& operator>>(istream& in,salles& sls)
{ 
	bool tr=true;
	salle *s=new salle();
	    cout<<"Ajout d'une salle: "<<endl;
		in>>*s;
		for ( unsigned int i=0;i<sls.tab.size();i++)
	  if (s->num == sls.tab[i]->num)
        { 
		  tr=false;
		  break;
	    }

  if(tr)	sls.tab.push_back(s);
  else cout<<"Numero de salle existant, ajout non-effectue!"<<endl;
  return in;
	
}
istream& operator>>(istream& in,salles* sls)
{ 
	bool tr=true;
	salle *s=new salle();
		in>>*s;
		for ( unsigned int i=0;i<sls->tab.size();i++)
	  if (s->num == sls->tab[i]->num)
        { 
		  tr=false;
		  break;
	    }

  if(tr)	sls->tab.push_back(s);
  return in;
	
}

void salles::chargement()
{
	ifstream f;
	f.open("d:\\salles.txt");
	while(1)
	{ 
		salle *m=new salle();
		f>>m;
		if(f.eof()) break;
		this->tab.push_back(m);
	}
	f.close();
	cout<<"chargement de donnees salles effectue!"<<endl;

}


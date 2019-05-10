#include"formateurs.h"
#include<iomanip>


formateurs::formateurs(const formateurs& fs)
{
	formateur *f;
	cout<<endl;
	for(unsigned int i=0;i<fs.tab.size();i++)
 	   {  f=new formateur(*fs.tab[i]);
	      tab.push_back(f);
	}
}

formateurs::~formateurs()
{
	cout<<endl;
for(unsigned int i=0;i<tab.size();i++)
	delete tab[i];
	tab.clear();

}


void formateurs::ajouterformateur()
{  bool tr=true,tr1=false;
  formateur *f=new formateur();
	string s;
	int x;
  cout<<endl;
  
  if(tab.size()==0)
	{
	         cout<<"Ajout d'un formateur: "<<endl;
		           f->saisir();
				   f->responsable=true;
				   tab.push_back(f);
				   cout<<endl<<"Ajout de formateur effectue!"<<endl;//hedhi*************************
			   
    }
	

	else 
	{  
	   cout<<"Verification du statut responsable: "<<endl;
	   cout<<"Donnez votre CIN: "<<endl;
	   cin>>x;
	   cout<<"Donnez votre code d'identification: "<<endl;
	   cin>>s;
	   for(unsigned int i=0;i<tab.size();i++)
		if(tab[i]->CIN==x && tab[i]->code==s )
		{ x=i; 
	      tr1=true;
		  break;
	    }
	   if(tr1)
	   { if (tab[x]->responsable)
	     {cout<<"Statut responsable confirme!"<<endl;
	   cout<<"Bienvenue: "<<tab[x]->prenom<<" "<<tab[x]->nom<<"!"<<endl;
	      cout<<"Ajout d'un formateur: "<<endl;
	      f->saisir();
		  for(unsigned int i=0;i<tab.size();i++)
			if(tab[i]->CIN==f->CIN)
				tr=false;
		       if(tr==false)
			   cout<<"CIN deja existante, Ajout non-effectue!"<<endl;
			   else
			   {cout<<"Ajout de formateur effectue!"<<endl; //hedhi***********************
			   f->responsable=false;
	            tab.push_back(f);
			    
			   }
	      } 
	   else cout<<"Vous n'etes pas autorise a faire cela!"<<endl;
	   }
	   else cout<<endl<<"Identifiants incorrectes!"<<endl; 
  }
	cout<<endl;
}
void formateurs::afficherformateurs()
{   cout<<endl;
	if(tab.size()>0)
	{
	cout<<"Affichage des formateurs: "<<endl<<endl;
	for(unsigned int i=0;i<tab.size();i++)
		tab[i]->afficher(salle, mat);}
	else cout<<endl<<"Aucun formateur n'est enrigistre!"<<endl;
}


void formateurs::modifierformateur()
{  int x;
   bool tr=false;
   string s;
   formateur* f;
	cout<<endl;
    cout<<"Verification du statut formateur: "<<endl;
	cout<<"Donnez votre CIN: "<<endl;
	cin>>x;
	cout<<"Donnez votre code d'identification: "<<endl;
	cin>>s;

	for(unsigned int i=0;i<tab.size();i++)
		if(tab[i]->CIN==x && tab[i]->code==s )
		{ x=i; 
	      tr=true;
		  break;
	    }

	if(tr)
	{   cout<<"Bienvenue: "<<tab[x]->prenom<<" "<<tab[x]->nom<<"!"<<endl;
		f=tab[x];
	    f->modifier();
		for(unsigned int i=0;i<tab.size();i++)
		{
			if ( i==x) continue;
			if(f->CIN==tab[i]->CIN)
				tr=false;
		}
		if(tr==false) cout<<"CIN deja existante, modification non-effectuee!"<<endl;
		else tab[x]=f;
	}
	else
		cout<<endl<<"Identifiants incorrectes!"<<endl;
	      

}
void formateurs::supprimerformateur()
{ int x;
  bool tr=false,tr1=false;
  string s;
  cout<<endl;
	   cout<<"Verification du statut responsable: "<<endl;
	   cout<<"Donnez votre CIN: "<<endl;
	   cin>>x;
	   cout<<"Donnez votre code d'identification: "<<endl;
	   cin>>s;
	   for(unsigned int i=0;i<tab.size();i++)
		if(tab[i]->CIN==x && tab[i]->code==s )
		{ x=i; 
	      tr1=true;
		  break;
	    }
	   if(tr1)
	   { if (tab[x]->responsable)
	     {cout<<"Statut responsable confirme!"<<endl;
	     cout<<"Bienvenue: "<<tab[x]->prenom<<" "<<tab[x]->nom<<"!"<<endl;
	      cout<<"Ajout d'un formateur: "<<endl;

	      cout<<"Donnez la CIN du formateur a supprimer!"<<endl;
	       cin>>x;

	     for(unsigned int i=0;i<tab.size();i++)
		if(tab[i]->CIN==x)
		{ x=i; 
	      tr=true;
		  break;
	    }

	if(tr)
	{ if(tab[x]->tab.size()>0)
	{   
	     for(unsigned int j=0;j<tab[x]->tab.size();j++)
		 {
			 s=tab[x]->tab[j]->id;
			 for( unsigned int i=0;i<salle.tab.size();i++)
				 for(unsigned int k=0;k<salle.tab[i]->tab.size();k++)
				 if(salle.tab[i]->tab[k].id==s)
					 salle.tab[i]->dessetreservation(k);

			 for( unsigned int i=0;i<mat.tab.size();i++)
				 for(unsigned int k=0;k<mat.tab[i]->tab.size();k++)
				 if(mat.tab[i]->tab[k].id==s)
					 mat.tab[i]->dessetreservation(k);
		 }


		
	}
	tab.erase(tab.begin()+x);
	cout<<"Suppression du formateur et ses formations effectuee!"<<endl;
	}
	else
		cout<<"CIN inexistante!"<<endl;
	}
       else cout<<"Vous n'etes pas autorise a faire cela!"<<endl;
	   }
	   else cout<<endl<<"Identifiants incorrectes!"<<endl; 
  
	cout<<endl;
}


/*void formateurs::chargementsalles(salles s)

{
	for( unsigned int i=0;i<tab.size();i++)
		for ( unsigned int j=0;j<tab[i]->tab.size();j++)
			tab[i]->tab[j]->salle(s);

}*/




//menu:


void formateurs::ajoutersalle()
{  int x;
   string s;
   bool tr=false,tr1=false;
    cout<<endl;
   cout<<"Verification du statut responsable: "<<endl;
	   cout<<"Donnez votre CIN: "<<endl;
	   cin>>x;
	   cout<<"Donnez votre code d'identification: "<<endl;
	   cin>>s;
	   for(unsigned int i=0;i<tab.size();i++)
		if(tab[i]->CIN==x && tab[i]->code==s )
		{ x=i; 
	      tr1=true;
		  break;
	    }
	   if(tr1) 
	{ if (tab[x]->responsable)
	     {cout<<"Statut responsable confirme!"<<endl;
	     cout<<"Bienvenue: "<<tab[x]->prenom<<" "<<tab[x]->nom<<"!"<<endl;
		
	   salle.ajouter();}
	  			
	else cout<<"Vous n'etes pas autorise a faire cela!"<<endl;
	   }
	   else cout<<endl<<"Identifiants incorrectes!"<<endl; 
  
	cout<<endl;
}

void formateurs::affichersalles()
{cout<<endl;
	salle.afficher();

}


void formateurs::ajouterformation()
{   
	int x;
   string s;
   bool tr=false,tr1=false;

   cout<<endl;
    cout<<"Verification du statut formateur: "<<endl;
	cout<<"Donnez votre CIN: "<<endl;
	cin>>x;
	cout<<"Donnez votre code d'identification: "<<endl;
	cin>>s;

	for(unsigned int i=0;i<tab.size();i++)
		if( tab[i]->CIN==x && tab[i]->code==s)
			{ x=i;
	          tr=true;
			  break;
	        }

	if(tr)
	{   cout<<"Statut formateur confirme!"<<endl;
	     cout<<"Bienvenue: "<<tab[x]->prenom<<" "<<tab[x]->nom<<"!"<<endl;
		formation *f=new formation();
	tr1=f->saisir(salle,mat);
	if(tr1)
	{
	for(unsigned int i=0;i<tab.size();i++)
		for(unsigned int j=0;j<tab[i]->tab.size();j++)
			if (f->id == tab[i]->tab[j]->id)
				{tr=false;
	            break;
	            }
	 if(tr) {  tab[x]->tab.push_back(f);
	           cout<<"Ajout de la formation effectue!"<<endl;
	    } 
	 else {cout<<"ID de formation deja existant, ajout non-effectue!"<<endl;	

	 for(unsigned int i=0;i<salle.tab.size();i++)
		for(unsigned int j=0;j<salle.tab[i]->tab.size();j++)
			if (f->id == salle.tab[i]->tab[j].id)
				salle.tab[i]->tab.pop_back();
	 }
	}
}
else cout<<endl<<"Identifiants incorrectes!"<<endl;

}

void formateurs::supprimerformation()
{
	int x;
    string s;
    bool tr=false;
	cout<<endl;
    cout<<"Verification du statut formateur: "<<endl;
	cout<<"Donnez votre CIN: "<<endl;
	cin>>x;
	cout<<"Donnez votre code d'identification: "<<endl;
	cin>>s;

	for(unsigned int i=0;i<tab.size();i++)
		if( tab[i]->CIN==x && tab[i]->code==s)
			{ x=i;
	          tr=true;
			  break;
	        }

	if(tr)
	{   cout<<"Statut formateur confirme!"<<endl;
	     cout<<"Bienvenue: "<<tab[x]->prenom<<" "<<tab[x]->nom<<"!"<<endl;
	    tab[x]->supprimer(salle,mat);

    }

	else cout<<endl<<"Identifiants incorrectes!"<<endl;
}


void formateurs::modifierformation()
{
	int x,y;
    string s;
    bool tr=false,tr1=false;
	cout<<endl;
    cout<<"Verification du statut formateur: "<<endl;
	cout<<"Donnez votre CIN: "<<endl;
	cin>>x;
	cout<<"Donnez votre code d'identification: "<<endl;
	cin>>s;

	for(unsigned int i=0;i<tab.size();i++)
		if( tab[i]->CIN==x && tab[i]->code==s)
			{ x=i;
	          tr=true;
			  break;
	        }

	if(tr)
	{   cout<<"Statut formateur confirme!"<<endl;
	     cout<<"Bienvenue: "<<tab[x]->prenom<<" "<<tab[x]->nom<<"!"<<endl;
		 if(tab[x]->tab.size()>0)
		 {   
			 for(unsigned int i=0;i<tab[x]->tab.size();i++)
				 tab[x]->tab[i]->afficher(salle,mat);

			 cout<<"Donnez l'ID de la formation a modifier: "<<endl;
		     cin>>s;
             
			 for(unsigned int i=0;i<tab[x]->tab.size();i++)
				 if(tab[x]->tab[i]->id==s)
				 {tr1=true;
			        y=i;
					break;
				 }

			 if(tr1) { tab[x]->tab[y]->modifier(salle);}
			 else cout<<"ID inexistant!"<<endl;
					 
		 }

	}
	else cout<<endl<<"Identifiants incorrectes!!"<<endl;

}






void formateurs::ajoutermateriel()
{

	int x;
   string s;
   bool tr=false;
   cout<<endl;
  
    cout<<"Verification du statut responsable: "<<endl;
	cout<<"Donnez votre CIN: "<<endl;
	cin>>x;
	cout<<"Donnez votre code d'identification: "<<endl;
	cin>>s;

	for(unsigned int i=0;i<tab.size();i++)
		if( tab[i]->CIN==x && tab[i]->code==s)
			{ x=i;
	          tr=true;
			  break;
	        }

	if(tr) 
	{ if (tab[x]->responsable)
	     {cout<<"Statut responsable confirme!"<<endl;
		   cout<<"Bienvenue: "<<tab[x]->prenom<<" "<<tab[x]->nom<<"!"<<endl;
	      mat.ajouter();}
			else cout<<"Vous n'etes pas autorise a faire cela!"<<endl;	
	}
	else cout<<endl<<"Identifiants incorrectes!"<<endl;
}

void formateurs::affichermateriels()
{cout<<endl;
	mat.afficher();
}

void formateurs::supprimersalle()
{

	int x;
   string s;
   bool tr=false;
  
   cout<<endl;
	 cout<<"Verification du statut responsable: "<<endl;
	cout<<"Donnez votre CIN: "<<endl;
	cin>>x;
	cout<<"Donnez votre code d'identification: "<<endl;
	cin>>s;

	for(unsigned int i=0;i<tab.size();i++)
		if( tab[i]->CIN==x && tab[i]->code==s)
			{ x=i;
	          tr=true;
			  break;
	        }

	if(tr) 
	{ if (tab[x]->responsable)
	     {cout<<"Statut responsable confirme!"<<endl;
		   cout<<"Bienvenue: "<<tab[x]->prenom<<" "<<tab[x]->nom<<"!"<<endl;
	salle.supprimer();}
		else cout<<"Vous n'etes pas autorise a faire cela!"<<endl;			
	}
	else cout<<endl<<"Identififants incorrectes!"<<endl;
}


void formateurs::supprimermateriel()
{
   int x;
   string s;
   bool tr=false;
  
   cout<<endl;
	cout<<"Verification du statut responsable: "<<endl;
	cout<<"Donnez votre CIN: "<<endl;
	cin>>x;
	cout<<"Donnez votre code d'identification: "<<endl;
	cin>>s;

	for(unsigned int i=0;i<tab.size();i++)
		if( tab[i]->CIN==x && tab[i]->code==s)
			{ x=i;
	          tr=true;
			  break;
	        }

	if(tr) 
	{ if (tab[x]->responsable)
	     {cout<<"Statut responsable confirme!"<<endl;
		  cout<<"Bienvenue: "<<tab[x]->prenom<<" "<<tab[x]->nom<<"!"<<endl;
		
	mat.supprimer();}
				
	else cout<<"Vous n'etes pas autorise a faire cela!"<<endl;			
	}
	else cout<<endl<<"Identififants incorrectes!"<<endl;
}


void formateurs::modifiersalle()
{
	int x;
   string s;
   bool tr=false;
  cout<<endl;

	cout<<"Verification du statut responsable: "<<endl;
	cout<<"Donnez votre CIN: "<<endl;
	cin>>x;
	cout<<"Donnez votre code d'identification: "<<endl;
	cin>>s;

	for(unsigned int i=0;i<tab.size();i++)
		if( tab[i]->CIN==x && tab[i]->code==s)
			{ x=i;
	          tr=true;
			  break;
	        }

	if(tr) 
	{ if (tab[x]->responsable)
	     {cout<<"Statut responsable confirme!"<<endl;
		  cout<<"Bienvenue: "<<tab[x]->prenom<<" "<<tab[x]->nom<<"!"<<endl;
		
	salle.modifier();}
				
	else cout<<"Vous n'etes pas autorise a faire cela!"<<endl;			
	}
	else cout<<endl<<"Identififants incorrectes!"<<endl;
}

void formateurs::modifiermateriel()
{
   int x;
   string s;
   bool tr=false;
  cout<<endl;

	cout<<"Verification du statut responsable: "<<endl;
	cout<<"Donnez votre CIN: "<<endl;
	cin>>x;
	cout<<"Donnez votre code d'identification: "<<endl;
	cin>>s;

	for(unsigned int i=0;i<tab.size();i++)
		if( tab[i]->CIN==x && tab[i]->code==s)
			{ x=i;
	          tr=true;
			  break;
	        }

	if(tr) 
	{ if (tab[x]->responsable)
	     {cout<<"Statut responsable confirme!"<<endl;
	      cout<<"Bienvenue: "<<tab[x]->prenom<<" "<<tab[x]->nom<<"!"<<endl;
	mat.modifier();}
	else cout<<"Vous n'etes pas autorise a faire cela!"<<endl;			
	}
	else cout<<endl<<"Identififants incorrectes!"<<endl;
}


//formation :

void formateurs::ajoutermaterielformation()
{
	int x,z;
   string s,c;
   bool tr=false,tr1=false;
  
   cout<<endl;
	cout<<"Verification du statut formateur: "<<endl;
	cout<<"Donnez votre CIN: "<<endl;
	cin>>x;
	cout<<"Donnez votre code d'identification: "<<endl;
	cin>>s;

	for(unsigned int i=0;i<tab.size();i++)
		if( tab[i]->CIN==x && tab[i]->code==s)
			{ x=i;
	          tr=true;
			  break;
	        }

	if(tr)
	{   cout<<"Statut formateur confirmé!"<<endl;	
	     cout<<"Bienvenue: "<<tab[x]->prenom<<" "<<tab[x]->nom<<"!"<<endl;
		if(tab[x]->tab.size()>0)
		{ 
			for(unsigned int i=0;i<tab[x]->tab.size();i++)
				 tab[x]->tab[i]->afficher(salle,mat);

			do
			{
			cout<<"Donnez l'ID de la formation a la quelle vous voulez ajouter du materiel: "<<endl;
		cin>>c;

		for( unsigned int i=0;i<tab[x]->tab.size();i++)
		if(tab[x]->tab[i]->id==c)
		   { tr1=true;
		      z=i;
			  break;}
		
		if(tr1)
		{
			tab[x]->tab[z]->ajoutermateriel(salle,mat);
		}
		else cout<<"ID inexistant!"<<endl;
			}while(tr1==false);
	}

	}

	else cout<<endl<<"Identififants incorrectes!"<<endl;
}

void formateurs::supprimermaterielformation()
{
	int x,z;
   string s,c;
   bool tr=false,tr1=false;
  cout<<endl;

	cout<<"Verification du statut formateur: "<<endl;
	cout<<"Donnez votre CIN: "<<endl;
	cin>>x;
	cout<<"Donnez votre code d'identification: "<<endl;
	cin>>s;

	for(unsigned int i=0;i<tab.size();i++)
		if( tab[i]->CIN==x && tab[i]->code==s)
			{ x=i;
	          tr=true;
			  break;
	        }

	if(tr)
		{   cout<<"Statut formateur confirmé!"<<endl;	
	        cout<<"Bienvenue: "<<tab[x]->prenom<<" "<<tab[x]->nom<<"!"<<endl;
		if(tab[x]->tab.size()>0)
		{ 
			for(unsigned int i=0;i<tab[x]->tab.size();i++)
				 tab[x]->tab[i]->afficher(salle,mat);
			do
			{
			cout<<"Donnez l'ID de la formation a la quelle vous voulez ajouter du materiel: "<<endl;
		cin>>c;

		for( unsigned int i=0;i<tab[x]->tab.size();i++)
		if(tab[x]->tab[i]->id==c)
		   { tr1=true;
		      z=i;
			  break;}
		
		if(tr1)
		{
			tab[x]->tab[z]->supprimermateriel(mat);
		}
		else cout<<"ID inexistante!"<<endl;
			}while(tr1==false);
	}

	}

	else cout<<endl<<"Identififants incorrectes!"<<endl;

}

void formateurs::afficheretudiantsformation()
{
	string s;
bool tr=false;
int x,y,b=0;
cout<<endl;
       for(unsigned int i=0;i<tab.size();i++)
		   for(unsigned int j=0;j<tab[i]->tab.size();j++)
			  { tab[i]->tab[j]->afficher(salle,mat);
	            b++;}

	   if(b>0)
	   {
	cout<<"Donnez l'ID de la formation dont vous voulez afficher les etudiants inscrits: "<<endl;
	cin>>s;
	for(unsigned int i=0;i<tab.size();i++)
		for( unsigned int j=0;j<tab[i]->tab.size();j++)
			if(tab[i]->tab[j]->id==s)
			{   x=i;
	            y=j;
				tr=true;
				break;
			} 
	if(tr) tab[x]->tab[y]->afficheretudiant();
	else cout<<"ID de formation inexistant!"<<endl;
	   }
	   else cout<<endl<<"Aucune formation prevue!"<<endl;
}

void formateurs::ajouteretudiantformation()
{string s;
bool tr=false;
int x,y,b=0;

           for(unsigned int i=0;i<tab.size();i++)
		   for(unsigned int j=0;j<tab[i]->tab.size();j++)
			  {
		        if(tab[i]->tab.size()>0){ b++;
				cout<<"Affichage des formations disponible: "<<endl;} //hnai***************************************
					 tab[i]->tab[j]->afficherjusteformation();
					 cout<<endl;
		      }
		   if(b>0)
		   {

	cout<<"Donnez l'ID de la formation a la quelle vous voulez vous inscrire: "<<endl;
	cin>>s;

	for(unsigned int i=0;i<tab.size();i++)
		for( unsigned int j=0;j<tab[i]->tab.size();j++)
			if(tab[i]->tab[j]->id==s)
			{   x=i;
	            y=j;
				tr=true;
				break;
			} 
	if(tr) tab[x]->tab[y]->ajouteretudiant(salle);
	else cout<<"ID de formation inexistant!"<<endl;
		   }
		   else cout<<endl<<"Aucune formation prevue!"<<endl;
}

void formateurs::supprimeretudiantformation()
{

	string s;
bool tr=false,tr1=false;;
int x,y,w;
cout<<endl;
    cout<<"Donnez votre CIN: "<<endl;
	cin>>w;
	for(unsigned int i=0;i<tab.size();i++)
		for( unsigned int j=0;j<tab[i]->tab.size();j++)
         for( unsigned int k=0;k<tab[i]->tab[j]->tab.size();k++)
			 if(tab[i]->tab[j]->tab[k].CIN==w)
				 tr1=true;

	if(tr1)
	{   cout<<"Liste des formations dont vous etes inscrits:"<<endl;
		for(unsigned int i=0;i<tab.size();i++)
		for( unsigned int j=0;j<tab[i]->tab.size();j++)
         for( unsigned int k=0;k<tab[i]->tab[j]->tab.size();k++)
			 if(tab[i]->tab[j]->tab[k].CIN==w)
				 tab[i]->tab[j]->afficherjusteformation();

	cout<<"Donnez l'ID de la formation a la quelle vous voulez vous desinscrire: "<<endl;
	cin>>s;

	for(unsigned int i=0;i<tab.size();i++)
		for( unsigned int j=0;j<tab[i]->tab.size();j++)
			if(tab[i]->tab[j]->id==s)
			{   x=i;
	            y=j;
				tr=true;
				break;
			} 
	if(tr) tab[x]->tab[y]->supprimeretudiant();
	else cout<<"ID de formation inexistante!"<<endl;
	}

	else cout<<endl<<"Vous n'etes inscrits dans aucune formation!"<<endl;
}


void formateurs::planning()
{
	int x;
     int a,m,j;
	 int z;
	 bool tr;
	 cout<<endl;
	 cout<<"Vous voulez afficher le planning de: "<<endl;
	 cout<<"1:Une annee - 2: Un mois - 3:Un jour"<<endl;
	 cin>>x;

	 switch(x)
	 {

	 case 1: { do
			 {
		        tr=true;
		       cout<<"Donnez l'annee dont vous voulez afficher le planning: "<<endl;
		       cin>>a;
			   if (a > 9999 || a < 2018)
			   {  cout<<"Annee non valide!"<<endl;
				   tr=false;
			   }
			 }while(tr==false);
			   z=0;
			    for( unsigned int i=0;i<salle.tab.size();i++)
		         for( unsigned int j=0; j<salle.tab[i]->tab.size();j++)
			        if (salle.tab[i]->tab[j].date.annee==a)
					{ for( unsigned int k=0;k<tab.size();k++)
		                for( unsigned int w=0; w<tab[k]->tab.size();w++)
							if(tab[k]->tab[w]->id==salle.tab[i]->tab[j].id)
					         cout<<endl<<"Formateur:"<<tab[k]->nom<<" "<<tab[k]->prenom<<endl;
						
					  cout<<"Salle: "<<salle.tab[i]->num<<" | ";
				      salle.tab[i]->tab[j].afficher();
					  z++;
					}
				if(z==0) cout<<endl<<"Aucune formation prevue pour cette annee!"<<endl;

			 } break;
    
	 case 2: {  do
			 {
		        tr=true;
		       cout<<"Donnez l'annee dont vous voulez afficher le planning: "<<endl;
		       cin>>a;
			   if (a > 9999 || a < 2018)
			   {  cout<<"Annee non-valide!"<<endl;
				   tr=false;
			   }
			 }while(tr==false);
			 do
			 {
		        tr=true;
		      cout<<"Donnez le mois dont vous voulez afficher le planning: "<<endl;
		       cin>>m;
			   if (m> 12 || m < 1)
			   {  cout<<"Mois non-valide!"<<endl;
				   tr=false;
			   }
			 }while(tr==false);
			   
			   z=0;
		  for( unsigned int i=0;i<salle.tab.size();i++)
		         for( unsigned int j=0; j<salle.tab[i]->tab.size();j++)
			        if (salle.tab[i]->tab[j].date.annee==a && salle.tab[i]->tab[j].date.mois==m)
					{ for( unsigned int k=0;k<tab.size();k++)
		                for( unsigned int w=0; w<tab[k]->tab.size();w++)
							if(tab[k]->tab[w]->id==salle.tab[i]->tab[j].id)
					         cout<<endl<<"Formateur:"<<tab[k]->nom<<" "<<tab[k]->prenom<<endl;
						
						
						cout<<"Salle: "<<salle.tab[i]->num;
				      salle.tab[i]->tab[j].afficher();
					  z++;
					}
				if(z==0) cout<<endl<<"Aucune formation prevue pour ce mois!"<<endl;

		        
			 }break;
       
	case 3:
		{   do
		{
			tr=true;
			cout<<"Donnez l'annee dont vous voulez afficher le planning: "<<endl;
		       cin>>a;
			   cout<<"Donnez le mois dont vous voulez afficher le planning: "<<endl; // manque juste la validite de la date!
		       cin>>m;
			   cout<<"Donnez le jour dont vous voulez afficher le planning: "<<endl;
		       cin>>j;
			   tr=datevalide(j,m,a);
			   if(tr==false) cout<<"Date non-valide!"<<endl;
		} while(tr==false);
			   z=0;
		  for( unsigned int i=0;i<salle.tab.size();i++)
		         for( unsigned int j=0; j<salle.tab[i]->tab.size();j++)
			        if (salle.tab[i]->tab[j].date.annee==a && salle.tab[i]->tab[j].date.mois==m && salle.tab[i]->tab[j].date.jour==j )
					{ 
						for( unsigned int k=0;k<tab.size();k++)
		                for( unsigned int w=0; w<tab[k]->tab.size();w++)
							if(tab[k]->tab[w]->id==salle.tab[i]->tab[j].id)
					         cout<<endl<<"Formateur:"<<tab[k]->nom<<" "<<tab[k]->prenom<<endl;
						
						cout<<"Salle: "<<salle.tab[i]->num;
				      salle.tab[i]->tab[j].afficher();
					  z++;
					}
				if(z==0) cout<<endl<<"Aucune formation prevue pour ce jour!"<<endl;

		}break;

   
		 default : cout<<endl<<"Choix errone!"<<endl;

	 }



}



void formateurs::planningformation()
{

	int x;
     int a,m,j;
	 int z;
	 bool tr;
	 string s;

	 cout<<endl;
	 cout<<"Donnez le nom de la formation selon le quel vous voulez afficher le planning: "<<endl;
	 cin>>s;
	 cout<<"Vous voulez afficher le planning de la formation de: "<<endl;
	 cout<<"1:Une annee - 2: Un mois - 3:Un jour"<<endl;
	 cin>>x;

	 switch(x)
	 {

	 case 1: { do
			 {
		        tr=true;
		       cout<<"Donnez l'annee dont vous voulez afficher le planning de la formation: "<<endl;
		       cin>>a;
			   if (a > 9999 || a < 2018)
			   {  cout<<"Annee non valide!"<<endl;
				   tr=false;
			   }
			 }while(tr==false);
			   z=0;
			    for( unsigned int i=0;i<salle.tab.size();i++)
		         for( unsigned int j=0; j<salle.tab[i]->tab.size();j++)
			        if (salle.tab[i]->tab[j].date.annee==a && salle.tab[i]->tab[j].formation==s)
					{ for( unsigned int k=0;k<tab.size();k++)
		                for( unsigned int w=0; w<tab[k]->tab.size();w++)
							if(tab[k]->tab[w]->id==salle.tab[i]->tab[j].id)
					         cout<<endl<<"Formateur :"<<tab[k]->nom<<" "<<tab[k]->prenom<<endl;
						
					  cout<<"Salle: "<<salle.tab[i]->num<<" | ";
				      salle.tab[i]->tab[j].afficher();
					  z++;
					}
				if(z==0) cout<<endl<<"Aucune formation prevue pour cette annee!"<<endl;

			 } break;
    
	 case 2: {  do
			 {
		        tr=true;
		       cout<<"Donnez l'annee dont vous voulez afficher le planning: "<<endl;
		       cin>>a;
			   if (a > 9999 || a < 2018)
			   {  cout<<"Annee non-valide!"<<endl;
				   tr=false;
			   }
			 }while(tr==false);
			 do
			 {
		        tr=true;
		      cout<<"Donnez le mois dont vous voulez afficher le planning: "<<endl;
		       cin>>m;
			   if (m> 12 || m < 1)
			   {  cout<<"Mois non-valide!"<<endl;
				   tr=false;
			   }
			 }while(tr==false);
			   
			   z=0;
		  for( unsigned int i=0;i<salle.tab.size();i++)
		         for( unsigned int j=0; j<salle.tab[i]->tab.size();j++)
			        if (salle.tab[i]->tab[j].date.annee==a && salle.tab[i]->tab[j].date.mois==m && salle.tab[i]->tab[j].formation==s)
					{ for( unsigned int k=0;k<tab.size();k++)
		                for( unsigned int w=0; w<tab[k]->tab.size();w++)
							if(tab[k]->tab[w]->id==salle.tab[i]->tab[j].id)
					         cout<<endl<<"Formateur: "<<tab[k]->nom<<" "<<tab[k]->prenom<<endl;
						
						
						cout<<"Salle: "<<salle.tab[i]->num;
				      salle.tab[i]->tab[j].afficher();
					  z++;
					}
				if(z==0) cout<<endl<<"Aucune formation prevue pour ce mois!"<<endl;

		        
			 }break;
       
	case 3:
		{   do
		{
			tr=true;
			cout<<"Donnez l'annee dont vous voulez afficher le planning: "<<endl;
		       cin>>a;
			   cout<<"Donnez le mois dont vous voulez afficher le planning: "<<endl; // manque juste la validite de la date!
		       cin>>m;
			   cout<<"Donnez le jour dont vous voulez afficher le planning: "<<endl;
		       cin>>j;
			   tr=datevalide(j,m,a);
			   if(tr==false) cout<<"Date non-valide!"<<endl;
		} while(tr==false);
			   z=0;
		  for( unsigned int i=0;i<salle.tab.size();i++)
		         for( unsigned int j=0; j<salle.tab[i]->tab.size();j++)
			        if (salle.tab[i]->tab[j].date.annee==a && salle.tab[i]->tab[j].date.mois==m && salle.tab[i]->tab[j].date.jour==j && salle.tab[i]->tab[j].formation==s)
					{ 
						for( unsigned int k=0;k<tab.size();k++)
		                for( unsigned int w=0; w<tab[k]->tab.size();w++)
							if(tab[k]->tab[w]->id==salle.tab[i]->tab[j].id)
					         cout<<endl<<"Formateur :"<<tab[k]->nom<<" "<<tab[k]->prenom<<endl;
						
						cout<<"Salle: "<<salle.tab[i]->num;
				      salle.tab[i]->tab[j].afficher();
					  z++;
					}
				if(z==0) cout<<endl<<"Aucune formation prevue pour ce jour!"<<endl;

		}break;

   
		 default : cout<<endl<<"Choix errone!"<<endl;

	 }


}







bool formateurs::datevalide(int d,int m,int y)
{
	
    if (y > 9999 || y < 2018)
      return false;
    if (m < 1 || m > 12)
      return false;
    if (d < 1 || d > 31)
      return false;
 
    
    if (m == 2)
    {
        if (bissextile(y))
           return (d <= 29);
        else
           return (d <= 28);
    }
 
   
    if (m==4 || m==6 || m==9 || m==11)
        return (d <= 30);
 
    return true;
}



bool formateurs::bissextile(int y)
{
	return (((y%4==0) && (y%100!=0)) ||
           (y%400==0));

}



istream& operator>>(istream& in,formateurs& fs)
{
	bool tr=true,tr1=false;
  formateur *f=new formateur();
	string s;
	int x;
  
  
  if(fs.tab.size()==0)
	{
	         cout<<"Ajout d'un formateur: "<<endl;
		           f->saisir();
				   f->responsable=true;
				   fs.tab.push_back(f);
			   
    }
	

	else 
	{  
	   cout<<"Verification du statut responsable: "<<endl;
	   cout<<"Donnez votre CIN: "<<endl;
	   cin>>x;
	   cout<<"Donnez votre code d'identification: "<<endl;
	   cin>>s;
	   for(unsigned int i=0;i<fs.tab.size();i++)
		if(fs.tab[i]->CIN==x && fs.tab[i]->code==s )
		{ x=i; 
	      tr1=true;
		  break;
	    }
	   if(tr1)
	   { if (fs.tab[x]->responsable)
	     {cout<<"Statut responsable confirme!"<<endl;
	   cout<<"Bienvenue: "<<fs.tab[x]->prenom<<" "<<fs.tab[x]->nom<<"!"<<endl;
	      cout<<"Ajout d'un formateur: "<<endl;
	      f->saisir();
		  for(unsigned int i=0;i<fs.tab.size();i++)
			if(fs.tab[i]->CIN==f->CIN)
				tr=false;
		       if(tr==false)
			   cout<<"CIN deja existante, Ajout non-effectue!"<<endl;
			   else
			   {cout<<"Ajout effectue!"<<endl;
			   f->responsable=false;
	            fs.tab.push_back(f);
			    
			   }
	      } 
	   else cout<<"Vous n'etes pas autorise a faire cela!"<<endl;
	   }
	   else cout<<"Identifiants incorrectes!"<<endl; 
  }
	cout<<endl;

	return in;
}
istream& operator>>(istream& in,formateurs* fs)
{
	bool tr=true,tr1=false;
  formateur *f=new formateur();
	string s;
	int x;
  
  
  if(fs->tab.size()==0)
	{
	         
		           cin>>f;
				   f->responsable=true;
				   fs->tab.push_back(f);
			   
    }
	

	else 
	{  
	   cout<<"Donnez votre CIN: "<<endl;
	   in>>x;
	   cout<<"Donnez votre code d'identification: "<<endl;
	   in>>s;
	   for(unsigned int i=0;i<fs->tab.size();i++)
		if(fs->tab[i]->CIN==x && fs->tab[i]->code==s )
		{ x=i; 
	      tr1=true;
		  break;
	    }
	   if(tr1)
	   { if (fs->tab[x]->responsable)
	     {cout<<"Statut responsable confirme!"<<endl;
	   cout<<"Bienvenue: "<<fs->tab[x]->prenom<<" "<<fs->tab[x]->nom<<"!"<<endl;
	      cout<<"Ajout d'un formateur: "<<endl;
	      in>>f;
		  for(unsigned int i=0;i<fs->tab.size();i++)
			if(fs->tab[i]->CIN==f->CIN)
				tr=false;
		       if(tr==false)
			   cout<<"CIN deja existante, Ajout non-effectue!"<<endl;
			   else
			   {cout<<"Ajout effectue!"<<endl;
			   f->responsable=false;
	            fs->tab.push_back(f);
			    
			   }
	   }
	   }
	       

  }
	cout<<endl;
	return in;
}
ostream& operator<<(ostream& out, formateurs& fs)
{
	for(int i=0;i<fs.tab.size();i++)
		cout<<fs.tab[i];
	//cout<<fs.salle;
	cout<<fs.mat;
	
	return out;

}
ostream& operator<<(ostream& out, formateurs* fs)
{ 
	for(int i=0;i<fs->tab.size();i++)
		out<<fs->tab[i];
	//out<<fs->salle;
	out<<fs->mat;
	
	return out;
}

void formateurs::chargement()
{


	ifstream f;
	f.open("d:\\formateurs.txt");
	while(1)
	{ 
		formateur *m=new formateur();
		f>>m;
		if(f.eof()) break;
		this->tab.push_back(m);
	}
	f.close();
	cout<<"Chargement de donnees formateurs effectue!"<<endl;



}
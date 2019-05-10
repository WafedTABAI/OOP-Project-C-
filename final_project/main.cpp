#include<iostream>
#include<string>
#include<fstream>
#include"formateurs.h"
#include"menu.h"


using namespace std;

void main()
{
	
	formateurs f;
	int choixActionPrincipale,choixAction;
	char choix;
	fstream fs,fm,ff;

	cout<<"Initialisation des donnees..."<<endl;
	cout<<"Lecture des donnees salles..."<<endl;
	cout<<"Lecture des donnees materiels..."<<endl;
	cout<<"Lecture des donnees formateurs..."<<endl;

	fs.open("d:\\salles.txt", ios::in | ios::out | ios::trunc);
	fm.open("d:\\materiels.txt", ios::in | ios::out | ios::trunc);
	ff.open("d:\\formateurs.txt", ios::in | ios::out | ios::trunc);

	f.chargement();
	f.salle.chargement();
	f.mat.chargement();

	cout<<"Chargement de donnees effectue!"<<endl<<endl;

	
	//fonctions chargementdonnees salles materiels et formateurs depuis les fichiers 

	cout<<"+-------------------------------+"<<endl;
	cout<<"|CONSOLE DE GESTION DE FORMATION|"<<endl;
	cout<<"+-------------------------------+"<<endl<<endl;

	do{
		choixActionPrincipale = menuPrincipal();
		
		switch(choixActionPrincipale)
		{   
			case 1:
				{
                    choixAction = menuFormateurs();
					switch(choixAction)
					{
						case 1:
							  {
									f.afficherformateurs();
							  }break;
						case 2:
							  {
									f.ajouterformateur();
							  }break;
						case 3:
							  {
                                    f.supprimerformateur();
							  }break;
						case 4:
							  {
								  f.modifierformateur();
							  }break;
						case 5:
							  {
                                    ff>>&f;
							  }break;
						case 6:
							  {
									system("cls");

							  }break;

						default : cout<<endl<<"Erreur: choix non-valide!"<<endl;
					}
				}break;
			case 2 :
				{
                    choixAction = menuFormations();
					switch(choixAction)
					{
						case 1:
							  {
									f.ajouterformation();
							  }break;
						case 2:
							  {
									f.supprimerformation();
							  }break;
						case 3:
							  {
                                    f.modifierformation();
							  }break;
						case 4:
							  {
                                    f.ajoutermaterielformation();
							  }break;
						case 5:
							  {
                                    f.supprimermaterielformation();
							 }break;
						case 6:
							  {
                                    //f.enregistrementdonnees();
							  }break;
						case 7:
							  {
									system("cls");

							  }break;

						default : cout<<endl<<"Erreur: choix non-valide!"<<endl;
					}
				}break;
			case 3 :
				{
					choixAction = menuMateriels();
					switch(choixAction)
						{
						case 1:
							  {
									f.affichermateriels();
							  }break;
						case 2:
							  {
									f.ajoutermateriel();
							  }break;
						case 3:
							  {
                                    f.supprimermateriel();
							  }break;
						case 4:
							  {
                                    f.modifiermateriel();
							  }break;
						case 5:
							  {
								  fm>>&f.mat;
							  }break;
						case 6:
							  {
									system("cls");

							  }break;
					default : cout<<endl<<"Erreur: choix non-valide!"<<endl;
					}
				}break;
			case 4 :
				{
					choixAction = menuSalles();
					switch(choixAction)
						{
						case 1:
							  {
									f.affichersalles();
							  }break;
						case 2:
							  {
									f.ajoutersalle();
							  }break;
						case 3:
							  {
                                    f.supprimersalle();
							  }break;
						case 4:
							  {
                                    f.modifiersalle();
							  }break;
						case 5:
							  {
								  fs>>&f.salle;
							  }break;
						case 6:
							  {
									system("cls");

							  }break;
					
						default : cout<<endl<<"Erreur: choix non-valide!"<<endl;
					}
				}break;
			case 5 :
				{
					choixAction = menuEtudiants();
					switch(choixAction)
						{
						case 1:
							  {
									f.planningformation();
							  }break;
						case 2:
							  {
									f.ajouteretudiantformation();
							  }break;
						case 3:
							  {
                                    f.supprimeretudiantformation();
							  }break;
						case 4:
							  {
                                    f.afficheretudiantsformation();
							  }break;
						case 5:
							  {
                                    //f.enregistrementdonnees();
							  }break;
						case 6:
							  {
									system("cls");

							  }break;
					
			          default : cout<<endl<<"Erreur: choix non-valide!"<<endl;
					}
		            }break;

			case 6:
				{choixAction = menuPlanning();
					switch(choixAction)
						{
						case 1:
							  {
									f.planning();
							  }break;

					default : cout<<endl<<"Erreur: choix non-valide!"<<endl;
					}
				}break;
				
		    case 7:{system("cls"); }break;

			default : cout<<endl<<"Erreur: choix non-valide!"<<endl;  

         }

				
               
			

		choix = SaisieReponse();
	}while(toupper(choix) != 'N');

	cout<<"+---------------+"<<endl;
	cout<<"|Fin du Programe|"<<endl;
	cout<<"+---------------+"<<endl;



	system("pause");

}

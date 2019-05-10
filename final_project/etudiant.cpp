#include"etudiant.h"

using namespace std;


void etudiant::saisir()

{   cout<<"Saisie des informations personnelles: "<<endl;
	cout<<"Nom: "<<endl;
    cin>>nom;
	cout<<"Prenom: "<<endl;
	cin>>prenom;
	cout<<"Age: "<<endl;
	cin>>age;
	//do
	//{
	cout<<"CIN: "<<endl;
	cin>>CIN;
	//}while(CIN/10000000==0);
	cout<<"Coded'identification: "<<endl;
	cin>>code;

}

void etudiant::afficher()
{
	cout<<endl<<"Nom: "<<nom<<" Prenom: "<<prenom<<" Age: "<<age<<endl;


}
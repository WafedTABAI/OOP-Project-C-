#include "reservation.h"
#include<iomanip>



bool reservation::saisir()
{   bool tr=false;
    
	cout<<"Saisie de la reservation: "<<endl;
	 do
	{
	cout<<"Donnez le nom de la formation sous la quelle est faite la reservation: ";
		 cin>>formation;
	for( unsigned int i=0;i<formation.size();i++)
	{
     if( int(toupper(formation.at(i)) ) >=65 && int(toupper(formation.at(i)) ) <= 90)
		 {tr=true;
	 break;}
	} 

	if(tr==false) cout<<"Nom de formation non-valide!"<<endl;
	}
	while(tr==false);
	   
		 cout<<"Donnez l'ID de la formation: ";
		 cin>>id;

		do
		{
		 cout<<endl<<"Annee: ";
	     cin>>date.annee;
		 cout<<"Mois: ";
	     cin>>date.mois;
	     cout<<"Jour: ";
	     cin>>date.jour;

	

	if (datevalide(date.jour,date.mois,date.annee)) 
		{
		  do
		  {
			
			cout<<"Le centre est ouvert de 08:00h a 18:00h"<<endl;
	    cout<<"Donnez l'heure et la minute de debut de reservation: "<<endl;
		cout<<"Heure: ";
		cin>>heuredebut.heure;
		cout<<"Minute: ";
		cin>>heuredebut.minute;
		cout<<"Donnez l'heure et la minute de fin de reservation: "<<endl;
		cout<<"Heure: ";
		cin>>heurefin.heure;
		cout<<"Minute: ";
		cin>>heurefin.minute;
		if (heurevalide(heuredebut,heurefin))
		{
		tr=true;
		}
		else cout<<"Horaire non-valide!"<<endl;
		  }while(tr==false);
        }
	else cout<<endl<<"Date non-valide!"<<endl;
		}while((datevalide(date.jour,date.mois,date.annee))==false);
		cout<<endl;
	return tr;

}

bool reservation::bissextile(int y)
{
	return (((y%4==0) && (y%100!=0)) ||
           (y%400==0));

}

  
bool reservation::datevalide(int d,int m,int y)
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


bool reservation::heurevalide(heures x,heures y)
{   
         if (x.heure>=8 && y.heure<18 && y.heure>x.heure)
    return (x.minute>=0 && x.minute<=59 && y.minute>=0 && y.minute<=59);
		 else if (x.heure>=8 && y.heure==18 && y.heure>x.heure)
			 return (  x.minute>=0 && x.minute<=59 && y.minute==0);
		 else if (x.heure>=8 && y.heure<18 && y.heure==x.heure)
		   return (x.minute>=0  && x.minute<y.minute && y.minute <=59 );
		 else return false;
}


void reservation::afficher()
{    string x;
	//cout<<"Affichage de la reservation: "<<endl;
    cout<<"Formation: "<<formation<<" | ID: "<<id;
    if( date.jour<10 ) x="0";
	else x="";
	cout<<" | Date: "<<x<<date.jour<<"/";
	if( date.mois<10 ) x="0";
	else x="";
	cout<<x<<date.mois<<"/";
	cout<<date.annee<<" | Heure debut: ";
	if( heuredebut.heure<10 ) x="0";
	else x="";
	cout<<x<<heuredebut.heure<<":";
	if( heuredebut.minute<10 ) x="0";
	else x="";
	cout<<x<<heuredebut.minute<<" - "<<"Heure fin: ";
	if( heurefin.heure<10 ) x="0";
	else x="";
	cout<<x<<heurefin.heure<<":";
	if( heurefin.minute<10 ) x="0";
	else x="";
	cout<<x<<heurefin.minute<<endl;

	
	
}

bool reservation::modifier()
{     char x;
      bool tr=false;
	cout<<"Voulez-vous modifier la date de reservation"<<endl<<"(Y/N)?"<<endl;
	cin>>x;
	while ( toupper(x)!='Y' && toupper(x)!='N')
	{
    cout<<"(Y/N)?"<<endl;
	cin>>x;
	}
     
	if (toupper(x)=='Y')
	{  do
	{
		cout<<"Jour: ";
	cin>>date.jour;
	cout<<"Mois: ";
	cin>>date.mois;
	cout<<"Annee: ";
	cin>>date.annee;
	if (datevalide(date.jour,date.mois,date.annee)==false) 
		cout<<"Date non-valide, veuillez donner une date valide!"<<endl;
	} while ( (datevalide(date.jour,date.mois,date.annee)==false));
	} 
	/*if (datevalide(date.jour,date.mois,date.annee)) 
		{
		    tr=true;	*/
			
			cout<<"Voulez-vous modifier l'horaire de reservation"<<endl<<"(Y/N)?"<<endl;
	        cin>>x;
	        while ( toupper(x)!='Y' && toupper(x)!='N')
	           {
              cout<<"(Y/N)?"<<endl;
	          cin>>x;
	           }
	      if (toupper(x)=='Y')
	       {  tr=false;
			do
			{
			cout<<"Le centre est ouvert de 08:00h a 18:00h"<<endl;
	    cout<<"Donnez l'heure et la minute de debut de reservation: "<<endl;
		cout<<"Heure: ";
		cin>>heuredebut.heure;
		cout<<"Minute: ";
		cin>>heuredebut.minute;
		cout<<"Donnez l'heure et la minute de fin de reservation: "<<endl;
		cout<<"Heure: ";
		cin>>heurefin.heure;
		cout<<"Minute: ";
		cin>>heurefin.minute;
		if (heurevalide(heuredebut,heurefin))
		tr=true;
		else cout<<"Horaire non-valide!"<<endl;
			} while( tr==false);
        }
		  //else tr=false; 
	
	//else cout<<"Date non-valide!"<<endl;
	return tr;

}

bool reservation::reservationvalide(reservation r)

{
	bool tr=false;

	if (date.annee!=r.date.annee)
		tr=true;
	else if ( date.mois!=r.date.mois)
			tr=true;
	else if ( date.jour!=r.date.jour)
		tr=true;
	else if ( heuredebut.heure>r.heurefin.heure)
		tr=true;
	else if (heuredebut.heure==r.heurefin.heure)
	{   if ( heuredebut.minute>=r.heurefin.minute)
	    tr=true;
	}
	else if (heuredebut.heure<r.heuredebut.heure)
	{if( heurefin.heure <r.heuredebut.heure ) 
	tr=true;
	  else if ( heurefin.heure==r.heuredebut.heure)
	  { 
		  if ( heurefin.minute<=r.heuredebut.minute)
	    tr=true;
	     }  
	   
	}
	return tr;
	
}


// surcharge
/*ostream& operator<<(ostream& out, reservation& r)
{
	out<<"\n date d : "<<r.date.jour<<"\n mois */



// surcharge

istream& operator>>(istream& in,reservation & r)
{
	 bool tr=false;
    
	cout<<"Saisie de la reservation: "<<endl;
	 do
	{
	cout<<"Donnez le nom de la formation sous la quelle est faite la reservation: ";
		 in>>r.formation;
	for( unsigned int i=0;i<r.formation.size();i++)
	{
     if( int(toupper(r.formation.at(i)) ) >=65 && int(toupper(r.formation.at(i)) ) <= 90)
		 tr=true;
	 break;
	} 

	if(tr==false) cout<<"Nom de formation non-valide!"<<endl;
	}
	while(tr==false);
	
		 cout<<"Donnez l'ID de la formation: ";
		 in>>r.id;

		 do{
 
          		 cout<<endl<<"Annee: ";
	            in>>r.date.annee;
				cout<<endl<<"Mois: ";
				 in>>r.date.mois;
				 cout<<"Jour: ";
				 in>>r.date.jour;
		 

	

	if (r.datevalide(r.date.jour,r.date.mois,r.date.annee)) 
		{ cout<<"Le centre est ouvert de 08:00h a 18:00h"<<endl;
	    cout<<"Donnez l'heure et la minute de debut de reservation: "<<endl;
		cout<<"Heure: ";
		in>>r.heuredebut.heure;
		cout<<"Minute: ";
		in>>r.heuredebut.minute;
		cout<<"Donnez l'heure et la minute de fin de reservation: "<<endl;
		cout<<"Heure: ";
		in>>r.heurefin.heure;
		cout<<"Minute: ";
		in>>r.heurefin.minute;
		if (r.heurevalide(r.heuredebut,r.heurefin))
		{
		tr=true;
		}
		else cout<<"Horaire non-valide!"<<endl;
        }
	else cout<<endl<<"Date non-valide!"<<endl;
		 } while(r.datevalide(r.date.jour,r.date.mois,r.date.annee)==false);
	       
	return in;

}
ostream& operator<<(ostream& out,reservation& r)
{
	out<<"Date de reservation: "<<r.date.jour<<"/";
	out<<r.date.mois<<"/";
	out<<r.date.annee<<" | Heure debut: ";
	out<<r.heuredebut.heure<<":";
	
	out<<r.heuredebut.minute<<" - "<<"Heure fin: ";
	out<<r.heurefin.heure<<":";
	out<<r.heurefin.minute<<endl;
	out<<" formation : "<<r.formation<<endl;
	out<<" id :"<<r.id<<endl;
	return out;
}

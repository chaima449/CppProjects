#include <iostream>
#include "Telecom.h"
#include "Telecom.cpp"
#include <vector>
//#include<windows.h>
//#include <stdio.h>

using namespace std;

void clearScreen() {
    cout << "\033[2J\033[1;1H"; // Clear screen using escape sequences
}

int main(){
    vector<Abonne*> listAbonne;
    vector<Ligne*> listLigne;
    vector<Service*> listService;
    vector<Consommation*> listConsommation;

    int choix=1;

    while(choix != 0)
    {
        clearScreen();
        cout <<"***************Menu*************"<<endl;
        cout << "1-Creer abonne" <<endl;
        cout << "2-Affcher liste des abonnes" <<endl;
        cout << "3-Creer ligne" <<endl;
        cout << "4-Lister les lignes" <<endl;
        cout << "5-Creer service" <<endl;
        cout << "6-Liste des services" <<endl;
        cout << "7-Creer consomation" <<endl;
        cout << "8-Calculer consomation" <<endl;
        cout << "0-Quitter" <<endl;

        cin >> choix;
        bool ajouter = false;

        switch (choix)
        {
            case 1:
                clearScreen();
                char nom[100];
                char adresse[1000];
                int serie;
                cout <<"entrez le numero de serie : " ;
                cin >> serie;
                cin.ignore();
                cout <<"entrez le nom : " ;
                cin.getline(nom, 100);
                cout <<"entrez l adresse : " ;
                cin.getline(adresse,1000) ;

                Abonne* tempAbonne;
                tempAbonne = new Abonne(serie, nom, adresse);
                listAbonne.push_back(tempAbonne);
                break;
        
            case 2:
                clearScreen();
                cout << "La liste des abonne : " << endl;
                for(int i = 0 ; i<listAbonne.size(); i++)
                {
                    listAbonne[i]->afficher();
                    cout << endl ;
                }
                cout <<"press enter to continue ..." << endl;
                cin.ignore(); // Consume the newline character
                cin.get();    // Wait for a character input
                break;
        
            case 3:
                int choixLigne;
                clearScreen();
                cout << "1-Creer une ligne fix" << endl;
                cout << "2-Creer une ligne mobile"<< endl;
                cout << "Autre numero pour quitter "<< endl;
                cin >> choixLigne ;
                if (choixLigne==1)
                {
                    //clearScreen();
                    int serie;
                    //bool ajouter = false;
                    cout <<"Entrer le numero de serie de l'abonne : " ;
                    cin>> serie;
                    for(int i=0; i<listAbonne.size(); i++)
                    {
                        if(listAbonne[i]->getSerie() == serie)
                        {
                            char numero[100],localisation[100];
                            Ligne* tempLigne;
                            cout << "Entrer le numero de la ligne : ";
                            cin >> numero ;
                            cout << "Entrer la localisation : ";
                            cin >> localisation ;
                            tempLigne = new LigneFix(numero,listAbonne[i],localisation);
                            listLigne.push_back(tempLigne);
                            cout << "Ajouter avec succees"<< endl;
                            ajouter = true;
                            break;
                        }
                    }
                    if(ajouter == false)
                    {
                        cout << "Ajout echoue, abonne introuvable..." << endl;
                    }
                    cout << "Press enter to continue..." << endl;
                    cin.ignore();
                    cin.get();
                }
                if(choixLigne==2)
                {
                    int serie;
                    //bool ajouter = false;
                    cout <<"Entrer le numero de serie de l'abonne : " ;
                    cin>> serie;
                    for(int i=0; i<listAbonne.size(); i++)
                    {
                        if(listAbonne[i]->getSerie() == serie)
                        {
                            char numero[100],reseau[100];
                            Ligne* tempLigne;
                            cout << "Entrer le numero de la ligne : ";
                            cin >> numero ;
                            cout << "Entrer le reseau : ";
                            cin >> reseau ;
                            tempLigne = new LigneFix(numero,listAbonne[i],reseau);
                            listLigne.push_back(tempLigne);
                            cout << "Ajouter avec succees"<< endl;
                            ajouter = true;
                            break;
                        }
                    }
                    if(ajouter == false)
                    {
                        cout << "Ajout echoue, abonne introuvable..." << endl;
                    }
                    cout << "Press enter to continue..." << endl;
                    cin.ignore();
                    cin.get();
                }
                break;
            case 4:
                clearScreen();
                cout<< "Liste des lignes : " << endl ;
                for (int i = 0 ; i < listLigne.size() ; i++)
                {
                    listLigne[i]->afficher();
                    cout << endl;
                }
                cout <<"press enter to continue..."<<endl;
                cin.ignore();
                cin.get(); 
                break;
            case 5:
                clearScreen();
                cout << "1-Service vocale " << endl;
                cout <<"2-Service internet" << endl;
                cout <<"Autre numero pour quitter " << endl;
                cin >> choix ;
                if(choix == 1)
                {
                    //clearScreen();
                    //bool ajouter = false ;
                    char numero[100],description[1000];
                    float prixUnitaire;
                    Vocal* unVocale;

                    cout << "Entrer le numero : " ;
                    cin >> numero ;
                    cout << "Entrer une desciption : " ;
                    cin >> description;
                    getchar();
                    cout << "Entrer le prix unitaire : " ;
                    cin >> prixUnitaire;

                    for(int i = 0 ; i < listLigne.size();i++)
                    {
                        if(strcmp(listLigne[i]->getNumero(),numero)== 0)
                        {
                            unVocale = new Vocal(numero,description,prixUnitaire);
                            listService.push_back(unVocale);
                            cout << "service ajouter avec succes..."<<endl;
                            ajouter = true ;
                        }
                    }
                    if(ajouter == false)
                        cout << "Ajout echoue, numero inexistant..." << endl;
                    cout <<"press enter to continue..."<<endl;
                    cin.ignore();
                    cin.get();  
                }   
                if(choix == 2)
                {
                    //clearScreen();
                    //bool ajouter = false ;
                    char numero[100],description[1000],ISP[100];
                    float prixUnitaire;
                    Internet* unInternet;

                    cout << "Entrer le numero : ";
                    cin >> numero ;
                    cout << "Entrer une desciption : ";
                    cin >> description;
                    getchar();
                    cout << "Entrer ISP : ";
                    cin >> ISP;
                    getchar();
                    cout << "Entrer le prix unitaire : ";
                    cin >> prixUnitaire;

                    for(int i = 0 ; i < listLigne.size();i++)
                    {
                        if(strcmp(listLigne[i]->getNumero(),numero)== 0)
                        {
                            unInternet = new Internet(numero,description,prixUnitaire,ISP);
                            listService.push_back(unInternet);
                            cout << "service ajouter avec succes..."<<endl;
                            ajouter = true ;
                        }
                    }
                    if(ajouter == false)
                        cout << "Ajout echoue, numero inexistant..." << endl;
                    cout <<"press enter to continue..."<<endl;
                    cin.ignore();
                    cin.get(); 
                }  
                break; 
            case 6:
                clearScreen();
                cout<< "Liste des Services : " << endl ;
                for (int i = 0 ; i < listLigne.size() ; i++)
                {
                    listService[i]->afficher();
                    cout << endl;
                }
                cout <<"press enter to continue..."<<endl;
                cin.ignore();
                cin.get(); 
                break;    
            case 7:
                clearScreen();
                Consommation* tempConsomation;
                //bool ajouter = false ; 
                int mois,annee,unite;
                char numero[100];
                cout << "Entrer le mois : " ;
                cin >> mois;
                cout << "Entrer l'annee : " ;
                cin >> annee;
                cout << "Entrer les unites consome : " ;
                cin >> unite;
                cout << "Entrer le numero : " ;
                cin >> numero;

                for(int i = 0 ; i < listLigne.size();i++)
                    {
                        if(strcmp(listLigne[i]->getNumero(),numero)== 0)
                        {
                            for(int j = 0;j<listService.size();j++)
                            {
                                if(strcmp(listService[j]->getNumero(),numero)== 0) //double checking...
                                {
                                    tempConsomation = new Consommation(mois,annee,unite,listLigne[i],listService[j]);
                                    listConsommation.push_back(tempConsomation);
                                    cout << "consomation ajouter avec succes..."<<endl;
                                    ajouter = true ;
                                }
                            }
                        }
                    }
                if(ajouter == false)
                    cout << "Ajout echoue, numero inexistant..." << endl;
                cout <<"press enter to continue..."<<endl;
                cin.ignore();
                cin.get(); 
                break;
            case 8:
                clearScreen();
                cout<< "Liste des consomations : " << endl ;
                for (int i = 0 ; i < listConsommation.size() ; i++)
                {
                    listConsommation[i]->afficher();
                    cout << "Prix totale : " <<listConsommation[i]->calculer();
                    cout << endl;
                }
                cout <<"press enter to continue..."<<endl;
                cin.ignore();
                cin.get(); 
                break;  

        
        }
    }
}
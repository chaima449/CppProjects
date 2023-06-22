#include "telecom.h"


Abonne::Abonne(int telNum, char* telNom, char* telAdresse)
{
    nom = new char[strlen(telNom) + 1];
    adresse = new char[strlen(telAdresse) + 1];

    strcpy(nom, telNom);
    strcpy(adresse, telAdresse);

    numSerie = telNum;
}

Abonne::~Abonne()
{
    delete[] nom;
    delete[] adresse;
}

void Abonne::afficher()
{
    cout << "Numero de serie : " << numSerie << endl;
    cout << "Nom : " << nom << endl;
    cout << "Adresse : " << adresse << endl ;
}



int Abonne::getSerie()
{
    return numSerie;
}

Ligne ::Ligne (char* telNum, Abonne* telAbonne)
{
    numero = new char[strlen(telNum) + 1];
    strcpy(numero, telNum);
    abonne = telAbonne;

}

void Ligne::afficher()
{
    cout << "Le numero de la ligne : " << numero << endl ;
    abonne->afficher();
}

char* Ligne::getNumero()
{
    return numero;
}


LigneFix ::LigneFix (char* telNum ,Abonne*ptrAbonne,char* telLocalisation) : Ligne(telNum,ptrAbonne)
{
    localisation = new char[strlen(telLocalisation) + 1];
    strcpy(localisation, telLocalisation);

}

LigneFix ::~LigneFix ()
{
    delete[] localisation;  //numero et abonne ???
}

void LigneFix :: afficher(){
    cout <<"La ligne fix : "<<endl;
    Ligne :: afficher();
    cout <<"Localisation : "<< localisation << endl ;
}

LigneMobile::LigneMobile(char* telNum, Abonne* ptrAbonne,char* telReseau) : Ligne(telNum,ptrAbonne)
{
    reseau = new char[strlen(telReseau) + 1];
    strcpy(reseau, telReseau);
}

void LigneMobile::afficher(){
    cout <<"La ligne mobile : "<<endl;
    Ligne::afficher();
    cout << "Le reseau : " << reseau << endl;
}

LigneMobile::~LigneMobile()
{
    delete[] reseau;
}

Service::Service(char* telNumero,char* telDescription, float telPrix)
{
    numero = new char[strlen(telNumero) + 1];
    description = new char[strlen(telDescription) + 1];

    strcpy(numero, telNumero);
    strcpy(description, telDescription);

    prixUnite = telPrix;
}

Service::~Service()
{
    delete[] numero;
    delete[] description;
}

char* Service :: getNumero(){
    return numero;
}

float Service::getPrixUnitaire()
{
    return prixUnite;
}

void Service::afficher(){
    cout << "Numero du service : " << numero << endl;
    cout << "Description du service : " << description << endl;
    cout << "cout par unite du service : " << prixUnite << endl;

}

Internet::Internet(char* telNumero,char* telDescription, float telPrix,char* telISP) : Service(telNumero,telDescription,telPrix){
    ISP = new char[strlen(telISP)+1];
    strcpy(ISP,telISP);
}

void Internet::afficher(){
    cout << "Type du service : internet" << endl;
    Service::afficher();
    cout << "ISP : " << ISP << endl;
}

Internet::~Internet(){
    delete[] ISP;
}

Vocal::Vocal(char* telNumero,char* telDescription, float telPrix) : Service(telNumero,telDescription,telPrix)
{

}

void Vocal::afficher()
{
    cout << "Type du service : comunication vocale" << endl;
    Service::afficher();
}

Consommation::Consommation(int telMois, int telAnne, int telUnite, Ligne* telLigne, Service* telService)
{
    mois = telMois;
    annee = telAnne;
    uniteConsomme = telUnite;
    service = telService;
    ligne = telLigne;
}

float Consommation::calculer()
{
    return uniteConsomme * service->getPrixUnitaire();
}

void Consommation::afficher()
{
    cout << "La consomation de la ligne : " << ligne->getNumero() << endl;
    cout << "Le "<<mois  <<"/"<<annee << endl ;
    cout << "Unite consomme : " << uniteConsomme<<endl ;
}
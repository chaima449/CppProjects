#ifndef TELECOM_H
#define TELECOM_H

#include<iostream>
#include<string.h>

using namespace std;

class Abonne
{
private:

    int numSerie;
    char* nom;
    char* adresse;

public:

    Abonne(int, char*, char*);
    void afficher();
    int getSerie();
    ~Abonne();

};

class Ligne
{
private:

    char* numero;
    Abonne* abonne;

public:

    Ligne(char*, Abonne*);
    virtual void afficher();
    virtual char* getNumero();

};

class LigneFix : public Ligne
{
private:

    char* localisation;

public:

    LigneFix (char*, Abonne*, char*);
    void afficher();
    ~LigneFix ();

};

class LigneMobile : public Ligne
{
private:

    char* reseau;

public:

    LigneMobile(char*, Abonne*, char*);
    void afficher();
    ~LigneMobile();

};

class Service
{
private:

    char* numero;
    char* description;
    float prixUnite;

public:

    Service(char*, char*, float);
    virtual void afficher();
    virtual char* getNumero();
    float getPrixUnitaire();
    ~Service();

};

class Internet : public Service
{
private:

    char* ISP;

public:

    Internet(char*, char*, float, char*);
    void afficher();
    ~Internet();

};

class Vocal : public Service
{
public:

    Vocal(char*, char*, float);
    void afficher();

};

class Consommation
{
private:

    int mois, annee, uniteConsomme;
    Ligne* ligne;
    Service* service;

public:

    Consommation(int, int, int, Ligne*, Service*);
    void afficher();
    float calculer();

};

#endif
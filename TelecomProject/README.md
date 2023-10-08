# Services de télécommunication

Ce projet contient un programme C++ qui permet de gérer des services de télécommunication.

Il utilise 4 classes principales:
- une classe Abonné : un objet de cette classe représente un client.
- une classe Ligne : représente une ligne téléphonique. Deux sous-classes héritent de cette classe: LigneFix et LigneMobile.
- une classe Service : qui représente un service de télécommunication. Deux sous-classes héritent de cette classe: Vocal et Internet.
- une classe Consommation : qui contient de l'information sur la consommation d'une ligne téléphonique.

Le programme propose un menu d'options qui permettent de:
- Saisir les information d'un abonné, une ligne ou un service.
- Aficher la liste des abonnés, des lignes ou des services.
- Calculer et afficher le coût de la consommation d'une ligne téléphonique.

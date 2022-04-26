>Heritage:

L'heritage est un concepte de la programmation orientee objet qui permet a une class d'utiliser le comportement d'une autre class. Cela permet la reutilisabilite du code et de donner une structure de base au developpeur.


>Polymorphisme

Le polymorphisme est la capacite d'une fonction a avoir le meme nom mais des parametres differents.


>Methodes virtuelles

Une methode virtuelle est une fonction de class dont on peut redefinir l'implemetation dans les class qui en herite.

>Classe abstraite

Une class abstraite est une class que l'on ne peut pas instancier. Elle permet de definir une couche d'abstraction en creant une interface.

>operateurs

Les operateurs sont des mots predefinis par le language cles qui agissent comme des fonctions. ( + - * < > () etc...)
On defini les operateurs dans les class.
Cela permet dans certains cas de rendre plus expressif pour un humain.

>pointeur

Un pointeur est une variable qui contient un adresse memoire.

>template





Pour ce projet, j'ai propose deux architectures.

-Architecture base sur une interface de base Shape.
Cette architecture est base sur la programmation orientee objet. Une class de base Shape dont toutes les autres class qui represente la geometrie depende. 
Cette facon de faire couple la representation des donnees et les algorithmes utilises pour calculer la surface et le perimetre. Cela permet d'avoir une interface clair et simple a comprendre pour le developeur s'il veut faire evoluer le logiciel.
Par exemple ajouter une nouvelle forme. Il suffit de creer une nouvelle class qui herite de Shape ou d'une forme specifique (Polygone par exemple). Puis coder les deux methodes Area et Perimeter.
Cette architecture a pour inconvenient de rendre depend la representation des donnees de la partie de calcule.
Utilise dans Shape.cpp Shape.h ShapeFactory.cpp ShapeFactory.h.

-Architecture base sur la donnee.
Cette architecture est base sur la programmation orientee donnees et aussi sur la programmation orientee objet puisque que l'on va utilise l'heritage.
Le but de cette architecture est de decoupler la representation des donnees de la partie calcul.
Cela rend le code un peu plus complex a comprendre qu'une pure implementation en POO.
Mais elle rend le code plus evolutif grace au decouplage.


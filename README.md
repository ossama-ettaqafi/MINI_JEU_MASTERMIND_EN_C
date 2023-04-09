# Jeu de Mastermind

Jeu de Mastermind est une application console en C qui simule le jeu de société Mastermind, où un joueur doit deviner une combinaison de chiffres en un nombre limité d'essais. This is a command-line based implementation of the popular board game called [Mastermind.](https://en.wikipedia.org/wiki/Mastermind_(board_game))

## Comment jouer

Au lancement du programme, le joueur est accueilli par le menu principal, qui offre les options suivantes :

1.  Jouer : permet de commencer une partie de Mastermind
2.  Comment jouer ? : fournit des instructions sur comment jouer au jeu
3.  Le son : active ou désactive le son de l'application
4.  Sortir : ferme l'application Si l'option "Jouer" est sélectionnée, le joueur peut choisir le niveau de difficulté, soit niveau 1 ou niveau 2. Dans le niveau 1, les joueurs ne peuvent pas utiliser des chiffres répétés. Dans le niveau 2, les joueurs peuvent utiliser un chiffre jusqu'à deux fois. Le joueur 1 entre une combinaison secrète de 5 chiffres et le joueur 2 doit la deviner en un nombre limité d'essais.

Après chaque essai, le programme affiche la réponse en utilisant les symboles suivants :

-   [+] : bien placé
-   [-] : mal placé
-   [&nbsp;&nbsp;] : n'existe pas Après 10 essais, le joueur 2 peut utiliser l'option Joker pour afficher un chiffre de la combinaison secrète du joueur 1. Toutefois, cela entraîne une pénalité de 3 essais.

## Comment exécuter

Le programme peut être exécuté sur un terminal ou une invite de commande. Il a été développé et testé sur Windows.

1.  Ouvrir une invite de commande ou un terminal
2.  Aller dans le répertoire où se trouve le fichier `Mastermind.c`
3.  Compiler le programme en utilisant la commande `gcc Mastermind.c -o Mastermind`
4.  Exécuter le programme en utilisant la commande `./Mastermind`

## Améliorations futures

Nous avons prévu les améliorations suivantes pour les versions futures de Jeu de Mastermind :

-   Ajout de niveaux de difficulté supplémentaires
-   Ajout d'une fonctionnalité pour enregistrer les scores et les comparer avec
-   Ajout d'Anglais (add English)

## À propos

Jeu de Mastermind a été développé par [OSSAMA ETTAQAFI](https://www.linkedin.com/in/afatratinmypocket/) en utilisant le langage de programmation C. Ce projet a été réalisé dans le cadre d'un projet scolaire. L'objectif de ce projet était de développer une application console en C pour simuler le jeu de société Mastermind.

## Crédits

Ce programme a été développé par [OSSAMA ETTAQAFI](https://www.linkedin.com/in/afatratinmypocket/) en utilisant le langage de programmation C. Il est libre de droit et peut être utilisé ou modifié à des fins non commerciales.

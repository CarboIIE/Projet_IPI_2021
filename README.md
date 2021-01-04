# Projet_IPI_2021

## Lancement du jeu

Vous pouvez :
- lancer l'exécution du fichier ```prog``` directement sans avoir à télécharger le
  reste des documents si vous voulez juste jouer au jeu
- compiler le code à l'aide de la commande ```make```

## Nettoyage des fichiers inutiles

Vous pouvez supprimer les fichiers autres que les purs fichiers de pur code
à l'aide de la commande ```make clean```.
Cette commande supprimera tous les fichiers objets aisni que d'autres fichiers
pouvant être générés par votre éditeur de texte.

## Rentrer les cases où l'on veut jouer

Pour rentrer les coordonnées d'une case où on veut poser un jeton il faut
les rentrer dans le terminal de la manière suivante :
```[numéro de la ligne] [numéro de la colonne]```

Ce qui donne par exemple :
```1  5```
lorsqu'on veut jouer son jeton au croisement de la ligne 1 et de la colonne 5

## Confirmation

Lorsque le programme vous demandera de confirmer si vous voulez bien jouer
à la case que vous avez rentré, il faudra rentrer un mot qui commence par 'o'
pour confirmer ou bien 'n' si on veut finalement jouer sur une autre case.
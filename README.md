*Ce projet a été réalisé dans le cadre du cursus de l’école 42 par maroard.*

 
#  ft_printf

##  Description

**ft_printf** est une réimplémentation de la fonction standard C `printf`.

L’objectif de ce projet est de comprendre et reproduire les mécanismes internes de l’affichage formaté en C, notamment le parsing des formats, la gestion des arguments variadiques, et l’application des règles de formatage.

Ce projet permet de travailler sur :
- Les fonctions variadiques (`va_list`, `va_start`, `va_arg`, `va_end`)
- Le parsing d’une chaîne de format
- La gestion des flags, de la largeur et de la précision
- L’implémentation d’un moteur de formatage
- La création d’une bibliothèque statique réutilisable

L’implémentation couvre à la fois les fonctionnalités obligatoires, les exigences bonus et même le type %**f**, avec un comportement très proche du `printf` standard.

---

##  Instructions

###  Compilation

####  Pour compiler la bibliothèque :
```bash
make
```
Cela génère la bibliothèque statique :
```bash
libftprintf.a
```

####  Pour compiler avec les fonctionnalités bonus :

```bash
make bonus
```

(Dans mon implémentation, les bonus sont intégrés directement dans le code principal. La règle bonus est présente pour compatibilité avec les testeurs, donc "make" suffit.)

---

###  Nettoyage

```bash
make clean  # Supprime les fichiers objets
make fclean  # Supprime les fichiers objets et libftprintf.a
make re  # Recompile tout
```

---
  
###  Utilisation

####  Exemple d’utilisation :

```c
#include  "ft_printf.h"

int  main(void)
{
	ft_printf("%s !\n%d baguettes s'il vous plaît !\n",  "Bonjour",  42);
	return (0);
}
```

####  Compilation :

```bash
gcc main.c  libftprintf.a  -o  prog
```

####  Output :
```bash
./prog
Bonjour !
42 baguettes  s'il vous plaît !

```

---

###  Fonctionnalités supportées

####  Conversions obligatoires

%**c** — *caractère*
%**s** — *chaîne de caractères*
%**p** — *pointeur*
%**d** / %**i** — *entier signé*
%**u** — *entier non signé*
%**x** — *hexadécimal (minuscule)*
%**X** — *hexadécimal (majuscule)*
%**%** — *caractère '%'*

---

####  Flags bonus

**-** — *alignement à gauche*
**0** — *remplissage avec des zéros*
**.** — *précision*
**#** — *préfixe 0x / 0X (hexa)*
**(espace)** — *espace avant les nombres positifs*
**+** — *affichage explicite du signe +*
**Largeur de champ** (ex : %**10**d)

---

###  Algorithme et structures de données

####  Architecture générale

L’implémentation est organisée en plusieurs étapes :

1. Parsing du format:
La chaîne de format est parcourue caractère par caractère.
Lorsqu’un % est rencontré, un parseur dédié lit :
	-- Les flags (-, 0, #, , +)
	-- La largeur
	-- La précision (.)
Il retourne le type de conversion (cspdiuxX%).
Une structure t_flags stocke toutes les options de formatage.

2. Lecture des arguments
Une **union** t_arg stocke l’argument courant après lecture avec va_arg.
Cela évite de relire plusieurs fois les arguments variadiques et rend va_copy innutile dans mon code.

3. Calcul des longueurs
Une structure t_len calcule :
	-- Le nombre de caractères à afficher
	-- La taille du signe
	-- La taille du préfixe (ex : 0x)
	-- Le nombre de zéros liés à la précision
	-- Le padding (espaces ou zéros)
Ces calculs sont faits avant l’affichage pour garantir un alignement correct.

4. Affichage formaté
L’affichage est effectué dans l’ordre exact :
	1. Padding gauche (espaces)
	2. Signe (-, + ou espace)
	3. Préfixe (0x / 0X pour hexadécimal ou pointeurs)
	4. Padding gauche (0)
	5. Zéros de précision
	6. Valeur (chiffres, chaîne, caractère, etc.)
	7. Padding droit (si le flag - est actif)

---

####  Structures utilisées

**t_flags**
Contient toutes les options de formatage (flags, largeur, précision, etc.)

**Union t_arg**
Contient la valeur de l’argument courant selon son type
En gros --> union = variable qui a plusieurs types (char, char *, void *, int, unsigned int, double)

**t_len**
Contient toutes les longueurs calculées pour gérer le formatage

---

####  Justification des choix

Cette architecture reflète le fonctionnement interne réel de printf :
- Séparation claire entre parsing et affichage
- Calcul des longueurs avant l’écriture
- Logique déterministe pour éviter les erreurs d’alignement

Elle permet également :
- Une **meilleure lisibilité**
- Un débogage plus simple
- L'ajout de types ou de formats avec facilité

##  Ressources

###  Références techniques

man 3 printf
Arguments variadiques (va_start, va_arg, va_end, va_copy): https://linux.die.net/man/3/va_start
Unions: https://zestedesavoir.com/tutoriels/755/le-langage-c-1/notions-avancees/les-unions/

---

###  Utilisation de l’IA

L’intelligence artificielle a été utilisée comme outil d’assistance pour :
- Clarifier les cas subtils de printf
- Discuter des noms de mes fonctions et variables
- Juger la propreté de mon architecture
- Rédiger la structure de ce README

L’ensemble du code, de la logique et des décisions techniques ont été implémentés manuellement.

---

###  Remarques

Cette implémentation vise à reproduire fidèlement le comportement du printf standard, y compris dans les cas limites liés à la précision, aux zéros et aux combinaisons de flags. Le projet est conçu pour être robuste, lisible et modulable !
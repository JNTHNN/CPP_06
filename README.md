# Module CPP 06

Ce module aborde en profondeur les **Casts** en C++, l'une des notions les plus puissantes (et dangereuses) du langage. Les casts permettent de forcer le compilateur à interpréter une zone mémoire sous un autre type.

En C++, nous avons à notre disposition plusieurs casts spécifiques pour remplacer le vieux cast du C (ex: `(int)var`), qui est trop permissif et dangereux.

## 1. `static_cast` (ex00)
Le `static_cast` est le cast par défaut en C++. Il est utilisé pour les **conversions explicites autorisées et logiques** entre types de base (scalaires) ou dans une hiérarchie de classes (upcast/downcast sûr).
- Dans `ex00` (ScalarConverter), nous l'utilisons pour convertir des valeurs numériques vers d'autres valeurs numériques (ex: `int` vers `float`, `char` vers `double`, etc.).
- Il effectue des vérifications à la compilation et refusera de convertir des pointeurs incompatibles.

## 2. `reinterpret_cast` (ex01)
Le `reinterpret_cast` est le cast le plus dangereux. Il ne modifie pas les bits, il dit juste au compilateur : *"Crois-moi, considère cette zone mémoire comme étant de ce nouveau type"*.
- Dans `ex01` (Serializer), nous l'utilisons pour convertir un pointeur `Data*` en un entier non-signé `uintptr_t` (une valeur numérique capable de contenir une adresse), puis pour refaire l'opération inverse.
- Très utile pour la sérialisation bas-niveau, la manipulation brute de la mémoire, ou pour interfacer avec du code C (ex: passer un objet en paramètre `void*` d'un thread).

## 3. `dynamic_cast` (ex02)
Le `dynamic_cast` est le seul cast qui s'effectue **à l'exécution** (runtime). Il ne fonctionne que sur les classes polymorphiques (qui possèdent au moins une méthode `virtual`).
- Il utilise le **RTTI** (Run-Time Type Information) pour vérifier si le cast est valide au moment de l'exécution.
- S'il est utilisé avec des **pointeurs** (ex: `dynamic_cast<A*>(p)`), et que l'objet pointé n'est pas de type `A`, il renvoie `nullptr`.
- S'il est utilisé avec des **références** (ex: `dynamic_cast<A&>(p)`), et que ça échoue, il lance une exception `std::bad_cast`.
- Dans `ex02`, nous l'utilisons pour identifier le véritable type d'une instance dérivée aléatoirement, masquée sous un pointeur de base.

## Corrections Apportées
- Ajout du prototype de `display()` dans `ScalarConverter.cpp`.
- Fix de la logique de détection des types (`detectType`) pour que les limites (`+inf`, `-inf`) soient reconnues comme des `EDGE cases` avant la vérification d'entiers.
- Affichage correct de l'infini et de `nan` sans le `f` final pour le format `double`.

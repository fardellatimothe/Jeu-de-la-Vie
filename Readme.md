# Le Jeu de la Vie

## 👨‍💻 Auteur
- **Thivillier Théo**
- **Fardella Timothé**

---

## 📖 Description

Le Jeu de la Vie est un automate cellulaire imaginé par John Horton Conway, un mathématicien britannique, pour décrire l'évolution d'une population de cellules dans le temps. 

Les cellules sont représentés par des cases placées sur une grille à deux dimensions. Elles peuvent prendre deux états : **vivante** ou **morte**.

### 🌟 Règles :

A chaque itération , l'actualisation de ces cellules est régis par deux règles : 
- Si une cellule morte à précisement trois cellules voisines vivantes, elle se transforme en vivante.
- Si une cellule vivante possède deux ou trois cellules voisines vivantes, elle reste vivante.

Notre programme reprend les concepts de la **programmation orienté objet (POO)** en simulant le jeu de la vie à travers le language **C++**.

---

## ⚙️ Installation

### 📋 Prérequis
- C++17 ou supérieur
- Compilation avec clang++
- Système compatible avec WSL ou Linux
- Bibliothèque : SFML

---

### 🛠️ Étapes d'installation

1. Clonez ce repository :
   ```bash
   git clone https://github.com/fardellatimothe/Jeu-de-la-Vie.git
    ```
2. Allez dans le répertoire du projet :

    ```bash
    cd jeu-de-la-vie/programme
    ```

3. Compilez le projet :
    ```bash
    make
    ```
    
4. Lancez le programme : 

- *nom commande* : 

    ```bash
    ./jeu_de_la_vie [mode] [options]
    ```

---
    
## 🚀 Choisir le mode : 

### 🎮 Modes d'exécution :

**Le programme sera plus ou moins rapide selon votre matériel.**

L'utilisateur peut choisir parmi 4 modes :

1. Mode Console
2. Mode Graphique
3. Mode GC (Graphique & Console)
4. Mode Test Unitaire

Le jeu intègre dans tous les modes un test unitaire. Si il n'est pas réussis, le programme ne se lance pas.

---

### ⌨️ Mode Console

Exécute le jeu dans le terminal et sauvegarde les itérations dans un dossier de sortie.

**Options obligatoires :**

1. Chemin du fichier d'entrée (ex. `fichier_input.txt`)
2. Chemin du dossier de sauvegarde (ex. `dossier_sauvegarde`)
3. Nombre d'itérations maximum (ex. `5`)
4. Si la grille est torique ou non (`true` ou `false`)

**Exemple de commande :**

```bash
./jeu_de_la_vie console fichier_input.txt dossier_sauvegarde 5 true
```

---

### 🖥️ Mode Graphique

Affiche le jeu dans une **interface graphique** interactive.

**Options obligatoires :**

1. Chemin du fichier d'entrée (ex. `fichier_input.txt`)
2. Vitesse des itérations (ex. `1`)
3. Si la grille est torique ou non (`true` ou `false`)

**Exemple de commande :**

```bash
./jeu_de_la_vie graphique fichier_input.txt 1 true
```

---

### 🔄 Mode GC (Graphique & Console)

Combine les fonctionnalités des modes console et graphique.

**Options obligatoires :**

1. Chemin du fichier d'entrée (ex. `fichier_input.txt`)
2. Chemin du dossier de sauvegarde (ex. `dossier_sauvegarde`)
3. Nombre d'itérations maximum (ex. `5`)
4. Vitesse des itérations (ex. `1`)
5. Si la grille est torique ou non (`true` ou `false`)

**Exemple de commande :**

```bash
./jeu_de_la_vie gc fichier_input.txt dossier_sauvegarde 5 1 true
```

--- 

### 🧪 Mode Test Unitaire

Teste si le programme est fonctionnel en comparant une grille initiale à une grille attendue après un certain nombre d'itérations.

**Options obligatoires :**

1. Chemin du fichier d'entrée (ex. `fichier_base.txt`)
2. Chemin du fichier attendu (ex. `fichier_attendu.txt`)
3. Numéro d'itération à tester (ex. `10`)

**Exemple de commande :**

```bash
./jeu_de_la_vie test fichier_base.txt fichier_attendu.txt 10
```

--- 


### 🎮 Commandes clavier (Mode Graphique)

Lorsque que vous exécutez le jeu en mode graphique, vous pouvez intéragir avec l'interface graphique grâce à votre clavier : 

- ❌ **Échap** : En appuyant sur cette touche, l'interface se fermera et le programme s'arrêtera.

- ⏸️ **Espace** : En appuyant sur cette touche, le jeu se mettra en pause. Pour que le jeu reprenne, il faudra réappuyer votre barre d'espace.

- ➡️ **Flèche de Droite** : En appuyant sur cette touche, la vitesse d'éxecution du jeu augmentera.

- ⬅️ **Flèche de Gauche** : En appuyant sur cette touche, la vitesse d'éxecution du jeu diminuera.

---

## Explication fonctionnement du programme

Dans cette partie, nous allons développer le fonctionnement mais aussi l'optimisation de notre code, et cela en 5 sous-parties : 
- **Compilation** (makefile)
- **Choix du mode** (main)
- **Simulation des prochaine itération** (controleur, grille, cellule, observers)
- **La sauvegarde pour le mode console** (controleur, console, observateur)
- **L'affichage pour le mode graphique** (controleur, graphique, observateur)

#### C++ : Pourquoi ?

Le language C++ offre à ses utilisateurs des performances élevées et une gestion des ressources optimale, notamment la mémoire. 
Il est possible de gérer de structures en 2D, comme notre grille de cellule, notament grâce à l'implémentation dans le language de conteneur

Utiliser le C++ pour développer le Jeu de la vie offre de nombreux avantages, notamment grâce à ses performances et sa gestion des ressources. 
Avec le C++, il est possible d'optimiser les calculs pour gérer de grandes grilles ou des simulations complexes tout en ayant un contrôle total sur les structures de données, comme les vecteurs ou tableaux. 
De plus, il permet d'intégrer facilement des bibliothèques comme SFML pour créer une interface graphique réactive. 

#### Compilation : Explication du Makefile

Nous utilisons ce Makefile pour compiler le programme "jeu_de_la_vie", qui utilise la bibliothèque SFML. Il fournit deux modes de compilation : une version standard et une version de débogage. Le Makefile permet également de nettoyer les fichiers générés lors de la compilation.

#### 1. Explication des Commandes

- **`all`**  
  C'est la cible par défaut. Lors de l'exécution de `make` sans argument, elle compile le programme principal `jeu_de_la_vie` en utilisant les fichiers sources et d'en-têtes définis.

- **`jeu_de_la_vie-debug`**  
  Cette cible est utilisée pour compiler une version de débogage du programme. Elle utilise des options spécifiques qui désactivent certaines optimisations du compilateur pour faciliter le débogage.

- **`clean`**  
  Supprime les fichiers binaires générés par la compilation (`jeu_de_la_vie` et `jeu_de_la_vie-debug`), permettant de repartir d'un environnement propre.

#### 2. Explication des Drapeaux de Compilation

- **`-std=c++17`**  
  Spécifie l'utilisation de la norme C++17 pour la compilation, garantissant que le code est compilé avec les fonctionnalités et les comportements définis par cette version du langage.

- **`-lsfml-graphics -lsfml-window -lsfml-audio -lsfml-network -lsfml-system`**  
  Ces options lient le programme avec les bibliothèques SFML nécessaires pour les fonctionnalités graphiques, de gestion des fenêtres, audio, réseau, et système. SFML est une bibliothèque utilisée pour la création de jeux et d'applications multimédia.

- **`-g`**  
  Ajoute des informations de débogage dans l'exécutable, ce qui permet d'utiliser des outils comme `gdb` ou `lldb` pour analyser le programme pendant son exécution.

- **`-Wmost`**  
  Active une série d'avertissements pour aider à identifier les problèmes potentiels dans le code (par exemple, variables inutilisées, mauvaises pratiques de programmation).

- **`-O0`**  
  Désactive les optimisations du compilateur, ce qui est utile en mode débogage, car cela permet de conserver la structure du code telle qu'elle apparaît dans les sources, facilitant ainsi l'analyse pendant le débogage.

- **`-U_FORTIFY_SOURCE`**  
  Cette option désactive certaines protections de sécurité (liées à la gestion des chaînes de caractères et des tampons) qui peuvent interférer avec le débogage, rendant le processus plus fluide.

#### 3. Pourquoi Utiliser `clang++` ?

Le compilateur `clang++` est choisi pour plusieurs raisons :

- **Performance** : `clang++` est réputé pour générer des exécutables plus performants grâce à son optimisation efficace du code.
  
- **Messages d'erreur clairs** : Contrairement à d'autres compilateurs, `clang++` fournit des messages d'erreur et des avertissements très lisibles, ce qui aide au débogage et à l'amélioration de la qualité du code.
  
- **Compatibilité avec C++17** : `clang++` offre un excellent support des dernières normes du C++ (ici, C++17), ce qui est essentiel pour le développement avec la bibliothèque SFML.
  
- **Intégration facile avec les outils de débogage** : `clang++` fonctionne très bien avec des outils comme `lldb` (le débogueur de LLVM) pour un débogage performant et une analyse détaillée.


### Simulation (itération):

La partie simulation va être sur comment on calcule la prochaine itération et donc par conséquent comment on calcule l'état prochain des cellules.

#### Fonctionnement simplifier

Notre objectif était d'optimiser le plus possible le cout en mémoire mais aussi en temps. Comme nous travaillons sur une grille le cout en temps peux vite devenir quadratique est c'est ce qu'on a évité.

##### 1er idée (rejeté)
La première idée était de stocker toute la grille dans une matrice et de parcourir cette dernière pour trouver les cellules vivantes et d'indiquer à leurs voisins qu'il y a une cellule vivante à côté d'eux. Puis ensuite, encore parcourir la matrice pour calculer les cellules qui vont survivre.

Le problème de cette méthode est le coût en temps dû au parcours de la matrice qui demande d'utiliser 2 boucles à chaque itération. Ce qui donne 2 coûts quadratiques additionnés. Et donc le temps d'exécution et de mémoire va dépendre de la taille de la matrice.

Nous avons donc choisi de trouver une autre solution.

##### 2èmes idée (celle utilisé)

Nous avons opté pour une approche utilisant des piles (`stack`), permettant de gérer efficacement l'état des cellules vivantes et des cellules voisines. La solution repose sur les éléments suivants :

1. **Sockage des cellules** :
    - Nous avons créé une pile 'CelluleVivantePile' qui permet de stocker les cellules vivantes. Nous l'initialisons dès que la classe reçoit la matrice en la parcourant pour y stocker les cellules vivantes et les obstacles vivants.

    - Nous avons aussi créé une pile `CelluleTransition` qui va être utilisée lors du calcul des voisins.

    - Nous avons créé une structure de données `CelluleExiste`, qui contient pour chaque position de la grille un pointeur vers une cellule active (vivante ou voisine d'une vivante sinon nullptr). Cela permet d'accéder directement avec un coût de O(1) à l'aide de coordonnées à la cellule souhaitée pour voir si elle existe ou non.

2. **Calcul des voisins** :
   - La méthode `CalculVoisin` est responsable de parcourir les cellules vivantes et d'identifier les cellules voisines.
   - Pour chaque cellule vivante, nous vérifions les 8 voisins (y compris les diagonales) et incrémentons leur compteur de voisins vivants dans `CelluleTransition`. Si une cellule voisine n'existe pas encore, elle est créée.
   - Les cellules voisines sont ensuite ajoutées à la pile `CelluleTransition` pour être traitées lors du calcul de la survie des cellules.

3. **Calcul de la survie des cellules** :
   - La méthode `CalculSurvie` traite les cellules de la pile `CelluleTransition` pour déterminer si elles restent vivantes ou mortes, en fonction des règles du jeu de la vie.
   - Si une cellule doit survivre, elle est réinsérée dans la pile des cellules vivantes (`CelluleVivantePile`). Si elle doit mourir, elle est supprimée de la grille et son état est mis à jour.
   - Ce processus est optimisé en ne traitant que les cellules qui ont potentiellement changé d'état, en utilisant des piles pour une gestion plus efficace.

4. **Observateurs** :
   - À chaque changement d'état d'une cellule, les observateurs sont notifiés via la méthode `notifierObservateur`. Cela permet d'actualiser les différentes vu pour qu'il ne change que ce qu'il y a modifié.


#### Complexité en Temps

- **Calcul des voisins** (`CalculVoisin`) :  
  La méthode parcourt les voisins de chaque cellule vivante. Si `V` est le nombre de cellules vivantes, la complexité est **O(V)**.

- **Calcul de la survie** (`CalculSurvie`) :  
  Chaque cellule de la pile `CelluleTransition` est vérifiée. La complexité est aussi **O(V)**.

La complexité totale par itération est donc **O(V)**.

Contrairement à la première idée, le coût en temps ne va pas principalement dépendre de la taille de la matrice mais plutôt du nombre de cellules vivantes

#### Complexité en Mémoire

- **Matrice `CelluleExiste`** :  
  Cette matrice a une taille de **O(n * m)**, où `n` et `m` sont les dimensions de la grille.

- **Piles `CelluleVivantePile` et `CelluleTransition`** :  
  Chaque pile contient jusqu'à **O(V)** cellules vivantes et voisines.

La complexité mémoire totale est **O(n * m)**.

### Sauvegarde mode Console

Le mode console permet de sauvegarder l'état de la grille à chaque itération dans des fichiers distincts, facilitant ainsi la traçabilité de l'évolution de la simulation. Cette fonctionnalité est implémentée dans la méthode `sauvegarderEtat` de la classe `GestionFichier`.

#### Fonctionnement

1. **Enregistrement de l'état** :
   - À chaque itération, un fichier est créé pour sauvegarder l'état actuel de la grille.
   - Si un chemin de sauvegarde (`cheminSauvegarde`) est spécifié, les fichiers sont enregistrés dans le dossier correspondant. Sinon, un dossier par défaut nommé `Sauvegarde` est créé pour stocker les fichiers.

2. **Nom des fichiers** :
   - Les fichiers sont nommés de manière séquentielle en fonction de l'itération (`fichier_ite_<numéro>`), permettant de suivre l'évolution chronologique de la simulation.

3. **Création du dossier** :
   - Si le chemin ou le dossier de sauvegarde n'existe pas, il est automatiquement créé via `std::filesystem::create_directory`.

4. **Format du fichier** :
   - Chaque fichier contient une représentation textuelle de la grille. Chaque ligne du fichier correspond à une ligne de la grille, et les valeurs des cellules sont séparées par des espaces.

#### Complexité

Le mode console est ralenti en raison du coût en temps du stockage des états, qui est quadratique. À chaque itération, toutes les cellules de la grille sont parcourues pour être écrites dans un fichier, ce qui engendre une complexité temporelle de $O(n \times m)$, où \(n\) est le nombre de lignes et \(m\) le nombre de colonnes de la grille. C'est pourquoi nous avons également développé une version alternative qui ne sauvegarde que l'état final pour réduire ce coût.


### Affichage mode Graphique

Le mode graphique utilise la bibliothèque **SFML** pour afficher en temps réel l'évolution de la grille à chaque itération.

#### Fonctionnement

1. **Affichage de la grille** :
   - Chaque cellule est représentée par un rectangle (`sf::RectangleShape`) dessiné à une position spécifique sur la fenêtre SFML.
   - Les cellules vivantes sont affichées en blanc et obstable vivant en vert, tandis que les cellules mortes apparaissent en noir et les obstacles mort en rouge.

2. **Mise à jour des cellules** :
   - La méthode `update(int x, int y, int etat)` modifie l'état graphique d'une cellule spécifique, en fonction des coordonnées `(x, y)` et de son état (`1` pour vivante, `0` pour morte).


#### Complexité

Le mode graphique est ralenti par le coût de rendu des cellules à chaque itération, bien que ce coût reste linéaire par rapport à la taille de la grille \(O(n \times m)\). Cependant, pour des grilles très grandes ou des animations rapides, le temps de rendu peut devenir un goulot d'étranglement. Mais comme nous modifions que ce qu'il y a besoin de modifier, nous limitons le coût en temps.






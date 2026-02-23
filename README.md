<div align="center"> <image src="GraphViz.PNG" alt="Description"> </div>

# 📊 Graph Algorithms en C

Implémentation de graphes en C avec visualisation via **Graphviz**. Le projet permet de créer des graphes orientés et non orientés, d'ajouter des arêtes et de les visualiser automatiquement.

---

## 📋 Prérequis

### 1. Installer Graphviz

**macOS (avec Homebrew) :**
```bash
brew install graphviz
```

**Linux (Debian/Ubuntu) :**
```bash
sudo apt-get install graphviz
```

**Vérifier l'installation :**
```bash
dot -V
```

### 2. Compilateur C
Un compilateur `gcc` est nécessaire. Sur macOS il est inclus avec les Command Line Tools :
```bash
xcode-select --install
```

---

## 🚀 Compilation et exécution

```bash
chmod +x compilation.sh   # rendre le script exécutable (une seule fois)
./compilation.sh
```

Le script compile le projet, l'exécute et génère automatiquement une image du graphe (`graph.png` ou `digraph.png`).

---

## 📁 Structure du projet

```
graph_algorithms/
├── include/
│   └── graph.h         # Définitions des structures et prototypes
├── src/
│   ├── main.c          # Programme principal
│   └── graph.c         # Implémentation des fonctions
├── obj/                # Fichiers objets (générés à la compilation)
├── compilation.sh      # Script de compilation
└── README.md
```

---

## ✏️ Créer votre propre graphe

Tout se passe dans `src/main.c`. Voici comment personnaliser votre graphe.

### Graphe non orienté (GNO)

Les arêtes vont dans les deux sens (ex: réseau routier, amitié).

```c
Graphe g = nouveau_graphe(5, faux);  // 5 sommets, non orienté

ajouter_arete(g, 1, 2);  // 1 -- 2
ajouter_arete(g, 1, 3);  // 1 -- 3
ajouter_arete(g, 2, 4);  // 2 -- 4

afficher_graphe(g);
effacer_graphe(g);
```

> Le fichier généré sera `graph.dot` → `graph.png`

---

### Graphe orienté (GO)

Les arêtes ont une direction (ex: réseau social, dépendances).

```c
Graphe g = nouveau_graphe(4, vrai);  // 4 sommets, orienté

ajouter_arete(g, 1, 2);  // 1 -> 2
ajouter_arete(g, 2, 3);  // 2 -> 3
ajouter_arete(g, 3, 4);  // 3 -> 4
ajouter_arete(g, 4, 1);  // 4 -> 1 (cycle)

afficher_graphe(g);
effacer_graphe(g);
```

> Le fichier généré sera `digraph.dot` → `digraph.png`

---

### Résumé des différences

| | Graphe non orienté | Graphe orienté |
|---|---|---|
| Paramètre | `faux` | `vrai` |
| Arête | `1 -- 2` (bidirectionnelle) | `1 -> 2` (unidirectionnelle) |
| Fichier généré | `graph.dot` / `graph.png` | `digraph.dot` / `digraph.png` |

---

## 🔧 Fonctions disponibles

| Fonction | Description |
|---|---|
| `nouveau_graphe(n, oriente)` | Crée un graphe de `n` sommets |
| `ajouter_arete(g, src, dest)` | Ajoute une arête entre `src` et `dest` |
| `afficher_graphe(g)` | Affiche les listes d'adjacence dans le terminal |
| `effacer_graphe(g)` | Libère la mémoire et ferme le fichier `.dot` |

---

## 🙈 Fichiers ignorés (.gitignore)

Les fichiers générés automatiquement ne sont pas inclus dans le dépôt :
```
*.dot
*.png
obj/
mon_programme
```

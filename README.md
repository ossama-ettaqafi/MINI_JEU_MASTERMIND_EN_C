# 🎯 Jeu Mastermind en C

Le **Jeu Mastermind** est une application console développée en langage **C** qui simule le célèbre jeu de société. Un joueur doit deviner une combinaison secrète de chiffres en un nombre limité d’essais, avec des indices à chaque tentative.

## 📖 Sommaire

- [🎮 Comment Jouer](#-comment-jouer)
- [📸 Captures d'Écran](#-captures-décran)
- [⚙️ Exécution](#️-exécution)
- [🚀 Améliorations Futures](#-améliorations-futures)
- [👥 Crédits](#-crédits)

## 🎮 Comment Jouer

Au lancement, le menu principal propose :

1. **Jouer** – Commencer une partie.
2. **Comment jouer ?** – Affiche les instructions.
3. **Son** – Active ou désactive le son.
4. **Quitter** – Ferme l’application.

### Niveaux de difficulté :
- **Niveau 1 :** chiffres uniques (pas de répétition).
- **Niveau 2 :** un chiffre peut apparaître **deux fois maximum**.

Le joueur 1 définit une **combinaison secrète de 5 chiffres**. Le joueur 2 a un nombre limité d'essais pour la deviner.

### Symboles des Résultats :

| Symbole | Signification              |
|---------|----------------------------|
| `+`     | Chiffre bien placé         |
| `-`     | Chiffre mal placé          |
| `[ ]`   | Chiffre inexistant         |

Après 10 essais, le **Joker** peut être utilisé : il révèle **un chiffre correct** de la combinaison en échange de **3 essais**.

## 📸 Captures d'Écran

### Menu Principal  
![Menu Principal](https://user-images.githubusercontent.com/119759894/230787611-d0322db6-c310-4947-954b-1041abd677f0.png)

### Instructions  
![Instructions](https://user-images.githubusercontent.com/119759894/230787635-47ef8829-86e3-48e2-b45d-80341665a564.png)

### Niveaux de Difficulté  
![Niveaux de Difficulté](https://github.com/user-attachments/assets/b738c3e8-f637-400c-b802-ad7893ec8089)

### Début de Partie  
![Début de la Partie](https://user-images.githubusercontent.com/119759894/230787676-83365cba-98ee-4097-8131-4e5f37237dc0.png)

### Fin de Partie  
![Fin de la Partie](https://user-images.githubusercontent.com/119759894/230787753-992210e1-570e-4717-a0ae-b8d75ea34b6c.png)

## ⚙️ Exécution

Le programme fonctionne sur un terminal (Windows recommandé).

### Étapes :

```bash
# Aller dans le dossier du fichier source
cd chemin/vers/le/projet

# Compiler le programme
gcc Mastermind.c -o Mastermind

# Exécuter
./Mastermind
```

## 🚀 Améliorations Futures

- 🔁 Ajout de niveaux de difficulté supplémentaires.
- 🏆 Intégration d’un système de scores sauvegardés.
- 🌐 Traduction anglaise du jeu.

## 👥 Crédits

Ce projet est open source et peut être utilisé ou modifié à des fins **non commerciales**.

💡 *N'hésitez pas à proposer des améliorations ou à signaler des bugs via les issues du dépôt GitHub.*

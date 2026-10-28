
#include <iostream>
#include <string>
#include <limits>
using namespace std;

class Livre {
private:
    string titre;
    double prix;

public:
    // Constructeur par defaut
    Livre() {
        titre = "";
        prix = 0.0;
    }

    // Methode pour saisir les informations
    void saisir() {
        cout << "Donner le titre du livre : ";
        getline(cin, titre);

        cout << "Donner le prix du livre : ";
        cin >> prix;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Methode pour afficher les informations
    void afficher() {
        cout << "Titre : " << titre << endl;
        cout << "Prix : " << prix << " DH" << endl;
    }
};

int main() {
    int n;

    // 1. Demander le nombre de livres
    cout << "Combien de livres voulez-vous creer ? ";
    cin >> n;

    if (n <= 0) {
        cout << "Le nombre doit etre positif." << endl;
        return 1;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // 2. Allocation dynamique du tableau
    Livre* livres = new Livre[n];

    // 3. Saisir les informations des livres
    for (int i = 0; i < n; i++) {
        cout << "\nLivre numero " << i + 1 << endl;
        livres[i].saisir();
    }

    // 4. Afficher tous les livres
    cout << "\n===== Liste des livres =====" << endl;

    for (int i = 0; i < n; i++) {
        cout << "\nLivre numero " << i + 1 << endl;
        livres[i].afficher();
    }

    // 5. Liberer la memoire
    delete[] livres;

    return 0;
}


#include <iostream>
#include <string>
using namespace std;

class Contact {
private:
    string nom;
    string telephone;
    string email;

public:
    // Constructeur
    Contact(string n, string t, string e) {
        nom = n;
        telephone = t;
        email = e;
    }

    // Getters
    string getNom() {
        return nom;
    }

    // Afficher un contact
    void afficher() {
        cout << "Nom : " << nom << endl;
        cout << "Telephone : " << telephone << endl;
        cout << "Email : " << email << endl;
    }
};

// Supprimer un contact par son nom
void supprimerContact(Contact** carnet, int& n, string nom) {
    int position = -1;

    // Rechercher le contact
    for (int i = 0; i < n; i++) {
        if (carnet[i]->getNom() == nom) {
            position = i;
            break;
        }
    }

    if (position == -1) {
        cout << "Contact introuvable !" << endl;
        return;
    }

    // Liberer l'objet
    delete carnet[position];

    // Decaler les pointeurs
    for (int i = position; i < n - 1; i++) {
        carnet[i] = carnet[i + 1];
    }

    n--;

    cout << "Contact supprime avec succes !" << endl;
}

int main() {
    int capacite = 10;
    int n = 0;

    // Tableau dynamique de pointeurs
    Contact** carnet = new Contact*[capacite];

    int choix;

    do {
        cout << "\n===== CARNET D'ADRESSES =====" << endl;
        cout << "1. Ajouter un contact" << endl;
        cout << "2. Afficher les contacts" << endl;
        cout << "3. Supprimer un contact" << endl;
        cout << "0. Quitter" << endl;
        cout << "Votre choix : ";
        cin >> choix;
        cin.ignore(10000, '\n');

        if (choix == 1) {
            if (n == capacite) {
                cout << "Carnet plein !" << endl;
            } else {
                string nom, telephone, email;

                cout << "Nom : ";
                getline(cin, nom);

                cout << "Telephone : ";
                getline(cin, telephone);

                cout << "Email : ";
                getline(cin, email);

                carnet[n] = new Contact(nom, telephone, email);
                n++;

                cout << "Contact ajoute !" << endl;
            }
        }

        else if (choix == 2) {
            if (n == 0) {
                cout << "Le carnet est vide." << endl;
            } else {
                for (int i = 0; i < n; i++) {
                    cout << "\nContact numero " << i + 1 << endl;
                    carnet[i]->afficher();
                }
            }
        }

        else if (choix == 3) {
            string nom;

            cout << "Nom du contact a supprimer : ";
            getline(cin, nom);

            supprimerContact(carnet, n, nom);
        }

        else if (choix != 0) {
            cout << "Choix invalide !" << endl;
        }

    } while (choix != 0);

    // Liberer tous les contacts restants
    for (int i = 0; i < n; i++) {
        delete carnet[i];
    }

    // Liberer le tableau de pointeurs
    delete[] carnet;

    cout << "Memoire liberee. Au revoir !" << endl;

    return 0;
}

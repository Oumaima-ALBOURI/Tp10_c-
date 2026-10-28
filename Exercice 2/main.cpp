
#include <iostream>
#include <string>
using namespace std;

class Personne {
private:
    string nom;
    int age;

public:
    // Constructeur
    Personne(string n, int a) {
        nom = n;
        age = a;
    }

    // Methode pour afficher les informations
    void afficher() {
        cout << "Nom : " << nom << endl;
        cout << "Age : " << age << " ans" << endl;
    }
};

int main() {
    // Allocation dynamique avec le constructeur
    Personne* p = new Personne("Oumaima", 20);

    // Afficher les informations
    p->afficher();

    // Liberer la memoire
    delete p;

    return 0;
}

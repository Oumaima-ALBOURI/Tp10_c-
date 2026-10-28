
#include <iostream>
using namespace std;

int main() {
    int n;

    // 1. Demander la taille du tableau
    cout << "Donner la taille du tableau : ";
    cin >> n;

    // Vérifier la taille
    if (n <= 0) {
        cout << "La taille doit etre positive." << endl;
        return 1;
    }

    // 2. Allocation dynamique
    int* tab = new int[n];

    // 3. Saisir les valeurs
    for (int i = 0; i < n; i++) {
        cout << "Donner tab[" << i << "] : ";
        cin >> tab[i];
    }

    // 4. Afficher les valeurs
    cout << "Les valeurs du tableau sont : " << endl;

    for (int i = 0; i < n; i++) {
        cout << tab[i] << " ";
    }

    cout << endl;

    // 5. Liberer la memoire
    delete[] tab;

    return 0;
}

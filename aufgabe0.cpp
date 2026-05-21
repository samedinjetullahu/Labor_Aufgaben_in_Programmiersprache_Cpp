#include <iostream>

int main() {
    using namespace std;

    int n;
    int i;
    int zahlen [10];
    int summe = 0;
    cout << "Anzahl eingeben:" << endl;
    cin >> n;

    for(i = 0; i < n; i++) {
        cout << "Zahl eingeben:" << endl;
        cin >> zahlen[i];
        summe += zahlen[i];
    }

    for(i = 0; i < n; i++) {
        cout << "Zahl[" << i <<"]: " << zahlen[i]  << endl;
    }

    double Durchschnitt = (double)summe / n;
    cout << "Durchschnitt: " << Durchschnitt << endl;

    return 0;
}
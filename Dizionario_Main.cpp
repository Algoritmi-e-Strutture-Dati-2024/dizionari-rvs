
int main() {
    DizionarioEsteso<string, string> diz;

    cout << "Inserimenti:\n";
    diz.inserisci("apple", "fruit");
    diz.inserisci("car", "vehicle");
    diz.inserisci("book", "object");
    diz.inserisci("bike", "vehicle");
    diz.inserisci("pear", "fruit");

    cout << "\nRecupero dei valori:\n";
    string value;
    if (diz.recupera("apple", value)) {
        cout << "Value for 'apple': " << value << "\n";
    } else {
        cout << "'apple' not found.\n";
    }

    if (dict.recupera("car", value)) {
        cout << "Value for 'car': " << value << "\n";
    } else {
        cout << "'car' not found.\n";
    }

    if (diz.recupera("pen", value)) {
        cout << "Value for 'pen': " << value << "\n";
    } else {
        cout << "'pen' not found.\n";
    }

    cout << "\nVerifica appartenenza:\n";
    cout << "'bike' presente: " << (diz.appartiene("bike") ? "SI" : "NO") << "\n";
    cout << "'pen' presente: " << (diz.appartiene("pen") ? "SI" : "NO") << "\n";

    cout << "\nRimozione di 'car':\n";
    if (diz.rimuovi("car")) {
        cout << "'car' rimossa con successo.\n";
    } else {
        cout << "Errore nella rimozione di 'car'.\n";
    }

    cout << "'car' presente dopo rimozione: " << (diz.appartiene("car") ? "SI" : "NO") << "\n";

    cout << "\nStato finale della tabella hash:\n";
    diz.stampa();

    return 0;
}


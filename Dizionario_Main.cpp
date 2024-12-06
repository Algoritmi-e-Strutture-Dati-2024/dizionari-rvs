
int main() {
    DizionarioEsteso<string, string> dict;

    cout << "Inserimenti:\n";
    dict.inserisci("apple", "fruit");
    dict.inserisci("car", "vehicle");
    dict.inserisci("book", "object");
    dict.inserisci("bike", "vehicle");
    dict.inserisci("pear", "fruit");

    cout << "\nRecupero dei valori:\n";
    string value;
    if (dict.recupera("apple", value)) {
        cout << "Value for 'apple': " << value << "\n";
    } else {
        cout << "'apple' not found.\n";
    }

    if (dict.recupera("car", value)) {
        cout << "Value for 'car': " << value << "\n";
    } else {
        cout << "'car' not found.\n";
    }

    if (dict.recupera("pen", value)) {
        cout << "Value for 'pen': " << value << "\n";
    } else {
        cout << "'pen' not found.\n";
    }

    cout << "\nVerifica appartenenza:\n";
    cout << "'bike' presente: " << (dict.appartiene("bike") ? "SI" : "NO") << "\n";
    cout << "'pen' presente: " << (dict.appartiene("pen") ? "SI" : "NO") << "\n";

    cout << "\nRimozione di 'car':\n";
    if (dict.rimuovi("car")) {
        cout << "'car' rimossa con successo.\n";
    } else {
        cout << "Errore nella rimozione di 'car'.\n";
    }

    cout << "'car' presente dopo rimozione: " << (dict.appartiene("car") ? "SI" : "NO") << "\n";

    cout << "\nStato finale della tabella hash:\n";
    dict.stampa();

    return 0;
}


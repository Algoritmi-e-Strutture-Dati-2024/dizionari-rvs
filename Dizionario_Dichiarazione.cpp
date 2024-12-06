#include <iostream>
#include <string>
using namespace std;
template <typename K, typename V>
class DizionarioEsteso {
private:
    static const int TABLE_SIZE = 100;

    struct Entry {
        K key;
        V value;
        bool occupied = false;

        Entry() = default;
        Entry(const K& k, const V& v) : key(k), value(v), occupied(true) {}
    };

    Entry table[TABLE_SIZE];

    int hashFunction(const K& key) const {
        int hash = 0;
        for (char ch : key) {
            hash += static_cast<int>(ch);
        }
        return hash % TABLE_SIZE;
    }

    int secondaryHash(const K& key) const {
        int hash = 0;
        for (char ch : key) {
            hash += static_cast<int>(ch);
        }
        return 1 + (hash % (TABLE_SIZE - 1));
    }

    int findSlot(int index, const K& key, bool useDoubleHashing) const {
        int originalIndex = index;
        int step = useDoubleHashing ? secondaryHash(key) : 1;

        while (table[index].occupied && table[index].key != key) {
            index = (index + step) % TABLE_SIZE;
            if (index == originalIndex) {
                return -1;
            }
        }
        return index;
    }

public:
    bool inserisci(const K& key, const V& value, bool useDoubleHashing = false) {
        int index = hashFunction(key);

        if (table[index].occupied) {
            index = findSlot(index, key, useDoubleHashing);
            if (index == -1) {
                return false;
            }
        }

        table[index] = Entry(key, value);
        return true;
    }

    bool recupera(const K& key, V& outValue, bool useDoubleHashing = false) const {
        int index = hashFunction(key);

        if (table[index].occupied) {
            if (table[index].key == key) {
                outValue = table[index].value;
                return true;
            }

            int step = useDoubleHashing ? secondaryHash(key) : 1;
            int originalIndex = index;
            while (table[index].occupied) {
                index = (index + step) % TABLE_SIZE;
                if (index == originalIndex) break;
                if (table[index].key == key) {
                    outValue = table[index].value;
                    return true;
                }
            }
        }

        return false;
    }

    bool rimuovi(const K& key, bool useDoubleHashing = false) {
        int index = hashFunction(key);

        if (table[index].occupied) {
            if (table[index].key == key) {
                table[index].occupied = false;
                return true;
            }

            int step = useDoubleHashing ? secondaryHash(key) : 1;
            int originalIndex = index;
            while (table[index].occupied) {
                index = (index + step) % TABLE_SIZE;
                if (index == originalIndex) break;
                if (table[index].key == key) {
                    table[index].occupied = false;
                    return true;
                }
            }
        }

        return false;
    }

    bool appartiene(const K& key, bool useDoubleHashing = false) const {
        V hold;
        return recupera(key, hold, useDoubleHashing);
    }

    void stampa() const {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            if (table[i].occupied) {
                std::cout << "Index " << i << ": [" << table[i].key << " => " << table[i].value << "]\n";
            } else {
                std::cout << "Index " << i << ": [Vuoto]\n";
            }
        }
    }
};






#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
class Set {
private:
    vector<T> elements;

public:
    Set() = default;

    Set(initializer_list<T> list) {
        for (const T& item : list) {
            add(item);
        }
    }

    void add(const T& item) {
        if (!contains(item)) {
            elements.push_back(item);
        }
    }

    bool contains(const T& item) const {
        return find(elements.begin(), elements.end(), item) != elements.end();
    }

    void remove(const T& item) {
        auto it = find(elements.begin(), elements.end(), item);
        if (it != elements.end()) {
            elements.erase(it);
        }
    }

    size_t size() const {
        return elements.size();
    }

    Set operator-(const T& item) const {
        Set result = *this;
        result.remove(item);
        return result;
    }

    Set operator*(const Set& other) const {
        Set result;
        for (const T& item : elements) {
            if (other.contains(item)) {
                result.add(item);
            }
        }
        return result;
    }

    bool operator<(const Set& other) const {
        for (const T& item : elements) {
            if (!other.contains(item)) {
                return false;
            }
        }
        return size() < other.size();
    }

    friend ostream& operator<<(ostream& os, const Set& set) {
        os << "{ ";
        for (size_t i = 0; i < set.elements.size(); ++i) {
            os << set.elements[i];
            if (i + 1 < set.elements.size()) os << ", ";
        }
        os << " }";
        return os;
    }
};

template<typename T>
Set<T> inputSet(const string& prompt) {
    cout << prompt;
    int n;
    cin >> n;
    Set<T> set;
    cout << "Введите " << n << " элементов(а): ";
    for (int i = 0; i < n; ++i) {
        T item;
        cin >> item;
        set.add(item);
    }
    return set;
}

int main() {
    Set<int> setA = inputSet<int>("Введите размер первого множества: ");
    Set<int> setB = inputSet<int>("Введите размер второго множества: ");

    cout << "\nМножество A: " << setA << endl;
    cout << "Множество B: " << setB << endl;

    cout << "\n--- Операции ---\n";

    int elem;
    cout << "Введите элемент для удаления из A (setA - elem): ";
    cin >> elem;
    Set<int> setA_minus = setA - elem;
    cout << "A - " << elem << " = " << setA_minus << endl;

    Set<int> intersection = setA * setB;
    cout << "A * B (пересечение) = " << intersection << endl;

    cout << "A < B (A строгое подмножество B)? " << (setA < setB ? "да" : "нет") << endl;
    cout << "B < A (B строгое подмножество A)? " << (setB < setA ? "да" : "нет") << endl;

    return 0;
}
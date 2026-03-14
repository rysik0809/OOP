#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
class Set {
    private:
        std::vector<T> elements; 

    public:
        Set() = default;

        Set(std::initializer_list<T> list) {
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
            return std::find(elements.begin(), elements.end(), item) != elements.end();
        }

        void remove(const T& item) {
            auto it = std::find(elements.begin(), elements.end(), item);
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

        friend std::ostream& operator<<(std::ostream& os, const Set& set) {
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
Set<T> inputSet(const std::string& prompt) {
    std::cout << prompt;
    int n;
    std::cin >> n;
    Set<T> set;
    std::cout << "Введите " << n << " элементов(а): ";
    for (int i = 0; i < n; ++i) {
        T item;
        std::cin >> item;
        set.add(item);
    }
    return set;
}

int main() {
    Set<int> setA = inputSet<int>("Введите размер первого множества: ");
    Set<int> setB = inputSet<int>("Введите размер второго множества: ");

    std::cout << "\nМножество A: " << setA << std::endl;
    std::cout << "Множество B: " << setB << std::endl;

    std::cout << "\n--- Операции ---\n";

    int elem;
    std::cout << "Введите элемент для удаления из A (setA - elem): ";
    std::cin >> elem;
    Set<int> setA_minus = setA - elem;
    std::cout << "A - " << elem << " = " << setA_minus << std::endl;

    Set<int> intersection = setA * setB;
    std::cout << "A * B (пересечение) = " << intersection << std::endl;

    std::cout << "A < B (A строгое подмножество B)? " << (setA < setB ? "да" : "нет") << std::endl;
    std::cout << "B < A (B строгое подмножество A)? " << (setB < setA ? "да" : "нет") << std::endl;

    return 0;
}
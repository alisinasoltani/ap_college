#include <iostream>
#include <exception>
#include <vector>
#include <fstream>
#include <string>

class RandomError : public std::exception {
    const char* msg;
    public:
        RandomError(const char* msg): msg(msg) {}
        const char* what() const noexcept {
            return this->msg;
        }
};


struct Main {
    int a, b;
    Main(int a, int b): a(a), b(b) {}
    Main(const Main& m): a(m.a), b(m.b) {}
};

template<typename T, int N>
class Array {
    private:
        std::vector<T> arr;
    public:
        Array() {
            arr.reserve(N);
        }
};

int main() {
    // std::vector<Main> vecy;
    // vecy.reserve(3);
    // int a, b;
    // for (int i = 0; i < 20; i++) {
    //     std::cin >> a;
    //     std::cin >> b;
    //     vecy.emplace_back(Main(a, b));
    //     std::cout << "size: " << vecy.size() << std::endl;
    //     std::cout << "capacity: " << vecy.capacity() << std::endl;
    // }
    // Array<int, 5> a;
    std::fstream file;
    std::string line;
    file.open("h.txt", std::ios::in | std::ios::out);
    if (file.is_open()) {
        while (std::getline(file, line)) {
            std::cout << line << std::endl;
        }
    } 
    file.close();

    return 0;
}
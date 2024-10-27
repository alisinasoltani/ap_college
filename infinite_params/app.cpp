#include <cstdarg>
#include <iostream>
 
using namespace std;

void add_nums(int count...)
{
    int result = 0;
    std::va_list args;
    va_start(args, count);
    std::cout << count;
    for (int i = 0; i < count; ++i)
        result += va_arg(args, int);
    va_end(args);
    // return result;
}

void askSaman(string count...) {
    cout << count << endl;
}
 
int main()
{
    askSaman("Asus", "1200", "Lenevo", "5200", "MacBook", "4500");
}
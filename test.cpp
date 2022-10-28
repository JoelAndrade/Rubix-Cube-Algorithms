#include <iostream>
#include <string>

int main() {
    std::string text = "myString";

    std::cout << text << std::endl;

    for (int i = 0; i < text.length(); ++i) {
        if (i == text.find("t", i)) {
            text.erase(i, 1);
            --i;
        }
    }

    std::cout << text << std::endl;
}
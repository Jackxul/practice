#include <iostream>
#include <cstring>
#include <string>

int main() {
    std::string line = "Hello, World!";
    const char* comma = ",";
    size_t pos = line.find('\0');
    line[pos] = '\0';

    char* field = strtok(const_cast<char*>(line.c_str()), comma);

    while (field != nullptr) {
        std::cout << field << std::endl;
        field = strtok(nullptr, comma);
    }

    return 0;
}


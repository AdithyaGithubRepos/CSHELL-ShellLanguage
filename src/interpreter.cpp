#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <cstring> 
#include <stdexcept> 

bool hasExt(const std::string& filename) {
    const std::string ext = ".shll";
    return filename.size() >= ext.size() &&
           filename.compare(filename.size() - ext.size(), ext.size(), ext) == 0;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Correct usage: seashell *.shll\n" << std::endl;
        return EXIT_FAILURE;
    }

    std::string filename = argv[1];
    if (!hasExt(filename)) {
        std::cerr << "File must have a .shll extension.\n" << std::endl;
        return EXIT_FAILURE;
    }

    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Unable to open file: " << filename << std::endl;
        return EXIT_FAILURE;
    }

    std::string line;
    int num1_2 = 0;
    int num2_2 = 0;
    int result_2 = 0;

    while (getline(file, line)) {
        if (strcmp(line.c_str(), "speak->") == 0) {
            if (getline(file, line)) {
                std::cout << line << std::endl;
            }
        } else if (strcmp(line.c_str(), "+operation_num_2->") == 0) {
            bool stopProcessing = false;
            for (int i = 0; i < 2; ++i) {
                if (!getline(file, line)) {
                    stopProcessing = true;
                    break;
                }
                if (line == "[stop]") {
                    std::cout << "Stopping operation_num_2 processing" << std::endl;
                    stopProcessing = true;
                    break;
                }
                try {
                    int num = std::stoi(line);
                    if (i == 0) {
                        num1_2 = num;
                    } else {
                        num2_2 = num;
                    }
                } catch (const std::invalid_argument& e) {
                    std::cerr << "Invalid number: " << line << std::endl;
                }
            }
            if (!stopProcessing) {
                result_2 = num1_2 + num2_2;
                std::cout << "Result: " << result_2 << std::endl;
                num1_2 = 0;
                num2_2 = 0;
            }
        } else if (strcmp(line.c_str(), "-operation_num_2->"))
        {
            bool stopProcessing = false;
            for (int i = 0; i < 2; ++i) {
                if (!getline(file, line)) {
                    stopProcessing = true;
                    break;
                }
                if (line == "[stop]") {
                    stopProcessing = true;
                    break;
                }
                try {
                    int num = std::stoi(line);
                    if (i == 0) {
                        num1_2 = num;
                    } else {
                        num2_2 = num;
                    }
                } catch (const std::invalid_argument& e) {
                    std::cerr << "Invalid number: " << line << std::endl;
                }
            }
            if (!stopProcessing) {
                result_2 = num1_2 - num2_2;
                std::cout << "Result: " << result_2 << std::endl;
                num1_2 = 0;
                num2_2 = 0;
            }
        } else if (strcmp(line.c_str(), "*operation_num_2->"))
        {
            bool stopProcessing = false;
            for (int i = 0; i < 2; ++i) {
                if (!getline(file, line)) {
                    stopProcessing = true;
                    break;
                }
                if (line == "[stop]") {
                    stopProcessing = true;
                    break;
                }
                try {
                    int num = std::stoi(line);
                    if (i == 0) {
                        num1_2 = num;
                    } else {
                        num2_2 = num;
                    }
                } catch (const std::invalid_argument& e) {
                    std::cerr << "Invalid number: " << line << std::endl;
                }
            }
            if (!stopProcessing) {
                result_2 = num1_2 * num2_2;
                std::cout << "Result: " << result_2 << std::endl;
                num1_2 = 0;
                num2_2 = 0;
            }
        } else if (strcmp(line.c_str(), "/operation_num_2->"))
        {
            bool stopProcessing = false;
            for (int i = 0; i < 2; ++i) {
                if (!getline(file, line)) {
                    stopProcessing = true;
                    break;
                }
                if (line == "[stop]") {
                    stopProcessing = true;
                    break;
                }
                try {
                    int num = std::stoi(line);
                    if (i == 0) {
                        num1_2 = num;
                    } else {
                        num2_2 = num;
                    }
                } catch (const std::invalid_argument& e) {
                    std::cerr << "Invalid number: " << line << std::endl;
                }
            }
            if (!stopProcessing) {
                result_2 = num1_2 / num2_2;
                std::cout << "Result: " << result_2 << std::endl;
                num1_2 = 0;
                num2_2 = 0;
            }
        }
    }

    file.close();
    return 0;
}

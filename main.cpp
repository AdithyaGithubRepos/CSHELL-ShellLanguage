#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cstring>

std::string toWrite; 

void write(const std::string &filename)
{
    std::ofstream outfile(filename);
    if (outfile.is_open())
    {
        outfile << "#include \"stdio.h\"\n";
        outfile << "#include \"stdlib.h\"\n\n";
        outfile << "int main() {\n";
        outfile << "    printf(\"-- Compiled in CSHELL --\\n\");\n";
        outfile << "    " << toWrite << "\n";
        outfile << "    return 0;\n";
        outfile << "}\n";
        outfile.close();
        std::cout << "Main method written to " << filename << std::endl;
    }
    else
    {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }
}

void apndStr(const std::string &filename, const std::string &speakvar)
{
    std::ofstream outfile(filename, std::ios_base::app);
    if (outfile.is_open())
    {
        outfile << "    printf(\"" << speakvar << "\\n\");\n";
        outfile.close();
       
    }
    else
    {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }

   
    toWrite += "    printf(\"" + speakvar + "\\n\");\n";
}

void compile(const std::string &filename)
{
    std::string command = "gcc -o out.exe " + filename;
    int result = system(command.c_str());
    if (result == 0)
    {
        std::cout << "Compilation successful. Please execute your output file in the current directory." << std::endl;
    }
    else
    {
        std::cerr << "Compilation failed. For more troubleshooting, please check your .c file." << std::endl;
    }
}

int main(int argc, char *argv[])
{
    std::string choice;
    std::string filename = "out.c"; 

    if (argc > 1 && std::strcmp(argv[1], "--version") == 0)
    {
        std::cout << "C-Shell, a simple shell-based language for beginners which directly compiles to machine code.\n";
        std::cout << "VERSION: al.0\n";
        std::cout << "Type .. --help for list of available commands supported in your version.\n";
    }
    else if (argc > 1 && std::strcmp(argv[1], "-init") == 0)
    {
        write(filename); 

        while (true)
        {
            std::cout << "cshell>> ";
            std::cin >> choice;
            if (choice == "hi")
            {
                std::cout << "Hello! :D\n";
            }
            else if (choice == "exit")
            {
                exit(EXIT_SUCCESS);
            }
            else if (choice == "compile")
            {
                write(filename);
                compile(filename);
            }
            else if (choice == "speak")
            {
                std::cout << "prnt>> ";
                std::cin.ignore(); 
                std::string speakvar;
                std::getline(std::cin, speakvar); 
                apndStr(filename, speakvar); 
            }
        }
    }
    else if (argc > 1 && std::strcmp(argv[1], "-ex") == 0)
    {
        exit(EXIT_SUCCESS);
    }
    else if (argc > 1 && std::strcmp(argv[1], "--help") == 0)
    {
        std::cout << "-ex === Exit the shell.\n";
        std::cout << "-init === Initiate the shell.\n";
        std::cout << "-o === Compile your out.c file.\n";
        std::cout << "...\n";
        std::cout << "...\n";
        std::cout << "...\n";
        std::cout << "...\n";
        std::cout << "...\n";
    }

    return 0;
}

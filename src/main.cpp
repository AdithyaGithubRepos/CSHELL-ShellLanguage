#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cstring>

std::string toWriteString;
std::string toWriteOper;
std::string operchoice;
int num1;
int num2;
std::string num1Declaration;
std::string num2Declaration;
std::string resultDeclaration;
std::string resultInit;

void write(const std::string &filename)
{
    std::ofstream outfile(filename);
    if (outfile.is_open())
    {
        outfile << "#include \"stdio.h\"\n";
        outfile << "#include \"stdlib.h\"\n\n";
        outfile << num1Declaration << "\n\n";
        outfile << num2Declaration << "\n\n";
        outfile << resultDeclaration << "\n\n";
        outfile << "int main() {\n";
        outfile << "    printf(\"-- Compiled in CSHELL --\\n\");\n";
        outfile << "    " << toWriteString << "\n";
        outfile << "    " << resultInit << "\n";
        outfile << "    " << toWriteOper << "\n";
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
    toWriteString += "    printf(\"" + speakvar + "\\n\");\n";
}

void compile(const std::string &filename)
{
    std::string command = "gcc -o out.exe " + filename + " && del out.c";
    int result = system(command.c_str());
    if (result == 0)
    {
        std::cout << "Compilation successful. Please execute your output file in the current directory." << std::endl;
    }
    else
    {
        std::cerr << "Compilation failed. For more troubleshooting, please check your .c file." << std::endl;
        std::string command = "gcc -o out.exe " + filename + " && rm out.c";
    }
}

void apndOper(int num1, int num2,  const std::string &filename)
{
    toWriteOper += "printf(\"%d\", result);";
    num1Declaration += "int num1 = " + std::to_string(num1) + ";";
    num2Declaration += "int num2 = " + std::to_string(num2) + ";";
    resultDeclaration += "int result;";
    resultInit += "result = num1+num2;";
}

void compileAndKeep(const std::string &filename)
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
        std::cout << "VERSION: 0.0.3\n";
        std::cout << "Type .. --help for list of available commands supported in your version.\n";
    }
    if (argc < 2)
    {
        std::cout << "invalid argument. Type [..] --help for list of commands supported in your version." << std::endl;
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
            else if (choice == "compile_keep_c")
            {
                write(filename);
                compileAndKeep(filename);
            } else if(choice == "operation")
            {
                std::cout << "Which operation?\n" << std::endl;
                std::cout << "+, -, *, / ??" << std::endl;
                std::cout << "Choose one.\n" << std::endl;
                std::cin >> operchoice;
                std::cout << "Enter the first number." << std::endl;
                std::cin >> num1;
                std::cout << num1;
                std::cout << "Enter the second number." << std::endl;
                std::cin >> num2;
                apndOper(num1, num2, operchoice);
                
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
        std::cout << "----------------CShell Functions--------------" << std::endl;
        std::cout << "\"operation\" to perform an operation. Only one at a time as of release 0.0.3\n";
        std::cout << "\"speak\" to make a print statement. Only one at a time possible as of release 0.0.3.\n";
        std::cout << "...\n";
        std::cout << "...\n";
        std::cout << "...\n";
    }

    return 0;
}
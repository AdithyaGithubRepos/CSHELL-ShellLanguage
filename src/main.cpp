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
int condition;
int i_value;
std::string inc;
std::string loopwrite;
std::string inc_choice;
std::string loopcommands;
std::string looparg;
std::string loopprint;

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
        outfile << "    " << loopwrite << "\n";
        outfile << "    " << looparg << "\n";
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

void apndOper(int num1, int num2, const std::string &filename)
{
    toWriteOper += "printf(\"%d\", result);";
    num1Declaration += "int num1 = " + std::to_string(num1) + ";";
    num2Declaration += "int num2 = " + std::to_string(num2) + ";";
    resultDeclaration += "int result;";
    resultInit += "result = num1+num2;";
}

void apndLoop(int i_value, int condition, const std::string &filename)
{
    while (true)
    {
        std::cout << "loop>>";
        std::cin >> loopcommands;
        if (loopcommands == "speak")
        {
            std::cout << "print(loop)>>";
            std::cin >> loopprint;
            looparg += "printf(\"" + loopprint + "\");\n";
            break;
        }
    }
    loopwrite += "for(int i = " + std::to_string(i_value) + "; i <= " + std::to_string(condition) + "; " + inc + ") {\n\n\n\n\n" + looparg + "}\n";
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
        std::cerr << "Compilation failed. For more troubleshooting, please check your .c file.\n To keep the C file after compilation, type ||compile_keep_c ||." << std::endl;
    }
}

int main(int argc, char *argv[])
{
    std::string choice;
    std::string filename = "out.c";

    if (argc > 1 && std::strcmp(argv[1], "--version") == 0)
    {
        std::cout << "C-Shell, a simple shell-based language for beginners which directly compiles to machine code.\n";
        std::cout << "VERSION: 0.0.5\n";
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
            }
            else if (choice == "operation")
            {
                std::cout << "Which operation?\n"
                          << std::endl;
                std::cout << "+, -, *, / ??" << std::endl;
                std::cout << "Choose one.\n"
                          << std::endl;
                std::cin >> operchoice;
                std::cout << "Enter the first number." << std::endl;
                std::cin >> num1;
                std::cout << num1;
                std::cout << "Enter the second number." << std::endl;
                std::cin >> num2;
                apndOper(num1, num2, operchoice);
            }
            else if (choice == "loop")
            {
                std::cout << "Enter value of i\n";
                std::cin >> i_value;
                std::cout << "Enter number which i will be less than or equal to (Only as of v...3)\n";
                std::cin >> condition;
                std::cout << "Decrement or increment? type i for increment and d for decrement.";
                std::cin >> inc_choice;
                if (inc_choice == "i")
                {
                    inc += "i++";
                }
                else if (inc_choice == "d")
                {
                    inc += "i--";
                }
                else
                {
                    std::cout << "invalid choice.";
                }
                apndLoop(i_value, condition, filename);
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
        std::cout << ".. -rmout === remove out files (may be dangerous if used in incorrect directories, careful!)\n";
        std::cout << "...\n";
        std::cout << "...\n";
    }
    else if (argc > 1 && std::strcmp(argv[1], "-rmout") == 0)
    {
        std::string rmcommand = "rm out.c && rm out.exe";  
        std::string delcommand = "del out.c && del out.exe";      
        int result = system(rmcommand.c_str());
        if (result == 0)
        {
            std::cout << "Successfully removed output files from current directory.";
        }
        else
        {
            int attempt2 = system(delcommand.c_str());
            if (attempt2 == 0)
            {
                std::cout << "Removed.";
            }
            else
            {
                std::cout << "Remove operation failed. There are a number of possible reasons::\n";
                std::cout << "1. Failed to detect files in parent directory\n";
                std::cout << "2. Folder requires administrative priveleges to read or write\n";
                std::cout << "3. Your current terminal doesn't supoort these commands:\n 1. rm filename.*\n 2. del filename.*";
            }
        }
    }

    return 0;
}
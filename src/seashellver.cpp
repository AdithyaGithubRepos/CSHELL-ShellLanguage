#include "iostream"
#include "cstring"

int main(int argc, char *argv[])
{
if(argc!=2)
{
    std::cout << "usage: --version\n usage: --upd\n";
}
     
    if (argc > 2 && std::strcmp(argv[1], "--version"))
    {
        std::cout << "Seashell, an extremely simple programming language for beginners to learn coding.\n"
                  << std::endl;
        std::cout << "Seashell is based on scratch, (basically a port of scratch but you have to type instead of code blocks)\n"
                  << std::endl;
        std::cout << "VERSION 1.0.0\n"
                  << std::endl;
    }
    if (argc > 2 && std::strcmp(argv[1], "--upd"))
    {
        std::cout << "Version 1.0.0\n";
        std::cout << "Added bare minimum, including operations and printing.\n ONLY 2 NUMBERS SUPPORTED FOR OPERATIONS!\n";
    }
    
}
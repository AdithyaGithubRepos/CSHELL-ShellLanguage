#include "iostream"
#include "string"
#include "cstring"
#include "streambuf"
#include "fstream"
#include "cstdlib"

std::string toWrite = "//Out file of CSHELL";

std::string filename;

void write(const std::string &filename)
{
   std::ofstream outfile(filename);
   if (outfile.is_open())
   {
      outfile << "#include \"stdio.h\"\n";
      outfile << "#include \"stdlib.h\"\n\n";
      outfile << "int main(){\n\n";
      outfile << "printf(\"Hello world!\");\n";
      outfile << (toWrite, "\n");
      outfile << "return 0;\n";
      outfile << "\n}\n";
      outfile.close();
      
   }
}

void apndPrint(const std::string &filename)
{
  
}

void compile(const std::string& filename)
{
   std::string command = "gcc -o out.exe out.c";
   int result = system(command.c_str());
   if(result==0)
   {
      std::cout << "Compilation successful. Please execute your output file in the current directory." << std::endl;
   } else if(result>1) {
      std::cout << "Compilation failed. For more troubleshooting, please check your .c file." << std::endl;
   }
}

int main(int argc, char *argv[])
{
   std::string choice;
   if (argc > 1 && std::strcmp(argv[1], "--version") == 0)
   {
      printf("C-Shell, a simple shell based language for beginners which directly compiles to machine code.\n");
      printf("VERSION: al.0\n");
      printf("Type .. --help for list of available commands supported in your version.\n");
   }
   if (argc > 1 && std::strcmp(argv[1], "-init") == 0)
   {
      while (true)
      {
         printf("cshell>>");
         std::cin >> choice;
         if (choice == "hi")
         {
            printf("Hello! :D\n");
         }
         if (choice == "exit")
         {
            exit(EXIT_SUCCESS);
         }
      }
   }
   if (argc > 1 && std::strcmp(argv[1], "-ex") == 0)
   {
      exit(EXIT_SUCCESS);
   }
   if (argc > 1 && std::strcmp(argv[1], "--help") == 0)
   {
      printf("-ex === Exit the shell.\n");
      printf("-init === Initiate the shell.\n");
      printf("-o === Compile your out.c file.\n");
      printf("...\n");
      printf("...\n");
      printf("...\n");
      printf("...\n");
      printf("...\n");
   }
   if(argc > 1 && std::strcmp(argv[1], "-out")==0)
   { 
      std::string filename = "out.c";
      write(filename);
      compile(filename);
      printf("The main method of your output file was written to: out.c ");
   } 
}
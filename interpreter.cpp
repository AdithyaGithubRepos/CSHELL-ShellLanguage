#include "iostream"
#include "cstdlib"
#include "string"
#include "fstream"

bool hasExt(const std::string& filename)
{
   const std::string ext = ".shll";
   if (filename.size() >= ext.size() && filename.compare(filename.size() - ext.size(), ext.size(), ext)==0)
   {
    return true;
   }
   return false;
}

int main(int argc, char* argv[])
{
   if(argc!=2)
   {
    std::cerr << "Correct usage: seashell *.shll\n" << std::endl;
    exit(EXIT_FAILURE);
   }

   std::string filename = argv[1];

   if(!hasExt(filename))
   {
    std::cerr << "File must have a .shll extension.\n" << std::endl;
    exit(EXIT_FAILURE);
   }

   std::ifstream file(filename);
   std::string line;

   if(file.is_open())
   {
    while (getline(file, line))
    {
        if (line=="happy")
        {
            std::cout << "I'm happy too!" << std::endl;
        }
    }
   }

}


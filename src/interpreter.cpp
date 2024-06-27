#include "iostream"
#include "cstdlib"
#include "string"
#include "fstream"
#include "cstring"

int num1_2;
int num2_2;
int result_2;



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
   if (argc != 2)
    {
        std::cerr << "Correct usage: seashell *.shll\n"
                  << std::endl;
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
        if (line=="speak->")
        {
           
           if (getline(file, line))
           {
            line;        
           }
           if (getline(file, line))
           {
            if (line=="[stop]")
            {
                std::cout << line;
                continue;
            }
            else {
                std::cerr << "Error: Expected [stop] after function." << std::endl;
                exit(EXIT_FAILURE);
            }
           }
        }
         bool continueProcessing = true;

        if (line=="operation_num_2->" && continueProcessing);
        {       
              
           try {
            if (getline(file, line))
            {
                num1_2 += std::stoi(line);
            }
           } catch (std::invalid_argument& ex) {
            std::cerr << "Invalid integer." << std::endl;
            exit(EXIT_FAILURE);
           }
            try {
            if (getline(file, line))
            {
                num2_2 += std::stoi(line);
            }
           } catch (std::invalid_argument& ex) {
            std::cerr << "Invalid integer." << std::endl;
            exit(EXIT_FAILURE);
           }
           if (getline(file,line))
           {
            if (line=="[stop]")
            {
                result_2 += num1_2 + num2_2;
                std::cout << result_2 << std::endl;
                continueProcessing = false;
                continue;
            } else {
                std::cerr << "Error: Expected [stop] keyword after operation." << std::endl;
                exit(EXIT_FAILURE);
            }
           }
        }

    }
   }

}


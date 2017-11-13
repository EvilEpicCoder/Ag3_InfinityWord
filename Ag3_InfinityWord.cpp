#include "Ag3_InfinityWord.h"
using namespace std;

int main(int argc, char const *argv[]);
static void show_usage(string name);
std::string buffer;
std::string infile,outfile,code,addition;


static void show_usage(string name)
{
cerr << "Usage: " << name << " <option(s)>"
              << "\nOptions:\n"
              << "\t-h,--help\t\tShow this help message\n"
              << "\t-i,--input INPUT file\n"
              << "\t-o,--output OUTPUT file\n"
              << "\t-c,--code string RU2EN EN2RU RU2ES RU2PL\n"
              << "\t-a adding string as _num, num, dd:mm:yy\n"
              << "\tUsage: Ag3 input.list output.list -code RU2EN -add dd.mm.yyyy-dd.mm.yyyy \n"
            	<< "\tUsage: Ag3 input.list output.list -code RU2EN -add _num 0-9999 \n"
              << std::endl;
}

int main(int argc, char const *argv[]){
  if (argc < 3) {
       show_usage(argv[0]);
       return 1;
   }
   std::vector <std::string> sources;

   for (int i = 0; i < argc; i++) {
       std::string arg = argv[i];
       if ((arg == "-h") || (arg == "--help")) {
           show_usage(argv[0]);
           return 0;
       } else if ((arg == "-i") || (arg == "--input")) {
         if (i + 1 < argc) {
           infile = argv[i+1];
           cout<<infile;
         } else {
           std::cerr << " input file is incorrect" << std::endl;
           return 1;
         }
       } else if ((arg == "-o") || (arg == "--output")){
         if (i + 1 < argc) {
           outfile = argv[i+1];
           cout<<outfile;
         } else {
           std::cerr << " output file is incorrect" << std::endl;
           return 1;
         }   //sources.push_back(argv[i]);
       }else if ((arg == "-c") || (arg == "--code")){
         if (i + 1 < argc) {
           code = argv[i+1];
           cout<<code;
         } else {
           std::cerr << " code for direction of transcofing is incorrect" << std::endl;
           return 1;
         }
       }else if ((arg == "-a") || (arg == "--add")){
         if (i + 1 < argc) {
           addition = argv[i+1];
           cout<<addition;
         } else {
           std::cerr << " code for direction of transcofing is incorrect" << std::endl;
           return 1;
         }
       }
     }
     std::ifstream myfile(infile.c_str());
     std::ofstream myoutfile(outfile.c_str());
     if (myfile.is_open())
     {
       while ( getline (myfile,buffer) )
         {
           myoutfile << buffer << '\n';
         }
         myfile.close();
       }
  return 0;
}

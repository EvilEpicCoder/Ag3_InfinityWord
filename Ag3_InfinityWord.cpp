#include "Ag3_InfinityWord.h"
using namespace std;

int main(int argc, char const *argv[]);
static void show_usage(string name);
std::string buffer;
std::string infile,outfile,code,addition;
std::string code;
std::string add;
char RU[75]={'Й','Ц','У','К','Е','Н','Г','Ш','Щ','З','Х','Ъ','Ф','Ы','В','А','П','Р','О','Л','Д','Ж','Э' ,'/','|','Я','Ч','С','М','И','Т','Ь','Б','Ю',',' ,'й','ц','у','к','е','н','г','ш','щ','з','х','ъ','ф','ы','в','а','п','р','о','л','д','ж','э' ,'\\','/','я','ч','с','м','и','т','ь','б','ю','.'};
char EN[75]={'Q','W','E','R','T','Y','U','I','O','P','{','}','A','S','D','F','G','H','J','K','L',':','\"','|','>','Z','X','C','V','B','N','M','<','>','\?','q','w','e','r','t','y','u','i','o','p','[',']','a','s','d','f','g','h','j','k','l',';','\'','\\','<','z','x','c','v','b','n','m',',','.','/'};

static void show_usage(string name)
{
cerr << "Usage: " << name << " <option(s)>"
              << "\nOptions:\n"
              << "\t-h,--help\t\tShow this help message\n"
              << "\t-i,--input\t\tINPUT file\n"
              << "\t-o,--output\t\tOUTPUT file\n"
              << "\t-c,--code\t\tstring RU2EN EN2RU RU2ES RU2PL\n"
              << "\t-a,--add\t\tadding string as _num, num, dd:mm:yy\n"
              << "\tUsage: ./Ag3_InfinityWord -i input.list -o output.list -c RU2EN -a dd.mm.yyyy-dd.mm.yyyy \n"
            	<< "\tUsage: ./Ag3_InfinityWord --input input.list --output output.list --code RU2EN --add _num 0-9999 \n"
              << std::endl;
}

int main(int argc, char const *argv[]){
  setlocale(LC_ALL,"Russian");
  //setlocale(LC_CTYPE, "rus");
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
    //std::locale::global(std::locale("ru_RU.utf8"));
    if (myfile.is_open())
    {
      // for(wchar_t c; myfile.get(c); ){
      //   myoutfile<<c<<'\n';
      // }
      for(char c; myfile.get(c); ){
        if(c=='\n'){
          myoutfile <<'\n';
        }
          for(int b=0;b<75;b++){
            if(c==RU[b]){
              myoutfile << EN[b];
            }
          }

        }
      myfile.close();
      myoutfile.close();
    }
  return 0;
}

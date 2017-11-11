#include "Ag3_InfinityWord.h"

int main(int argc, char const *argv[]);
using namespace std;
string a;

int main(int argc, char const *argv[]) {
  /* code */
  cout<<"Usage: Ag3 input.list output.list -code RU2EN -add dd.mm.yyyy-dd.mm.yyyy \n";
	cout<<"Usage: Ag3 input.list output.list -code RU2EN -add _num 0-9999 \n";
	switch(argc) {
        case 0: cout<<"no input file specified";
        case 1: cout<<"no output file specified";
        case 2: cout<<"no direction transcode specified";
        case 3: cout<<"no additional generetion specified";
        default: cout<<"Starting word generator";
    }
	cout<<argv[1]<<" input file";
	cout<<argv[2]<<" output file";
	cout<<argv[3]<<" -code"<<argv[4];
	if (argv[5]=="-add"&&argv[6]){
		cout<<argv[5]<<" -code"<<argv[6];
	}
	ifstream ifs("input.txt");
    cin.rdbuf(ifs.rdbuf());

    cin>>a;
    ifs.close();
    ofstream ofs("output.txt");
    cout.rdbuf(ofs.rdbuf());
    cout<<a;
    ofs.close();
     return 0;
  return 0;
}

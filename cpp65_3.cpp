#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

class file {
	protected:
    	ifstream inFile;      
		virtual void math() ;
    public:
    	
		 void start(char* file);
        ~file();
};
void file::math(){}
void file::start(char* file) {
	
    inFile.open(file);
    if (!inFile.good())
        {
        	cerr << "Error-File cannot be accesed";
            exit(1);
        }
        math();
}
file::~file() {
    inFile.close();
}



class ex65_3 :public  file
{
    int num1,num2,result;
    int nwd(int a, int b);
    
    virtual void math();
    
};
void ex65_3::math(){
    
    for(int i=0;i<1000;++i){
        inFile>>num1;
        inFile>>num2;
        result+=num1/nwd(num1,num2);
        
    }
    
    cout<<result;
    
}
int ex65_3::nwd(int a, int b)
{
    if(b==0)
        return a;
   return nwd(b, a%b);
}

int main(int argc, char** argv) {
    ex65_3 kva;
    kva.start(argv[1]);
    return 0;
}

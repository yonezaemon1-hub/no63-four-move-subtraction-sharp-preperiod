#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <stdexcept>
using namespace std;
int main(int argc,char**argv){
 const int MAXC = argc>=2?atoi(argv[1]):1501;
 if(MAXC<23 || !(MAXC&1)){cerr<<"maxc must be odd >=23\n";return 2;}
 const string W="000111022133020",E="12103";
 long long total=0;
 for(int c=23;c<=MAXC;c+=2){
   int limit=6*c+30;vector<unsigned char> g(limit+1,0);
   for(int n=0;n<=limit;n++){
    int mask=0; for(int s:{3,7,9,c})if(n>=s)mask |= 1<<g[n-s];
    int nim=0;while(mask & (1<<nim))++nim;g[n]=nim;
    int expected=(n<15)?W[n]-'0': (n<c)?(n&1): (n<c+5)?E[n-c]-'0':n&1;
    if(nim!=expected){cerr<<"FAIL c="<<c<<" n="<<n<<" got="<<nim<<" expected="<<expected<<"\n";return 1;}
   }
   if(g[c+4]==g[c+6] || g[c+5]==g[c+6]){cerr<<"minimality fail c="<<c<<"\n";return 1;}
   total+=limit+1;
 }
 cout<<"INDEPENDENT_CPP_FINITE_PASS max_c="<<MAXC<<" checked_positions="<<total<<"\n";
}

// Independent exact finite-state certificates for six small c cases.
// Does not invoke Python or look at a prior computed sequence.
#include <iostream>
#include <string>
#include <vector>
#include <array>
using namespace std;
int main(){
 const string W="000111022133020";
 const array<int,6> cs{11,13,15,17,19,21};
 const array<string,6> extra{"32203","", "13102","12103","14102","13102"};
 int checks=0;
 for(int i=0;i<6;i++){
  int c=cs[i],T=(c==13?0:c+5),p=(c==13?16:2),N=T+c+p-1;
  string prefix;
  if(c==13)prefix="0001110221330241";
  else {
   prefix=(c<15?W.substr(0,c):W+string((c-15), ' '));
   if(c>=15){for(int j=15;j<c;j++)prefix[j]=(j&1)?'1':'0';}
   prefix+=extra[i];
  }
  auto val=[&](int n)->int{
   if(c==13)return prefix[n%p]-'0';
   if(n<T)return prefix[n]-'0';
   return n&1;
  };
  for(int n=0;n<=N;n++){
   int mask=0;
   for(int s:{3,7,9,c})if(n>=s)mask |= 1<<val(n-s);
   int mex=0;while(mask&(1<<mex))mex++;
   if(val(n)!=mex){cerr<<"FAIL c="<<c<<" n="<<n<<" v="<<val(n)<<" mex="<<mex<<"\n";return 1;}
   checks++;
  }
  if(T>0 && val(T-1)==val(T-1+p)) {cerr<<"FAIL minimal transient c="<<c<<"\n";return 1;}
  for(int d=1;d<p;d++)if(p%d==0){
   bool isPeriod=true;
   for(int n=T;n<T+p;n++)if(val(n)!=val(n+d)){isPeriod=false;break;}
   if(isPeriod){cerr<<"FAIL least period c="<<c<<"\n";return 1;}
  }
  cout<<"SMALL_CPP_PASS c="<<c<<" T="<<T<<" p="<<p<<" n=0.."<<N<<"\n";
 }
 cout<<"SMALL_INDEPENDENT_CERTIFICATES_PASS checks="<<checks<<"\n";
}

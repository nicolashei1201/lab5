#include<iostream>
#include<cstring>
#include<sstream>
using namespace std;
class HugeInt{
	friend istream &operator >>(istream & in,HugeInt &obj);
	friend ostream &operator <<(ostream & out,const HugeInt &obj);
	public:
	  HugeInt operator+(const HugeInt &k){
		HugeInt x(0);
		int carry=0;
		for(int i=0;i<25;++i){
		x.ptr[i]=carry+k.ptr[i]+ptr[i];
		  if(x.ptr[i]>=10){
		    x.ptr[i]%=10;
		    carry=1;		
		  }else{
		    carry=0;		
		  }
 		}
		return x;
	  }
	  HugeInt operator-(const HugeInt &k){
		HugeInt x(0);
		int borrow=0;
		for(int i=0;i<25;++i){
		x.ptr[i]=ptr[i]-k.ptr[i]-borrow;
		  if(x.ptr[i]<0){
		    x.ptr[i]+=10;
		    borrow=1;	
		  }else{
		    borrow=0;		
		  }
 		}
		return x;
	  }
	  HugeInt(int j=0){
		size=0;
		ptr=new int[25];
		for(int i=0;j!=0;++i){
		  ptr[i]=j%10;
		  ++size;
		  j/=10;
		}
	  }
	  HugeInt(string num){
		ptr=new int[25];
	 	string str;
		size=num.size(); 
		for(int i=size-1,j=0;i>=0;--i,++j){
		  str=num[i];
		  stringstream ss(str);
		  ss>>ptr[j];
		}
	  }
	  HugeInt operator = (const  HugeInt &rvalue){
	    for(int i=0;i<25;++i){
		ptr[i]=rvalue.ptr[i];
	    }
  	  }
	private:
	  //unsigned long long int a;
	  int* ptr;
	  int size;
};

istream &operator >>(istream&in,HugeInt&obj){
	string input;
	in>>input;
	HugeInt x(input);
	obj=x;
	return in;
}
ostream &operator <<(ostream&out,const HugeInt&obj){
	int size=0;
	for(int i=24;i>=0;--i){
	  if(obj.ptr[i]!=0){
		size=i+1;
		break;
	  }
	}
	for(int j=size-1;j>=0;--j){
		out<<obj.ptr[j];	
	}
	return out;
}


int main(){
 HugeInt x;
 HugeInt y(28825252);
 HugeInt z("314159265358979323846");
 HugeInt result;

 cin >> x;
 result = x+y;
 cout << x << "+" << y << " = " << result << endl;

 result = z - x;
 cout << result << endl;

 return 0;
}

#include<bits/stdc++.h>
#include<dirent.h>
#include<fstream>
//#include <filesystem>
using namespace std;
#include<algorithm>
#define all(c) c.begin(),c.end()
#define tr(container,it) for(typeof(container.begin()) it=container.begin();it!=container.end();it++)
#define present(container,element) container.find(element)!=container.end()//for set and maps
#define cpresent(container,element) find(all(container),element)!=container.end()//for vectors
#define f(i,n,k) for(int i=k;i<n;i++)
#define pb(v,k) v.push_back(k)

    //std::string path = "F:\Hackathon\ProblemStatementIITBHU\Grammar";
    //for (auto & p : fs::directory_iterator(path))
        //std::cout << p << std::endl;
       int number=0;
int max2(vector<int> v1,vector<float> v2){
	float p;
	int y=0;
float o=float(v1[0]);
float e=float(v2[0]);
float max;
max=(float)(o/e);
f(i,v1.size(),1){
	//1cout<<"Nm";
	o=float(v1[i]);
	e=float(v2[i]);
	p=(float)(o/e);
	if(p>max){
		y=i;
		max=p;
	}
}
return y;	
}
int max(vector<int> u){
	int l=u.size();
	int m=u[0];
	int y=0;
	f(i,l,0){
		if(u[i]>m) {
			m=u[i];
			y=i;
		}
	}
	return y;}
int max1(float u[]){
	float m=u[0];
	int y=0;
	f(i,10,0){
				if(u[i]>m) {
			m=u[i];
			y=i;
		}
	}
	return y;
}
int* lps(string s){
	int l=s.length();
	//int a[s.length()];
	int* a = (int*) malloc(sizeof(int)*s.length());
	a[0]=0;
	int j=1;
	int i=1;
	int len=0;
	while(i<l){
		if(s.at(i)==s.at(len)){
			len++;
			a[i]=len;
			i++;
		}
		else{
			if(len!=0){
				len=a[len-1];
			}
			else{
				a[i]=0;
				i++;
			}
		}
	}
	return a;
}
bool matches(string pat,string orig,int b[]){
	bool val=false;
	int m=orig.length()-1;
	int n=pat.length();
	f(u,n,0){
	//	cout<<"\n"<<b[u]<<"  ";
	}
	int i=0,j=0;
	while(i<m){
		if(orig.at(i)==pat.at(j)){
			i++;
			j++;
	//		cout<<"kmp1";
		}
		if(j==n){
			//matches++;
			val=true;
	//		cout<<"SDSASDASDAS";
			break;
		}
		else if((orig.at(i)!=pat.at(j))&&i<m){
			if(j!=0){
				j=b[j-1];
	//			cout<<"kmp3";
			}
			else i++;
			//cout<<"kmp4";
			}
		}
		return val;
	}       
int main () {
	string s1[10],sr;
	int you=1;
	s1[0]="CallByName.txt",s1[1]="CreateAlarmWithTime.txt",s1[2]="CreateEventWithTime.txt",s1[3]="CreateEventWithTimeAndPlace.txt",s1[4]="DateTimeInPlace.txt",s1[5]="DateTimeNow.txt",s1[6]="SendEmail.txt",s1[7]="WeatherInCity.txt",s1[8]="WeatherTimeCity.txt",s1[9]="BookTicket.txt";
	int n,initial,m;
	cin>>n;
	string s[n];
	f(i,n,0){
		cin>>s[i];
		//getline(cin,s[i]);
	}
//	int L=0;
	//int e[n];
	float h[10];
	f(x,10,0){
			  string line;
  ifstream myfile (s1[x].c_str());
 // if(myfile.is_open()){
  //	getline(myfile,line){
  	//	L++;
	  //}
 // }
  if(myfile.is_open()){
  	vector<int> v1;
  	vector<float> v2;
  	vector<string> s3;
  while(getline (myfile,line)){
  	//vector<int> v1;
  	//vector<string> s3;
  	number=0;
  	f(a,line.length()-1,0){
  		//cout<<"nm";
  		if(line.at(a)=='{'||line.at(a)=='}'||line.at(a)=='<'||line.at(a)=='>') number++;
	  }
	  cout<<"after is"<<number<<"the line is"<<"  "<<line<<"\n";
	  //cout<<"poi";
  	m=0;
	f(i,n,0){
		//int r=1;
  //cout<<"\n hey 1";
  //vector<string> s2;
		//string s1;
		//initial=0;
		//m=0;
		//int l=s[i].length();
		//e[i]=y;
		//if(myfile.is_open()){
			//vector<string> s3;
			//while(getline (myfile,line)){
				//cout<<"\n"<<line<<"\n";
				    //m=0;
					//f(p,y,0){
						//cout<<s2[p]<<"\n";
				int* a = (int*) malloc(sizeof(int)*s[i].length());	
				//cout<<"1";	
				a=lps(s[i]);
				//cout<<"2";
				bool v=matches(s[i],line,a);
				//cout<<"3";
				if(v){
					m++;
				}	
		}
		if(m==(number/2)){
			cout<<"\n"<<"found"<<"  "<<line<<"\n";
			cout<<s1[x]<<"   found    ";
			you=0;
			//cout<<"found"<<" "<<line<<"\n";
			//r=0;
			break;
		}
		else{
			//cout<<"not found"<<"\n";
			pb(v1,m);
			pb(s3,line);
			cout<<"number is"<<"  "<<number;
			pb(v2,number);
		}
	}
	if(m!=(number/2)){
		cout<<"v2 starts";
		f(t,v2.size(),0) cout<<v2[t]<<"\n";
		//int q=max(v1);
		int y=max2(v1,v2);
		float e=float(v1[y]);
		float o=float(v2[y]);
		h[x]=float(e/o);
		cout<<"here is you max one"<<s3[y]<<"\n";
		cout<<"v2[4]"<<v2[4]<<"\n";
		
	}
	else{
		myfile.close();
		//cout<<sr;
		break;
	}
	//f(o,)
	myfile.close();}
	
	}
	if(you==1){
			int maximum=max1(h);
	cout<<s1[maximum]<<" "<<"  "<<"   maximum   "<<" "<<h[maximum]<<" "<<h[5];
	}
	//if(r==1) break;
	}

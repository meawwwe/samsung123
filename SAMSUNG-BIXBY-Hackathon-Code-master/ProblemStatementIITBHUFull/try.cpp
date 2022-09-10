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
int main(){
	DIR* dirFile = opendir( "\Grammar");
if ( dirFile ) 
{
   struct dirent* hFile;
   errno = 0;
   while (( hFile = readdir( dirFile )) != NULL )
   {
      if ( !strcmp( hFile->d_name, "."  )) continue;
      if ( !strcmp( hFile->d_name, ".." )) continue;
      // in linux hidden files all start with '.'
      if ( ( hFile->d_name[0] == '.' )) continue;

      // dirFile.name is the name of the file. Do whatever string comparison 
      // you want here. Something like:
      if ( strstr( hFile->d_name, ".txt" ))
          printf( "%s\n", hFile->d_name );
   } 
   closedir( dirFile );
}
}

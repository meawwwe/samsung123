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
void computeLPSArray(string pat, int M, int *lps)
{

    int len = 0;

    lps[0] = 0;


    int i = 1;
    while (i < M)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len-1];

                }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }

}



bool KMPSearch(string pat, string txt)
{
    int M = 0;
    for(M=0;pat[M]!='\0';M++)
    {

    }
    M=M-1;
    int N = 0;
    for(N=0;txt[N]!='\0';N++)
    {
    }


    int lps[M];


    computeLPSArray(pat, M, lps);

    int i = 0;
    int j  = 0;

    while (i < N)
    {
        if (pat[j] == txt[i])
        {
            j++;
            i++;
        }
        if (j == M)
        {
            return true;
            j = lps[j-1];
        }


        else if (i < N && pat[j] != txt[i])
        {

            if (j != 0)
                j = lps[j-1];
            else
                i = i+1;
        }
    }
    return false;
}


bool concept(string input,string name)
{

    vector<string> concepts;


    //////////Reading from file(begin)//////////////
    ifstream infile;
    string url = "Concept/"+name+".txt";
    infile.open(url.c_str());
    string text;

    while(getline(infile,text))
    {
        concepts.push_back(text);
    }

    infile.close();
    //////////Reading from file(end)////////////////

    int flag=0;
    int counter=0;

    ///////Search if book concept is present in input//////
    for(counter=0;counter<concepts.size();counter++)
    {

        if(KMPSearch(concepts[counter],input))
            flag+=1;
    }

    if(flag>0)
        return true;
    else
        return false;
}

bool placeholder(string input,string name)
{
    vector<string> placeholder;
    //////////Reading from file(begin)//////////////
    ifstream infile;
    string url = "Placeholder-Modified/"+name+".txt";
    infile.open(url.c_str());
    string text;
    if(infile.fail())
        cout<<"Failed";

    while(getline(infile,text))
    {
        placeholder.push_back(text);
    }

    infile.close();
    //////////Reading from file(end)////////////////
    int flag=0;
    int counter=0;

    ///////Search if book concept is present in input//////
    for(counter=0;counter<placeholder.size();counter++)
    {

        if(KMPSearch(placeholder[counter],input))
            flag+=1;
    }

    if(flag>0)
        return true;
    else
        return false;
}


int main()
{string text;
cin>>text;
        string input=text;

    int you=1;

    vector<string> conceptsPresent;
    vector<string> placeHolders;
    vector<string> all;

    string bookCpt = "book_concept";///////////done
    string callCpt = "call_concept";///////////done
    string createCpt = "create_concept";///////done
    string emailCpt = "email_concept";////////done
    string messageCpt = "message_concept";////done
    string pleaseCpt = "please_concept";//////done
    string talkCpt = "talk_concept";/////////done
    string tellCpt = "tell_concept";////////done
    string wakeCpt = "wake_concept";////////done
    string weatherAct = "weather_activity";/////done
    string whatCpt = "what_concept";///////done
    string contactName = "contact_name";
    string places = "places";
    ///////////////CHECKING THE PRESENCE OF CONCEPTS AND PLACEHOLDERS//////////////////

        if(concept(input,bookCpt))
            conceptsPresent.push_back("{book_concept}");
        if(concept(input,callCpt))
            conceptsPresent.push_back("{call_concept}");
        if(concept(input,talkCpt))
            conceptsPresent.push_back("{talk_concept}");
        if(concept(input,wakeCpt))
            conceptsPresent.push_back("{wake_concept}");
        if(concept(input,createCpt))
            conceptsPresent.push_back("{create_concept}");
        if(concept(input,whatCpt))
            conceptsPresent.push_back("{what_concept}");
        if(concept(input,tellCpt))
            conceptsPresent.push_back("{tell_concept}");
        if(concept(input,emailCpt))
            conceptsPresent.push_back("{email_concept}");
        if(concept(input,messageCpt))
            conceptsPresent.push_back("{message_concept}");
        if(concept(input,weatherAct))
            conceptsPresent.push_back("{weather_activity}");
        if(concept(input,pleaseCpt))
            conceptsPresent.push_back("{please_concept}");


        if(placeholder(input,contactName))
            placeHolders.push_back("<contact_name>");
        if(placeholder(input,places))
            placeHolders.push_back("<place>");

        ////////////////SPECIAL SEARCHING FOR <dateTime>////////
        if(KMPSearch("a.m.",input) || KMPSearch("p.m.",input))
            {placeHolders.push_back("<dateTime>");
             placeHolders.push_back("<time>");}

    ///////////////////////////////DONE CHECKING PRESENCE////////////

    int x=0;
    ///////////////////PUSHING BACK INTO ONE VECTOR////////////
    for(x=0;x<conceptsPresent.size();x++)
        cout<<(conceptsPresent[x])<<"\n";
    for(x=0;x<placeHolders.size();x++)
        cout<<(placeHolders[x])<<"\n";}


//Three address code or intermediat code generator
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


char res[100],arg1[100],op[100],arg2[100],sym[100];
int main()
{

    FILE *f1,*f2;

    f1=fopen("5input.txt","r");
    f2=fopen("5output.txt","w");
    int i=0;
    while(!feof(f1))
    {
        fscanf(f1,"%s%s%s%s%s",res,sym,arg1,op,arg2);

        if(strcmp(op,"+")==0)
        {
            fprintf(f2,"MOV R%d,%s\n",i,arg1);
            fprintf(f2,"ADD R%d,%s\n",i,arg2);
            ++i;
        }

        else if(strcmp(op,"-")==0)
        {
            fprintf(f2,"MOV R%d,%s\n",i,arg1);
            fprintf(f2,"SUB R%d,%s\n",i,arg2);
            ++i;
        }
        else if(strcmp(op,"*")==0)
        {
            fprintf(f2,"MOV R%d,%s\n",i,arg1);
            fprintf(f2,"MUL R%d,%s\n",i,arg2);
            ++i;
        }
        else if(strcmp(op,"/")==0)
        {
            fprintf(f2,"MOV R%d,%s\n",i,arg1);
            fprintf(f2,"DIV R%d,%s\n",i,arg2);
            ++i;
        }

    }
    fclose(f1);
    fclose(f2);

    return 0;
}

//

//symbol table.........
#include<bits/stdc++.h>
using namespace std;


char res[100],arg1[100],op[100],arg2[100],sym[100];
int main()
{
    string res;
    getline(cin,res,'$');

    void *ptr;

    printf("Symbol Table : \n");
    printf("Name\t\tAddress\t\tType\n");

    for(int j=0; j<res.size(); j++)
    {
        char c=res[j];
        if(isalpha(toascii(c)))
        {
            ptr = malloc(c);
            printf("%c\t\t%d\t\t identifier\n",c,ptr);
        }
        else if(c=='+' || c=='-' || c=='*' || c=='/')
        {
            ptr = malloc(c);
            printf("%c\t\t%d\t\t operator\n",c,ptr);
        }
        else if(c=='(' || c==')' || c=='{' || c=='}')
        {
            ptr = malloc(c);
            printf("%c\t\t%d\t\t parentheses\n",c,ptr);
        }
        else if(c==';')
        {
            ptr = malloc(c);
            printf("%c\t\t%d\t\t semicolon\n",c,ptr);
        }

    }


    return 0;
}

/*
ter expression with $ : a+b-c*e;{$
Symbol Table :
Name            Address         Type
a               928208           identifier
+               928320           operator
b               928376           identifier
-               928488           operator
c               928544           identifier
*               926336           operator
e               926392           identifier
;               926504           semicolon
{               926576           parentheses
*/

//
//keyword token........
#include<bits/stdc++.h>
using namespace std;

vector<string> keywords;


void check(string s)
{
    if(s=="for" || s=="return" || s=="void" || s=="break"
            || s=="continue" ||s=="while" || s=="do" || s=="print"
            || s=="else" || s=="int" || s=="float" || s=="if"
            || s=="char" || s=="double" || s=="string" || s=="static"
            || s=="switch" || s=="case" || s=="scanf" || s=="printf" )
    {
        if(um[s]==0) keywords.push_back(s);
        um[s] = 1;
    }
}

int main()
{


    string s;
    while(getline(cin,s))
    {
        string str = "";
        for(int i=0; i<s.size(); ++i)
        {
            if(s[i]==' ' || s[i]==';' || s[i]==',' )
            {
                if(str!=" ") check(str);
                str = "";
            }
            else if(s[i]=='=' || s[i]=='(' || s[i]=='{')
            {
                if(str!=" ") check(str);
                str = "";
                break;
            }
            else if(s[i]>='a' && s[i]<='z' || s[i]>='A' && s[i]<='Z')
            {
                str += s[i];
            }
        }
        if(s=="!")
        {
            break;
        }
    }
    cout<<"Keywords: ";
    for(auto it: keywords) cout<<it<<", ";

    return 0;
}

//

//check identifier........
#include <bits/stdc++.h>
using namespace std;

bool isValid(string str)
{

    if (!((str[0] >= 'a' && str[0] <= 'z')|| (str[0] >= 'A' && str[0] <= 'Z')|| str[0] == '_'))return false;
    for (int i = 1; i < str.length(); i++)
    {
        if (!((str[i] >= 'a' && str[i] <= 'z')
                || (str[i] >= 'A' && str[i] <= 'Z')
                || (str[i] >= '0' && str[i] <= '9')
                || str[i] == '_'))
            return false;
    }
    return true;
}
int main()
{
    string str;
    cin>>str;

    if (isValid(str))
    {
        cout << "Valid Identifier";
    }
    else
    {
        cout << "Invalid Identifier";
    }
    return 0;
}

//.........

//igonre comment............
#include <bits/stdc++.h>
using namespace std;

string removeComments(string prgm)
{
    int n = prgm.length();
    string res;

    bool a = false;
    bool b = false;



    for (int i=0; i<n; i++)
    {
        if (a == true && prgm[i] == '\n')
        {
            a = false;
        }

        else if (b == true && prgm[i] == '*' && prgm[i+1] == '/')
        {

            b = false, i++;
        }

        else if (a || b)
        {
            continue;
        }

        else if (prgm[i] == '/' && prgm[i+1] == '/')
        {
            a = true, i++;
        }
        else if (prgm[i] == '/' && prgm[i+1] == '*')
        {
            b = true, i++;
        }

        else
        {
            res += prgm[i];
        }
    }
    return res;
}

int main()
{
    string prgm = " /* Test program */ \n"
                  " int main() \n"
                  " {		 \n"
                  "	 // variable declaration \n"
                  "	 int a, b, c; \n"
                  "	 /* This is a test \n"
                  "		 multiline	 \n"
                  "		 comment for \n"
                  "		 testing */	 \n"
                  "	 a = b + c;	 \n"
                  " }		 \n";
    cout << "Given Program \n";
    cout << prgm << endl;
    cout << " Modified Program ";
    cout << removeComments(prgm);
    return 0;
}

//.........

//types of comment...........

#include <bits/stdc++.h>
using namespace std;

int isComment(string line)
{

	if(line.size()<=2)
    {

        return -1;

    }
    else{
        bool x=false;
        for(int i=0;i<line.size();i++)
        {

            if(line[i]=='/' and line[i+1]=='/')
            {

                return 1;
            }
            else if(line[i]=='/' and line[i+1]=='*')
            {
                return 2;
            }
            /*else{
                if(line[i]=='\n')
                {

                    continue;
                }
            }*/
        }
    }
    return -1;
}
int main()
{
	string line ;
	getline(cin,line,'$');

	if(isComment(line)==-1)
    {

        cout<<"It is not a comment"<<endl;
    }
    else{
        if(isComment(line)==1)
        {

            cout<<"Single line comment"<<endl;
        }
        else{
            cout<<"Multiline comment"<<endl;
        }
    }

	return 0;
}


////..........

//how many letters in comment..........
#include <bits/stdc++.h>
using namespace std;

int isComment(string line)
{
    int cnt=0;
    if(line.size()<=2)
    {

        return -1;

    }
    else
    {
        for(int i=0; i<line.size(); i++)
        {

            if(line[i]=='/' and line[1+i]=='/')
            {


                int j=i+2;;
                while(line[j]!='\n')
                {

                    j++;
                    cnt++;
                }
                cnt;
            }
            else if(line[i]=='/' and line[1+i]=='*')
            {

                int j=2+i;
                while(line[j]!='*' and j<line.size())
                {

                    j++;
                    cnt++;
                }
                if(i==line.size())
                {

                    return -1;
                }

            }
        }
        return cnt;
    }
    return -1;
}
int main()
{
    string line ;
    getline(cin,line,'!');

    if(isComment(line)==-1)
    {

        cout<<"It is not a comment"<<endl;
    }
    else
    {
        cout<<"It is a comment "<<"letters count: "<<isComment(line)<<endl;
    }

    return 0;
}
//////........
//where comment is written............
#include <bits/stdc++.h>
using namespace std;
vector<int>v;
string removeComments(string prgm)
{
    int n = prgm.length();
    string res;

    bool a = false;
    bool b = false;
    int cnt=1;

    for (int i=0; i<n; i++)
    {
        if(prgm[i] == '\n')
        {

            cnt++;
        }
        if (a == true && prgm[i] == '\n')
        {
            a = false;
        }

        else if (b == true && prgm[i] == '*' && prgm[i+1] == '/')
        {
            b = false, i++;
        }

        else if (a || b)
        {
            continue;
        }

        else if (prgm[i] == '/' && prgm[i+1] == '/')
        {
            v.push_back(cnt);
            a = true, i++;
        }
        else if (prgm[i] == '/' && prgm[i+1] == '*')
        {
            v.push_back(cnt);
            b = true, i++;
        }

        else
        {
            res += prgm[i];
        }
    }
    return res;
}

int main()
{
    string prgm;
    getline(cin,prgm,'$');
    cout << removeComments(prgm);
    for(auto l:v)
    {
        cout<<l<<endl;
    }
    return 0;
}


/////.........

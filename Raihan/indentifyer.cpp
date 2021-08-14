#include<bits/stdc++.h>
using namespace std;
vector<string>keywords={"auto",	"break",	"case",	"char",
                        "const",	"continue",	"default",	"do",
                        "double",	"else",	"enum",	"extern",
                        "float",	"for",	"goto",	"if",
                        "int",	"long",	"register",	"return",
                        "short",	"signed",	"sizeof",	"static",
                        "struct",	"switch",	"typedef",	"union",
                        "unsigned",	"void",	"volatile",	"while"
                        "bool","vecetor","set","map","list","queue","stack"
                        "push_back","insert","size","bits","stdc++","using","namespace",
                        "std","freopen","stdin","#include","printf","scanf","stdio.h","main"
                        "string.h"
                        };
set<string>st_keywords;
vector<string>variables;
set<string>st_variables;
vector<string>specialCharacters={"%d","%lf","%f","%s",":",";","?",",",".","\n","\t"};
set<string>st_spacialCharacters;
vector<string>brackets={"(",")","{","}","[","]"};
set<string>st_brackets;
vector<string>operators={"+","-","*","/","&&","||","=","!","&","|","!=","<",">"};
set<string>st_operators;
vector<string>strings;
vector<string>inputVector;

bool isSaparator(char c){
    return c=='('||c==')'||c=='{'||c=='}'||c=='+'||c=='-'||c=='*'||c=='/'||c=='<'||c=='>'||c=='='||c=='&'||c=='|'||c=='^'||
    c==' '||c==','||c==';'||c=='%'||c=='!';
}
bool isValidString(string s){

    bool validity=false;
    for(int i=0;i<s.length();i++){
        if(s[i]!=' '&&s[i]!='\n')
            validity=true;
    }
    return validity;
}
int inputString(string line,int index){

    string s(1,'"');
    for(int i=index+1;line[i]!='"';i++){
        index=i;
        s.push_back(line[i]);
        if(line[i]=='%'){
            if(line[i+1]=='d')
                inputVector.push_back("%d");
            else if(line[i+1]=='f')
                inputVector.push_back("%f");
            else if(line[i+1]=='s')
                inputVector.push_back("%s");
            else if(line[i+1]=='l'&&line[i+2]=='f')
                inputVector.push_back("%lf");
        }

    }
    s.push_back('"');
    strings.push_back(s);
    return index+1;
}
void saparator(string &line){
    string part="";

    for(int i=0;i<line.length();i++){
        char c=line[i];
        if(line[i]=='"'){
            i=inputString(line,i);
            continue;
        }
        if(isSaparator(line[i])){
            //onnanno string operatorer kaj kormo.......................

            if(isValidString(part)){

                inputVector.push_back(part);
            }
            part="";
            string temp(1,c);

            if(isValidString(temp)){

                inputVector.push_back(temp);
            }
        }
        else
        {
            part+=c;
        }

    }
//    cout<<"part== "<<part<<endl;
    if(isValidString(part))
        inputVector.push_back(part);
}
void combined(){
    for(int i=0;i<inputVector.size()-1;i++){
        if(inputVector[i]=="&"&&inputVector[i+1]=="&"){
            inputVector[i]=inputVector[i]+inputVector[i+1];
            inputVector.erase(inputVector.begin()+i+1);
        }
        else if(inputVector[i]=="|"&&inputVector[i+1]=="|"){
            inputVector[i]=inputVector[i]+inputVector[i+1];
            inputVector.erase(inputVector.begin()+i+1);
        }
        else if(inputVector[i]=="="&&inputVector[i+1]=="="){
            inputVector[i]=inputVector[i]+inputVector[i+1];
            inputVector.erase(inputVector.begin()+i+1);
        }
        else if(inputVector[i]=="!"&&inputVector[i+1]=="="){
            inputVector[i]=inputVector[i]+inputVector[i+1];
            inputVector.erase(inputVector.begin()+i+1);
        }

    }
}
void prnt(vector<string>&v,string mssg){
    cout<<mssg<<"--------";
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<"  ";
    }
    cout<<endl;
}
void prntSet(set<string>st,string mssg){
    cout<<mssg<<"-------- ";
    for(auto it=st.begin();it!=st.end();it++){
        cout<<*it<<"  ";
    }
    cout<<endl;
}
void drawLine(){

    for(int i=0;i<60;i++){
        printf("_");
    }
    printf("\n\n");
}
int main(void)
{
    freopen("i.txt","r",stdin);
    string line;
    while(getline(cin,line)){
        cout<<line<<endl;

        saparator(line);
    }
    combined();

    for(int i=0;i<inputVector.size();i++){
        if(count(keywords.begin(),keywords.end(),inputVector[i])){
            st_keywords.insert(inputVector[i]);
        }
        else if(count(specialCharacters.begin(),specialCharacters.end(),inputVector[i])){
            st_spacialCharacters.insert(inputVector[i]);
        }
        else if(count(brackets.begin(),brackets.end(),inputVector[i])){
            st_brackets.insert(inputVector[i]);
        }
        else if(count(operators.begin(),operators.end(),inputVector[i])){
            st_operators.insert(inputVector[i]);
        }
        else {
            st_variables.insert(inputVector[i]);
        }
    }
        drawLine();
        prntSet(st_keywords,"keywords");
        drawLine();
        prntSet(st_spacialCharacters,"Special Characters");
        drawLine();
        prntSet(st_brackets,"Brackets");
        drawLine();
        prntSet(st_operators,"Operators");
        drawLine();
        prntSet(st_variables,"Variables and tokens");
        drawLine();
        prnt(strings,"Strings");
        drawLine();
    return 0;
}


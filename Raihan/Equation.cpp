#include<bits/stdc++.h>
using namespace std;
vector<string>inputVector;
void printReplace(){
    printf("   [After replacing the charecter]\n");
}
void insert(string &str,char letter,char replaceBy){
    for(int i=0;i<str.length();i++){
        if(str[i]==letter){
            str[i]=replaceBy;
        }
    }
}
int equalOperatorPossition(string str){
    for(int i=0;i<str.length();i++){
        if(str[i]=='=')return i;
    }
    //return 0; //I have inserted
}
string stringCopy(string str,int position){
    string cp="";
    for(int i=position;i<str.length();i++){
        cp+=str[i];
    }
    return cp;
}
bool isSaparator(char c){
    return c=='+'||c=='-'||c=='*'||c=='/';
}
bool isOperator(string c){
    return c=="+"||c=="-"||c=="*"||c=="/";
}
bool isVariable(string c){
    if((c[0]>='A'&&c[0]<='Z')||(c[0]>='a'&&c[0]<='z')){
        return true;
    }
    return false;
}
bool isValidString(string s){
    bool validity=false;
    for(int i=0;i<s.length();i++){
        if(s[i]!=' ')
            validity=true;
    }
    return validity;
}
void saparator(string &line){
    string part="";
    for(int i=0;i<line.length();i++){
        if(isSaparator(line[i])){
          inputVector.push_back(part);
          string temp="";
          temp.push_back(line[i]);
          inputVector.push_back(temp);
          part="";
        }
        else{
            part.push_back(line[i]);
        }
    }
    inputVector.push_back(part);
}
void conCatinateMultiplicationAndDivision(string &variables){
    vector<bool>deleteIndex(inputVector.size(),false);
    for(int i=0;i<inputVector.size();i++){
        string index=inputVector[i];
        if(index=="*"||index=="/"){
            if(isVariable(inputVector[i-1])||isVariable(inputVector[i+1])){
                if(i-2>=0)deleteIndex[i-2]=true;
                deleteIndex[i-1]=true;
                deleteIndex[i]=true;
                deleteIndex[i+1]=true;
            }
            else if(deleteIndex[i-1]){
                if(i-2>=0)deleteIndex[i-2];
                deleteIndex[i-1]=true;
                deleteIndex[i]=true;
                deleteIndex[i+1]=true;
            }
        }
    }
   for(int i=inputVector.size()-1;i>=0;i--){
        string index=inputVector[i];
        if(index=="*"||index=="/"){
            if(isVariable(inputVector[i-1])||isVariable(inputVector[i+1])){
                if(i-2>=0)deleteIndex[i-2]=true;
                deleteIndex[i-1]=true;
                deleteIndex[i]=true;
                deleteIndex[i+1]=true;
            }
            else if(deleteIndex[i+1]){
                if(i-2>=0)deleteIndex[i-2];
                deleteIndex[i-1]=true;
                deleteIndex[i]=true;
                deleteIndex[i+1]=true;
            }
        }

    }
    for(int i=inputVector.size()-1;i>=0;i--){
        if(deleteIndex[i]){
          variables=inputVector[i]+variables;
            inputVector.erase(inputVector.begin()+i);
        }
    }
}
string calculate(){
    vector<string>lst;
    string variables="";
    double values=0;
    string Operatr="+";
    int j=0;
    conCatinateMultiplicationAndDivision(variables);
    if(isOperator(inputVector[0])){
        Operatr=inputVector[0];
        j++;
    }
    for(int i=j;i<inputVector.size();i++){
        string index=inputVector[i];
        if(isOperator(index)){
            Operatr=index;
        }
        else if(isVariable(index)){
            variables=variables+Operatr+index;
        }
        else{
            double num=stod(index);
            lst.push_back(Operatr);
            lst.push_back(index);
            //if(Operatr=="+")values+=num;
            //else if(Operatr=="-")values-=num;
             if(Operatr=="*"){
                if(values==0)values=1;
                values*=num;
            }
            else if(Operatr=="/"){
                if(values!=0){
                    values/=num;
                }
                else{
                    values=num;
                }
            }
        }
    }

    if(values==0){
        cout<<variables;
        printReplace();
        return variables;
    }
    if(values<0)variables+="-";
    else variables+="+";
    cout<<variables;
    for(int i=1;i<lst.size();i++){
        cout<<lst[i];
    }
    printReplace();
    return variables+to_string(values);
}

void prnt(vector<auto>v){
    printf("Size==%d\n\n",(int)v.size());
    for(int i=1;i<v.size();i++){
        cout<<"i="<<i<<" "<<v[i]<<"\n";
    }
    printf("\n");
}
string removeSpace(string str){
    string temp="";
    for(int i=0;i<str.length();i++){
        if(str[i]==' ')continue;
        temp.push_back(str[i]);
    }
    return temp;
}
int main(void)
{
//    freopen("i.txt","r",stdin);
    string equation;
    printf("Sample input: ");
    getline(cin,equation);
    string originalEquation=equation;
    string temp="";
    for(int i=0;i<equation.length();i++){//removing spaces;
        if(equation[i]==' ')continue;
        temp.push_back(equation[i]);
    }
    equation=temp;
    char letter,replaceBy;
    printf("which letter do you want to change: ");
    scanf("%c",&letter);
    cin.ignore();
    printf("which letter do you want to put: ");
    scanf("%c",&replaceBy);

    insert(equation,letter,replaceBy);

    int position=equalOperatorPossition(equation)+1;
    string str=stringCopy(equation,position);

    saparator(str);

    for(int i=0;i<inputVector.size();i++){//removing all blank index and spaces;
        if(inputVector[i].length()==0){
            inputVector.erase(inputVector.begin()+i);
        }
        inputVector[i]=removeSpace(inputVector[i]);
    }
    printf("Sample Output:\n");
    cout<<"    "<<originalEquation<<endl;
    printf("or, ");
    for(int i=0;i<position;i++){
        printf("%c",equation[i]);
    }
    string result=calculate();
    printf("or, ");
    for(int i=0;i<position;i++){
        printf("%c",equation[i]);
    }
    cout<<result<<endl;
}

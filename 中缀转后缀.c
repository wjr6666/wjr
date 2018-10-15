#include<stdio.h>
#include<string.h>
#define N 100
int Leval(char ch)
{
	switch(ch){
		case '*':
		case '/':return 2;
		case '+':
		case '-':return 1;
		case '(':return 0;
		case '#':return -1; 
	}
	
}

void Calculate(char s[])
{
	char Sop[N];
	int Optop=0,i=0;
	Sop[0]='#';
	while(s[i]){
		if(s[i]<='z'&&s[i]>='a')
			printf("%c",s[i]);
		else if(s[i]=='*'||s[i]=='/'||s[i]=='+'||s[i]=='-'){
			while(Leval(s[i])<=Leval(Sop[Optop])){
				printf("%c",Sop[Optop--]);
			}
			Sop[++Optop]=s[i];
		}
		else if(s[i]=='(')
			Sop[++Optop]=s[i];
		else if(s[i]==')'){
			while(Sop[Optop]!='('){
				printf("%c",Sop[Optop--]);
			}
			Optop--;
		}
		i++;
	}
	while(Optop){
		printf("%c",Sop[Optop--]);
	}
}

int main(void)
{
	char ex[N];
	gets(ex);
	Calculate(ex);
	
	return 0;
}

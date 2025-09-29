#include&lt;stdio.h&gt;
#include&lt;string.h&gt;
void add(char a[],char b[],char c[]);
int main()
{
	int T;
	scanf("%d",&amp;T);
	for(int i=0;i&lt;T;i++){
		char a[500];
		char b[500];
		char c[6];
		scanf("%s",a);
		scanf("%s",b);
		add(a,b,c);
		printf("%s\n",c);
	}
	return 0;
}
void add(char a[],char b[],char c[]){
	int len=strlen(b);
	for(int j=0;j&lt;3;j++){
		c[j]=a[j];
	}
	for(int j=0;j&lt;3;j++){
		c[j+3]=b[len+j-3];
	}
	c[6]='\0';
}

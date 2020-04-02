#include <stdio.h>
void gcdExtended(int,int);
int main(int argc, char const *argv[]){

	int a,b;
	printf("Enter a and m:-\n");
	scanf("%d %d",&a,&b);
	if (a==b||a<0||b<0)
	{
		printf("Multiplicative Inverse doesn't exist\n");
	}
	else if (a>b)
	{
		gcdExtended(a,b);
	}
	else{
		gcdExtended(b,a);
	}
	return 0;
}
void gcdExtended(int a,int b){
	int q,x,s=0,old_s=1,t=1,old_t=0,r=b,old_r=a;
	while(r!=0){
		q = old_r/r;
		x = r;
		r = old_r-q*r;
		old_r = x;
		x = s;
		s = old_s-q*s;
		old_s = x;
		x = t;
		t = old_t-q*t;
		old_t = x;
	}
	printf("%d = %d * %d + %d * %d\n",old_r,old_s,a,old_t,b);
	if (old_r==1)
	{
		printf("Multiplicative Inverse exist\n");
		if(old_t<0){
			old_t=a+old_t;
			printf("Multiplicative Inverse of %d is %d\n",b,old_t);			
		}
		else
			printf("Multiplicative Inverse of %d is %d\n",b,old_t);
	}
	else
		printf("Multiplicative inverse doesn't exist\n");
}

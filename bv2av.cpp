#include <iostream>

const char table[58]={'f','Z','o','d','R','9','X','Q','D','S','U','m','2','1','y','C','k','r','6','z','B','q','i','v','e','Y','a','h','8','b','t','4','x','s','W','p','H','n','J','E','7','j','L','5','V','G','3','g','u','M','T','K','N','P','A','w','c','F'};
const char rtable[256]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,13,12,46,31,43,18,40,28,5,-1,-1,-1,-1,-1,-1,-1,54,20,15,8,39,57,45,36,-1,38,51,42,49,52,-1,53,7,4,9,50,10,44,34,6,25,1,-1,-1,-1,-1,-1,-1,26,29,56,3,24,0,47,27,22,41,16,-1,11,37,2,35,21,17,33,30,48,23,55,32,14,19,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
//逆向表可以每次启动时生成，但是我就想把它写成常量……
const int order[6]={11,10,3,8,4,6};
const long long xon=177451812,add=8728348608;//为了增加笑料，所以写成”xon“。

int av2bv(long long iav,char *obv)
{
	char bv[13]="BV1??4?1?7??";
	for (int i=0;i<13;i++)
	{
		obv[i]=bv[i];
	}
	long long div=1;
	iav=(iav^xon)+add;
	for (int i=0;i<6;i++)
	{
		obv[order[i]]=table[(iav/div)%58];
		div=div*58;
	}
	return 0;
}

long long bv2av(char bv[])
{
	long long av=0,mult=1;
	for (int i=0;i<6;i++)
	{
		if (rtable[int(bv[order[i]])]<0)
		{
			return -1;
		}
		av=av+rtable[int(bv[order[i]])]*mult;
		mult=mult*58;
	}
	av=(av-add)^xon;
	return av;
}

long long s2n(char *input,long long mult1,int lenth,long long av,long long div1,int s)//我就想造轮子，你能怎么地😂
{
	mult1=mult1/div1;
	for (int i=s;i<lenth;i++)
	{
		av=av+((long long)(input[i]-'0'))*mult1;
		mult1=mult1/10;
	}
	return av;
}

int main()
{
	long long av=0,mult1=1;
	int lenth;
	char BV[13],input[16];
	std::cout<<"AV号BV号互转工具\n请输入（AVx、x（x<38068692544）、BV1??4?1?7??）"<<std::endl;
	std::cin>>input;
	for (lenth=1;lenth<16;lenth++)
	{
		if (input[lenth]==0)
		{
			break;
		}
		mult1=mult1*10;
	}
	switch (input[0])
	{
		case 'a': case 'A':
		av2bv(s2n(input,mult1,lenth,av,100,2),BV);
		std::cout<<BV<<std::endl;
		break;
		case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': 
		av2bv(s2n(input,mult1,lenth,av,1,0),BV);
		std::cout<<BV<<std::endl;
		break;
		case 'B':
		std::cout<<bv2av(input)<<std::endl;
		break;
		default:
		std::cout<<"输入不正确"<<std::endl;
	}
	return 0;
}
#include<iostream>  
#include<conio.h>
#include<windows.h>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>            
#include<string.h>
using namespace std;
int qs=10;
int xthl=0;//先天魂力 
int hldj=1;//魂力等级 
int wh1;//武魂1 
long long hj[9]={0};//九个魂环的年限
long long hj2[9]={0};//第二武魂九个魂环的年限
int n,a,b,d,as;
int main()
{
	long long name,c;
	int gj=0,xl=0;
	srand(time(NULL));
    cout<<"       ----------斗罗大陆----------      \n";
	cout<<"你好，欢迎来到斗罗大陆，行走江湖，还请留下代号（数字）：";
	cin >> name;
	cout<<name<<"，你即将觉醒武魂，请做好准备\n";Sleep(2000);
	n=rand()%4+1;
	if(n>=0&&n<=4){
		srand(time(NULL));
		wh1=rand()%4+1;
		if(wh1==1){
			cout<<"你的武魂是：蓝银草\n";Sleep(2000);
			gj=gj+15;
			xl=xl+20; 
		}
		if(wh1==2){
			cout<<"你的武魂是：邪火凤凰\n";Sleep(2000);
			gj=gj+20;
			xl=xl+50;
		}
		if(wh1==3){
			cout<<"你的武魂是：昊天锤\n";Sleep(2000);
			gj=gj+30;
			xl=xl+70;
		}
		if(wh1==4){
			cout<<"你的武魂是：蓝电霸王龙\n";Sleep(2000);
			gj=gj+25;
			xl=xl+60;
		}
		if(wh1==5){
		    cout<<"你的武魂是：七杀剑\n";Sleep(2000);	
			gj=gj+20;
			xl=xl+55;
		}
		system("cls");
		cout<<"你即将查看魂力，请做好准备\n";Sleep(2000);
		srand(time(NULL));
		b=rand()%9+1;
		if(b==1){
			cout<<"你的魂力只有1级";Sleep(2000);
			hldj=1; 
			system("cls");
		}
		if(b==2){
			cout<<"你的魂力只有2级";Sleep(2000);
			hldj=2;
			system("cls");
		}
		if(b==3){
			cout<<"你的魂力有3级了";Sleep(2000);
			hldj=3;
			system("cls");
		}
		if(b==4){
			cout<<"你的魂力有4级!";Sleep(2000);
			hldj=4;
			system("cls");
		}
		if(b==5){
			cout<<"你的魂力有5级!";Sleep(2000);
			hldj=5;
			system("cls");
		}
		if(b==6){
			cout<<"你的魂力有6级!";Sleep(2000);
			hldj=6;
			system("cls");
		}
		if(b==7){
			cout<<"你的魂力有7级!逆天!";Sleep(2000);
			hldj=7;
			system("cls");
		}
		if(b==8){
			cout<<"你的魂力有8级!逆天!";Sleep(2000);
			hldj=8;
			system("cls");
		}
		if(b==9){
			cout<<"你的魂力有9级!好厉害!";Sleep(2000);
			hldj=9;
			system("cls");
		}
		if(b==10){
			cout<<"你的魂力有10级!将来一定能成封号斗罗!!!";Sleep(2000);
			hldj=10;
			system("cls");
		}
		for(;;)
		{
		cout<<"       ----------主菜单----------\n";
		cout<<"    1：查看等级2：修炼3：魂兽森林\n";
		cin>>a;
		if(a==1){
			cout<<"你的魂力等级是："<<hldj;Sleep(2000);system("cls"); 
		}
		if(a==2){
			if(qs-hldj==9){
				for(int i=2;i<=10;i++)
				{
					cout<<"你修炼到了"<<hldj+1<<"级\n";
					hldj=hldj+1; 
				}
				
			}
			if(qs-hldj==8){
				for(int d=2;d<=9;d++)
				{
					cout<<"你修炼到了"<<hldj+1<<"级\n"; 
					hldj=hldj+1; 
				}
				
			}
			if(qs-hldj==7){
				for(int u=2;u<=8;u++)
				{
					cout<<"你修炼到了"<<hldj+1<<"级\n";
					hldj=hldj+1;  
				}
				
			}
			if(qs-hldj==6){
				for(int g=2;g<=7;g++)
				{
					cout<<"你修炼到了"<<hldj+1<<"级\n";
					hldj=hldj+1;  
				}
				
			}
			if(qs-hldj==5){
				for(int x=2;x<=6;x++)
				{
					cout<<"你修炼到了"<<hldj+1<<"级\n";
					hldj=hldj+1;  
				}
				
			}
			if(qs-hldj==4){
				for(int j=2;j<=5;j++)
				{
					cout<<"你修炼到了"<<hldj+1<<"级\n";
					hldj=hldj+1;  
				}
				
			}
			if(qs-hldj==3){
				for(int s=2;s<=4;s++)
				{
					cout<<"你修炼到了"<<hldj+1<<"级\n";
					hldj=hldj+1;  
				}
				
			}
			if(qs-hldj==2){
				for(int w=2;w<=3;w++)
				{
					cout<<"你修炼到了"<<hldj+1<<"级\n";
					hldj=hldj+1;  
				}
				
			}
			if(qs-hldj==1){
				for(int y=1;y<=2;y++)
				{
					cout<<"你修炼到了"<<hldj+1<<"级\n";
					hldj=hldj+1;  
				}
			}
			if(qs-hldj==0){
				cout<<"你已满级，可前去猎杀魂兽";Sleep(3000);system("cls"); 
			} 
		}
		if(a==3)
		{
			srand(time(NULL));
			if(hldj==10){
			srand(time(NULL));
			c=rand()%410;
		    }
		    if(hldj>10){
		    srand(time(NULL));
		    c=rand()%650;
			}
			cout<<"你遇到了"<<c<<"年魂兽\n";Sleep(2000);
			cout<<"1：攻击2：不攻击\n";
			cin>>d;
			if(d==1)
			{
				if(c<=400&&hldj==10||c>=400&&hldj>10)
				{
					cout<<"你的血量：100\n它的血量：85";Sleep(3000);system("cls");
					cout<<"你的血量：85\n它的血量：70";Sleep(3000);system("cls");
					cout<<"你的血量：70\n它的血量：55";Sleep(3000);system("cls");
					cout<<"你的血量：55\n它的血量：40";Sleep(3000);system("cls");
					cout<<"你的血量：40\n它的血量：25";Sleep(3000);system("cls");
					cout<<"你的血量：25\n它的血量：5";Sleep(3000);system("cls");
					cout<<"你的血量：10\n它的血量：-10\n";Sleep(3000);
					cout<<"你赢了！\n";Sleep(4000);
					cout<<"是否吸收"<<c<<"年魂环\n";
					cout<<"1：吸收2：不吸收\n";
					cin>>as;
					if(as==1)
					{
						Sleep(9000);
						cout<<"吸收成功！！！现在你的魂力等级是11级！！！";Sleep(3000);system("cls");hldj=hldj+1;
					}
					if(as==2)
					{
						Sleep(1000);system("cls");
					} 
				}
				if(c>400)
				{
					cout<<"他的年限太高，你被它杀死了！（第1魂环的最高年限是400年！）";Sleep(3000);return 0;
				}
			}
			if(d==2)
			{
				Sleep(1000);system("cls");
			}
		} 
	}
	qs=qs+10;
    }
	return 0;
}
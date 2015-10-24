# include <sys\stat.h>
# include <iostream.h>
# include <graphics.h>
# include <process.h>
# include <fstream.h>
# include <string.h>
# include<stdlib.h>
# include <stdio.h>
# include <conio.h>
# include <bios.h>
# include <time.h>
# include <dos.h>
# include <io.h>
int pos =0 ;
fstream win;
int npr=6;
int idf;
struct weapon
{
char name[20];
int nob,hurt,freq;
};
class play
{ int id;
  int food,life;
  int nw;
  char status;
  weapon cuwe;
  weapon wea[5];

  public :
  void fight(int,play,char *d="o");
  int & idacc()
  {return id;}
  int & foodacc()
  { return food;}
  int & lifeacc()
  {return life;}
  void displayhide()
  {
  cout<<"\n\n\t\t\tFOOD : "<<food;
    cout<<"\n\n\t\t\tLIFE : "<<life;
    cout<<"\n\n\t\t\tCURRENT WEAPON : ";puts(cuwe.name); }
  play()
  {
  id=idf;}

  play(int idf)
  { id = idf;
    food = 10000;life=10000;nw = 1;
    strcpy(wea[0].name,"Knife");
    wea[0].nob=100;
    wea[0].hurt = 25;
    wea[0].freq = 2000;
    status = 'a';
    cuwe = wea[0];
  }
  void changestatus()
  {status = 'd';

  win.open("win.txt",ios::in);
   win>>npr;
   win.close();
  win.open("win.txt",ios::out);
  npr--;win<<npr;
   win.close();
     }

};  long int stati=0;
struct no{int n;int f;};
void play::fight(int a,play ply,char* ch)

{
 int flu=0;
char string[2]; char str[5];int pos,i,pork;
 fstream f,o;
 string[0]=idf/10+48;string[1] = '\0';
 str[0]='f';str[1]='t';str[2]=idf%10+48;str[3]=a+48;str[4]='\0';
 if(a==-1)
 goto direct;
 ch[0] = id/10 + 48;
 ch[1] = id%10 + 48;
 ch[2] = a + 48;
 ch[3] = '\0';
 cout<<"\t\t\tWaiting for response ";
 for ( pork = 1;pork<=3;pork++)
{ delay(100);
 cout<<'.';}
 f.open(ch,ios::out|ios::binary);
 f.close();
 o.open(string,ios::out|ios::ate);

 o.seekp(0,ios::end); pos = o.tellp()+1;
 o<<" "<<str;
 o.close();
for( i=0;i<10;i++)
{f.open(ch,ios::out|ios::ate|ios::binary) ;
 f.seekp(0,ios::end);
 if( f.tellp()!=0 )
{ f.close();f.open(ch,ios::out|ios::trunc|ios::binary);f.close();break;}

 delay(1000);
  }
o.open(string,ios::out|ios::ate);
o.seekp(pos);
o<<"    ";

 if(i>=10)
 {cout<<"No response :( ";delay(2000);  }
 else
 { direct :
   clrscr();
   long int timer;int t;no temp; no iter;int p =0;
   for(;;)
 {
   clrscr();
   timer = biostime(0,0L);
   cout<<"The weapon used is ";puts(cuwe.name);
   cout<<"\n\t\t\tClick 'S' to shoot";
   cout<<life; cout<<p<<"\t"<<temp.n<<"\t"<<temp.f;

   while(bioskey(1)==0)
   {
   {

   f.open(ch,ios::in|ios::binary);
   f.seekg(p);

   if(f.read((char*)&temp,sizeof(no)))
  //  if(f.eof()==0)
  {  p=f.tellg();

   if(temp.n!=-1 &&temp.f!=id%10&&f.eof()==0)
   life-=temp.n;
   else if(temp.n==-1&&temp.f==-1)
   { clrscr();
   cout<<"Your opponent is dead";
   cout<<"\nYou gain all the food ";
     food+=ply.food;
     delay(5000); flu=-1;
     break;
     }

   no m;m.f=-1;m.n=-1;
   if(life<0)
  { f.open(ch,ios::out|ios::ate|ios::binary);
    changestatus();while(!f){f.close();f.open(ch,ios::out|ios::ate|ios::binary);}f.write((char*)&m,sizeof(no));f.close();exit(0);
   } } } f.close();  } bioskey(0);
   if(flu==-1)break;
   t=cuwe.nob-biostime(0,0L)+timer ;
   if(5>=0)

 {
    f.open(ch,ios::out|ios::app|ios::binary);
     iter.n=5*cuwe.hurt; iter.f=id%10;
    f.write((char*)&iter,sizeof(no));
   f.close();
  }}}}
void process (char buf[10] ,play player)

{ char ch[5];
  ch[0] = 'f';
  ch[1] = 'p';
  ch[3] = idf/10 +48;
  ch[4] = '\0';
 switch(buf[0])
{case 'a' : player.foodacc()-=250;
	    clrscr();
	    cout<<"\n\n\t\t\t\tYou lose 250 units of food in a trap set by your competitior";
	    delay(1000);
	    break;
 case 'b' : player.lifeacc()-=300;
	    clrscr();
	    cout<<"\n\n\t\t\t\tYou lose 300 units of life in a trap set by your competitior";
	    delay(1000);

	    break;
 case 'c' : player.changestatus();
	    clrscr();
	    cout<<"\n\n\t\t\t\tYou die in a trap set by your competitior";
	    cout<<"\n\n\t\t\t\tYOU LOSE!!!!!!!";
	    delay(1000);
	    exit(0);
	    break;
 case 'd' : ch[2] = buf[2];
	    fstream fp ;
	    fp.open(ch,ios::out|ios::binary|ios::app);
	    fp.write((char*)&player,sizeof(player));
	    fp.close();
	    break;
 case 'f' : if(buf[3] == idf%10 + 48)
	   {clrscr();
	    char str[4];
	    str[0] = idf/10 + 48;
	    str[1] = buf[2];
	    str[2] = idf%10+ 48;
	    str[3] = '\0';
	    no g;g.n=-1;
	    fstream f(str,ios::out|ios::ate|ios::binary);
	    f.write((char*)&g,sizeof(no));clrscr();
	    f.close();
	    clrscr();
	    cout<<"You are invited to fight by player "<<str[1];
	    cout<<"\nTransferring control........... ";
	    delay(3000);
	    player.fight(-1,player,str);
	    }


}}
int assign ()
 { while(bioskey(1)!=0)bioskey(0);

char id[3];int idf;
fstream arena;
arena.open("Arena.txt",ios::in);
//fwrite("10",3,1,arena);
arena>>id;
arena.close();
idf = id[1] - 48 + (id[0]-48)*10;

if(id[0]=='1'){cout<<"Enough players taken already. Try again Later.";delay(2000);exit(0); }
if(id[1]=='5')
{
id[0]++;id[1]='0';}
else
id[1]++;

arena.open("Arena.txt",ios::out);
arena.seekp( 0);
arena<<id;
arena.close();
while(id[1]!='0'&&bioskey(1)==0)
{
clrscr();  cout<<idf;
cout<<"\n\n\n\n\t\t\tASSIGNING ARENA......";
cout<<"\n\n\n\t\t\t"<<6-id[1] + 48<<" players remaining";
arena.open("Arena.txt",ios::in);
arena>>id;
arena.close();
delay(1000);
}
if(bioskey(1)!=0)
return -1;
else
return idf;

 }


void main()
{
   textbackground(0);
   textcolor(7);
    int n,arch;
   lab :
   clrscr();
   cout<<"\t\t\t\tTHE HUNGER GAMES";
   cout<<"\n\t\t\t\t****************";
   cout<<"\n\n\n\t\t\t1.Start Game";
   cout<<"\n\n\n\t\t\t2.Game Instructions";
   cout<<"\n\n\n\t\t\t3.Exit";
   cout<<"\n\n\n\t\t\tEnter Choice ";cin>>n;
   switch(n)
   {case 1:

	    idf=assign();
	    if(idf==-1)
	    {win.open("win.txt",ios::in);
   win>>npr;
   win.close();
  win.open("win.txt",ios::out);
  npr--;win<<npr;
   win.close();
	    goto lab;}

	    play player(idf);
	    long start,i;
	    long c;
	    static long fold;
	    start = biostime(0, 0L);
	    arena :
	     clrscr();
	    for(;bioskey(1)==0;)
	    {
	   win.open("win.txt",ios::in);
	    win>>npr;
	    win.close();
	     if(npr==1)
	    {clrscr();
	     cout<<"YOU WIN!!!!!!!!!!!";
	     fstream arena;
	     arena.open("Arena.txt",ios::out);
	     arena<<"00";
	     arena.close();
	     delay(1000);
	     exit(0);
	     }
	    clrscr();
	    i=biostime(0,0L);
	    if((i-start)>=1)
	  { player.foodacc()-=(i-start); start = i;  }
	    if(player.foodacc()<=0)
	    {player.foodacc()=0;
	     static fold = biostime(0, 0L);
	     c=biostime(0,0L);
	     if(c-fold>=1)
	     {player.lifeacc()-=(c-fold);
	     fold = c;
	     } }
	     if(player.lifeacc()<0)

	    {player.changestatus();
	     clrscr();
	     cout<<"YOU LOSE!!!!!!!!!!!!";
	     delay(500);
	    exit(0);}
	    cout<<"\n\t\t\tWELCOME TO YOUR ARENA";
	    cout<<"\n\t\t\t*********************";
	    cout<<"\n\n\t\tYour Arena includes ten people including you";
	    cout<<"\n\n\n\t\t\tSELECT AN ACTION";
	    cout<<"\n\n\n\t\t\t1.STAY IN HIDE";
	    cout<<"\n\n\n\t\t\t2.GO WANDER";
	    cout<<"\n\n\n\t\t\t3.KILL YOURSELF";
	    cout<<"\n\n\t\t\t\tEnter ";
	    delay(100);
	 }
	    switch( bioskey(0) )
	    {case 561:
	     for(;bioskey(1)==0;)
	    {
	     win.open("win.txt",ios::in);
	    win>>npr;
	    win.close();
	     if(npr==1)	    {clrscr();
	     cout<<"YOU WIN!!!!!!!!!!!";
	     fstream arena;
	     arena.open("Arena.txt",ios::out);
	     arena<<"00";
	     arena.close();
	     delay(1000);
	     exit(0);
	     }
	    clrscr();
	    i=biostime(0,0L);
	    cout<<start;
	    if((i-start)>=1)
	  { player.foodacc()-=(i-start); start = i;  }
	    if(player.foodacc()<=0)
	    {player.foodacc()=0;
	     static fold = biostime(0, 0L);
	     c=biostime(0,0L);
	     if(c-fold>=1)
	     {player.lifeacc()-=(c-fold);
	     fold = c;
	     } }
	     if(player.lifeacc()<0)
	    {player.changestatus();
	     clrscr();
	     cout<<"YOU LOSE!!!!!!!!!!!!";
	     delay(500);
	    exit(0);}
	    clrscr();
	    cout<<"\n\t\t\t\t\tHIDE";
	    cout<<"\n\t\t\t\t\t****";
	    player.displayhide();
	    delay(100);
	 } bioskey(0);
	   goto arena;

	     case 818:
	     int posn;
	     fstream roam;
	     char buf[10];
	     char str[2];
	     str[0]=idf/10 + 48;
	     str[1]='\0';
	     char string[4];
	    string[0]='d';
	    string[1]='t';
	    string[2]=idf%10 + 48;
	    string[3]='\0';
	    for(;bioskey(1)==0;)
	    { win.open("win.txt",ios::in);
	    win>>npr;
	    win.close();
	     if(npr==1)
	    {clrscr();
	     cout<<"\t\t\tYOU WIN!!!!!!!!!!!";
	     fstream arena;
	     arena.open("Arena.txt",ios::out);
	     arena<<"00";
	     arena.close();
	     delay(1000);
	     exit(0);
	     }
	     clrscr();
	    i=biostime(0,0L);
	    if((i-start)>=1)
	  {cout<<i-start;  cout<<"\n"<<player.foodacc();
	  player.foodacc()-=(i-start); start = i;
	 cout<<"\n"<<player.foodacc();
	   }
	    if(player.foodacc()<=0)
	    {player.foodacc()=0;
	     static fold = biostime(0,0L);
	     c=biostime(0,0L);
	     if(c-fold>=1)
	    {player.lifeacc()-=(c-fold);
	     fold = c;
	     } }
	     if(player.lifeacc()<0)
	    {player.changestatus();
	    clrscr();
	    cout<<"YOU LOSE!!!!!!!!!!!!";
	    delay(1500);
	    exit(0);}
	    stati++;
	   if(stati==15)
      { stati =0;   roam.open(str,ios::in);
	     roam.seekg(pos);
	    if(roam.eof()==0)
	  {  roam>>buf;
		{ pos = roam.tellg();
	       if(buf[2]!=(char)(idf%10+48))
	  {  if(buf[1]=='o')
	   { pos = roam.tellg()-3;
	    roam.close();
	    roam.open(str,ios::out|ios::ate);
	    roam.seekg(pos);
	    roam<<"   ";
	    roam.close();
	    roam.open(str,ios::in);
	    roam.seekg(pos+3);
	    }
	    process(buf,player); }    } }
	    roam.close();  }
	    clrscr();
	    cout<<"\n\t\t\tYOU ARE PRESENTLY ROAMING";
	    cout<<"\n\n\t\t\tPress any key to go to hide";
	    cout<<"\n\n\t\t\tPress '1' to go to FIGHT MENU";
	    cout<<"\n\n\t\t\tPress '2' to set traps";
	    delay(100); }
	    switch(bioskey(0))
	    {case 561 :
	    clrscr();
	     char ch[3];
	    ch[0] = 'f';
	    ch[1] = 'p';
	    ch[2] = idf%10 +48;
	    ch[3] = idf/10 +48;
	    ch[4] = '\0';
	    roam.open(str,ios::out|ios::ate);
	    posn = roam.tellp() + 1;
	    roam<<" "<<string;
	    roam.close();
	    for(;bioskey(1)==0;)
	    { win.open("win.txt",ios::in);
	    win>>npr;
	    win.close();
	     if(npr==1)
	    {clrscr();
	     cout<<"YOU WIN!!!!!!!!!!!";
	     fstream arena;
	     arena.open("Arena.txt",ios::out);
	     arena<<"00";
	     arena.close();
	     delay(1000);
	     exit(0);
	     }
	    i=biostime(0,0L);
	    if((i-start)>=1)
	  { player.foodacc()-=(i-start); start = i;  }
	    if(player.foodacc()<=0)
	    {player.foodacc()=0;
	     static food = biostime(0, 0L);
	     c=biostime(0,0L);
	     if(c-food>=1)
	     {player.lifeacc()-=(c-food);
	     food = c;
	     } }
	     if(player.lifeacc()<0)
	   {player.changestatus();
	    clrscr();
	    cout<<"YOU LOSE!!!!!!!!!!!!";
	    delay(500);
	    exit(0);}
	    clrscr();
	    stati++;
	  if(stati==15)
    {stati=0; roam.open(str,ios::in);
	     roam.seekg(pos);
	     if(roam.eof()==0)
	   {  roam>>buf;
	     pos= roam.tellg();
	     { if(buf[2]!=(char)(idf%10+48))
	  { if(buf[1]=='o')
	   {int pos = roam.tellg()-3;
	    roam.close();
	    roam.open(str,ios::out|ios::ate);
	    roam.seekg(pos);
	    roam<<"   ";
	    roam.close();
	    roam.open(str,ios::in);
	    roam.seekg(pos+3);
	    }
	    process(buf,player);   }  }}
	    roam.close(); }
	    clrscr();
	    cout<<"\t\t\t\tLIST OF PLAYERS ROAMING\t";cout<<posn;
	    play temp;
	    ifstream fp;
	    fp.open(ch,ios::binary);
	    while( fp.read((char*)&temp,sizeof(play)))
	  {
	   cout<<"\n\n\t\t\t\tPlayer "<<temp.idacc()%10;
	   cout<<"\n\n\t\t\t\tLife "<<temp.lifeacc();
	   cout<<"\n\n\t\t\t\tFood "<<temp.foodacc();
	   }
	   fp.close();
	    cout<<"\n\n\t\t\tPress the player code to initiate fight ";
	    cout<<"\n\t\t\tOr press any other key except(0-9) to back off ";
	    delay(100);

	 }
	 play temp;int to=-1,flag=0;
	 switch(bioskey(0))
	 {case 2864 : to=0;break;
	  case 561 : to=1;break;
	  case 818 : to=2;break;
	  case 1075 : to=3;break;
	  case 1332 :to=4;break;
	  case 1589 :to=5 ;break;
	  case 1846 : to=6;break;
	  case 2103 : to=7;break;
	  case 2360 :to=8 ;break;
	  case 2617 : to=9;break;
	  default : break;
	  }
	 ifstream fq;
	  fq.open(ch,ios::binary);
	   while( fq.read((char*)&temp,sizeof(play)))
	  if(temp.idacc()%10==to)
	  {flag=-1; break;}

	   fq.close();
	 roam.open(str,ios::out|ios::ate);
	 roam.seekp(posn);
	 roam<<"   ";
	 roam.close();
	 ofstream fp;
	 fp.open(ch);
	 fp.close();
	 if(flag==0&&to==-1){clrscr();cout<<"no response";delay(1000);goto arena;}
	 else
	{ player.fight(to,temp);
	  }
	 goto arena;

	  case 818 :
	    for(;bioskey(1)==0;)
	    { win.open("win.txt",ios::in);
	    win>>npr;
	    win.close();
	     if(npr==1)
	    {clrscr();
	     cout<<"YOU WIN!!!!!!!!!!!";
	     fstream arena;
	     arena.open("Arena.txt",ios::out);
	     arena<<"00";
	     arena.close();
	     delay(1000);
	     exit(0);
	     }

	    i=biostime(0,0L);
	    if((i-start)>=1)
	  { player.foodacc()-=(i-start); start = i;  }
	    if(player.foodacc()<=0)
	    {player.foodacc()=0;
	     static food = biostime(0, 0L);
	     c=biostime(0,0L);
	     if(c-food>=1)
	     {player.lifeacc()-=(c-food);
	     food = c;
	     } }
	     if(player.lifeacc()<0)
	    {player.changestatus();
	     clrscr();
	     cout<<"YOU LOSE!!!!!!!!!!!!";
	     delay(500);
	    exit(0);}
	    clrscr();
	    stati++;
	   if(stati==15)
	   {stati=0;  roam.open(str,ios::in);
	    roam.seekg(pos);
	    if(roam.eof()==0)
	    { roam>>buf;
	      pos=roam.tellg();
	     {  if(buf[2]!=(char)(idf%10+48))
	  { if(buf[1]=='o')
	   {int pos = roam.tellg()-3;
	    roam.close();
	    roam.open(str,ios::out|ios::ate);
	    roam.seekg(pos);
	    roam<<"   ";
	    roam.close();
	    roam.open(str,ios::in);
	    roam.seekg(pos+3);
	    }

	    process(buf,player);   } }}}
	    clrscr();
	    cout<<"\n\n\t\t\tTRAPS AVAILABLE                       COST(food)";
	    cout<<"\n\n\t\t\t1.To reduce food by 250                 300 " ;
	    cout<<"\n\n\t\t\t2.To reduce life by 100                 400 ";
	    cout<<"\n\n\t\t\t3.To Kill a Player without fighting     800  "  ;
	    delay(100);
	 }
	 roam.close();
	 char chara[5];
	 roam.open(str,ios::out|ios::app);
	  clrscr();
	  switch( bioskey(0))
	  { case 561:
	    if(player.foodacc()<300)
	    {cout<<"\n\n\t\t\t\tYou don't have enough resources";
	    delay(1500);}
	    chara[0]='a';break;
	    case 818:
	    if(player.foodacc()<400)
	    {cout<<"\n\n\t\t\t\tYou don't have enough resources";
	    delay(1500); }
	    chara [0]='b'; break;
	    case 1075:
	    if(player.foodacc()<800)
	    {cout<<"\n\n\t\t\t\tYou don't have enough resources";
	    delay(1500);  }
	    chara [0] = 'c';break;
	    }
	    chara[1]='o';
	    chara[2]=idf%10 +48;
	    chara[3]='\0';
	    roam<<" "<<chara;
	    roam.close();
	     goto arena;
	     default : goto arena;
	   }
	     case 1075:  clrscr();break;
	     default: goto arena ;
	    }

	    break;

case 2 : clrscr();
	      char k;int h;
	    for( h=0; h<=0; h++)
   {  cout<<"\t\t\t\t\t";
   cprintf("\n\t\t\tGame Instructions");

   }
   for (h=0;h<=0;h++)
   {
   cout<<"\n\t\t\t**** ************";
}
	     delay(250);
	      cout<<"\n\n\nThe Hunger Games is a game based on survival and the one to survive will be the winner.";
		  delay(300);
		cout<<"\n\n\nYou can choose between staying under hide and wandering.In the beginning"
		  <<" you canget many useful things from the cornucopia"
		  <<" but when you do so you are under     constant threat of an attack. By wandering you can be invited to"
		  <<" fight or can   initiate fight or set traps for other players. When  you kill a player you get  all the"
		  <<" food and weapon he has. The food initially given  will not be sufficientduring gameplay.";
		 delay(300);
		cprintf("\n\n\nForming allies can increase the effective attack inflicted on other player and  you can get help from your allice ");
		cprintf("when you are under attack. Alliances(if any)  will be broken when it comes to two players.\n\n\nThere is only a single rule ");
		  cprintf("for this game SURVIVE\n\nPress 1 to return to main menu ");
		  cin>>k;
		  clrscr();
		  goto lab;
		  default: exit(0);

   }



}








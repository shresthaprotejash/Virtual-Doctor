#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>
#include<ctype.h>
#include<string.h>
#include<malloc.h>
#include<stdlib.h>

int initmouse();
void showmouse();
void getmouse(int &x,int &y,int &click);
void hidemouse();
void heading();
void about(int xi);
void border();
void loading();
void home(char homori[20]);
void tabs(int tab);
void draw_box();
void disease(char f[100],int t);
void medicine1(char f[100],int d);
void search(int d);
void disease_search();
void medicine(int d);
void percentage();
void simple();
void selection();


union REGS i,o;

int temp=0;
int k=0;

struct list
{
    int key;
    char info[100];
}s[100];

int initmouse()
{
    i.x.ax=0;
    int86(51,&i,&o);
    return(o.x.ax);
}

void showmouse()
{
    i.x.ax=1;
    int86(51,&i,&o);
}

void  getmouse(int &x,int &y,int &click)
{
    i.x.ax=3;
    int86(51,&i,&o);
    x=o.x.cx;
    y=o.x.dx;
    click=o.x.bx;
}

void hidemouse()
{
    i.x.ax=2;
    int86(51,&i,&o);
}

void heading()
{
	rectangle(50,50,590,100);
	settextstyle(10,HORIZ_DIR,3);
	outtextxy(170,45,"VIRTUAL DOCTOR");
}

void about(int xi)
{
    int t,q,w;char c;
     FILE* fp;
     if(xi==1)
     {
     	fp=fopen("info.txt","r");
     		gotoxy(8,9);t=9;w=8;
     }
     if(fp==NULL)
     {
     	printf("file is empty\n");
     		return;
     }
     delay(800);
     while(!feof(fp))
     {
            c=fgetc(fp);
     		if(c=='\n')
	     	{
	     			gotoxy(w,++t);
	     			continue;
	     	}
		delay(10);
     		printf("%c",c);
     }
}

void border()
{
   rectangle(30,10,610,467);
}

void loading()
{
    int r,j;
    float area,area1;
    void *pi,*q;
    r=280;j=250;
    rectangle(r,j,r+60,j+17);
    setfillstyle(SOLID_FILL,BLUE);
    rectangle(r+2,j+3,r+9,j+13);
    floodfill(283,254,WHITE);
    area=imagesize(r+2,j+3,r+9,j+13);
    pi=malloc(area);
    getimage(r+2,j+3,r+9,j+13,pi);

    putimage(r+11.5,j+3,pi,XOR_PUT);
    putimage(r+20.5,j+3,pi,XOR_PUT);
    area1=imagesize(r+2,j+3,r+20.5,j+13); q=malloc(area1);
    getimage(r+2,j+3,r+30,j+13,q);
    int i=0,k=0;
    while(i<50)
    {
      if(i%10==0)
           k=0;
      cleardevice();
      setbkcolor(0);
      gotoxy(36,15);
      settextstyle(7,HORIZ_DIR,1);
      outtextxy(270,210,"LOADING");
      rectangle(r,j,r+60,j+17);
      putimage(r+5+(3*k),j+3,q,XOR_PUT);
      delay(70);
      i++; k++;
     }
}


void home(char homori[20])
{
     int t,q,w;char c;
     FILE* hp;
	 hp=fopen(homori,"r");
   	 gotoxy(8,12);t=12;w=8;

     if(hp==NULL)
     {
     	printf("file is empty\n");
     	return;
     }
     delay(500);
     while(!feof(hp))
     {
     	c=fgetc(hp);
     	if(c=='\n')
     	{
	     		gotoxy(w,++t);
		     	continue;
    	}
    	delay(1);
    	printf("%c",c);
     }
     fclose(hp);
     return;
}

void tabs(int tab)
{
    hidemouse();
    cleardevice();
    setbkcolor(0);
 
     heading();
     border();
     gotoxy(6,10);
     printf("   HOME   DISEASE SEARCH    EVALUATION OF SYMPTOMS  MEDICINES  EXIT");
     int f,e;
     if(tab==1)
     {
	 e=58;f=98;
     }
     if(tab==2)
     {
	 e=112;f=233;
     }
     if(tab==3)
     {
	 e=259;f=440;
     }
     if(tab==4)
     {
	 e=453;f=531;
     }
     if(tab==5)
     {
	 e=542;f=593;
     }
     int poly[50]={e,160,e,143,f,143,f,160,593,160,593,455,50,455,50,160,e,160};
     drawpoly(9,poly);
     showmouse();
}


void  draw_box()
{
     int m,n,x,y,j,click;
     m=80;n=220;
     rectangle(m,n,m+200,n+20);
     rectangle(m+205,n+3,m+257,n+20);
     gotoxy(37,15);
     printf("search");
     settextstyle(10,HORIZ_DIR,3);
}

void disease(char f[100],int t)
{
    FILE *fp;
    fp=fopen("names.txt","r");
    int j=0,h=0,m,n,x,y,click;
    char c,word[100];
    cleardevice();
    setbkcolor(0);
	border();
    tabs(t);
    if(strcmp(f,"\0")!=0)
    {
        gotoxy(13,12);
            printf("Disease : %s",f);
    }
    while(!feof(fp))
    {
        if(isdigit(c=fgetc(fp)))
        {
                j=0;
                while((c=fgetc(fp))!='\n')
                           word[j++]=c;
                word[j]='\0';
                if(word==NULL)
                                break;

                if(strcmp(word,f)==0)
                {
                       while(!isdigit(c=fgetc(fp)))
                       {
                                 if(c=='@')
                                 {
                                          while((c=fgetc(fp))!='\n')
                                          {
                                          }
                                          continue;
                                 }
                                 if(c=='$'||c=='#')
                                 {
                                          gotoxy(11,13+h++);continue;}
                                          if(h==10)
                                          {
                                                 delay(500);
                                                 m=532; n=380;
                                                 setcolor(WHITE);
                                                 rectangle(m,n,m+45,n+20);
                                                 gotoxy(68,25);
                                                 printf("next>");
                                                 click=0;
                                                 while(1)
                                                 {
                                                       getmouse(x,y,click);
                                                       if(x>532&&x<532+45&&y>380&&y<400&&click==1)
                                                       {
                                                              hidemouse();cleardevice();
                                                              setbkcolor(0);
                                                              border();
                                                              tabs(t);showmouse();
                                                              gotoxy(11,17);h=0;
                                                              break;
                                                       }
                                                 }
                                          }
                                          printf("%c",c);
                                 }
                       }
                }
      }
      fclose(fp);
}

void medicine1(char f[100],int d)
{
    int j=0,m,n,x,y,click;
    char word[100],c,h=0;
    FILE *fp;
    fp=fopen("names.txt","r");
    cleardevice();
    if(d==1)
    tabs(4);
    if(d==2)
    tabs(3);
    border();
    if(strcmp(f,"\0")!=0)
    {
        gotoxy(13,12);
        printf("Disease : %s",f);
    }
    while(!feof(fp))
    {
        if(isdigit(c=fgetc(fp)))
        {
                j=0;
                while((c=fgetc(fp))!='\n')
                                word[j++]=c;
                word[j]='\0';
                if(strcmp(word,f)==0)
                {
                                while(!isdigit(c=fgetc(fp)))
                                {
                                        if(c=='$'||c=='#')
                                        {
                                               while((c=fgetc(fp))!='\n');
                                               	{
                                               	}
                                              	continue;
                                       	}
                                       	if(c=='@')
                                       	{
                                       	        gotoxy(11,13+h++); continue;}
                                       	        if(h==7)
                                       	        {
                                       	                  delay(500);
                                       	                  m=532; n=380;
                                       	                  setcolor(WHITE);
                                       	                  rectangle(m,n,m+45,n+20);
                                       	                  gotoxy(68,25);
                                       	                  printf("next>");
                                       	                  click=0;
                                       	                  while(1)
                                       	                  {
                                       	                          getmouse(x,y,click);
                                       	                          if(x>532&&x<532+45&&y>380&&y<400&&click==1)
                                       	                          {
                                       	                                 hidemouse();cleardevice();
                                       	                                 if(d==2)
                                       	                                 tabs(3);
                                       	                                 if(d==1)
                                       	                                 tabs(4);
                                       	                                 border();
                                       	                                 showmouse();gotoxy(11,13);h=0;
                                                                         break;
                                                                  }
                                                          }
                                                }
                                                printf("%c",c);
                                        }
                                }
                }
        }
}

void search(int d)
{
    char c,g,word[100][100],word1[100],f[100];
    int ii=0,j=0,n,xi,count=0,p=0,l=0,flag=0;
    FILE *fp;
    c='\0';
    fp=fopen("names.txt","r");
    strcpy(f,"\0");
    while(!feof(fp))
    {
        if(isdigit(c=fgetc(fp)))
        {
                while((c=fgetc(fp))!='\n')
                      word[ii][j++]=c;
                word[ii][j]='\0';
                ii++;
        }
        j=0;
    }
    count=ii;
    g='\0';
    strcpy(f,"\0");
    while((int)g!=13&&strcmp(f,"quit")!=0)
    {
        g=getch();
        if((int)g==8)
        {
                gotoxy(12+p,15);
                printf("  ");
                printf("\0");
                f[--p]='\0';
                if(p<0)
                      p=0;
                gotoxy(13,15);
                f[p]='\0';
                printf("%s",f);
                continue;
        }
        f[p++]=g;
        gotoxy(13,15);
        f[p]='\0';
        printf("%s",f);
        cleardevice();
        hidemouse();
        border();
        tabs(d+1);
        draw_box();
        gotoxy(13,15);
        printf("%s",f);
        showmouse();
        for(n=0;n<count;n++)
        {
                for(j=0;j<p;j++)
                {
                         if(f[j]==word[n][j])
                                continue;
                         else
                                break;
                }
                if(j==p)
                {
                         gotoxy(11,17+l++);
                         if(flag<1)
                               strcpy(word1,word[n]);
                         printf("%s\n",word[n]);flag++;
                }
        }
        l=0;flag=0;
    }
    if(d==1)
        disease(word1,2);
    if(d==3)
        medicine1(word1,1);
}


void disease_search()
{
    int m,n,x,y,j,click;
    settextstyle(8,HORIZ_DIR,1);
    outtextxy(80,180,"Enter the disease name in the box");
    draw_box();
    while(1)
    {
        getmouse(x,y,click);
        if(x>80&&x<280 &&y>220 &&y<270 && click==1 )
        {
                search(1);
        }
        else if(((x>58&&x<98)||(x>258 && x<593))&&(y<160&&y>143) && click==1)
                break;
        else if(click==2)
                break;
    }
}


void medicine(int d)
{
    int m,n,x,y,j,click;
    settextstyle(8,HORIZ_DIR,1);
    outtextxy(80,180,"Enter the disease name in the box");
    draw_box();
    while(1)
    {
        getmouse(x,y,click);
        if(x>80&&x<280 &&y>220 &&y<270 && click==1 )
        {
                if(d==1)
                      search(3);
                if(d==2)
                       search(2);
        }
        else if(((x>58&&x<440)||(x>542 && x<593))&&(y<160&&y>143) && click==1)
                break;
        else if(click==2)
                break;
    }
}

void percentage()
{
	FILE *fp;
	int i,ii=0,j=0,l=0;
	float per[20],rep[50];
	char c,word[50][30];
	fp=fopen("compare.txt","r");
	if(fp==NULL)
	{
		printf("File open error\n");
		return;
	}

	while(!feof(fp))
	{
		rep[ii]=1;
	       while((c=fgetc(fp))!='\n'&& !feof(fp))
		       word[ii][j++]=c;
		word[ii][j]='\0';
		for(i=0;i<ii&&ii>0;i++)
		{
			if(strcmp(word[i],word[ii])==0)
			{
				rep[i]=rep[i]+1;
				ii--;
			}
		}
	ii++;
	j=0;
	}

	for(i=0;i<(ii-1);i++)
	{
		per[i]=(rep[i]/(ii-1))*100;
	}
	for(i=0;i<(ii-1);i++)
	{
		if(per[i]>=55 && per[i]>per[l])
			l=i;
	}
	FILE *hp;
	hp=fopen("result.txt","w");
	if(per[l]>=55)
	      fprintf(hp,"%s",word[l]);
	else
		fprintf(hp,"no");
	fclose(hp);
	fclose(fp);
}


//taking the symptoms
void simple()
{   
    char c,g,word[200][100],word1[100],f[100],res[20],t;
    int ii=0,j=0,n,xi,count=0,p=0,l=0,flag=0,tot=0,ra;
    FILE *fp,*gp,*hp;
    c='\0';
    fp=fopen("symp.txt","r");
    hp=fopen("compare.txt","w");
    strcpy(f,"\0");

    while(!feof(fp))
    {
          if((c=fgetc(fp))=='$')
          {
                 while((c=fgetc(fp))!='\n')
                    word[ii][j++]=c;
                 word[ii][j]='\0';
                 ii++;
          }
          j=0;
    }
    count=ii;
    for(xi=0;xi<6;xi++)
    {
        hp=fopen("compare.txt","a");
        cleardevice();
         hidemouse();
         tabs(3);
         showmouse();
         p=0;
         g='\0';
         strcpy(f,"\0");
         while((int)g!=13&&strcmp(f,"quit")!=0)
         {
                  gotoxy(12,13);
                  printf("Enter the symptom: ");
                  g=getch();
                  if((int)g==8)
                  {
                      gotoxy(31+p,13);
                      printf("  ");
                      printf("\0");
                      f[--p]='\0';
                      if(p<0)
                           p=0;
                      gotoxy(32,13);
                      f[p]='\0';
                      printf("%s",f);
                      continue;
                  }
                  f[p++]=g;
                  gotoxy(32,13);
                  f[p]='\0';
                  printf("%s",f);
                  cleardevice();
                  hidemouse();
                  tabs(3);
                  gotoxy(32,13);
                  printf("%s",f);
                  showmouse();
                  for(n=0;n<count;n++)
                  {
                         for(j=0;j<p;j++)
                         {
                              if(f[j]==word[n][j])
                                   continue;
                              else
                                    break;
                         }
                         if(j==p && l<10)
                         {
                                 gotoxy(13,15+l++);
                                 if(flag<1)
                                        strcpy(word1,word[n]);
                                 printf("%s",word[n]);
                                 flag++;
                         }
                  }
                  l=0;flag=0;
         }
         if(strcmp(f,"quit")==0)
                  return;
         if((int)f[0]==13)
         {
                  xi--;
                  gotoxy(10,16);
                  printf("No symptoms selected.. Please select again..!!\n");
                  delay(2500);
                  continue;
         }                  
         cleardevice();
         hidemouse();
         tabs(3);
         showmouse();
         gotoxy(10,16);
         printf("The sypmtom you selected is: %s",word1);
         gotoxy(28,18);
         printf("Press any key to continue");
         getch();
         char d,word2[1][60],word3[1][60];
         j=0;
         gp=fopen("names.txt","r");
         while(!feof(gp))
         {     
                  d=fgetc(gp);
                  j=0;
                  if(isdigit(d))
                  {
                        while((d=fgetc(gp))!='\n')
                              word2[0][j++]=d;
                        word2[0][j]='\0';
                  }
                  if(d=='$')
                  {       
                        j=0;
                        while((d=fgetc(gp))!='\n')
                               word3[0][j++]=d;
                        word3[0][j]='\0';
                        if(strcmp(word1,word3[0])==0)
                        {
                               tot++;
                               fprintf(hp,"%s\n",word2[0]);
                        }
                  }
         }                 
         fclose(hp);
         if(xi>=2)
         {
                  percentage();
                  j=0;
                  FILE *rs;
                  rs=fopen("result.txt","r");
                  while(!feof(rs))
                  {
                        t=fgetc(rs);
                        res[j++]=t;
                  }
                  res[--j]='\0';
                  ra=strlen(res);
                  fclose(rs);
                  if(ra<=3)
                       continue;
                  else
                       break;
         }
    }
    cleardevice();
    hidemouse();
    tabs(3);
    showmouse();
    gotoxy(14,13);
    if(xi>=6)
    {
        printf("Disease couldnot be detected..Please try again");
        return;
    }
    fclose(hp);
    printf("Disease detected: %s ",res);
    delay(2000);
    disease(res,3);
    gotoxy(30,25);
    printf("Press any key to continue.");
    getch();
    medicine1(res,2);
    return;
}


void selection()
{
    char n;
    int x,y,click;
    while(1)
    {
        getmouse(x,y,click);
        if(x>80&&x<155&&y>175&&y<200&&click==1)
        {
                cleardevice();
                border();
                heading();
                tabs(3);
                simple();
        }               
        if(((x>58&&x<233)||(x>453 && x<593))&&(y<160&&y>143) && click==1)
                break;
        else if(click==2)
                break;
    }
}


void main()
{
    int m,n;
    int gm,pm,x,y,w,t,click;
    char c;
    gm=DETECT;
    initgraph(&gm,&pm,"C:\\TC\\BGI");
    setbkcolor(0);
    border();
    heading();
    about(1);
    m=532; n=380;
    rectangle(m,n,m+45,n+20);
    gotoxy(68,25);
    printf("next>");
    initmouse();
    showmouse();
    while(1)
    {
        getmouse(x,y,click);
        if(x>532 && x<m+45 && y>380 && y<400 && click==1)
        {
                hidemouse();
                cleardevice(); setbkcolor(0);
                gotoxy(36,15);
                settextstyle(4,HORIZ_DIR,2);
                outtextxy(200,200,"LOADING");
                showmouse();
                loading();
                delay(300);
                cleardevice();
                setbkcolor(BLACK);
                showmouse();
                break;
        }
    }
    tabs(1);
    home("home.txt");
    while(1)
    {
        label:  getmouse(x,y,click);
        if(x>58 && x<98 && y>143 && y<160 && click==1)
        {
                tabs(1);
                home("home.txt");
                goto label;
        }                
        if(x>112 && x<233 && y>143 && y<160 && click==1)
        {
                tabs(2);
                disease_search();
                goto label;
        }
        if(x>260 && x<440 && y>143 && y<160 && click==1)
        {
                tabs(3);
                settextstyle(3,HORIZ_DIR,1);
                setcolor(RED);
                outtextxy(80,175,"Click here");
                setcolor(WHITE);
                outtextxy(174,175,"to start selection.");
                selection();
                goto label;
        }                
        if(x>453 && x<531 && y>143 && y<160 && click==1)
        { 
                tabs(4);
                medicine(1);
                goto label;
        }
        if(x>542 && x<591 && y>143 && y<160 && click==1)
        {
                tabs(5);
                home("origin.txt");
                circle(507,392,8);
                gotoxy(25,25);
                textcolor(RED);
                printf("Press any key to EXIT");
                getch();
                return;
        }
        if(click==2)
                break;
    }
    getch();
    closegraph();
}


#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include<iomanip>
#include<io.h>
#include<time.h>
#include <sstream>
 
 FILE *fp;
 using namespace std;
 void traval(char name[]);//遍历一个目录
//int i=0;
 int main()
 {
  if((fp=fopen("data.txt","w"))==NULL)
  {
   cout<<"打开写文件失败！\n";
   return 0;
  }
  char name[250]="D:\\workspace\\c4r\\*.*";
  traval(name);
  fclose(fp);
  
  return 0;
  
 }

void traval(char name[])//遍历一个目录
{
  char name1[250];
  //cout<<name;
  //fprintf(fp,"%s  ****%d",name,++i);
  _finddata_t file;
  long lf;
  if((lf=_findfirst(name,&file))==-1l)
  {
   cout<<"该目录不存在！\n";
   fprintf(fp,"该目录不存在！\n");
  }
  else
  {
   while(_findnext(lf,&file)==0)
   {
    if(file.name[2]==0)
     continue;
    cout<<file.name<<"\t";
    fprintf(fp,"%s\t",file.name);
    if(file.attrib==0)
    {
     cout<<"正常 ";
     fprintf(fp,"正常 ");
    }
    if((file.attrib%2)==1)
    {
     cout<<"只读 ";
     fprintf(fp,"只读 ");
    }
    if((file.attrib==2)||(file.attrib==3)||(file.attrib==6)||(file.attrib==7)||
     (file.attrib==18)||(file.attrib==19)||(file.attrib==22)||(file.attrib==23)||
     (file.attrib==34)||(file.attrib==35)||(file.attrib==38)||(file.attrib==39)||
     (file.attrib==50)||(file.attrib==51)||(file.attrib==54)||(file.attrib==55))
    {
     fprintf(fp,"%s\t",file.name);
     cout<<"隐藏 ";
     fprintf(fp,"隐藏 ");
    }
    if((file.attrib==4)||(file.attrib==5)||(file.attrib==6)||(file.attrib==7)||
     (file.attrib==20)||(file.attrib==21)||(file.attrib==22)||(file.attrib==23)||
     (file.attrib==36)||(file.attrib==37)||(file.attrib==38)||(file.attrib==39)||
     (file.attrib==52)||(file.attrib==53)||(file.attrib==54)||(file.attrib==55))
    {
     cout<<"系统 ";
     fprintf(fp,"系统 ");
    }
    if((file.attrib>=32&&file.attrib<=55))
    {
     cout<<"存档 ";
     fprintf(fp,"存档 ");
    }
    if((file.attrib>=16&&file.attrib<=23)||(file.attrib>=48&&file.attrib<=55))
    {
     cout<<"文件夹 ";
     cout<<endl;
     fprintf(fp,"文件夹\n");
     strcpy(name1,name);
     name[strlen(name)-3]='\0';//最后三个字符去掉
    name=strcat(name,file.name);//
     name=strcat(name,"\\*.*");
     cout<<endl<<name<<endl;
     //fprintf(fp,"\n%s\n",name1);
     traval(name);
     strcpy(name,name1);
    }
    else
    {
     cout<<endl;
     fprintf(fp,"\n");
    }
   }
  }
  _findclose(lf);
 }

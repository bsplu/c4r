/*
 * 首先应该有一个文件列表叫save.list
 * 该文件记录着要同步的文件名
 */
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include<iomanip>
#include<io.h>
#include<time.h>
#include <sstream>


using namespace std;

int sys(int s);
void traval(char name[]);

int main(){


	//sys(1);
	char name[250]=".\\log";
	traval(name);

	return 0;
}


/*
 * 该函数主要作用是同步的时候，选择要同步的文件
 * in:s表示同步指令
 * out:函数是否执行成功
 */
int sys(int s){



	string ssavepath;//要同步的目录名字

	string sc4rbpath;//c4r储存的目录
	string starfilename;
	stringstream stime;

	ssavepath = ".";

	sc4rbpath = "D:/workspace";


	stime << int(time(NULL));
	starfilename = (stime.str() + ".tar.gz").c_str();

	//检查sc4r目录是否存在
	if(_access((sc4rbpath+"/.c4rb").c_str(),0) == -1){
		system(("powershell \"mkdir " + sc4rbpath + "/.c4rb \"").c_str());
	}

	//如果要同步所有文件，则不会罗列出还没有同步的文件列表
	if(s == 1){
		//表示全部同步

		ofstream fout((sc4rbpath + "/.c4rb/save.list").c_str());

		//刷新整个列表
		//重新创建save.list
		//AddSaveList(fout,ssavepath);

		//将整个目录打包
		system(("tar --exclude " + sc4rbpath + "/.c4rb -zcvf "+sc4rbpath+"/.c4rb/" + starfilename + " " +
				ssavepath + "/ --force-local" + " > "+ sc4rbpath+ "/.c4rb/log").c_str() );


		return 1;

	}else if(s == 2 || s == 3){
		//打开save.list文件

		//2表示新产生的文件全部同步 3表示需要用户选择需要增添或者要同步的文件
		//增添列表
		if(s == 2){
			//获得新文件单子，将单子直接

		}else if( s == 3){

		}else{

		}

		//将新的到的列表打包


	}else{

	}

	return 1;

}


int AddSaveList(ofstream fout_in,char spath[]){

}

void traval(char name[])//遍历一个目录
		{
	char name1[250];
	//cout<<name;
	//fprintf(fp,"%s  ****%d",name,++i);
	_finddata_t file;
	long lf;
	if ((lf = _findfirst(name, &file)) == -1l) {
		cout << "该文件或目录不存在！\n";
		//fprintf(fp,"该目录不存在！\n");
	} else {
		//输入启示为文件

		cout << file.name << "\t";
		//fprintf(fp,"%s\t",file.name);
		if (file.attrib == 0) {
			cout << "正常 ";
			//fprintf(fp,"正常 ");
		}
		if ((file.attrib % 2) == 1) {
			cout << "只读 ";
			//fprintf(fp,"只读 ");
		}
		if ((file.attrib == 2) || (file.attrib == 3) || (file.attrib == 6)
				|| (file.attrib == 7) || (file.attrib == 18)
				|| (file.attrib == 19) || (file.attrib == 22)
				|| (file.attrib == 23) || (file.attrib == 34)
				|| (file.attrib == 35) || (file.attrib == 38)
				|| (file.attrib == 39) || (file.attrib == 50)
				|| (file.attrib == 51) || (file.attrib == 54)
				|| (file.attrib == 55)) {
			//fprintf(fp,"%s\t",file.name);
			cout << "隐藏 ";
			//fprintf(fp,"隐藏 ");
		}
		if ((file.attrib == 4) || (file.attrib == 5) || (file.attrib == 6)
				|| (file.attrib == 7) || (file.attrib == 20)
				|| (file.attrib == 21) || (file.attrib == 22)
				|| (file.attrib == 23) || (file.attrib == 36)
				|| (file.attrib == 37) || (file.attrib == 38)
				|| (file.attrib == 39) || (file.attrib == 52)
				|| (file.attrib == 53) || (file.attrib == 54)
				|| (file.attrib == 55)) {
			cout << "系统 ";
			//fprintf(fp,"系统 ");
		}
		if ((file.attrib >= 32 && file.attrib <= 55)) {
			cout << "存档 ";
			//fprintf(fp,"存档 ");
		}

		//输入启示为文件夹
		if ((file.attrib >= 16 && file.attrib <= 23)
				|| (file.attrib >= 48 && file.attrib <= 55)) {


			while (_findnext(lf, &file) == 0) {
				if (file.name[2] == 0)
					continue;
				cout << file.name << "\t";
				//fprintf(fp,"%s\t",file.name);
				if (file.attrib == 0) {
					cout << "正常 ";
					//fprintf(fp,"正常 ");
				}
				if ((file.attrib % 2) == 1) {
					cout << "只读 ";
					//fprintf(fp,"只读 ");
				}
				if ((file.attrib == 2) || (file.attrib == 3)
						|| (file.attrib == 6) || (file.attrib == 7)
						|| (file.attrib == 18) || (file.attrib == 19)
						|| (file.attrib == 22) || (file.attrib == 23)
						|| (file.attrib == 34) || (file.attrib == 35)
						|| (file.attrib == 38) || (file.attrib == 39)
						|| (file.attrib == 50) || (file.attrib == 51)
						|| (file.attrib == 54) || (file.attrib == 55)) {
					//fprintf(fp,"%s\t",file.name);
					cout << "隐藏 ";
					//fprintf(fp,"隐藏 ");
				}
				if ((file.attrib == 4) || (file.attrib == 5)
						|| (file.attrib == 6) || (file.attrib == 7)
						|| (file.attrib == 20) || (file.attrib == 21)
						|| (file.attrib == 22) || (file.attrib == 23)
						|| (file.attrib == 36) || (file.attrib == 37)
						|| (file.attrib == 38) || (file.attrib == 39)
						|| (file.attrib == 52) || (file.attrib == 53)
						|| (file.attrib == 54) || (file.attrib == 55)) {
					cout << "系统 ";
					//fprintf(fp,"系统 ");
				}
				if ((file.attrib >= 32 && file.attrib <= 55)) {
					cout << "存档 ";
					//fprintf(fp,"存档 ");
				}
				if ((file.attrib >= 16 && file.attrib <= 23)
						|| (file.attrib >= 48 && file.attrib <= 55)) {
					cout << "文件夹 ";
					cout << endl;
					//fprintf(fp,"文件夹\n");
					strcpy(name1, name);
					name[strlen(name) - 3] = '\0';  //最后三个字符去掉
					name = strcat(name, file.name);  //
					name = strcat(name, "\\*.*");
					cout << endl << name << endl;
					//fprintf(fp,"\n%s\n",name1);
					traval(name);
					strcpy(name, name1);
				} else {
					cout << endl;
					//fprintf(fp,"\n");
				}
			}
		}
	}
	_findclose(lf);
}

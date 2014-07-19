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
void traval(string name_in);

int main(){


	//sys(1);
	string name=".\\*.*";
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

void traval(string name)//遍历一个目录
		{

	string name1;
	//cout<<name;
	//fprintf(fp,"%s  ****%d",name,++i);
	_finddata_t file;
	long lf;
	if ((lf = _findfirst(name.c_str(), &file)) == -1l) {
		cout << "该文件或目录不存在！\n";
		//fprintf(fp,"该目录不存在！\n");
	} else {

			while (_findnext(lf, &file) == 0) {
				if (strcmp(file.name,"..") == 0)
					continue;
				cout << file.name << "\t";
				//fprintf(fp,"%s\t",file.name);
				if (file.attrib == 0) {
					cout << "正常 ";
					//fprintf(fp,"正常 ");
				}
				if ((file.attrib & _A_RDONLY) != 0) {
					cout << "只读 ";
					//fprintf(fp,"只读 ");
				}
				if ((file.attrib & _A_HIDDEN) != 0) {
					//fprintf(fp,"%s\t",file.name);
					cout << "隐藏 ";
					//fprintf(fp,"隐藏 ");
				}
				if ((file.attrib & _A_SYSTEM) != 0) {
					cout << "系统 ";
					//fprintf(fp,"系统 ");
				}
				if ((file.attrib & _A_ARCH) != 0) {
					cout << "存档 ";
					//fprintf(fp,"存档 ");
				}

				if ((file.attrib & _A_SUBDIR) != 0) {
					cout << "文件夹 ";
					cout << endl;
					//fprintf(fp,"文件夹\n");
					name1 = name;

					name.insert(name.length()-3,strcat(file.name,"\\"));

					cout << name << endl;

					//traval(name);
					cout<<endl;

					name = name1;
				} else {
					cout << endl;
					//fprintf(fp,"\n");
				}
			}


	}
	_findclose(lf);
}

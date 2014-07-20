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
int AddSaveList(ofstream *fout_in,string name);

int main() {

	sys(1);
	//string name = ".\\*.*";
	//traval(name);

	return 0;
}

/*
 * 该函数主要作用是同步的时候，选择要同步的文件
 * in:s表示同步指令
 * out:函数是否执行成功
 */
int sys(int s) {

	string ssavepath; //要同步的目录名字

	string sc4rbpath; //c4r储存的目录
	string starfilename;
	stringstream stime;

	ssavepath = ".";

	sc4rbpath = "D:/workspace";

	stime << int(time(NULL));
	starfilename = (stime.str() + ".tar.gz").c_str();

	//检查sc4r目录是否存在
	if (_access((sc4rbpath + "/.c4rb").c_str(), 0) == -1) {
		system(("powershell \"mkdir " + sc4rbpath + "/.c4rb \"").c_str());
	}

	//如果要同步所有文件，则不会罗列出还没有同步的文件列表
	if (s == 1) {
		//表示全部同步

		ofstream fout((sc4rbpath + "/.c4rb/save.list").c_str());
		system(("cp " + sc4rbpath + "/.c4rb/save.list" + " " + ssavepath + "/_temp.save.list").c_str());

		//刷新整个列表
		//重新创建save.list
		if(AddSaveList(&fout,ssavepath+"\\*.*") == -1){
			cout<<"储存列表错误";
			return -1;
		}

		//将整个目录打包
		system(
				("tar --exclude " + sc4rbpath //去掉.c4rb文件夹
						+ "/.c4rb -zcvf " + sc4rbpath + "/.c4rb/" + starfilename + " " //创建备份文件名
						+ ssavepath //压缩的文件

						+ "/ --force-local" + " > " + sc4rbpath + "/.c4rb/log").c_str());

		system(("rm -f " + ssavepath + "/_temp.save.list").c_str());

		return 1;

	} else if (s == 2 || s == 3) {
		//打开save.list文件

		//2表示新产生的文件全部同步 3表示需要用户选择需要增添或者要同步的文件
		//增添列表
		if (s == 2) {
			//获得新文件单子，将单子直接

		} else if (s == 3) {

		} else {

		}

		//将新的到的列表打包

	} else {

	}

	return 1;

}


//遍历一个目录 返回文件个数（如果是目录的话）
int AddSaveList(ofstream *fout_in,string name) {

	int num_file(0);
	string name1;
	_finddata_t file;
	long lf;
	if ((lf = _findfirst(name.c_str(), &file)) == -1l) {
		cout << "该文件或目录不存在！\n";
		return -1;
	} else {
		//先判断一下初始目录是否为文件
		if (file.attrib == 0) {
			name1 = name;
			name1 = (name1.erase(name1.length() - 3, 3)) + file.name;
			//cout << name1 << endl;
			*fout_in << name1 << endl;
			return 0;

		} else if ((file.attrib & _A_ARCH) != 0) {
			name1 = name;
			name1 = (name1.erase(name1.length() - 3, 3)) + file.name;
			//cout << name1  << endl;
			*fout_in << name1 << endl;
			return 0;
		} else {
			while (_findnext(lf, &file) == 0) {
				if (strcmp(file.name, "..") == 0)
					continue;

				if (file.attrib == 0) {
					name1 = name;
					name1 = (name1.erase(name1.length() - 3, 3)) + file.name;
					//cout << name1 << endl;
					*fout_in << name1 << endl;
					num_file++;
				}
				if ((file.attrib & _A_ARCH) != 0) {
					name1 = name;
					name1 = (name1.erase(name1.length() - 3, 3)) + file.name;
					//cout << name1 << endl;
					*fout_in << name1 << endl;
					num_file++;
				}

				if ((file.attrib & _A_SUBDIR) != 0) {

					name1 = name;

					name.insert(name.length() - 3, strcat(file.name, "\\"));
					num_file++;
					if(AddSaveList(fout_in,name) == 0 ){
						name = (name.erase(name.length() - 3, 3));
						//cout << name << endl;
						*fout_in << name << endl;
					}

					name = name1;

				}
			}
			//cout<<file.name<<":"<<num_file<<endl;
			return num_file;
		}
	}
	_findclose(lf);
}



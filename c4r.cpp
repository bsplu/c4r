/*
 * ����Ӧ����һ���ļ��б��save.list
 * ���ļ���¼��Ҫͬ�����ļ���
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
 * �ú�����Ҫ������ͬ����ʱ��ѡ��Ҫͬ�����ļ�
 * in:s��ʾͬ��ָ��
 * out:�����Ƿ�ִ�гɹ�
 */
int sys(int s){



	string ssavepath;//Ҫͬ����Ŀ¼����

	string sc4rbpath;//c4r�����Ŀ¼
	string starfilename;
	stringstream stime;

	ssavepath = ".";

	sc4rbpath = "D:/workspace";


	stime << int(time(NULL));
	starfilename = (stime.str() + ".tar.gz").c_str();

	//���sc4rĿ¼�Ƿ����
	if(_access((sc4rbpath+"/.c4rb").c_str(),0) == -1){
		system(("powershell \"mkdir " + sc4rbpath + "/.c4rb \"").c_str());
	}

	//���Ҫͬ�������ļ����򲻻����г���û��ͬ�����ļ��б�
	if(s == 1){
		//��ʾȫ��ͬ��

		ofstream fout((sc4rbpath + "/.c4rb/save.list").c_str());

		//ˢ�������б�
		//���´���save.list
		//AddSaveList(fout,ssavepath);

		//������Ŀ¼���
		system(("tar --exclude " + sc4rbpath + "/.c4rb -zcvf "+sc4rbpath+"/.c4rb/" + starfilename + " " +
				ssavepath + "/ --force-local" + " > "+ sc4rbpath+ "/.c4rb/log").c_str() );


		return 1;

	}else if(s == 2 || s == 3){
		//��save.list�ļ�

		//2��ʾ�²������ļ�ȫ��ͬ�� 3��ʾ��Ҫ�û�ѡ����Ҫ�������Ҫͬ�����ļ�
		//�����б�
		if(s == 2){
			//������ļ����ӣ�������ֱ��

		}else if( s == 3){

		}else{

		}

		//���µĵ����б���


	}else{

	}

	return 1;

}


int AddSaveList(ofstream fout_in,char spath[]){

}

void traval(string name)//����һ��Ŀ¼
		{

	string name1;
	//cout<<name;
	//fprintf(fp,"%s  ****%d",name,++i);
	_finddata_t file;
	long lf;
	if ((lf = _findfirst(name.c_str(), &file)) == -1l) {
		cout << "���ļ���Ŀ¼�����ڣ�\n";
		//fprintf(fp,"��Ŀ¼�����ڣ�\n");
	} else {

			while (_findnext(lf, &file) == 0) {
				if (strcmp(file.name,"..") == 0)
					continue;
				cout << file.name << "\t";
				//fprintf(fp,"%s\t",file.name);
				if (file.attrib == 0) {
					cout << "���� ";
					//fprintf(fp,"���� ");
				}
				if ((file.attrib & _A_RDONLY) != 0) {
					cout << "ֻ�� ";
					//fprintf(fp,"ֻ�� ");
				}
				if ((file.attrib & _A_HIDDEN) != 0) {
					//fprintf(fp,"%s\t",file.name);
					cout << "���� ";
					//fprintf(fp,"���� ");
				}
				if ((file.attrib & _A_SYSTEM) != 0) {
					cout << "ϵͳ ";
					//fprintf(fp,"ϵͳ ");
				}
				if ((file.attrib & _A_ARCH) != 0) {
					cout << "�浵 ";
					//fprintf(fp,"�浵 ");
				}

				if ((file.attrib & _A_SUBDIR) != 0) {
					cout << "�ļ��� ";
					cout << endl;
					//fprintf(fp,"�ļ���\n");
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

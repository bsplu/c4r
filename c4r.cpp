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
void traval(char name[]);

int main(){


	//sys(1);
	char name[250]=".\\log";
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

void traval(char name[])//����һ��Ŀ¼
		{
	char name1[250];
	//cout<<name;
	//fprintf(fp,"%s  ****%d",name,++i);
	_finddata_t file;
	long lf;
	if ((lf = _findfirst(name, &file)) == -1l) {
		cout << "���ļ���Ŀ¼�����ڣ�\n";
		//fprintf(fp,"��Ŀ¼�����ڣ�\n");
	} else {
		//������ʾΪ�ļ�

		cout << file.name << "\t";
		//fprintf(fp,"%s\t",file.name);
		if (file.attrib == 0) {
			cout << "���� ";
			//fprintf(fp,"���� ");
		}
		if ((file.attrib % 2) == 1) {
			cout << "ֻ�� ";
			//fprintf(fp,"ֻ�� ");
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
			cout << "���� ";
			//fprintf(fp,"���� ");
		}
		if ((file.attrib == 4) || (file.attrib == 5) || (file.attrib == 6)
				|| (file.attrib == 7) || (file.attrib == 20)
				|| (file.attrib == 21) || (file.attrib == 22)
				|| (file.attrib == 23) || (file.attrib == 36)
				|| (file.attrib == 37) || (file.attrib == 38)
				|| (file.attrib == 39) || (file.attrib == 52)
				|| (file.attrib == 53) || (file.attrib == 54)
				|| (file.attrib == 55)) {
			cout << "ϵͳ ";
			//fprintf(fp,"ϵͳ ");
		}
		if ((file.attrib >= 32 && file.attrib <= 55)) {
			cout << "�浵 ";
			//fprintf(fp,"�浵 ");
		}

		//������ʾΪ�ļ���
		if ((file.attrib >= 16 && file.attrib <= 23)
				|| (file.attrib >= 48 && file.attrib <= 55)) {


			while (_findnext(lf, &file) == 0) {
				if (file.name[2] == 0)
					continue;
				cout << file.name << "\t";
				//fprintf(fp,"%s\t",file.name);
				if (file.attrib == 0) {
					cout << "���� ";
					//fprintf(fp,"���� ");
				}
				if ((file.attrib % 2) == 1) {
					cout << "ֻ�� ";
					//fprintf(fp,"ֻ�� ");
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
					cout << "���� ";
					//fprintf(fp,"���� ");
				}
				if ((file.attrib == 4) || (file.attrib == 5)
						|| (file.attrib == 6) || (file.attrib == 7)
						|| (file.attrib == 20) || (file.attrib == 21)
						|| (file.attrib == 22) || (file.attrib == 23)
						|| (file.attrib == 36) || (file.attrib == 37)
						|| (file.attrib == 38) || (file.attrib == 39)
						|| (file.attrib == 52) || (file.attrib == 53)
						|| (file.attrib == 54) || (file.attrib == 55)) {
					cout << "ϵͳ ";
					//fprintf(fp,"ϵͳ ");
				}
				if ((file.attrib >= 32 && file.attrib <= 55)) {
					cout << "�浵 ";
					//fprintf(fp,"�浵 ");
				}
				if ((file.attrib >= 16 && file.attrib <= 23)
						|| (file.attrib >= 48 && file.attrib <= 55)) {
					cout << "�ļ��� ";
					cout << endl;
					//fprintf(fp,"�ļ���\n");
					strcpy(name1, name);
					name[strlen(name) - 3] = '\0';  //��������ַ�ȥ��
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

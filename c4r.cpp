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
int AddSaveList(ofstream *fout_in,string name);

int main() {

	sys(1);
	//string name = ".\\*.*";
	//traval(name);

	return 0;
}

/*
 * �ú�����Ҫ������ͬ����ʱ��ѡ��Ҫͬ�����ļ�
 * in:s��ʾͬ��ָ��
 * out:�����Ƿ�ִ�гɹ�
 */
int sys(int s) {

	string ssavepath; //Ҫͬ����Ŀ¼����

	string sc4rbpath; //c4r�����Ŀ¼
	string starfilename;
	stringstream stime;

	ssavepath = ".";

	sc4rbpath = "D:/workspace";

	stime << int(time(NULL));
	starfilename = (stime.str() + ".tar.gz").c_str();

	//���sc4rĿ¼�Ƿ����
	if (_access((sc4rbpath + "/.c4rb").c_str(), 0) == -1) {
		system(("powershell \"mkdir " + sc4rbpath + "/.c4rb \"").c_str());
	}

	//���Ҫͬ�������ļ����򲻻����г���û��ͬ�����ļ��б�
	if (s == 1) {
		//��ʾȫ��ͬ��

		ofstream fout((sc4rbpath + "/.c4rb/save.list").c_str());
		system(("cp " + sc4rbpath + "/.c4rb/save.list" + " " + ssavepath + "/_temp.save.list").c_str());

		//ˢ�������б�
		//���´���save.list
		if(AddSaveList(&fout,ssavepath+"\\*.*") == -1){
			cout<<"�����б����";
			return -1;
		}

		//������Ŀ¼���
		system(
				("tar --exclude " + sc4rbpath //ȥ��.c4rb�ļ���
						+ "/.c4rb -zcvf " + sc4rbpath + "/.c4rb/" + starfilename + " " //���������ļ���
						+ ssavepath //ѹ�����ļ�

						+ "/ --force-local" + " > " + sc4rbpath + "/.c4rb/log").c_str());

		system(("rm -f " + ssavepath + "/_temp.save.list").c_str());

		return 1;

	} else if (s == 2 || s == 3) {
		//��save.list�ļ�

		//2��ʾ�²������ļ�ȫ��ͬ�� 3��ʾ��Ҫ�û�ѡ����Ҫ�������Ҫͬ�����ļ�
		//�����б�
		if (s == 2) {
			//������ļ����ӣ�������ֱ��

		} else if (s == 3) {

		} else {

		}

		//���µĵ����б���

	} else {

	}

	return 1;

}


//����һ��Ŀ¼ �����ļ������������Ŀ¼�Ļ���
int AddSaveList(ofstream *fout_in,string name) {

	int num_file(0);
	string name1;
	_finddata_t file;
	long lf;
	if ((lf = _findfirst(name.c_str(), &file)) == -1l) {
		cout << "���ļ���Ŀ¼�����ڣ�\n";
		return -1;
	} else {
		//���ж�һ�³�ʼĿ¼�Ƿ�Ϊ�ļ�
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



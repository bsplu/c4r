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

int main() {

	//sys(1);
	string name = ".\\*.*";
	traval(name);

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

		//ˢ�������б�
		//���´���save.list
		//AddSaveList(fout,ssavepath);

		//������Ŀ¼���
		system(
				("tar --exclude " + sc4rbpath + "/.c4rb -zcvf " + sc4rbpath
						+ "/.c4rb/" + starfilename + " " + ssavepath
						+ "/ --force-local" + " > " + sc4rbpath + "/.c4rb/log").c_str());

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

int AddSaveList(ofstream fout_in, char spath[]) {

}

//����һ��Ŀ¼
void traval(string name) {

	string name1;
	_finddata_t file;
	long lf;
	if ((lf = _findfirst(name.c_str(), &file)) == -1l) {
		cout << "���ļ���Ŀ¼�����ڣ�\n";
		return;
	} else {

		while (_findnext(lf, &file) == 0) {
			if (strcmp(file.name, "..") == 0)
				continue;

			if (file.attrib == 0) {
				name1 = name;
				cout << (name1.erase(name.length() - 3, 3)) + file.name << endl;

			}
			if ((file.attrib & _A_ARCH) != 0) {
				name1 = name;
				cout << (name1.erase(name.length() - 3, 3)) + file.name << endl;

			}

			if ((file.attrib & _A_SUBDIR) != 0) {

				name1 = name;

				name.insert(name.length() - 3, strcat(file.name, "\\"));

				traval(name);

				name = name1;
			}
		}

	}
	_findclose(lf);
}

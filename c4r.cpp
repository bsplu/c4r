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

int main(){


	sys(1);


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


int AddSaveList(ofstream fout_in,string spath){

}

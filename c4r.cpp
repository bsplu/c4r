/*
 * 首先应该有一个文件列表叫save.list
 * 该文件记录着要同步的文件名
 */
#include<iostream>
#include<stdio.h>
#include <stdlib.h>

using namespace std;

int main(){



	system("touch test.txt");

	return 0;
}

/*save函数
 * 用来记录保存内容
 * 每调用一次save函数就把当下需要同步的文件copy一份出来
 *
 *
 */
int save(void){

	//将要保存的文件名从save.list中读出{

	//}================================


	//检查文件是否存在{

	//存在}============================

	//存在，将文件打包

	//添加到存档文件中
}


/*
 * 该函数主要作用是同步的时候，选择要同步的文件
 * in:s表示同步指令
 * out:函数是否执行成功
 */
int AddSveList(int s){


	//如果要同步所有文件，则不会罗列出还没有同步的文件列表
	if(s == 1){
		//表示全部同步
		//刷新整个列表

		//重新创建save.list

		//将整个目录打包

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


	else{

	}



}

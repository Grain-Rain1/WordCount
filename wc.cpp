#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<cmath>
#include <fstream>
#include <cassert>
using namespace std;
void help(){
	printf("-c字符数 -w单词数 -s句子数\n");
}
long count(string file){//除了空格和换行都算字符 
	char c;
	long number=0;
	ifstream infile; 
    infile.open(file.data());//将文件流对象与文件连接起来 
    assert(infile.is_open());//若失败,则输出错误消息,并终止程序运行 
    while (!infile.eof())
    {
        infile>>c;
        number++;
    }
    if(number>=2) number--;
    infile.close();//关闭文件输入流 
	return number;
}
long word(string file){//除了被-隔开的都算单词 
	char c;
	long number=0;
	int temp=0;
	ifstream infile; 
    infile.open(file.data());//将文件流对象与文件连接起来 
    assert(infile.is_open());//若失败,则输出错误消息,并终止程序运行 
    infile >> noskipws;
    while (!infile.eof())
    {
        infile>>c;
        if(65<=c&&c<=122&&temp==0){
        	temp++;
		}
		if(temp!=0&&c<65&&c!=45){
			number++;
			temp=0;
		}
		if(temp!=0&&c>122){
			number++;
			temp=0;
		}
    }
    if(temp!=0) number++;
    infile.close();//关闭文件输入流 
	return number;
}
long sentence(string file){//被.和;隔开的算句子 
	char c;
	long number=0;
	int temp=0;
	ifstream infile; 
    infile.open(file.data());//将文件流对象与文件连接起来 
    assert(infile.is_open());//若失败,则输出错误消息,并终止程序运行 
    infile >> noskipws;
    while (!infile.eof())
    {
        infile>>c;
        if(65<=c&&c<=122&&temp==0){
        	temp++;
		}
		if(temp!=0&&c==59){
			number++;
			temp=0;
		}
		if(temp!=0&&c==46){
			number++;
			temp=0;
		}
		
    }
    if(temp!=0) number++;
    infile.close();//关闭文件输入流 
	return number;
}
int main(int argc,char *argv[])
{
	string c="-c",w="-w",s="-s";//-c字符数 -w单词数 -s句子数 
	if(argc==2||argc==1){
		help();
	}else{
		
		if(argv[1]==c){
			printf("%ld",count(argv[2]));
		}else if(argv[1]==w){
			printf("%ld",word(argv[2]));
		}else if(argv[1]==s){
			sentence(argv[2]);
		}
	}
	return 0;
}



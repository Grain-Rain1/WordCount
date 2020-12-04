#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<cmath>
#include <fstream>
#include <cassert>
using namespace std;
void help(){
	printf("-c字符数 -w单词数 -s句子数\n-code代码行 -e空白 -n注释行\n");
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
long cod(string file){//空行也算行 
	long number=0;
	ifstream infile; 
    infile.open(file.data());   //将文件流对象与文件连接起来 
    assert(infile.is_open());   //若失败,则输出错误消息,并终止程序运行 

    string s;
    while(getline(infile,s))
    {
        number++;
    }
    infile.close();             //关闭文件输入流 
    return number;
}
long empty(string file){
	long number=0;
	ifstream infile; 
    infile.open(file.data());   //将文件流对象与文件连接起来 
    assert(infile.is_open());   //若失败,则输出错误消息,并终止程序运行 

    string s;
    while(getline(infile,s))
    {
    	if(s==""){
        number++;
		}
    }
    infile.close();             //关闭文件输入流 
    return number;
}
long note(string file){//当一行里有//算有一行注释行 
	char c;
	long number=0;
	int temp=0,q=0;
	ifstream infile; 
    infile.open(file.data());//将文件流对象与文件连接起来 
    assert(infile.is_open());//若失败,则输出错误消息,并终止程序运行 
    infile >> noskipws;
    while (!infile.eof())
    {
        infile>>c;
        if(c=='/'){
        	temp++;
		}else{
			temp=0;
		}
		if(temp==2&&q!=1){
			number++;
			temp=0;
			q=1;
		}
		if (c=='\n'){
			q=0;
		}
    }
    infile.close();//关闭文件输入流 
	return number;
}
int main(int argc,char *argv[])
{
	string c="-c",w="-w",s="-s",code="-code",e="-e",n="-n",h="-h";//-c字符数 -w单词数 -s句子数 -code代码行 -e空白 -n注释行 -h帮助
	if(argc==2||argc==1){
		help();
	}else{
		
		if(argv[1]==c){
			printf("%ld个字符\n",count(argv[2]));
		}else if(argv[1]==w){
			printf("%ld单词\n",word(argv[2]));
		}else if(argv[1]==s){
			printf("%ld句子\n",sentence(argv[2]));
		}else if(argv[1]==code){
			printf("%ld行代码\n",cod(argv[2]));
		}else if(argv[1]==e){
			printf("%ld行空行\n",empty(argv[2]));
		}else if(argv[1]==n){
			printf("%ld行注释行\n",note(argv[2]));
		}
	}
	return 0;
}



#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<cmath>
#include <fstream>
#include <cassert>
using namespace std;
void help(){
	printf("-c�ַ��� -w������ -s������\n");
}
long count(string file){//���˿ո�ͻ��ж����ַ� 
	char c;
	long number=0;
	ifstream infile; 
    infile.open(file.data());//���ļ����������ļ��������� 
    assert(infile.is_open());//��ʧ��,�����������Ϣ,����ֹ�������� 
    while (!infile.eof())
    {
        infile>>c;
        number++;
    }
    if(number>=2) number--;
    infile.close();//�ر��ļ������� 
	return number;
}
long word(string file){//���˱�-�����Ķ��㵥�� 
	char c;
	long number=0;
	int temp=0;
	ifstream infile; 
    infile.open(file.data());//���ļ����������ļ��������� 
    assert(infile.is_open());//��ʧ��,�����������Ϣ,����ֹ�������� 
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
    infile.close();//�ر��ļ������� 
	return number;
}
long sentence(string file){//��.��;����������� 
	char c;
	long number=0;
	int temp=0;
	ifstream infile; 
    infile.open(file.data());//���ļ����������ļ��������� 
    assert(infile.is_open());//��ʧ��,�����������Ϣ,����ֹ�������� 
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
    infile.close();//�ر��ļ������� 
	return number;
}
int main(int argc,char *argv[])
{
	string c="-c",w="-w",s="-s";//-c�ַ��� -w������ -s������ 
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



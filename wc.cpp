#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<cmath>
#include <fstream>
#include <cassert>
using namespace std;
void help(){
	printf("-c�ַ��� -w������ -s������\n-code������ -e�հ� -nע����\n");
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
long cod(string file){//����Ҳ���� 
	long number=0;
	ifstream infile; 
    infile.open(file.data());   //���ļ����������ļ��������� 
    assert(infile.is_open());   //��ʧ��,�����������Ϣ,����ֹ�������� 

    string s;
    while(getline(infile,s))
    {
        number++;
    }
    infile.close();             //�ر��ļ������� 
    return number;
}
long empty(string file){
	long number=0;
	ifstream infile; 
    infile.open(file.data());   //���ļ����������ļ��������� 
    assert(infile.is_open());   //��ʧ��,�����������Ϣ,����ֹ�������� 

    string s;
    while(getline(infile,s))
    {
    	if(s==""){
        number++;
		}
    }
    infile.close();             //�ر��ļ������� 
    return number;
}
long note(string file){//��һ������//����һ��ע���� 
	char c;
	long number=0;
	int temp=0,q=0;
	ifstream infile; 
    infile.open(file.data());//���ļ����������ļ��������� 
    assert(infile.is_open());//��ʧ��,�����������Ϣ,����ֹ�������� 
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
    infile.close();//�ر��ļ������� 
	return number;
}
int main(int argc,char *argv[])
{
	string c="-c",w="-w",s="-s",code="-code",e="-e",n="-n",h="-h";//-c�ַ��� -w������ -s������ -code������ -e�հ� -nע���� -h����
	if(argc==2||argc==1){
		help();
	}else{
		
		if(argv[1]==c){
			printf("%ld���ַ�\n",count(argv[2]));
		}else if(argv[1]==w){
			printf("%ld����\n",word(argv[2]));
		}else if(argv[1]==s){
			printf("%ld����\n",sentence(argv[2]));
		}else if(argv[1]==code){
			printf("%ld�д���\n",cod(argv[2]));
		}else if(argv[1]==e){
			printf("%ld�п���\n",empty(argv[2]));
		}else if(argv[1]==n){
			printf("%ld��ע����\n",note(argv[2]));
		}
	}
	return 0;
}



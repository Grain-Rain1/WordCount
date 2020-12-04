WC项目要求
----------
实现一个命令行文本计数统计程序。能正确统计导入的纯英文txt文本中的字符数，单词数，句子数。

具体命令行界面要求如下:

命令模式： wc.exe [参数] [文件名]

例：
wc.exe -c file.txt 统计字符数
wc.exe -w file.txt 统计单词数
wc.exe -s file.txt 统计句子数

拓展功能：
-code 统计代码行
-e    统计空白行
-n    统计注释行
并提供相应命令接口

思路及代码说明
----------
### 1. 主函数
```
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
```
#### 思路：输入指令分成两组，根据第一组的指令对第二组的指令文件名执行相应的操作。
### 2. 基本功能
#### -c统计字符数
```
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
```

#### -w统计单词数
```
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
```

#### -s统计句子数
```
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
```
### 3. 拓展功能
#### -code统计代码行
```
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
```

#### -e统计空白行
```
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
```

#### -n统计注释行
```
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
```
测试结果
----------
（弹出命令行界面方法：win+r，cmd，回车）
### txt文件
#### Dogs.txt
![Image](https://github.com/Grain-Rain1/WordCount/blob/main/1.png)
#### cx.txt
![Image](https://github.com/Grain-Rain1/WordCount/blob/main/2.png)
### 运行结果
#### 统计字符数，单词数，句子数运行结果
![Image](https://github.com/Grain-Rain1/WordCount/blob/main/3.png)
#### 统计代码行，空白行，注释行运行结果
![Image](https://github.com/Grain-Rain1/WordCount/blob/main/4.png)







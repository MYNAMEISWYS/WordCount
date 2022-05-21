#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 10240

int NumberOfWord(char* file_name);//单词数量
int NumberOfChar(char* file_name);//字符数量
 
FILE* fp;//文件指针 
char buffer[MAX];//用于存储字符的数组 

int NumberOfWord(char* file_name){

	int line_word=0;//一行中的单词数
	int total_word=0;//总单词数 
	
	fp=fopen(file_name,"r");
	if(fp==NULL){
		exit(0);
	}
	else{
		while(fgets(buffer,MAX,fp)!=NULL){
			line_word=1;//第一个空格前有一个单词 
			for(int i=0;i<strlen(buffer)-1;i++){
				if(buffer[i]==' '||buffer[i]==','){
					line_word++;
				}
			} 
			total_word+=line_word;
		}
	}
	fclose(fp);

	return total_word;
}
int NumberOfChar(char* file_name){
	
	int total_char=0;//总字符数
	int line_char=0;//一行中的字符数 
	 
	fp=fopen(file_name,"r");
	if(fp==NULL){
		exit(0);
	}
	else{
		while(fgets(buffer,MAX,fp)!=NULL){
			line_char=1;//每一行都有换行符 
			for(int i=0;i<strlen(buffer)-1;i++){
				line_char++;
			}
			total_char+=line_char; 
		}
		total_char-=1;//最后一行没有换行符 
	}
	fclose(fp);
	
	return total_char;
}
int main(){
	char parameter[2];//控制参数 
	char input_file_name[128];//文件名 
	scanf("%s%s",parameter,input_file_name);
	if(parameter[1]=='w'){
		//统计单词数 
		printf("%d",NumberOfWord(input_file_name));
	}
	else if(parameter[1]=='c'){
		//统计字符数 
		printf("%d",NumberOfChar(input_file_name));
	}
	else{
		exit(0);
	}
	return 0;	
}

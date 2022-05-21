#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 10240

int NumberOfWord(char* file_name);//��������
int NumberOfChar(char* file_name);//�ַ�����
 
FILE* fp;//�ļ�ָ�� 
char buffer[MAX];//���ڴ洢�ַ������� 

int NumberOfWord(char* file_name){

	int line_word=0;//һ���еĵ�����
	int total_word=0;//�ܵ����� 
	
	fp=fopen(file_name,"r");
	if(fp==NULL){
		exit(0);
	}
	else{
		while(fgets(buffer,MAX,fp)!=NULL){
			line_word=1;//��һ���ո�ǰ��һ������ 
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
	
	int total_char=0;//���ַ���
	int line_char=0;//һ���е��ַ��� 
	 
	fp=fopen(file_name,"r");
	if(fp==NULL){
		exit(0);
	}
	else{
		while(fgets(buffer,MAX,fp)!=NULL){
			line_char=1;//ÿһ�ж��л��з� 
			for(int i=0;i<strlen(buffer)-1;i++){
				line_char++;
			}
			total_char+=line_char; 
		}
		total_char-=1;//���һ��û�л��з� 
	}
	fclose(fp);
	
	return total_char;
}
int main(){
	char parameter[2];//���Ʋ��� 
	char input_file_name[128];//�ļ��� 
	scanf("%s%s",parameter,input_file_name);
	if(parameter[1]=='w'){
		//ͳ�Ƶ����� 
		printf("%d",NumberOfWord(input_file_name));
	}
	else if(parameter[1]=='c'){
		//ͳ���ַ��� 
		printf("%d",NumberOfChar(input_file_name));
	}
	else{
		exit(0);
	}
	return 0;	
}

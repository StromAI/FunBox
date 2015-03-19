/*
 * scannermain.cpp
 *
 *  Created on: 2014年11月10日
 *      Author: zw531129
 */

#include "scanner.h"

void main(int argc, char *argv[]){
	Token token;
	if(argc < 2){
		printf("请输入源文件! \n");
		return ;
	}
	if(!InitScanner(argv[1])){
		printf("源文件打开错误！ \n");
	}
	printf("记号类别       字符串       常数值       函数指针 \n");
	printf("______________________________________________\n");
	while(1){
		token = GetToken();
		if(token.type != NONTOKEN)
			printf("%4d, %12s, %12f, %12x \n", token.type, token.lexeme, token.value, token.FuncPtr);
		else
			break;
	}
	printf("______________________________________________\n");
	CloseScanner();
}



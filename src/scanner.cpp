/*
 * scanner.cpp
 *
 *  Created on: 2014年11月10日
 *      Author: zw531129
 */

#include "scanner.h"

#define TOKEN_LEN 100			//记号最大长度
unsigned int LineNo;			//跟踪源文件行号
static FILE *InFile;			//记号字符缓冲
static char TokenBuffer[TOKEN_LEN];

/**
 * 初始化词法分析器
 */
extern int InitScanner(const char *FileName){
	LineNo = 1;
	InFile = fopen(FileName, "r");
	if (InFile != NULL)
		return 1;
	else
		return 0;
}

/**
 * 关闭词法分析器
 */
extern void CloseScanner(void){
	if(InFile != NULL)
		fclose(InFile);
}

/**
 * 从输入源程序读入一个字符
 */
static char GetChar(void){
	int Char = getc(InFile);
	return toupper(Char);
}

/**
 * 把与读的字符退回到输入源程序中
 */
static void BackChar(char Char){
	if(Char != EOF)
		ungetc(Char, InFile);
}

/**
 * 加入字符到记号缓冲区
 */
static void AddCharTokenString(char Char){
	int TokenLength = strlen(TokenBuffer);
	if(TokenLength + 1 >= sizeof(TokenBuffer))
		return ;
	TokenBuffer[TokenLength] = Char;
	TokenBuffer[TokenLength + 1] = '\0';
}

/**
 * 清空记号缓冲区
 */

static void EmptyTokenString(){
	memset(TokenBuffer, 0, TOKEN_LEN);
}

/**
 * 判断所给的字符串是否在符号表中
 */
static Token JudgeKeyToken(const char *IDString){
	int loop;
	for(loop = 0; loop < sizeof(TokenTab) / sizeof(TokenTab[0]); loop++){
		if(strcmp(TokenTab[loop].lexeme, IDString) == 0)
			return TokenTab[loop];
	}

	Token errortoken;

	memset(&errortoken, 0, sizeof(Token));
	errortoken.type = ERRTOKEN;
	return errortoken;
}

/**
 * 获取一个记号
 */
extern Token GetToken(void){
	Token token;
	int Char;

	memset(&token, 0, sizeof(Token));
	EmptyTokenString();
	token.lexeme = TokenBuffer;
	for(;;){	//过滤源程序中的空格、TAB、回车等，遇到文件结束符返回空记号
		Char = GetChar();
		if(Char == EOF){
			token.type = NONTOKEN;
			return token;
		}

		if(Char == '\n')
			LineNo++;
		if(!isspace(Char))
			break;
	}

	AddCharTokenString(Char);	//若不是空格、TAB、回车、文件结束符等，则先加入到记号的字符缓冲区中

	if(isalpha(Char)){
		for(;;){
			Char = GetChar();
			if(isalnum(Char))
				AddCharTokenString(Char);
			else
				break;
		}
		BackChar(Char);
		token = JudgeKeyToken(TokenBuffer);
		token.lexeme = TokenBuffer;
		return token;
	}
	else if(isdigit(Char)){
		for(;;){
			Char = GetChar();
			if(isdigit(Char))
				AddCharTokenString(Char);
			else
				break;
		}
		if(Char == ','){
			AddCharTokenString(Char);
			for(;;){
				Char = GetChar();
				if(isdigit(Char))
					AddCharTokenString(Char);
				else
					break;
			}
		}
		BackChar(Char);
		token.type = CONST_ID;
		token.value = atof(TokenBuffer);
		return token;
	}
	else{
		switch (Char) {
			case ';' : token.type = SEMICO;
				break;
			case '(' : token.type = L_BRACKET;
				break;
			case ')' : token.type = R_BRACKET;
				break;
			case ',' : token.type = COMMA;
				break;
			case '+' : token.type = PLUS;
				break;
			case '-' :
				Char = GetChar();
				if(Char == '-'){
					while(Char != '\n' && Char != EOF)
						Char = GetChar();
					BackChar(Char);
					return GetToken();
				}else{
					BackChar(Char);
					token.type = MINUS;
					break;
				}
			case '/' :
				Char = GetChar();
				if(Char == '/'){
					while(Char != '\n' && Char != EOF)
						Char = GetChar();
					BackChar(Char);
					return GetToken();
				}else{
					BackChar(Char);
					token.type = DIV;
					break;
				}
			case '*' :
							Char = GetChar();
							if(Char == '*'){
								token.type = POWER;
								break;
							}else{
								BackChar(Char);
								token.type = MUL;
								break;
							}
			default : token.type = ERRTOKEN;
				break;
		}
	}
	return token;
}











































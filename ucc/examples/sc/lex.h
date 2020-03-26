#ifndef	LEX_H
#define	LEX_H
//
#define	MAX_ID_LEN	15




//
typedef	union{
	char name[MAX_ID_LEN+1];
	int  numVal;

}Value;

// gcc -E lex.h 执行, 查看结果
/**
 * typedef enum {
 * TK_NA,
 * TK_ADD,
 * TK_SUB,
 * TK_MUL,
 * TK_DIV,
 * TK_ID,
 * TK_COMM
 * ....
 * } TokenKind;
 */
typedef enum {
	#define	TOKEN(kind,name)	kind,
	#include "tokens.txt"
	#undef	TOKEN
}TokenKind;
//
typedef struct{
	TokenKind kind;
	Value value;
}Token;


typedef	char (* NEXT_CHAR_FUNC)(void);

#define	MAX_ID_LEN	15
#define	EOF_CH		((char)0xFF)


extern Token curToken;

// 获取下一个 token, token 会被消耗掉
#define	NEXT_TOKEN	do{curToken = GetToken();}while(0)
Token GetToken(void);
const char * GetTokenName(TokenKind tk);
void InitLexer(NEXT_CHAR_FUNC next);
#endif

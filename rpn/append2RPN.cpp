/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2019. All rights reserved.
 ******************************************************************************************/

/*DSA*/#include "rpn.h"

 //将操作数接至RPN末尾
void append ( char*& rpn, float opnd ) 
{ 
   char buf[64];
   if ( opnd != ( float ) ( int ) opnd ) 
	   sprintf ( buf, "%.2f \0", opnd ); //浮点格式，或
   else                         
	   sprintf ( buf, "%d \0", ( int ) opnd ); //整数格式
   rpn = ( char* ) realloc ( rpn, sizeof ( char ) * ( strlen( rpn ) + strlen ( buf ) + 1 ) ); //扩展空间
   strcat ( rpn, buf ); //RPN加长
}

//将运算符接至RPN末尾
void append ( char*& rpn, char optr ) 
{ 
   int n = strlen ( rpn ); //RPN当前长度（以'\0'结尾，长度n + 1）
   rpn = ( char* ) realloc ( rpn, sizeof ( char ) * ( n + 3 ) ); //扩展空间
   sprintf ( rpn + n, "%c ", optr ); rpn[n + 2] = '\0'; //接入指定的运算符
}
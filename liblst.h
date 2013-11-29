/*
 *  liblst.h
 *
 *  framework library
 *
 *  Author: Andrey Zmushko
 */

#ifndef __LIBLST_H
#define __LIBLST_H

#include <stdlib.h> // size_t definition

#ifdef __cplusplus

extern "C" {

#endif

ssize_t lstPush(char*** lst, const char* str);
size_t	lstSize(char** lst);
size_t	lstLength(char** lst);
void	lstFree(char** lst);
char**	lstSplitStr(const char splitter, const char* s);
char**	lstEgrep(char* const* lst, const char* regexp);
char**	lstReadDir(const char* path);

char*	ptReplaceStr(const char* string, const char* search, const char* replace);
int	replaceStrFormat(char** string, const char* search, const char* format, ...);
int	chopStr(char* s);
int	trimStr(char* s);
char*	ptCutStr(const char* string, const char* begin, const char* end);

char*	ptGetFileContent(const int fn);
int	getFileContentFormat(char** content, const char* format, ...);
int	writeToFileFormat(const int fd, const char* format, ...);
int	getShellContentFormat(char** content, const char* format, ...);
int	executeShellFormat(const char* format, ...);
int 	isDirFormat(const char* format, ...);

ssize_t	readFileRow(char** data, const int fd);
char*	ptGetFileRowFormat(const char* format, ...);

#ifdef __cplusplus

}

#endif

#endif

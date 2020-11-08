#ifndef TEXT_H_INCLUDED
#define TEXT_H_INCLUDED

#include <string.h>
typedef struct fileString fileString;
//! @file

struct fileString
{
    char* p;
    size_t length;
};

enum file_codes {
                    FILE_OK = 0,
                    CANNOT_OPEN_FILE,
                    NO_MEMORY,
                    CANNOT_READ_FILE
                };

/*!
    Input from text file
    @param[in] name the name of file
    @param[out] buffer writing buffer pointer

    @return execute code
    @version 1.0
    @authors Zvezdin Nikita
    @warning Use only ANSI txt file
*/
int input(const char* name, char** buffer);

/*!
    Output for data of string
    @param[in] name the name of file
    @param[in] text fileString data pointer
    @param[in] count number of strings

    @return execute code
    @version 1.0
    @authors Zvezdin Nikita
    @warning Use only ANSI txt file
*/
int output(const char* name, fileString* text, int count);

/*!
    Output for c-strings
    @param[in] name the name of file
    @param[in] string c-string pointer

    @return execute code
    @version 1.0
    @authors Zvezdin Nikita
    @warning Use only ANSI txt file
*/
int nativeOutput(const char* name, const char* str);

/*!
    Clear the file
    @param[in] name the name of file

    @return execute code
    @version 1.0
    @authors Zvezdin Nikita
    @warning Use only ANSI txt file
*/
int clearFile(const char* name);

/*!
    Parse the buffer to string data
    @param[out] buffer pointer to buffer
    @param[out] count number of strings
    @param[in] symbol separator

    @return parsed buffer (fileString data)
    @version 1.0
    @authors Zvezdin Nikita
*/
fileString* bufferParse(char* buffer, int* count, char symbol);

#endif // TEXT_H_INCLUDED

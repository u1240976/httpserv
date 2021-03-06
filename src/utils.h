/** 
 * @file utils.h
 * @brief helpers and wrappers of standard library and POSIX api.
 */

#ifndef __UTILS_H__
#define __UTILS_H__

#include <vector>
#include <string>

/* string helper functions */

std::string fetch_word(std::string& parsed_str, const char* split_chars);

const char WHITESPACE[] = " \t\r\n\v\f";

/** @brief remove leading whitespaces of string */
std::string lstrip(const std::string& str);
/** @brief remove trailing whitespaces of string */
std::string rstrip(const std::string& str);
/** @brief remove leading and trailing whitespaces of string */
std::string strip(const std::string& str);

/* IO wrapper functions */

void perror_and_exit(const char* str);
/** @brief print format string to stderr and exit */
void error_printf_and_exit(const char* format ... );

/** @brief write system call wrapper, it must write all data in buf to fd */
int write_all(int fd, const void* buf, size_t count);

/** @brief helper functions between std::string and POSIX api */
namespace str{
    /** @brief wrapper of POSIX syscall read, return C++ std::string instead of memory buffer */
    std::string read(int fd, int count, bool is_nonblocking);
}

/* OS(e.g. POSIX api) wrapper functions */

/** @brief OS(e.g. POSIX api) wrapper functions */
namespace os{
    /** @brief return the list of name of files in directory. sorted. error if return empty vector */
    std::vector<std::string> list_dir(std::string directory_path);
    /** @brief return true if path is a directory */
    bool is_dir(std::string path);
} /* os */ 

#endif /* end of include guard: __UTILS_H__ */

#ifndef GET_NUM_H
#define GET_NUM_H

#define GN_NONNEG       01      /* Value must be >= 0 */
#define GN_GT_0         02      /* Value must be > 0 */

/* By default, integers are decimal */
#define GN_ANY_BASE   0100      /* Can use any base - like strtol(3) */
#define GN_BASE_8     0200      /* Value is expressed in octal */
#define GN_BASE_16    0400      /* Value is expressed in hexadecimal */

int getInt(const char* arg,int flags,const char* name);
int getLong(const char* arg,int flags,const char* name); /* long  命令行参数字符串 标志位或者 名字*/

#endif // GET_NUM_H
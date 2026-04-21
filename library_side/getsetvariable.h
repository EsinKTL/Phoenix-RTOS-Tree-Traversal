#ifndef _SYS_GETSETVARIABLE_H_
#define _SYS_GETSETVARIABLE_H_

extern void setVariable(int);
extern int getVariable(void);

/* Senin Task 1 fonksiyonun: PID ve Yol Uzunluğu döndürecek */
/* Not: C'de bir fonksiyondan iki değer döndürmek için pointer kullanırız */
extern int getLongestAncestorPath(int skip_pid, int *path_len);

#endif



#ifdef DEBUG
#ifndef DEBUG_H
#define DEBUG_H
#define deprint printf
#endif
#else
#ifndef DEBUG_H
#define DEBUG_H
#define deprint ;
#endif
#endif
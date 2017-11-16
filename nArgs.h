#define countARGS_SEQ(_1, _2, _3, _4, _5, _6, _7,_8, _9,_10,_11,_12,_13,_14,_15,N,...) N
#define countARGS(...) 	countARGS_SEQ(__VA_ARGS__, 15, 14, 13, 12, 11, 10, 9,  8,  7,  6, 5, 4, 3, 2, 1       )
#define nArgs(...) _nArgs(countARGS(__VA_ARGS__))
static int _nArgs(unsigned int n){return n;}  

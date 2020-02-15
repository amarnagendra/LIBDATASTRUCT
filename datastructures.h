#ifndef __datastructures
#define __datastructures
typedef char DT_INT8;
typedef short DT_INT16;
typedef int DT_INT32;
typedef unsigned char DT_UINT8;
typedef unsigned short DT_UINT16;
typedef unsigned int DT_UINT32;
typedef float DT_FLOAT;
typedef double DT_DOUBLE;
typedef void DT_VOID;
typedef size_t DT_HANDLE;

typedef enum
{
    DT_FAILURE,
    DT_SUCCESS
}DT_STATUS;

typedef enum
{
    DT_FALSE,
    DT_TRUE
}DT_BOOL;
#endif

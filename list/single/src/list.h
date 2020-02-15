#ifndef __list
#define __list
#include "datastructures.h"
#include "list_int.h"

/**
 * Structure for each node
 * Next          Points to next member
 * Prev          Points to prev member
 * Data          Generic data pointer
 * Size          size of data saved
*/
typedef struct node_t node;
struct node_t
{
    node *psNext;
    node *psPrev;
    DT_VOID *pvData;
    DT_INT32 iSize;
};

typedef struct
{
    node *psHead;
    node *psTail;
    DT_UINT32 uiNumOfEle;
    fpdatastruct_list_print fpprint;
}list;
#endif

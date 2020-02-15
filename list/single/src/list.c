#include <stdio.h>
#include "list.h"
#include "list_int.h"
#include "datastructures.h"
#include <string.h>
#include <stdlib.h>

static DT_STATUS datastruct_list_createnode(node **ppsNode)
{
    *ppsNode = malloc(sizeof(node));
    node *psNode = *ppsNode;
    psNode->psNext = NULL;
    psNode->psPrev = NULL;
    psNode->iSize = 0;
}

DT_STATUS datastruct_list_setfp(DT_HANDLE uiHandle, fpdatastruct_list_print fpprint)
{
    list *psList = (list *)uiHandle;
    psList->fpprint = fpprint;
}

DT_STATUS datastruct_list_init(DT_HANDLE *puiHandle)
{
    DT_INT32 uiRet = DT_SUCCESS;
    list *psList = NULL;

    *puiHandle = (DT_HANDLE)malloc(sizeof(list));
    psList = (list *)(*puiHandle);
    if (NULL == psList)
    {
        uiRet = DT_FAILURE;
        goto EXIT;
    }
    psList->psHead = NULL;
    psList->psTail = NULL;
    psList->uiNumOfEle = 0;
    psList->fpprint = NULL;
EXIT:
    return uiRet;
}

DT_STATUS datastruct_list_append(DT_HANDLE uiHandle, DT_VOID *pvData, DT_UINT32 uiSize, DT_BOOL eCopy)
{
    DT_INT32 uiRet = DT_SUCCESS;
    list *psList = (list *)uiHandle;
    node *psNode = psList->psHead;

    if (psNode == NULL)
    {
        datastruct_list_createnode(&psNode);
        psList->psHead = psNode;
        goto COPY_LOGIC;
    }

    while (psNode->psNext != NULL)
    {
        psNode = psNode->psNext;
    }
    datastruct_list_createnode(&psNode->psNext);
    psNode->psNext->psPrev = psNode;
    psNode = psNode->psNext;
COPY_LOGIC:
    if (DT_TRUE == eCopy)
    {
        psNode->pvData = malloc(uiSize);
        memcpy(psNode->pvData, pvData, uiSize);
    }
    else
    {
        psNode->pvData = pvData;
    }
    psNode->iSize = uiSize;
    psNode->psNext = NULL;
}

DT_VOID datastruct_list_print(DT_HANDLE uiHandle)
{
    list *psList = (list *)uiHandle;
    node *psNode = psList->psHead;

    while (psNode != NULL)
    {
       psList->fpprint(psNode->pvData); 
       psNode = psNode->psNext;
    }
}

DT_STATUS datastruct_list_inshead(DT_HANDLE uiHandle, DT_VOID *pvData, DT_INT32 iSize, DT_BOOL eCopy)
{
    list *psList = (list *)uiHandle;
    node *psNode = NULL;
    DT_INT32 uiRet = DT_SUCCESS;

    datastruct_list_createnode(&psNode);
    if (psList->psHead == NULL)
    {
        psList->psHead = psNode;
    }
    else
    {
        psNode->psNext = psList->psHead;
        psList->psHead = psNode;
    }
    if (DT_TRUE == eCopy)
    {
        psNode->pvData = malloc(iSize);
        memcpy(psNode->pvData, pvData, iSize);
    }
    else
    {
        psNode->pvData = pvData;
    }
    psNode->iSize = iSize;
    return  uiRet;

}

DT_STATUS datastruct_list_insat(DT_HANDLE uiHandle, DT_VOID *pvData, DT_INT32 iSize, DT_BOOL eCopy, DT_UINT32 uiPos)
{
    list *psList = (list *)uiHandle;
    node *psNode = NULL;
    node *psTmpNode = psList->psHead;
    DT_UINT32 uiPosCnt = 0;
    DT_INT32 uiRet = DT_SUCCESS;

    if (uiPos == 0)
    {
        datastruct_list_inshead(uiHandle, pvData, iSize, eCopy);
        goto EXIT;
    }
    while (NULL != psTmpNode)
    {
        if (uiPosCnt == uiPos - 1)
        {
            break;
        }
        psTmpNode = psTmpNode->psNext;
        uiPosCnt++;
    }
    if (psTmpNode == NULL)
        goto EXIT;
    datastruct_list_createnode(&psNode);
    if (DT_TRUE == eCopy)
    {
        psNode->pvData = malloc(iSize);
        memcpy(psNode->pvData, pvData, iSize);
    }
    else
    {
        psNode->pvData = pvData;
    }
    psNode->iSize = iSize;
    psNode->psNext = psTmpNode->psNext;
    psTmpNode->psNext = psNode;
EXIT:
    return uiRet;
}

DT_STATUS datastruct_list_delhead(DT_HANDLE uiHandle)
{
    list *psList = (list *)uiHandle;
    node *psNode = psList->psHead;

    psList->psHead = psNode->psNext;
    free(psNode);
}

DT_STATUS datastruct_list_delat(DT_HANDLE uiHandle, DT_UINT32 uiPos)
{
    list *psList = (list *)uiHandle;
    node *psNode = NULL;
    node *psTmpNode = psList->psHead;
    DT_UINT32 uiPosCnt = 0;
    DT_INT32 uiRet = DT_SUCCESS;

    if (uiPos == 0)
    {
        datastruct_list_delhead(uiHandle);
        goto EXIT;
    }
    while (NULL != psTmpNode)
    {
        if (uiPosCnt == uiPos - 1)
        {
            break;
        }
        psTmpNode = psTmpNode->psNext;
        uiPosCnt++;
    }
    if (NULL == psTmpNode)
    {
        goto EXIT;
    }
    psNode = psTmpNode->psNext;
    psTmpNode->psNext = psTmpNode->psNext->psNext;
    free(psNode);
EXIT:
    return uiRet;    
}

DT_STATUS datastruct_list_deltail(DT_HANDLE uiHandle)
{
    list *psList = (list *)uiHandle;
    node *psNode = psList->psHead;
    node *psPrevNode = psNode;
    DT_INT32 uiRet = DT_SUCCESS;

    if (psNode == NULL)
    {
        goto EXIT;
    }
    else if (psNode->psNext == NULL)
    {
        free(psNode);
        psList->psHead = NULL;
        goto EXIT;
    }
    while (psNode->psNext != NULL)
    {
        psPrevNode = psNode;
        psNode = psNode->psNext;
    }
    psPrevNode->psNext = NULL;
    free(psNode);
EXIT:
    return  uiRet;
}

DT_STATUS datastruct_list_gethead(DT_HANDLE uiHandle, DT_VOID **pvData, DT_UINT32 *uiSize)
{
    list *psList = (list *)uiHandle;
    node *psNode = psList->psHead;

    *pvData = psNode->pvData;
    *uiSize = psNode->iSize;
}

DT_STATUS datastruct_list_gettail(DT_HANDLE uiHandle, DT_VOID **pvData, DT_UINT32 *uiSize)
{
    list *psList = (list *)uiHandle;
    node *psNode = psList->psHead;

    while (psNode->psNext != NULL)
    {
        psNode = psNode->psNext;
    }
    *pvData = psNode->pvData;
    *uiSize = psNode->iSize;
}
DT_STATUS datastruct_list_getat(DT_HANDLE uiHandle, DT_VOID **pvData, DT_UINT32 *uiSize, DT_UINT32 uiPos)
{
    list *psList = (list *)uiHandle;
    node *psNode = psList->psHead;
    DT_UINT32 uiPosCnt = 0;
    DT_INT32 uiRet = DT_SUCCESS;

    while (NULL != psNode)
    {
        if (uiPosCnt == uiPos)
        {
            break;
        }
        psNode = psNode->psNext;
        uiPosCnt++;
    }
    *pvData = psNode->pvData;
    *uiSize = psNode->iSize;
}

DT_STATUS datastruct_list_deinit(DT_HANDLE uiHandle)
{
    list *psList = (list *)uiHandle;
    node *psNode = psList->psHead;
    node *psTmpNode = NULL;
    DT_INT32 uiRet = DT_SUCCESS;

    if (psNode == NULL)
    {
        goto EXIT;
    }
    while(psNode->psNext != NULL)
    {
        psTmpNode = psNode;
        psNode = psNode->psNext;
        free(psTmpNode);
    }
    free(psNode);
    free(psList);
EXIT:
    return uiRet;
}

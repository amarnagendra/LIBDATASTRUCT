#ifndef __list_int
#define __list_int
#include "datastructures.h"

typedef void (*fpdatastruct_list_print)(void *data);
DT_STATUS datastruct_list_init(DT_HANDLE *puiHandle);
DT_STATUS datastruct_list_append(DT_HANDLE uiHandle, DT_VOID *pvData, DT_UINT32 uiSize, DT_BOOL eCopy);
DT_STATUS datastruct_list_inshead(DT_HANDLE uiHandle, DT_VOID *pvData, DT_INT32 iSize, DT_BOOL eCopy);
DT_STATUS datastruct_list_insat(DT_HANDLE uiHandle, DT_VOID *pvData, DT_INT32 iSize, DT_BOOL eCopy, DT_UINT32 uiPos);
DT_STATUS datastruct_list_delhead(DT_HANDLE uiHandle);
DT_STATUS datastruct_list_delat(DT_HANDLE uiHandle, DT_UINT32 uiPos);
DT_STATUS datastruct_list_deltail(DT_HANDLE uiHandle);
DT_STATUS datastruct_list_gethead(DT_HANDLE uiHandle, DT_VOID **pvData, DT_UINT32 *uiSize);
DT_STATUS datastruct_list_gettail(DT_HANDLE uiHandle, DT_VOID **pvData, DT_UINT32 *uiSize);
DT_STATUS datastruct_list_getat(DT_HANDLE uiHandle, DT_VOID **pvData, DT_UINT32 *uiSize, DT_UINT32 uiPos);
DT_STATUS datastruct_list_deinit(DT_HANDLE uiHandle);
DT_VOID datastruct_list_print(DT_HANDLE uiHandle);
DT_STATUS datastruct_list_setfp(DT_HANDLE uiHandle, fpdatastruct_list_print fpprint);
#endif

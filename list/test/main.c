#include "stdio.h"
#include "datastructures.h"
#include "list_int.h"
void printfunction(void *data);
int main()
{
    DT_HANDLE uiHandle = 0;
    DT_STATUS uiStatus = DT_FAILURE;

    uiStatus = datastruct_list_init(&uiHandle);
    if (uiStatus == DT_FAILURE)
    {
        printf("Init Failed\n");
        goto EXIT;
    }
    datastruct_list_setfp(uiHandle, printfunction);
    int data = 3;
    datastruct_list_append(uiHandle, &data, sizeof(data), DT_TRUE);
    data = 2;
    datastruct_list_append(uiHandle, &data, sizeof(data), DT_TRUE);
    data = 1;
    datastruct_list_append(uiHandle, &data, sizeof(data), DT_TRUE);
    data = 1;
    datastruct_list_append(uiHandle, &data, sizeof(data), DT_TRUE);
    data = 1;
    datastruct_list_append(uiHandle, &data, sizeof(data), DT_TRUE);
    data = 7;
    datastruct_list_inshead(uiHandle, &data, sizeof(data), DT_TRUE);
    data = 23;
    datastruct_list_insat(uiHandle, &data, sizeof(data), DT_TRUE, 8);
    //datastruct_list_delhead(uiHandle);
    datastruct_list_delat(uiHandle, 8);
    datastruct_list_deltail(uiHandle);
    void *pvdata = NULL;
    DT_INT32 uiSize = 0;
    datastruct_list_gethead(uiHandle, &pvdata, &uiSize);
    printf("Data %d size %d\n", *(int *)pvdata, uiSize);
    datastruct_list_gettail(uiHandle, &pvdata, &uiSize);
    printf("Data %d size %d\n", *(int *)pvdata, uiSize);
    datastruct_list_getat(uiHandle, &pvdata, &uiSize, 0);
    printf("Data %d size %d\n", *(int *)pvdata, uiSize);
    datastruct_list_print(uiHandle);
    datastruct_list_deinit(uiHandle);
EXIT:
    return uiStatus;
}
void printfunction(void *data)
{
    printf("Element %d \n",*(int *)data);
}

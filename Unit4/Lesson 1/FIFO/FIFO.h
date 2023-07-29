#ifndef _FIFO_H_
#define _FIFO_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define element_type uint8_t
#define len 5
#define WIDTH1 5



typedef struct {
uint8_t counter;
uint8_t lenght;
uint8_t* base;
uint8_t* head;
uint8_t* tail;

}FiFO_Buf_t;

typedef enum {
fifo_no_error,
fifo_full,
fifo_empty,
fifo_null

}fifo_status;


fifo_status fifo_ENqueue(FiFO_Buf_t* fifo_buf,element_type* item);
fifo_status fifo_DEqueue(FiFO_Buf_t* fifo_buf, element_type *item);
fifo_status fifo_init(FiFO_Buf_t* fifo_buf, element_type* buf, uint8_t lenght);
fifo_status fifo_FULL(FiFO_Buf_t* fifo_buf);
void fifo_Print(FiFO_Buf_t* fifo_buf);















#endif // _FIFO_H_

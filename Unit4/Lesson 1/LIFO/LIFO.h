#ifndef _LIFO_H_
#define _LIFO_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


#define len 5

typedef struct {
uint8_t counter;
uint8_t lenght;
uint8_t* base;
uint8_t* head;

}lifo_buf_t;

typedef enum {
lifo_no_error,
lifo_full,
lifo_empty,
lifo_null

}lifo_status;


lifo_status lifo_add_item(lifo_buf_t* buf,uint8_t item);
lifo_status lifo_get_item(lifo_buf_t* buf, uint8_t *item);
lifo_status lifo_init(lifo_buf_t* lifo_buf, uint8_t* buf, uint8_t lenght);
















#endif // _LIFO_H_

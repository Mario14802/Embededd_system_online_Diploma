#include "FIFO.h"






fifo_status fifo_ENqueue(FiFO_Buf_t* fifo_buf, element_type* item)
{
	if (!fifo_buf->head || !fifo_buf->base || !fifo_buf->tail)
		return fifo_null;

	if ((fifo_buf->head) == (fifo_buf->lenght))
	{
		printf("FIFO ENQUEUE FAILED");
		return fifo_full;
		

	}

	*(fifo_buf->head) = *item;
	fifo_buf->counter++;

	if (fifo_buf->head == (fifo_buf->base + (fifo_buf->lenght * sizeof(element_type))))
		fifo_buf->head = fifo_buf->base;
	else
	fifo_buf->head++;

	return fifo_no_error;

}
fifo_status fifo_DEqueue(FiFO_Buf_t* fifo_buf, element_type* item)
{

	if (!fifo_buf->head || !fifo_buf->base || !fifo_buf->tail)
		return fifo_null;

	if (fifo_buf->counter==0){
		printf("fifo is empty");
		return fifo_empty;
	}

	*item = *(fifo_buf->tail);

	fifo_buf->counter--;

	if (fifo_buf->head == (fifo_buf->base + (fifo_buf->lenght*sizeof(element_type))))
		fifo_buf->tail = fifo_buf->base;
	else
		fifo_buf->tail++;

	

	return fifo_no_error;
}

fifo_status fifo_init(FiFO_Buf_t* fifo_buf, element_type* buf, uint32_t lenght)
{
	if (fifo_buf == NULL)
		return fifo_null;

	fifo_buf->base = buf;
	fifo_buf->head = fifo_buf->base;
	fifo_buf->tail = fifo_buf->base;
	fifo_buf->counter = 0;
	fifo_buf->lenght = len;


	return fifo_no_error;
}



fifo_status fifo_FULL(FiFO_Buf_t* fifo_buf)
{
	

	if (!fifo_buf->head || !fifo_buf->base || !fifo_buf->tail)
		return fifo_null;

	if (fifo_buf->counter >= fifo_buf->lenght) {
		printf("fifio is full");
		return fifo_full;
	}
	return fifo_no_error;


}
void fifo_Print(FiFO_Buf_t* fifo_buf){
	int i;
	element_type* temp=NULL;
	

	if (fifo_buf->counter == 0){
		printf( "fifo_empty");
		return fifo_empty;
	}
	
	temp = fifo_buf->tail;

	printf("\n=====fifo print======\n");
	for (i = 0; i < fifo_buf->counter; i++)
	{
	
	printf("\t the buffer = %x\n", *temp);
	temp++;


	}
	printf("/n==================================== \n");

}

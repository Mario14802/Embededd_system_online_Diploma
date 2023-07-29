#include "LIFO.h"


lifo_status lifo_add_item(lifo_buf_t* lifo_buf, uint8_t item)
{
	if (!lifo_buf->head || !lifo_buf->base)
		return lifo_null;

	if ((lifo_buf->head) == (lifo_buf->lenght))
		return lifo_full;

	*(lifo_buf->head) = item;
	lifo_buf->head++;
	lifo_buf->counter++;

	return lifo_no_error;

}

lifo_status lifo_get_item(lifo_buf_t* lifo_buf, uint8_t* item)
{

	if (!lifo_buf->head || !lifo_buf->base)
		return lifo_null;

	if (lifo_buf->counter==0)
		return lifo_empty;

	lifo_buf->head--;
	*item=  *(lifo_buf->head);
	lifo_buf->counter--;

	return lifo_no_error;
}
lifo_status lifo_init(lifo_buf_t * lifo_buf, uint8_t* buf, uint8_t lenght)
{
	if (lifo_buf == NULL)
		return lifo_null;

	lifo_buf->base = buf;
	lifo_buf->head = buf;
	lifo_buf->counter = 0;
	lifo_buf->lenght = len;


	return lifo_no_error;
}
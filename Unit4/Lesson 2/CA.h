#ifndef	CA_H_
#define CA_H_

#include "STATE.h"

//define states
enum
{
	ca_waiting,
	ca_driving
}ca_state_id;


STATE_define(ca_waiting);
STATE_define(ca_driving);

//state pointer to function
extern void(*CA_state)();


#endif //_CA_H_
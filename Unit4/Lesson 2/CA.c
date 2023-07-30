#include "CA.h"
#include "STATE.h"


//variables
int CA_speed=0;
int CA_distance=0;
int CA_threshold=0;

//state pointer to function
void(*CA_state)();


STATE_define(ca_waiting)
{
	//state_name
	ca_state_id=ca_waiting;
	//state_action
	CA_speed=0;

	CA_distance = gen_ran(45, 55, 1);
	//event_check
	(CA_distance <= CA_threshold) ? (CA_state = STATE(ca_waiting)) : (CA_state = STATE(ca_driving));
    printf(" ca-watiting satate:distatnce:%d , speed:%d,CA_speed ", CA_distance, CA_speed);

}

STATE_define(ca_driving)
{

//state_name
	ca_state_id=ca_driving;
	//state_action
	CA_speed=30;

	CA_distance = gen_ran(45, 55, 1);
	//event_check
	(CA_distance <= CA_threshold) ? (CA_state = STATE(ca_waiting)) : (CA_state = STATE(ca_driving));
     printf("ca-driving satate:distatnce:%d , speed:%d ",CA_distance,CA_speed);

	
}

int gen_ran(int l, int r, int count)
{

	int i;
	for (i = 0; i < count; i++)
	{


		int rand_num = (rand() % (r - l + 1)) + l;
		return rand_num;
	}




}
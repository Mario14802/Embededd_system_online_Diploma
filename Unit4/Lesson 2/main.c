#include "CA.h"

void setup()
{
	CA_state = STATE(ca_waiting);


}



int main()
{

	volatile int d;
	setup();
	while (1)
	{
		CA_state();
		//delay
		for (d = 0; d <= 1000; d++);


	}


	return 0;
}


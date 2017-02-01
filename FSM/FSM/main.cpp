#include "Animation.h"
#include <thread>

int main()
{
	Animation fsm;
	int i = 0;
	fsm.idle();
	while (true)
	{
		if (i == 0)
		{
			fsm.jumping();
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			i = 1;
		}
		else
		{
			fsm.climbing();
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			i = 0;
		}
	}
	return 0;
}
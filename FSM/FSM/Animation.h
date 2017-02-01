#pragma once
#include <iostream>

class State;

class Animation
{
	State* current;
public:
	Animation();
	void setCurrent(State* s);
	void idle();
	void jumping();
	void climbing();
};

class State
{
public:
	State() {}
	virtual ~State() {}
	virtual void idle(Animation* a)
	{
		std::cout << "State::Idling" << std::endl;
	}

	virtual void jumping(Animation* a)
	{
		std::cout << "State::Jumping" << std::endl;
	}

	virtual void climbing(Animation* a)
	{
		std::cout << "State::Climbing" << std::endl;
	}
};

class Idle : public State
{
public:
	Idle() {}
	~Idle() {}
	virtual void jumping(Animation* a)
	{
		std::cout << "Jumping" << std::endl;
		a->setCurrent(new Idle());
		delete this;
	}

	virtual void climbing(Animation* a)
	{
		std::cout << "Climbing" << std::endl;
		a->setCurrent(new Idle());
		delete this;
	}
};

class Jumping : public State
{
public:
	Jumping() {}
	~Jumping() {}
	virtual void idle(Animation* a)
	{
		std::cout << "Going from Jumping to Idling" << std::endl;
		a->setCurrent(new Idle());
		delete this;
	}
};

class Climbing : public State
{
public:
	Climbing() {}
	~Climbing() {}
	virtual void idle(Animation* a)
	{
		std::cout << "Going from Climbing to Idling" << std::endl;
		a->setCurrent(new Idle());
		delete this;
	}
};

inline Animation::Animation()
{
	current = new Idle();
}

inline void Animation::setCurrent(State* s)
{
	current = s;
}
inline void Animation::idle()
{
	current->idle(this);
}
inline void Animation::jumping()
{
	current->jumping(this);
}
inline void Animation::climbing()
{
	current->climbing(this);
}

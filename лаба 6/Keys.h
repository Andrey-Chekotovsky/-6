#pragma once
class Keys
{
	bool top;
	bool bot;
	bool esc;
	bool ent;
public:
	Keys()
	{
		top = false;
		bot = false;
		esc = false;
		ent = false;
	}
	void set_top(bool top)
	{
		this->top = top;
	}
	bool get_top()
	{
		return this->top;
	}
	void set_bot(bool bot)
	{
		this->bot = bot;
	}
	bool get_bot()
	{
		return this->bot;
	}
	void set_esc(bool top)
	{
		this->esc = esc;
	}
	bool get_esc()
	{
		return this->esc;
	}
	void set_ent(bool ent)
	{
		this->ent = ent;
	}
	bool get_ent()
	{
		return this->ent;
	}
	void all_false()
	{
		top = false;
		bot = false;
		esc = false;
		ent = false;
	}
};


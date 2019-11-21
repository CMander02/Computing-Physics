#pragma once

template<unsigned dimension>
class Field
{
public:
	Field(double(*f[dimension])())
	{
		func = f;
	}
	~Field() = default;

	void tick_tock()
	{
		tick++;
	}

	double force();

private:

	double (*func[dimension])();

	double tick;

	double density;

};


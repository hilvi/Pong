#include <SFML\System\Clock.hpp>

#pragma once
class Time
{
private:
	sf::Clock clock;
public:
	Time(void);

	float getDeltaTime();
	void reset();

	~Time(void);
};


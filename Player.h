#ifndef EX2_PLAYER_H
#define EX2_PLAYER_H

#include "utilities.h"
#include <string>

#define DEFAULT_MAX_HP 100
#define DEFAULT_POWER 5
#define MAX_LEVEL 10

class Player {
public:
	Player(const char* name, int max_hp = DEFAULT_MAX_HP, int power = DEFAULT_POWER);

	~Player();
	void operator=(const Player& player);
	void printInfo() const;
	void levelUp();
	int getLevel() const;
	int getAttackStrength() const;
	void buff(int power_up);
	void heal(int add_hp);
	void damage(int damage);
	void addCoins(int coins);
	bool isKnockedOut() const;
	bool pay(int cost);

	Player()
	{
		m_name = "";
		m_max_hp = DEFAULT_MAX_HP;
		m_power = DEFAULT_POWER;
		m_current_hp = DEFAULT_MAX_HP;
	}

private:
	const char* m_name;
	int m_max_hp;
	int m_power;
	int m_current_hp;
	int m_level = 1;
	int m_coins = 0;
};

#endif //EX2_PLAYER_H
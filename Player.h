#ifndef EX2_PLAYER_H
#define EX2_PLAYER_H

#include "utilities.h"
#include <string>

#define DEFAULT_MAX_HP 100
#define DEFAULT_POWER 5
#define MAX_LEVEL 10

class Player {
public:
	Player(const char* name);
	Player(const char* name, int max_hp);
	Player(const char* name, int max_hp, int power);
	//Player(const Player& player);
	Player();
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
	~Player() = default;

private:
	const char* m_name;
	int m_max_hp;
	int m_power;
	int m_current_hp;
	int m_level = 1;
	int m_coins = 0;

	/**int getMaxHp() const;
	int getCurrentHp() const;
	int getPower() const;
	char* getName() const;*/
};

#endif //EX2_PLAYER_H

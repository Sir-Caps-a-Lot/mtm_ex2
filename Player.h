#ifndef EX2_PLAYER_H
#define EX2_PLAYER_H

#include "utilities.h"
#include <string>

#define DEFAULT_MAX_HP 100
#define DEFAULT_POWER 5
#define MAX_LEVEL 10

class Player {
public:
	/*
     * C'tor of Player class
     *
     * @param name - The type of the Player (optional when useing the default counstractor).
     * @param max hp - of the player (optional if power is inisilised)
	 * @param power - of the player if (optional)
     * @return new instance of Player.
    */
	Player(const char* name);
	Player(const char* name, int max_hp);
	Player(const char* name, int max_hp, int power);
	Player();

	/**
	 * default D'tor
	*/
	~Player() = default;

	/**
	 * 
	*/
	void operator=(const Player& player);
	
	/**
	 * prints the parameters of player in the following format
	 * Player Details:
	 * Name: 
	 * Gandalf Level: 1
	 * Force: 5
	 * HP: 300
	 * Coins: 0
	*/
	void printInfo() const;

	/**
	 * increases the level of player by one
	 * if his level is lower form 10 otherwise i'll do nothing
	*/
	void levelUp();

	/**
	 * @return the level of player
	*/
	int getLevel() const;

	/**
	 * @return the Attack Strength of player
	*/
	int getAttackStrength() const;

	/**
	 * riases the player level by power_up
	 * @param power_up - how much to riase the player level
	*/
	void buff(int power_up);

	/**
	 * raises the health of player by add_hp or to ten whichever is lower
	 * @param add_hp how much hp to add
	*/
	void heal(int add_hp);

	/**
	 * lowers the health of player by damage if it's lower then 0 it does nothing
	 * @param damage by how much to lower hp
	*/
	void damage(int damage);

	/**
	 * gives player the amount of coins
	 * @param coins the amount of coins to add
	*/
	void addCoins(int coins);

	/**
	 * checks if the player's health is 0 or lower
	 * @return if the player is knocked out
	*/
	bool isKnockedOut() const;

	/**
	 * lowers the player's coins by cost if he can pay otherwise he dosen't pay anything
	 * @param cost how much player has to pay
	 * @return if the player made the payment
	*/
	bool pay(int cost);

private:
	const char* m_name;
	int m_max_hp;
	int m_power;
	int m_current_hp;
	int m_level = 1;
	int m_coins = 0;
};

#endif //EX2_PLAYER_H

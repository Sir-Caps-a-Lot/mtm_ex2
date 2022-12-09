#include "Player.h"
#include "utilities.h"

Player::Player(const char* name) : Player{name ,DEFAULT_MAX_HP, DEFAULT_POWER}{}

Player::Player(const char* name, int max_hp) : Player{name ,max_hp, DEFAULT_POWER}{}

Player::Player(const char* name, int max_hp, int power): m_name(name),m_max_hp(max_hp),m_power(power),m_current_hp(m_max_hp){
	if (this->m_max_hp <= 0) {
		this->m_max_hp = DEFAULT_MAX_HP;
		this->m_current_hp = m_max_hp;
	}
	if (this->m_power <= 0) {
		this->m_power = DEFAULT_POWER;
	}
}

Player::Player(): m_name(""),m_max_hp(DEFAULT_MAX_HP),m_power(DEFAULT_POWER),m_current_hp(m_max_hp){
	/*this->m_max_hp = DEFAULT_MAX_HP;
	this->m_power = DEFAULT_POWER;
	this->m_name = "";
	this->m_current_hp = m_max_hp;*/
}

void Player::operator=(const Player& player)
{
	this->m_max_hp = player.m_max_hp;
	this->m_power = player.m_power;
	this->m_name = player.m_name;
	this->m_coins = player.m_coins;
	this->m_level = player.m_level;
	this->m_current_hp = player.m_current_hp;
}

void Player::printInfo() const
{
	printPlayerInfo(this->m_name, this->m_level, this->m_power,this->m_current_hp, this->m_coins);
}

void Player::levelUp()
{
	if (this->m_level < MAX_LEVEL)
		this->m_level++;
}

int Player::getLevel() const
{
	return this->m_level;
}

int Player::getAttackStrength() const
{
	return this->m_power + this->m_level;
}

void Player::buff(int power_up)
{
	this->m_power += power_up;
}

void Player::heal(int add_hp)
{
	if (add_hp > 0) {
		m_current_hp += add_hp;
	}
	if (this->m_current_hp > this->m_max_hp) {
		this->m_current_hp = this->m_max_hp;
	}
}

void Player::damage(int damage)
{
	if (damage > 0) {
		this->m_current_hp -= damage;
	}
	if (this->m_current_hp < 0) {
		this->m_current_hp = 0;
	}
}

void Player::addCoins(int coins)
{
	this->m_coins += coins;
}

bool Player::isKnockedOut() const
{
	if (this->m_current_hp == 0) {
		return true;
	}
	return false;
}

bool Player::pay(int cost)
{
	if (cost > this->m_coins) {
		return false;
	}
	this->m_coins -= cost;
	return true;
}

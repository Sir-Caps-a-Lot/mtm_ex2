#include "Player.h"
#include "Mtmchkin.h"

Mtmchkin::Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards)
{
	this->m_player = Player(playerName);
	this->m_card_deck = new Card[numOfCards];
	for (int i=0; i < numOfCards; i++)
	{
		this->m_card_deck[i] = cardsArray[i];
	}
	this->m_number_of_cards = numOfCards;
}

void Mtmchkin::playNextCard()
{
	Card current_card = m_card_deck[m_current_card++ % m_number_of_cards];
	current_card.printInfo();
	current_card.applyEncounter(this->m_player);
	this->m_player.printInfo();

	if (this->m_player.getLevel() == MAX_LEVEL) {
		this->m_status = GameStatus::Win;
	}
	if (this->m_player.isKnockedOut()) {
		this->m_status = GameStatus::Loss;
	}
}

bool Mtmchkin::isOver() const
{
	if (this->m_status == GameStatus::Win || this->m_status == GameStatus::Loss)
		return true;
	return false;
}

GameStatus Mtmchkin::getGameStatus() const
{
	return this->m_status;
}

Mtmchkin::~Mtmchkin()
{
	delete[] this->m_card_deck;
}
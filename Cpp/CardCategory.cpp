/*
 * CardCategory.cpp
 *
 *  Created on: Jul 29, 2019
 *      Author: haroon
 */

#include "CardCategory.h"

namespace std {

int CardCategory::card_Number = 0;

CardCategory::CardCategory() {
	card_Type = "\0";
}

CardCategory::CardCategory(string cc) {
	this->card_Type = cc;
	card_Number++;
}

const string& CardCategory::getCardType() const {
	return card_Type;
}

void CardCategory::setCardType(const string& cardType) {
	card_Type = cardType;
}

CardCategory::~CardCategory() {
	// TODO Auto-generated destructor stub
}

} /* namespace std */


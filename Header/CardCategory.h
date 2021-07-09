/*
 * CardCategory.h
 *
 *  Created on: Jul 29, 2019
 *      Author: haroon
 */
#include<iostream>
#ifndef CARDCATEGORY_H_
#define CARDCATEGORY_H_

namespace std {

class CardCategory {
protected:
	string card_Type;
	static int card_Number;
public:
	CardCategory();
	CardCategory(string);
	const string& getCardType() const;
	void setCardType(const string& cardType);
	virtual ~CardCategory();
};

} /* namespace std */

#endif /* CARDCATEGORY_H_ */


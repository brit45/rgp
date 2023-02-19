#include "InfoComponent.hpp"

InfoComponent::InfoComponent(std::string name, uint level, uint hp, uint hpM, uint exp, uint expM) :
    Name(name),
    Level(level),
    Hp(hp),
    Hp_Max(hpM),
    Exp(exp),
    Exp_Max(expM) {}

InfoComponent::~InfoComponent() {}

const std::string InfoComponent::getName() const {

    return this->Name;
}

const uint InfoComponent::getLevel() const {

    return this->Level;
}

const uint InfoComponent::getHp() const {

    return this->Hp;
}

const uint InfoComponent::getHpMax() const {

    return this->Hp_Max;
}

const uint InfoComponent::getExp() const {

    return this->Exp;
}

const uint InfoComponent::getExpMax() const {

    return this->Exp_Max;
}

void InfoComponent::AddHp(uint value) {

    if((this->Hp + value) < this->Hp_Max)

        this->Hp += value;
    else 

        this->Hp = this->Hp_Max;
}

void InfoComponent::AddExp(uint value) {

    if((this->Exp + value) >= this->Exp_Max) {

        uint delta = (this->Exp - this->Exp_Max);

        this->Level++;
        this->Exp = delta;
        this->Exp_Max *= this->Exp_Base_Operator;
    }
    else 

        this->Exp += value;
}

void InfoComponent::RemoveHp(uint value) {

    if((this->Hp - value) > 0)

        this->Hp -= value;
    else 

        this->Hp = 0;
}
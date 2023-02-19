#ifndef __COMPONENTS_INFOCOMPONENT_HPP__
#define __COMPONENTS_INFOCOMPONENT_HPP__

#include "Component.inl"

class InfoComponent {

    public:

        /**
         * @brief Construct a new Info Component.
         * 
         * @param name 
         * @param Level 
         * @param hp 
         * @param hpM 
         * @param exp 
         * @param expM 
         */
        InfoComponent(std::string name, uint Level, uint hp, uint hpM, uint exp, uint expM);

        virtual ~InfoComponent();

        /**
         * @brief Get the Name.
         * 
         * @return const std::string 
         */
        const std::string getName() const;

        /**
         * @brief Get the Level.
         * 
         * @return const uint 
         */
        const uint getLevel() const;

        /**
         * @brief Get the Hp.
         * 
         * @return const uint 
         */
        const uint getHp() const;


        /**
         * @brief Get the Hp Max.
         * 
         * @return const uint 
         */
        const uint getHpMax() const;

        /**
         * @brief Get the Exp.
         * 
         * @return const uint 
         */
        const uint getExp() const;

        /**
         * @brief Get the Exp Max.
         * 
         * @return const uint 
         */
        const uint getExpMax() const;

        /**
         * @brief Add Hp count value.
         * 
         * @param value 
         */
        void AddHp(uint value);

        /**
         * @brief Add Exp count value.
         * 
         * @param value 
         */
        void AddExp(uint value);

        /**
         * @brief Remove Hp count value.
         * 
         * @param value 
         */
        void RemoveHp(uint value);

    private:

        std::string Name;
        uint Level, Hp, Hp_Max, Exp, Exp_Max;

        const float Exp_Base_Operator = 1.25;
};

#endif //! __COMPONENTS_INFOCOMPONENT_HPP__
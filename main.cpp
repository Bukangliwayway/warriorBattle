#include <iostream>
#include <ctime>
#include "windows.h"
#define Health 10000
#define Attack 1500
#define Defense 2000
#define Pause Sleep(250)
#define Percent (Random(1,100))

#define Design "\n===============\n"
#define Tank "     TANK"
#define Fighter "   FIGHTER"
#define Mage "     MAGE"
#define Marksman "   MARKSMAN"

#define High(Stats) Stats *(Random(75,100))/100
#define HtoM(Stats) Stats *(Random(63,88))/100
#define Med(Stats) Stats * (Random(50,75))/100
#define MtoL(Stats) Stats *(Random(38,63))/100
#define Low(Stats) Stats * (Random(25,50))/100
#define CritDamage Attack * (Random(41,50))/100

#define Add(Constant, Stats) Constant + Stats * (Random(10,25))/100
#define Random(first,last) first+(rand()% (last-first)+1)
#define Additional(first, last, Stats) Stats * (Random(first,last))/100
#define Probability(last,value) (value >= 1 && value <= last)
#define NetDamage(first, last, attack) attack * (Random(first,last))/100
#define Damage(attack) attack * (Random(20,50))/100

/** RULES :
        I.  STATS:
                HEALTH: 10000
                ATTACK: 1000
                DEFENSE: 2000
       II.  LEVELS :
                HIGH = 75% - 100% : 100%
                MED = 50% - 75% : 75%
                LOW = 25% - 50% : 50%
      III.  2 PLAYERS ONLY UWU
       IV.  DEFENSES :
                DEFENSE ACTS AS A SHIELD (TAKES 1%-50% OF DAMAGE WILL TAKE)
                RESETS EVERY 10TH ROUNDS
        V.  ATTACK :
                AUTOMATICALLY ATTACK EACH ROUND
                20%-40% : NORMAL CALCULATION
                41 - 50% : CRITICAL
       VI. EXCESS STATS WILL BE DENIED
*/
/** TANK CLASS :
            HIGH HEALTH
            HIGH TO MED DEFENSE
            LOW MAGIC AND DAMAGE
            ABILITIES :
                TPASSIVEA : NORMAL ATTACK
                        DEALS 100% CONSTANT BASE DAMAGE (NOTICE RULE)
                SPECIAL ABILITY: ADDITIONAL MAX HEALTH & HEALTH REGEN
                    TSABILITYA : ADDITIONAL MAX HEALTH
                        +10%-25% MAX HEALTH
                    TSABILITYB : HEALTH REGEN
                        20% CHANCE PER ROUND
                        +1%-10% HEALTH (EXCESS REGEN WILL NOT EFFECT)
                TABILITYA: HEAL
                        +1% - 10% HEALTH
                TABILITYB: SELF - DESTRUCT
                        -20% HEALTH (BASED ON MAXHEALTH)
                        30% CHANCE OF DAMAGING THE OPPONENT EQUAL TO DEDUCTED HEALTH
                TABILITYC: BLOCK
                        0% - 50% DAMAGES BLOCK
                        40% CHANCE OF RETURNING 15% -30% OF DAMAGE TAKEN
*/
/** FIGHTER CLASS :
            HIGH TO MED HEALTH
            HIGH TO MED DEFENSE
            MED TO LOW DAMAGE
            ABILITIES:
                NORMAL ATTACK
                        75% TO 100% DAMAGE
                SPECIAL ABILITY: HEAL ON ATTACK & 100% BLOCK
                    HEAL ON ATTACK
                        30% CHANCE PER ATTACK
                        HEALS 25% - 50% OF DAMAGE ATTACKED
                    100% BLOCK
                        20% CHANCE PER ROUND
                ABILITY A: DOUBLE ATTACK
                    50% CHANCE OF DOUBLE DAMAGE
                ABILITY B: POISON
                    ADDITIONAL 5-10% DAMAGE FOR THE NEXT 3 ROUNDS
                ABILITY C: COMEBACK
                    DEALS 200% OF OPPONENT'S DAMAGE
                    40% CHANCE OF TURNING IT BACK TO THEM
*/
/** MAGE CLASS :
            LOW HEALTH
            MED TO LOW DEFENSE
            HIGH TO MED DAMAGE
            ABILITIES:
                NORMAL ATTACK :
                        50% TO 75% DAMAGE
                SPECIAL ABILITY : ADDITIONAL MAX MAGIC DAMAGE & DOUBLE DAMAGE
                    ADDITIONAL MAX DAMAGE:
                        +10% - 25% DAMAGE
                    DOUBLE ATTACK
                        30% CHANCE OF DOUBLED ATTACK DAMAGE PER ATTACK
                ABILITY A: BURN
                        BURN 1%-10% OF THE OPPONENT'S MAX HEALTH
                ABILITY B: DEFENSE
                        100% BLOCK DEFENSE
                        30% CHANCE OF RESETTING DEFENSE
                ABILITY C: ABSORB
                        40% CHANCE OF CONVERTING 50% INCOMING DAMAGE INTO HEALTH INSTEAD
*/
/** MARKSMAN CLASS :
            LOW HEALTH
            MED TO LOW DEFENSE
            HIGH DAMAGE
            ABILITIES:
                NORMAL ATTACK :
                        75% TO 100% DAMAGE
                SPECIAL ABILITY : DODGE & CRITICAL ATTACK
                    DODGE:
                        20% CHANCE OF DODGING OPPONENT'S ATTACK
                    CRIT ATTACK
                        CRITICAL  ATTACK AUTOMATICALLY DEALS 100% DAMAGE
                ABILITY A : DOUBLE HIT
                        50% Chance of +50% ATTACK DAMAGE
                ABILITY B : HEAL
                        HEALS 10%-20% BASE MAX HEALTH
                ABILITY C: BLOCK
                        BLOCK 50% OF OPPONENT'S ATTACK
                        PASSIVE: AGGRESSIVE
                            USING THIS 3 TIMES WILL GRANT YOU DOUBLE DAMAGE
*/
using namespace std;
int netDefend;
int netAttack;
class Warrior{
public:
    Warrior(int);
    int warriorClass;
    int health;
    int defense;
    int damage;
    int Maxhealth;
    int Maxdefense;
    int Maxdamage;
    int Choices(int);

};

Warrior::Warrior(int warriorClass){
    this->warriorClass = warriorClass;
    switch(warriorClass){
    case 1:
        cout << Tank << Design << "    Stats" << endl; Pause;
        health = High(Health);
        Maxhealth = health = Add(health, Health); /// TSABILITYA
        cout << "Health: " << health << endl; Pause;
        Maxdamage = damage = Low(Attack);
        cout << "Damage: " << damage << endl; Pause;
        Maxdefense = defense = HtoM(Defense);
        cout << "Defense: " << defense << Design << endl; break;
    case 2:
        cout << Fighter << Design << "    Stats" << endl; Pause;
        Maxhealth = health = HtoM(Health);
        cout << "Health: " << health << endl; Pause;
        Maxdamage = damage = HtoM(Attack);
        cout << "Damage: " << damage << endl; Pause;
        Maxdefense = defense = MtoL(Defense);
        cout << "Defense: " << defense << Design << endl; break;
    case 3:
        cout << Mage << Design << "    Stats" << endl; Pause;
        Maxhealth = health  = Low(Health);
        cout << "Health: " << health << endl; Pause;
        damage = HtoM(Attack);
        Maxdamage = damage = Add(damage, Attack); /// Additional Max Damage
        cout << "Damage: " << damage << endl; Pause;
        Maxdefense = defense = MtoL(Defense);
        cout << "Defense: " << defense << Design << endl; break;
    case 4:
        cout << Marksman << Design << "    Stats" << endl; Pause;
        Maxhealth = health  = Low(Health);
        cout << "Health: " << health << endl; Pause;
        Maxdamage = damage = High(Attack);
        cout << "Damage: " << damage << endl; Pause;
        Maxdefense = defense = Low(Defense);
        cout << "Defense: " << defense << Design << endl; break;
    }
}

///Not Sure
void Commentator(int task, Warrior& warrior){
    switch(task){
    case 1:
        cout << Design << "Current Health: " << warrior.health << endl; Pause;
        cout << "Current Damage: " << warrior.damage << endl; Pause;
        cout << "Current Defense " << warrior.defense << Design; Pause;
        cout << "Opponent Damage: " << netDefend; Pause;
    }
}

int Choices(int classType){
    int choice;
    switch(classType){
    case 1:
        cout << Design << "Choose your Ability: \n";
        cout << "1: Heal\n2: Self-Destruct\n3: Block\n Choose Ability: ";
        cin >> choice;
        cout << Design;
        return choice;
    case 2:
        cout << Design << "Choose your Ability: \n";
        cout << "1: Double Attack\n2: Poison\n3: Comeback\n Choose Ability: ";
        cin >> choice;
        cout << Design << endl;
        return choice;
    case 3:
        cout << Design << "Choose your Ability: \n";
        cout << "1: Burn\n2: Defense\n3: Heal\n Choose Ability: ";
        cin >> choice;
        cout << "\n====================" << endl;
        return choice;
    case 4:
        cout << Design << "Choose your Ability: \n";
        cout << "1: Double Hit\n2: Heal\n3: Block\n Choose Ability: ";
        cin >> choice;
        cout << Design << endl;
        return choice;
    default:
        cout << "\nInvalid Choice" << Design; Pause;
        Choices(classType);
    }
}

 void TankAbilities(Warrior& warrior){
    static int defenseReset;
    int basicAttack = Damage(warrior.damage);
    netAttack = basicAttack; /// TPASSIVEA
    int defenseDecrease = Additional(1,50,warrior.defense);
    int additionalHealth = Additional(5,15,warrior.Maxhealth);
    int selfdamage = Additional(19,20,warrior.Maxhealth);
    int blocked = Additional(0,50,netDefend);
    int percentageBlocked = Additional(15,30,blocked);
    int healthRegen = Additional(10,25,warrior.health);
    Commentator(1,warrior);

    switch(Choices(1)){
        case 1: ///TABILITYA
            if(warrior.health+additionalHealth < warrior.Maxhealth) /// Denies Excess Heal
                warrior.health+= additionalHealth;
            else warrior.health = warrior.Maxhealth;
            break;
        case 2: ///TABILITYB
            if(warrior.health >= selfdamage) warrior.health-= selfdamage; /// Disable Ability When Base Health is Low
            else{
                cout << Design << "Couldn't Perform Ability due to Low Health" << Design;
                TankAbilities(warrior); /// Loop
            }
            if(Probability(30,Percent))netAttack += selfdamage; /// Probability of Damaging Enemy
            break;
        case 3: ///TABILITYC
            netDefend -= blocked;
            if(Probability(40,Percent)) netAttack += percentageBlocked; /// Probability of Adding Net Attack
            break;
    }

    if(Probability(20,Percent)){ ///TSABILITYB
        if(warrior.health + healthRegen < warrior.Maxhealth) /// Heal Excess will be denied
            warrior.health+= healthRegen;
        else warrior.health = warrior.Maxhealth;
    }
    ///Calculation
    defenseReset++;
    if(defenseReset%10==0) warrior.defense = warrior.Maxdefense; ///Resets Defense every 10 Rounds
    if(netDefend > defenseDecrease){
        netDefend-= defenseDecrease; /// Damages Blocked By Defense
        warrior.defense -= defenseDecrease; /// Decreases Base Defense
    }else{
        netDefend = 0; /// Removes Excess
        warrior.defense -= defenseDecrease;
    }
    warrior.health -= netDefend; /// Net Opponents Damage
    netDefend = netAttack;
    netAttack = 0;
}

 void FighterAbilities(Warrior& warrior){
    static int defenseReset;
    static int poisonRound;
    int basicAttack = NetDamage(75,100,Damage(warrior.damage)); /// Basic Attack 75% - 100% of Pure Damage
    netAttack = basicAttack;
    int defenseDecrease = Additional(1,50,warrior.defense);
    int poisonEffect = Additional(5,10,basicAttack);
    int attackHeal = Additional(25,50,netAttack);
    Commentator(1,warrior);


    switch(Choices(2)){
        case 1: /// Double Attack
            if(Probability(50,Percent)) netAttack*=2;
            break;
        case 2: /// Poison
            poisonRound = 1; /// Disturbs the PoisonRound
            break;
        case 3: ///Comeback
            netDefend*=2; /// 200% Opponents Damage
            if(Probability(40,Percent)) netAttack += netDefend; /// Adds NetAttack
            break;
    }
    if(poisonRound%3!=0 && poisonRound!=0){
        netAttack += poisonEffect;
        poisonRound++; ///Increment the Round up to 3
    }else poisonRound = 0; /// Converts the Completed cycle to 0

    if(Probability(20,Percent)) netDefend = 0; ///100% Block
    if(Probability(30,Percent))warrior.health += attackHeal; /// Heal on Attack

    ///CALCULATION
    defenseReset++;
    if(defenseReset%10==0) warrior.defense = warrior.Maxdefense; ///Resets Defense every 10 Rounds
    if(netDefend > defenseDecrease){
        netDefend-= defenseDecrease; /// Damages Blocked By Defense
        warrior.defense -= defenseDecrease; /// Decreases Base Defense
    }else{
        netDefend = 0; /// Removes Excess
        warrior.defense -= defenseDecrease;
    }
    warrior.health -= netDefend; /// Net Opponents Damage
    netDefend = netAttack;
    netAttack = 0;
}

 void MageAbilities(Warrior& warrior, Warrior& opponent){
    static int defenseReset;
    int basicAttack = NetDamage(75,100,Damage(warrior.damage)); /// Basic Attack 75% - 100% of Pure Damage
    netAttack = basicAttack;
    int defenseDecrease = Additional(1,50,warrior.defense);
    int burnDamage = Additional(5,10,opponent.Maxhealth);

    if(Probability(30,Percent)) netAttack *= 2; /// Double Attack
    switch(Choices(3)){
        case 1: /// Burn
            netAttack += burnDamage;
            break;
        case 2: ///Defend
            if(Probability(30,Percent)) warrior.defense = warrior.Maxdefense;
            if(netDefend <= warrior.defense){
                netDefend = 0;
                warrior.defense -= netDefend;
            }else{
                netDefend -= warrior.defense;
                warrior.defense = 0;
            }
            break;
        case 3: ///ABSORB
            if(Probability(40,Percent)){
                warrior.health += netDefend/2;
                netDefend /= 2;
            }else cout << "Ability Failed" << endl;
            break;
    }
    ///CALCULATION
    defenseReset++;
    if(defenseReset%10==0) warrior.defense = warrior.Maxdefense; ///Resets Defense every 10 Rounds
    if(netDefend > defenseDecrease){
        netDefend-= defenseDecrease; /// Damages Blocked By Defense
        warrior.defense -= defenseDecrease; /// Decreases Base Defense
    }else{
        netDefend = 0; /// Removes Excess
        warrior.defense -= defenseDecrease;
    }
    warrior.health -= netDefend; /// Net Opponents Damage
    netDefend = netAttack;
    netAttack = 0;
}

 void MarksmanAbilities(Warrior& warrior){
    static int defenseReset;
    int basicAttack = Damage(warrior.damage);
    if(basicAttack >= warrior.damage*0.41) /// Least Critical Possible
        netAttack = basicAttack; /// 100% Critical Attack
    else netAttack = NetDamage(75,100,basicAttack); /// Basic Attack 75% - 100% of Pure Damage
    int defenseDecrease = Additional(1,50,warrior.defense); /// Generate Defense Amount
    int doubleHit = netAttack*0.5;
    int heal = Additional(10,20,warrior.Maxhealth);
    static int blockReset;

    switch(Choices(4)){
        case 1: /// DOUBLE HIT
            if(Probability(50,Percent)) netAttack += doubleHit; /// Plus 50% Damage
            else cout << "Ability Failed" << endl;
            break;
        case 2: ///HEAL
            warrior.health += heal; /// 10-20% Max Health
            break;
        case 3: ///BLOCK
            blockReset++;
            netDefend /= 2;
            if(blockReset%3==0) netAttack *= 2; /// Using this 3 times grants you Double Damage
            break;
    }

    if(Probability(20,Percent)) netDefend = 0; /// Dodge

        ///CALCULATION
    defenseReset++;
    if(defenseReset%10==0) warrior.defense = warrior.Maxdefense; ///Resets Defense every 10 Rounds

    if(netDefend > defenseDecrease){
        netDefend-= defenseDecrease; /// Damages Blocked By Defense
        warrior.defense -= defenseDecrease; /// Decreases Base Defense
    }else{
        netDefend = 0; /// Removes Excess
        warrior.defense -= defenseDecrease;
    }
    warrior.health -= netDefend; /// Net Opponents Damage
    netDefend = netAttack;
    netAttack = 0;
}

void startingProcess(Warrior& awarrior, Warrior& bwarrior){
    int initialAttack = (NetDamage(50,100,Damage(awarrior.damage)) + NetDamage(50,100,Damage(bwarrior.damage)))/2;
    netDefend = initialAttack;
}

class battleArena{
private:
    int battleSwitch(Warrior& warriorA, Warrior& warriorB, int warriorAClass);
public:
    battleArena();
    void battleProcessor(Warrior& warriorA, int warriorAClass, Warrior& warriorB, int warriorBclass);


};

void battleArena::battleProcessor(Warrior& warriorA, int warriorAClass, Warrior& warriorB, int warriorBclass){
    startingProcess(warriorA,warriorB);
    while(true){
        switch(battleSwitch(warriorA, warriorB, warriorAClass)){
        case 1:
            cout << "\nPlayer 1 Win!\n";
            break;
        case 2:
            cout << "\nPlayer 2 Win!\n";
            break;
        }
        switch(battleSwitch(warriorB, warriorA, warriorAClass)){
        case 1:
            cout << "\nPlayer 1 Win!\n";
            break;
        case 2:
            cout << "\nPlayer 2 Win!\n";
            break;
        }
    }
}



battleArena::battleSwitch(Warrior& warrior, Warrior& opponent, int classType){
    switch(classType){
    case 1:
        TankAbilities(warrior);
        break;
    case 2:
        FighterAbilities(warrior);
        break;
    case 3:
        MageAbilities(warrior,opponent);
        break;
    case 4:
        MarksmanAbilities(warrior);
    }
    if(warrior.health < 0) return 1;
    if(opponent.health < 0) return 2;
    return 0;
}



int main(){
    srand(time(0));
    Warrior Eyy(1);
    Warrior Hatdog(2);
    battleArena Hi();
    Hi::battleProcessor(Eyy,1,Hatdog,2);
    return 0;
}

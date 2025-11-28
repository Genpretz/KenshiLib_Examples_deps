#pragma once

#include "Enums.h"
#include "util/hand.h"
#include "util/OgreUnordered.h"
#include "util/lektor.h"
#include "util/TimeOfDay.h"
#include "FitnessSelector.h"

#include <mygui/MyGUI_Widget.h>
#include <boost/unordered_set.hpp>
#include <ogre/OgreMemoryAllocatorConfig.h>

#include <map>
#include <set>


enum TalkerEnum
{
    T_ME,
    T_TARGET,
    T_TARGET_IF_PLAYER,
    T_INTERJECTOR1,
    T_INTERJECTOR2,
    T_INTERJECTOR3,
    T_WHOLE_SQUAD,
    T_TARGET_WITH_RACE
};

enum DialogActionEnum
{
    DA_NONE,
    DA_TRADE,
    DA_TALK_TO_LEADER,
    DA_JOIN_SQUAD_WITH_EDIT,
    DA_AFFECT_RELATIONS,
    DA_AFFECT_REPUTATION,
    DA_ATTACK_CHASE_FOREVER,
    DA_GO_HOME,
    DA_TAKE_MONEY,
    DA_GIVE_MONEY,
    DA_PAY_BOUNTY,
    DA_CHARACTER_EDITOR,
    DA_FORCE_SPEECH_TIMER,
    DA_DECLARE_WAR,
    DA_END_WAR,
    DA_CLEAR_AI,
    DA_FOLLOW_WHILE_TALKING,
    DA_THUG_HUNTER,
    DA_JOIN_SQUAD_FAST,
    DA_REMEMBER_CHARACTER,
    DA_FLAG_TEMP_ALLY,
    DA_FLAG_TEMP_ENEMY,
    DA_MATES_KILL_ME,
    DA_MAKE_TARGET_RUN_FASTER,
    DA_GIVE_TARGET_MY_SLAVES,
    DA_TAG_ESCAPED_SLAVE,
    DA_FREE_TARGET_SLAVE,
    DA_MERGE_WITH_SIMILAR_SQUADS,
    DA_SEPARATE_TO_MY_OWN_SQUAD,
    DA_ARREST_TARGET,
    DA_ARREST_TARGETS_CARRIED_PERSON,
    DA_ATTACK_TOWN,
    DA_ASSIGN_BOUNTY,
    DA_CRIME_ALARM,
    DA_RUN_AWAY,
    DA_INCREASE_FACTION_RANK,
    DA_LOCK_THIS_DIALOG,
    DA_ASSAULT_PHASE,
    DA_RETREAT_PHASE,
    DA_VICTORY_PHASE,
    DA_ENSLAVE_TARGETS_CARRIED_PERSON,
    CHOOSE_SLAVES_SELLING,
    CHOOSE_SLAVES_BUYING,
    CHOOSE_PRISONER_BAIL,
    CHOOSE_CONSCRIPTION,
    CHOOSE_RECRUITING,
    CHOOSE_HIRING_CONTRACT,
    SURRENDER_NON_HUMANS,
    CHOOSE_ANIMALS_BUYING,
    DA_CLEAR_BOUNTY,
    DA_PLAYER_SELL_PRISONERS,
    DA_PLAYER_SURRENDER_MEMBER_DIFFERENT_RACE,
    DA_SUMMON_MY_SQUAD,
    DA_REMOVE_SLAVE_STATUS,
    DA_OPEN_NEAREST_GATE,
    DA_ATTACK_STAY_NEAR_HOME,
    DA_MASSIVE_ALARM,
    DA_ATTACK_IF_NO_COEXIST,
    DA_KNOCKOUT,
    DA_END
};

// TODO move?
namespace wraps
{
    class BaseLayout
    {
    public:
        // VTable         : (none)
        // no_addr void BaseLayout(const class wraps::BaseLayout &);// public
        BaseLayout(const std::string& _layout, MyGUI::Widget* _parent);// protected RVA = 0xCFC90
        // no_addr void BaseLayout();// protected
        void initialise(const std::string& _layout, MyGUI::Widget* _parent, bool _throw, bool _createFakeWidgets);// protected RVA = 0xCADD0
        void shutdown();// protected RVA = 0xC8560
        std::string FindParentPrefix(MyGUI::Widget* _parent);// private RVA = 0xC92B0
        void snapToParent(MyGUI::Widget* _child);// private RVA = 0xC8640
        MyGUI::Widget* _createFakeWidgetT(const std::string& _typeName, MyGUI::Widget* _parent);// private RVA = 0xC87F0
        virtual ~BaseLayout();// public RVA = 0xC89E0 vtable offset = 0x0
        MyGUI::Widget* mMainWidget; // 0x8 Member
        std::string mPrefix; // 0x10 Member
        std::string mLayoutName; // 0x38 Member
        std::vector<MyGUI::Widget*> mListWindowRoot; // 0x60 Member
        // Typedef        : VectorBasePtr
        std::vector<wraps::BaseLayout*> mListBase; // 0x80 Member
        // no_addr class wraps::BaseLayout & operator=(const class wraps::BaseLayout &);// public
        // no_addr void __local_vftable_ctor_closure();// public
        //virtual void * __vecDelDtor(unsigned int) = 0;// public vtable offset = 0x0
    };
};

class DialogueSpeechBubble : public wraps::BaseLayout, public Ogre::GeneralAllocatedObject
{
public:
    // wraps::BaseLayout offset = 0x0, length = 0xA0
    // Ogre::GeneralAllocatedObject offset = 0xA1, length = 0x1
    // no_addr void DialogueSpeechBubble(const class DialogueSpeechBubble &);// public
    DialogueSpeechBubble(bool shout, bool importnt);// public RVA = 0x5B3900
    virtual ~DialogueSpeechBubble();// public RVA = 0x5B0C00 vtable offset = 0x0
    void setText(const std::string& text);// public RVA = 0x5AFA70
    void setAlpha(float value);// public RVA = 0x5AFB70
    void setPosition(int x, int y);// public RVA = 0x5B0570
    void setPosition(const Ogre::Vector3& position);// public RVA = 0x5AFB90
    void reset();// public RVA = 0x5AFB50
    float getAlpha() const;// public RVA = 0x5AFCC0
    MyGUI::types::TRect<int> getRect() const;// public RVA = 0x5AFCE0
    bool stayOnScreen; // 0xA1 Member
    bool shout; // 0xA2 Member
    int marginW; // 0xA4 Member
    int marginH; // 0xA8 Member
    MyGUI::EditBox* textBox; // 0xB0 Member
    MyGUI::types::TSize<int> baseSize; // 0xB8 Member
    static MyGUI::Colour TextColour; // Static Member
    // no_addr class DialogueSpeechBubble & operator=(const class DialogueSpeechBubble &);// public
    //virtual void * __vecDelDtor(unsigned int) = 0;// public vtable offset = 0x0
};

class CampaignTriggerData
{
public:
    GameData* what; // 0x0 Member
    int minTime; // 0x8 Member
    int maxTime; // 0xC Member
    float chance; // 0x10 Member
};

class Faction;
class WorldEventStateQueryList;
class DialogChoiceList;
class Dialogue;

// TODO move?
class GameDataValuePair
{
public:
    GameDataValuePair(GameData* d, int v);// public RVA = 0x5207A0
    GameDataValuePair* _CONSTRUCTOR(GameData* d, int v);// public RVA = 0x5207A0
    GameDataValuePair();// public RVA = 0x520790
    GameDataValuePair* _CONSTRUCTOR();// public RVA = 0x520790
    GameData* data; // 0x0 Member
    int val0; // 0x8 Member
};

class DialogLineData
{
public:
    // VTable         : (none)
    class DialogAction
    {
    public:
        DialogActionEnum key; // 0x0 Member
        int value; // 0x4 Member
    };
    class DialogCondition
    {
    public:
        DialogConditionEnum key; // 0x0 Member
        ComparisonEnum compareBy; // 0x4 Member
        TalkerEnum who; // 0x8 Member
        int value; // 0xC Member
    };
    class FlagCondition
    {
    public:
        // no_addr void FlagCondition();// public
        DialogConditionEnum key; // 0x0 Member
        bool want; // 0x4 Member
        unsigned int flags; // 0x8 Member
    };
    unsigned int targetFlagsNeeded; // 0x8 Member
    unsigned int targetFlagsNotWanted; // 0xC Member
    unsigned int personalityNeeded; // 0x10 Member
    unsigned int personalityNotWanted; // 0x14 Member
    FitnessSelector<CampaignTriggerData*> campaignTriggers; // 0x18 Member
    lektor<GameData*> isTargetRace; // 0x78 Member
    lektor<GameData*> isTargetSubRace_specificallyTheTarget; // 0x90 Member
    DialogLineData* getParent() const;// public RVA = 0x5207B0
    lektor<GameDataValuePair> givesItem; // 0xA8 Member
    bool isForSpecificCharacter(GameData* who);// public RVA = 0x521000
    bool hasSpecificCharacterRequirement() const;// public RVA = 0x538DA0
    std::set<Faction*, std::less<Faction*>, Ogre::STLAllocator<Faction*, Ogre::GeneralAllocPolicy > > inTownOf; // 0xC0 Member
    std::set<Faction*, std::less<Faction*>, Ogre::STLAllocator<Faction*, Ogre::GeneralAllocPolicy > > isTargetFaction; // 0xE8 Member
    std::set<Faction*, std::less<Faction*>, Ogre::STLAllocator<Faction*, Ogre::GeneralAllocPolicy > > isMyFaction; // 0x110 Member
    lektor<GameData*> isCharacter; // 0x138 Member
    lektor<GameData*> isTargetCarryingCharacter; // 0x150 Member
    lektor<GameData*> _hasPackage; // 0x168 Member
    lektor<GameData*> isMyRace; // 0x180 Member
    lektor<GameData*> isMySubRace; // 0x198 Member
    ItemFunction hasItemType; // 0x1B0 Member
    lektor<GameData*> hasItem; // 0x1B8 Member
    WorldEventStateQueryList* worldState; // 0x1D0 Member
    void _initialiseAList(const std::string& listname, lektor<GameDataValuePair>* list);// protected RVA = 0x52A4F0
    void _initialiseAList(const std::string& listname, lektor<GameData*>* list);// protected RVA = 0x52A400
    // no_addr void DialogLineData(const class DialogLineData & _a1);// public missing arg names
    DialogLineData(GameData* dat);// protected RVA = 0x52A630
    DialogLineData* _CONSTRUCTOR(GameData* dat);// protected RVA = 0x52A630
    virtual ~DialogLineData();// protected RVA = 0x5229D0 vtable offset = 0x0
    void _DESTRUCTOR();// protected RVA = 0x5229D0 vtable offset = 0x0
    void setupChildren();// protected RVA = 0x52C820
    bool checkRepeatLimits();// protected RVA = 0x520C20
    bool checkTags(Character* me, Character* target);// protected RVA = 0x524210
    GameData* data; // 0x1D8 Member
    bool onceOnly; // 0x1E0 Member
    bool isMonologue; // 0x1E1 Member
    CharacterTypeEnum forCertainType; // 0x1E4 Member
    DialogChoiceList* children; // 0x1E8 Member
    lektor<DialogLineData::DialogCondition*> conditions; // 0x1F0 Member
    lektor<DialogLineData::DialogAction*> actions; // 0x208 Member
    int lineCount; // 0x220 Member
    std::string* texts; // 0x228 Member
    DialogLineData* parent; // 0x230 Member
    float chancePermanent; // 0x238 Member
    float chanceTemporary; // 0x23C Member
    bool unique; // 0x240 Member
    hand uniqueOwner; // 0x248 Member
    float dialogRepeatMinTimeInHours; // 0x268 Member
    TimeOfDay lastTimeSaid; // 0x270 Member
    int score; // 0x278 Member
    bool oneAtATime; // 0x27C Member
    bool isLocked; // 0x27D Member
    lektor<DialogLineData*> locks; // 0x280 Member
    lektor<DialogLineData*> unlocks_lockMe; // 0x298 Member
    lektor<DialogLineData*> unlocks_dontLockMe; // 0x2B0 Member
    DialogLineData* crowdTrigger; // 0x2C8 Member
    std::string getName() const;// public RVA = 0x4B0F40
    bool saidItBefore();// public RVA = 0x5207C0
    bool willTalkToEnemies();// public RVA = 0x5207E0
    virtual bool isEmptyNode() const;// public RVA = 0x54BA70 vtable offset = 0x8
    bool _NV_isEmptyNode() const;// public RVA = 0x54BA70 vtable offset = 0x8
    bool isAnnouncement();// public RVA = 0x5207F0
    void stampLastTimeSaid();// public RVA = 0x520D30
    ogre_unordered_map<GameData*, int>::type factionRelationEffects; // 0x2D0 Member
    DialogLineData* playerInterruptionDialog; // 0x310 Member
    bool isInterjection; // 0x318 Member
    TalkerEnum speaker; // 0x31C Member
    int getScore(Character* target) const;// public RVA = 0x521170
    int getScorePlusChildrenIfEmpty(Character* target);// public RVA = 0x521310
    bool hasChildren() const;// public RVA = 0x520800
    bool checkConditions(Dialogue* dialog, Character* target, bool isWordswap);// public RVA = 0x5284F0
    DialogLineData* chooseAChild(Dialogue* who, Character* target, bool isForWordswaps);// public RVA = 0x520C90
    std::string getText(bool _stampTime);// public RVA = 0x524BF0
    void getText(std::string& out, bool _stampTime);// public RVA = 0x5248E0
    std::string getStringID() const;// public RVA = 0x548120
    GameData* getGameData();// public RVA = 0x520810
    DialogLineData* getChildByStringID(const std::string& sid);// public RVA = 0x521750
    void getPlayerReplies(lektor<DialogLineData*>& out, Dialogue* who, Character* target);// public RVA = 0x5290C0
    void setParent(DialogLineData* p);// public RVA = 0x520820
    int getMoneyCostForLine() const;// public RVA = 0x5210D0
    const lektor<DialogLineData::DialogAction*>* getActions() const;// public RVA = 0x520830
    // no_addr class DialogLineData & operator=(const class DialogLineData & _a1);// public missing arg names
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// protected vtable offset = 0x0 missing arg names
};

class DialogChoiceList
{
public:
    lektor<DialogLineData*> conversationChoices; // 0x0 Member
    // no_addr void DialogChoiceList(const class DialogChoiceList & _a1);// public missing arg names
    DialogChoiceList();// public RVA = 0x53BA80
    DialogChoiceList* _CONSTRUCTOR();// public RVA = 0x53BA80
    ~DialogChoiceList();// public RVA = 0x53BAE0
    void _DESTRUCTOR();// public RVA = 0x53BAE0
    void add(GameData* conversation, DialogLineData* parent);// public RVA = 0x551C40
    // no_addr class DialogChoiceList & operator=(const class DialogChoiceList & _a1);// public missing arg names
    // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
};

class CharStats;
class CharMovement;
class GameData;
class Character;
class DatapanelGUI;
class Faction;

class Dialogue
{
public:
    class RepetitionCounter
    {
    public:
        class DialogState
        {
        public:
            DialogState();// public RVA = 0x520D40
            int count; // 0x0 Member
            float lastTimeStamp; // 0x4 Member
            float resetTime; // 0x8 Member
        };
        std::map<EventTriggerEnum, Dialogue::RepetitionCounter::DialogState, std::less<EventTriggerEnum>, Ogre::STLAllocator<std::pair<EventTriggerEnum const, Dialogue::RepetitionCounter::DialogState>, Ogre::GeneralAllocPolicy > > states; // 0x0 Member
        void setup();// public RVA = 0x5222D0
        bool count(EventTriggerEnum ev);// public RVA = 0x522220
        double getTimeSinceLastTrigger(EventTriggerEnum ev);// public RVA = 0x522280
        int getCount(EventTriggerEnum ev);// public RVA = 0x54AD60
        // no_addr void resetCount(enum EventTriggerEnum);// public
        // no_addr void RepetitionCounter(const class Dialogue::RepetitionCounter &);// public
        RepetitionCounter();// public RVA = 0x54BEB0
        ~RepetitionCounter();// public RVA = 0x54BED0
        // no_addr class Dialogue::RepetitionCounter & operator=(const class Dialogue::RepetitionCounter &);// public
        // no_addr void * __vecDelDtor(unsigned int);// public
    };
    Dialogue::RepetitionCounter repCounter; // 0x0 Member
    std::string getWordSwap(const std::string& key, Character* _target, bool, DialogLineData* _line);// private RVA = 0x529FF0
    void setupWordSwaps();// private RVA = 0x52DD80
    void _insertWordSwapsRecurse(std::string& text, Character* target, bool swapMe, DialogLineData* _line);// private RVA = 0x52E120
    bool _needsDynamicAssessments; // 0x28 Member
    std::map<DialogLineData*, bool, std::less<DialogLineData*>, Ogre::STLAllocator<std::pair<DialogLineData* const, bool>, Ogre::GeneralAllocPolicy > > locked; // 0x30 Member
    std::string sayMsg; // 0x58 Member
    enum DT_MSG
    {
        DT_NONE,
        DT_END_DIALOG,
        DT_OPENWINDOW,
        DT_CLOSEWINDOW,
        DT_CLEAR_RESPONSES,
        DT_SET_RESPONSES,
        DT_SET_NPC_REPLY
    };

    Ogre::vector<Dialogue::DT_MSG>::type threadMessages; // 0x80 Member
    // no_addr void Dialogue(const class Dialogue &);// public
    Dialogue();// public RVA = 0x5237F0
    ~Dialogue();// public RVA = 0x5249A0
    void insertWordSwaps(std::string& text, Character* target, bool swapMeYou, DialogLineData* line);// public RVA = 0x52E370
    void getGUIData(DatapanelGUI* datapanel, int cat);// public RVA = 0x49D040
    void create(Character* c, CharStats* s, CharMovement* m);// public RVA = 0x520E40
    hand getHandle() const;// public RVA = 0x5214B0
    Character* getCharacter();// public RVA = 0x520D50
    void setLineLocked(DialogLineData* line, bool on);// public RVA = 0x54AD80
    bool isLocked(DialogLineData* line);// public RVA = 0x54ADB0
    void setInDialog(bool on);// public RVA = 0x524160
    void clearDialogues();// public RVA = 0x523680
    void clearAnnouncements();// public RVA = 0x522300
    std::set<GameData*, std::less<GameData*>, Ogre::STLAllocator<GameData*, Ogre::GeneralAllocPolicy > > pacakgesIHave; // 0xA0 Member
    bool needsDialogAssessmentUpdate() const;// public RVA = 0x5213E0
    void addDialoguePackage(GameData* _con);// public RVA = 0x52F570
    void addConversation(GameData* _con, EventTriggerEnum t);// public RVA = 0x52DCE0
    void clearConversationList(EventTriggerEnum t);// public RVA = 0x522200
    bool willTalkToEnemies();// public RVA = 0x522D20
    DialogLineData* playerInterruptionDialog; // 0xC8 Member
    bool sendEventOverride(Character* who, EventTriggerEnum what, bool forceRepeat);// public RVA = 0x5350E0
    bool sendEvent(Character* who, EventTriggerEnum what);// public RVA = 0x534410
    void stopEvent(EventTriggerEnum what);// public RVA = 0x524920
    bool runCustomDialog(GameData* dialog);// public RVA = 0x5347F0
    int scoreCustomDialog(GameData* dialog);// public RVA = 0x52DB20
    bool conversationHasEnded() const;// public RVA = 0x521720
    hand getConversationTarget();// public RVA = 0x6AF080
    void changeConversationTarget(Character* c);// public RVA = 0x5213F0
    bool conversationHasEndedPrettyMuch() const;// public RVA = 0x521490
    bool makeAnnouncement(GameData* dat);// public RVA = 0x5351D0
    void update(float frameTime);// public RVA = 0x534B10
    void endDialogue(bool definitelyTheEnd);// public RVA = 0x5242F0
    void notifyUnderAttack(Character* attacker);// public RVA = 0x535040
    bool hasDialogue_Fast();// public RVA = 0x5223E0
    bool hasDialogue_Accurate();// public RVA = 0x52A510
    bool hasDialogueEvent(EventTriggerEnum e);// public RVA = 0x5224F0
    void say(DialogLineData* dialogLine);// private RVA = 0x533390
    void say(const std::string& _text, DialogLineData* line);// public RVA = 0x52F840
    bool dialogDelivered(EventTriggerEnum e);// public RVA = 0x5232F0
    bool _checkCondition(DialogConditionEnum conditionName, ComparisonEnum compareBy, int val, Character* target, Character* actualConversationTarget);// public RVA = 0x526410
    void dontLetTargetBeMe(Character** target, Character* actualTarget);// public RVA = 0x521280
    bool isAtTownOf(const std::set<Faction*, std::less<Faction*>, Ogre::STLAllocator<Faction*, Ogre::GeneralAllocPolicy > >& f);// public RVA = 0x60D650
    bool hasThisChanceLine(DialogLineData* line, float chance);// public RVA = 0x522520
    DialogLineData* _chooseDialog(DialogChoiceList* list, Character* target, bool isWordswap);// public RVA = 0x529B80
    void triggerNextLine(DialogLineData* previousLine);// public RVA = 0x5341A0
    bool targetInTalkingRange(Character* target, float mult);// public RVA = 0x5211B0
    void save(GameData* to);// public RVA = 0x5293C0
    void load(GameData* to);// public RVA = 0x52F240
    void replyClicked(const std::string& index);// private RVA = 0x533680
    void replyClicked(int index);// public RVA = 0x533870
    Character* getSpeaker(TalkerEnum who, DialogLineData* line, bool isForWordswaps);// public RVA = 0x5226B0
    bool isCurrentConversationRunning(DialogLineData* line) const;// public RVA = 0x53C020
    static void resolveOverlappedSpeechBubbles();// public RVA = 0x521A10
    void _wordSwapCharacterName(std::string& name);// public RVA = 0x4E0070
    std::map<EventTriggerEnum, float, std::less<EventTriggerEnum>, Ogre::STLAllocator<std::pair<EventTriggerEnum const, float>, Ogre::GeneralAllocPolicy > > eventRepeatTimers; // 0xD0 Member
    std::map<EventTriggerEnum, hand, std::less<EventTriggerEnum>, Ogre::STLAllocator<std::pair<EventTriggerEnum const, hand>, Ogre::GeneralAllocPolicy > > eventDeliveredStates; // 0xF8 Member
    Character* findInterjectionCharacter(DialogLineData* line);// private RVA = 0x529680
    bool isKOExempt(EventTriggerEnum what);// private RVA = 0x520D60
    std::map<DialogLineData*, bool, std::less<DialogLineData*>, Ogre::STLAllocator<std::pair<DialogLineData* const, bool>, Ogre::GeneralAllocPolicy > > _hasChanceLines; // 0x120 Member
    void _endPlayerConversation(bool finished);// private RVA = 0x524990
    bool startPlayerConversation(Character* target, DialogLineData* _talk);// private RVA = 0x533DA0
    bool startConversation(Character* target, DialogLineData* _talk, EventTriggerEnum ev, bool force);// private RVA = 0x533A10
    bool _hasEnded; // 0x148 Member
    bool shouting; // 0x149 Member
    bool staysOnScreen; // 0x14A Member
    Character* me; // 0x150 Member
    hand conversationTarget; // 0x158 Member
    CharStats* stats; // 0x178 Member
    CharMovement* movement; // 0x180 Member
    EventTriggerEnum currentConversationType; // 0x188 Member
    DialogLineData* currentConversation; // 0x190 Member
    DialogLineData* currentLine; // 0x198 Member
    DialogChoiceList* getConversationList(EventTriggerEnum t);// private RVA = 0x522180
    std::map<EventTriggerEnum, DialogChoiceList*, std::less<EventTriggerEnum>, Ogre::STLAllocator<std::pair<EventTriggerEnum const, DialogChoiceList*>, Ogre::GeneralAllocPolicy > > conversationsMain; // 0x1A0 Member
    void _doActions(DialogLineData* dialogLine);// private RVA = 0x530020
    bool sayLine(DialogLineData* line);// private RVA = 0x533420
    void listPlayerReplies();// private RVA = 0x52FBF0
    bool isLastLine(DialogLineData* dialogLine);// private RVA = 0x520F80
    void setSpeaker(TalkerEnum who, Character* c);// private RVA = 0x520EF0
    hand interjector1; // 0x1C8 Member
    hand interjector2; // 0x1E8 Member
    hand interjector3; // 0x208 Member
    void _updateTextPos();// private RVA = 0x521DE0
    void clearSpeechBox();// private RVA = 0x521D90
    void clearRespones();// private RVA = 0x5246E0
    void clearResponesGUI();// private RVA = 0x523A40
    void setResponesGUI();// private RVA = 0x523B30
    void setConversationReplyGUI();// private RVA = 0x523C30
    DialogueSpeechBubble* speechBubblePanel; // 0x228 Member
    float speechTextTimer; // 0x230 Member
    float speechTextTimer_forced; // 0x234 Member
    Ogre::vector<std::string>::type replyIds; // 0x238 Member
    Ogre::vector<std::string>::type responses; // 0x258 Member
    std::string npcReplyText; // 0x278 Member
    hand conversationMaster; // 0x2A0 Member
    hand waitingForReplyFrom; // 0x2C0 Member
    // TODO
    static ogre_unordered_set<DialogueSpeechBubble*>::type speechBubbleList; // Static Member
    // no_addr class Dialogue & operator=(const class Dialogue &);// public
    // no_addr void * __vecDelDtor(unsigned int);// public
};

class WorldEventStateQueryList;

class DialogDataManager
{
public:
    static ogre_unordered_map<GameData*, DialogLineData*>::type allDatas; // RVA = 0x18EEC90 Static Member
    static GameData* saveData; // RVA = 0x1AC61C0 Static Member
    static DialogLineData* _createData(GameData* d);// private RVA = 0x551AD0
    static void initialise();// private RVA = 0x52D390
    static void save(GameData* d);// public RVA = 0x2C2AD0
    static void load(GameData* d);// public RVA = 0x2C2BA0
    static void newGameReset();// public RVA = 0x2C0E20
    static DialogLineData* getData(GameData* d);// public RVA = 0x551B50
};
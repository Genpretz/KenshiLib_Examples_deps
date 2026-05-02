#pragma once

#include <ogre/OgreVector3.h>
#include "Enums.h"
#include "util/hand.h"

class CharBody;
class AI;

// TODO move?
enum taskPriority
{
    TP_JUST_ACTION,
    TP_FLUFF,
    TP_NON_URGENT,
    TP_URGENT,
    TP_OBEDIENCE,
    TP_MAX_SIZE
};

// TODO move?
enum StateType
{
    NONE_RESULT,
    AT_LOCATION,
    BUILDING_COMPLETE,
    SUBJECT_IN_INVENTORY,
    HAS_WEAPON,
    HAS_WEAPON_EQUIPPED,
    NO_ENEMIES_IN_VICINITY,
    TARGET_DOWN,
    WEAPON_AS_TARGET,
    HOSTILE_APPROACHING,
    UNDER_MELEE_ATTACK,
    UNDER_RANGED_ATTACK,
    ALLIES_UNDER_ATTACK,
    TARGETED_ENEMY,
    TARGETED_ATTACKER_OF_ALLY,
    ITEM_IS_PHYSICALLY_LOOTABLE,
    AGGRESSION_TOWARDS_TARGET,
    AM_IDLE,
    AT_HOME_BUILDING,
    VILLAGE_RAZED,
    NONE_REQUIREMENT,
    CHARACTER_HEALTH_IN_DANGER,
    NEEDS_FIRST_AID,
    HAS_FIRST_AID_KIT,
    IS_CROUCHING,
    IS_LYING,
    IS_CROUCHING_OR_LYING,
    MOVEMENT_ALLOWED,
    NEAR_TO,
    GENERAL_AGGRESSION_LEVEL,
    NODE_UNOCCUPIED_BY_OTHERS,
    AT_NODE,
    HAS_VALID_TARGET_TOWN,
    TIRED,
    FOLLOW_ME_MODE,
    HAS_ENOUGH_GUARDS,
    AT_TARGET_TOWN,
    READY_FOR_MELEE_ACTION,
    HAS_ONE_WORKING_ARM,
    AGGRESSION_TOWARDS_ME,
    WITHIN_10_METERS,
    WITHIN_50_METERS,
    TARGET_STANDING_STILL,
    I_AM_DOWN,
    WANTS_TO_GET_UP,
    CAN_GET_UP,
    AT_LOCATION_ASAP,
    IS_CARRYING_SOMETHING,
    IS_CARRYING_TARGET,
    PLAYER_FORCES_GET_UP,
    HAS_SOME_BUILDING_MATERIALS,
    BUILDING_HAS_SOME_BUILDING_MATERIALS,
    DOOR_IS_OPEN,
    DOOR_IS_OPEN_HERE,
    DOOR_IS_LOCKED,
    DOOR_IS_LOCKED_HERE,
    DOOR_IS_BROKEN,
    AT_LOCATION_BUILDING_DOOR,
    AT_CURRENT_LOCATION_BUILDING_DOOR,
    DESTINATION_IS_ACCESSIBLE,
    LOCATION_IS_ACCESSIBLE,
    INVENTORY_FULL_OF_RESOURCES,
    MACHINES_INPUTS_EMPTY,
    MACHINES_OUTPUTS_FULL,
    MACHINE_IS_JAMMED,
    ANY_MACHINES_JAMMED,
    HAVE_SOME_RESOURCES_FROM,
    HAVE_SOME_RESOURCES_FOR,
    HAVE_SOME_LOOT_FROM,
    ROUTE_IS_BLOCKED,
    I_OWN_OBJECT,
    BUILDING_IS_DAMAGED,
    IS_FULLY_RESTED,
    MACHINE_HAS_FREE_OPERATOR_SLOT,
    ENEMY_FORCE_DEFEATED,
    MY_FORCE_DEFEATED,
    MESSAGE_DELIVERED,
    CARRIED_DUDE_NOW_IN_BED,
    TARGET_IS_IMPRISONED,
    I_AM_IMPRISONED,
    CARRYING_ARM_IS_OK,
    CARRIED_DUDE_NOW_IN_CAGE,
    GOT_INVENTORY_ROOM_FOR_RESOURCES,
    I_AM_IN_BED,
    AT_A_SHOP,
    BOUGHT_SHIT,
    AT_A_TOWN,
    ALL_DOORS_LOCKED_UP,
    INSIDE_BUILDING,
    HAVE_SOME_RESOURCES_FROM_THIS_MACHINE_BUT_WANT_THEM_GONE_IF_POSSIBLE,
    DESTINATION_NOT_BLOCKED_BY_FORTIFICATIONS,
    AT_LOCATION_FORTIFICATION_GATE,
    IS_ENEMY,
    BUILDING_HAS_POWER,
    AT_TARGET_TOWN_FAST,
    AT_HOME_TOWN,
    TARGET_IS_FREE,
    CAGES_ARE_ALL_FULL,
    MACHINE_OCCUPANT_IS_ALIVE,
    CARRYING_A_DEAD_GUY,
    CARRIED_DUDE_NOW_IN_DISPOSAL_MACHINE,
    LEADER_IS_DOWN,
    SQUAD_UNDER_ATTACK,
    MY_LEGS_MESSED_UP,
    USING_TARGET_TURRET,
    MACHINES_OUTPUTS_EMPTY,
    MACHINES_INPUTS_FULL,
    I_AM_INSIDE_TARGET_BUILDING,
    STRANGERS_INSIDE_MY_BUILDING,
    SPOKEN_TO,
    SPOKEN_TO_WITHOUT_MOVING,
    AT_LOCATION_BUILDING_DOOR_INSIDE,
    DOOR_IS_LOCKED_AND_IM_INSIDE,
    TARGET_IN_TOWN,
    TARGET_CUFFS_ARE_LOCKED,
    IS_CARRYING_TARGET_HEALTHY,
    TARGET_IS_MY_SLAVE,
    TARGET_HAS_BEEN_LOOTED,
    TARGET_IS_UNARMED,
    TARGET_IS_SURRENDERED,
    TARGET_LOOKS_LIKE_A_SLAVE,
    CARRYING_EXCESS_LOOT,
    HAS_TOOLS,
    IS_WORKING,
    TARGET_IS_ESCAPEE_OR_FREE,
    TARGET_IS_CONSCIOUS,
    AT_LOCATION_BUILDING_DOOR_OUTSIDE,
    DOOR_IS_LOCKED_AND_IM_OUTSIDE,
    IS_ALLY,
    TARGET_IS_ARRESTED,
    ALARMS_IN_THE_VICINITY,
    AT_PACKAGE_TARGET,
    HAS_REPAIR_KIT,
    NEEDS_REPAIR_ROBOT,
    TARGET_IS_WEARING_CUFFS,
    TARGET_IS_EATEN,
    IS_WORKING_PRETEND,
    INTRUDER_IS_OUTSIDE_BUILDING,
    AT_A_TOWN_FOR_SLAVE_SELLING,
    IM_SWIMMING,
    TARGET_SWIMMING,
    STRANGERS_INSIDE_MY_BUILDING_AND_ITS_PRIVATE,
    TARGET_IS_RESTRAINED_OR_KO,
    TARGET_FARM_HAS_FOOD,
    AM_HUNGRY,
    IS_USING_ANY_TURRET,
    TARGET_WORSHIPPED,
    DITCHED_ALL_RESOURCES,
    LOOTED_STORABLE_ITEMS,
    GOT_A_FOOD_ITEM,
    HAVE_SOME_BUILD_MATS,
    HAS_SPLINT_KIT,
    NEEDS_SPLINT,
    FINAL_GOT_A_KIDNAP_VICTIM,
    FINAL_FOUND_AND_PUT_CARRIED_IN_A_CAGE,
    I_HAVE_SOME_SLAVES,
    HAS_CROSSBOW_EQUIPPED,
    HAS_ANYTHING_EQUIPPED,
    I_AM_BEING_MELEE_ATTACKED_IMMEDIATELY,
    I_AM_BEING_MELEE_ATTACKED_INCOMING,
    WITHIN_MY_BOW_RANGE,
    HAS_TWO_WORKING_ARMS,
    I_AM_PRONE,
    BUILDING_IS_DESTROYED,
    INTRUDER_IS_OUTSIDE_GATES,
    CROWD_LIMIT_8_PEOPLE,
    I_HAVE_SUFFICIENT_LOCK_SKILL,
    I_HAVE_SUFFICIENT_LOCK_SKILL_FOR_SHACKLES,
    DESTINATION_IS_ACCESSIBLE_ANIMAL,
    MACHINE_HAS_INVALID_INPUTS
};

// TODO move?
class TaskStateData
{
public:
    TaskStateData(StateType _key, bool _val, bool progression);// public RVA = 0x60DDA0
    TaskStateData* _CONSTRUCTOR(StateType _key, bool _val, bool progression);// public RVA = 0x60DDA0
    TaskStateData();// public RVA = 0x60DD80
    TaskStateData* _CONSTRUCTOR();// public RVA = 0x60DD80
    // no_addr bool operator bool();// public
    StateType key; // 0x0 Member
    bool val; // 0x4 Member
    bool progressionOnly; // 0x5 Member
};

class function;

// TODO move?
enum PermajobType
{
    NOT_A_PERMAJOB,
    PERMAJOB_NORMAL,
    PERMAJOB_HIGHCOMBAT
};

// TODO move?
class TaskData : public Ogre::GeneralAllocatedObject
{
public:
    // Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<0> > offset = 0x0, length = 0x1
    // no_addr void TaskData(const class TaskData & _a1);// public missing arg names
    TaskData(TaskType namekey, function* scoreFunc, bool actionFunc, bool _needTarget);// private RVA = 0x61CBD0
    TaskData* _CONSTRUCTOR(TaskType namekey, function* scoreFunc, bool actionFunc, bool _needTarget);// private RVA = 0x61CBD0
    void addResult(StateType s, bool val, bool progressional);// private RVA = 0x60DF90
    void addRequirement(StateType s, bool val, bool progressional);// private RVA = 0x60E1C0
    void setCharacteristics(float _aid, float _aggressionLevel, float noise, bool leadsSomewhere);// private RVA = 0x317610
    void setInfrequentGoalChecks();// private RVA = 0x317630
    bool infrequentGoalChecks; // 0x0 Member
    void setAlertnessMult(float a);// private RVA = 0x317640
    void setRequirementsCantEndActionPrematurely(bool on);// private RVA = 0x317650
    void setCopyMeInfluence(float weight);// private RVA = 0x317660
    void setFollowMeWeight(float weight);// private RVA = 0x317670
    PermajobType permaJob; // 0x4 Member
    bool permaJob_FixedTarget; // 0x8 Member
    TaskType permaJob_Associated; // 0xC Member
    TaskType permaJob_Associated_Secondary; // 0x10 Member
    bool requirementsAlwaysFalse; // 0x14 Member
    bool _resultsAlwaysFalse; // 0x15 Member
    bool _requirementsCantEndActionPrematurely; // 0x16 Member
    void setSelfRegulation(bool requirements, bool results);// private RVA = 0x317680
    void setDurationBased(float mintime, float fuzz, bool _endsAfterTime);// private RVA = 0x317690
    float durationMin; // 0x18 Member
    float durationFuzz; // 0x1C Member
    bool isDurationBased; // 0x20 Member
    bool endsAfterTime; // 0x21 Member
    bool isUnstoppableTask; // 0x22 Member
    bool canDoTaskInStages; // 0x23 Member
    bool hasInfrequentGoalChecks() const;// public RVA = 0x50B9B0
    bool getRequirementsCantEndActionPrematurely() const;// public RVA = 0x50B9C0
    void setPermaJob(PermajobType on, bool fixedTarget, TaskType t, TaskType secondary);// public RVA = 0x3176B0
    PermajobType getPermaJobType() const;// public RVA = 0x50B9D0
    bool isPermaJob() const;// public RVA = 0x32D900
    bool isPermaJobFixedTarget() const;// public RVA = 0x506360
    TaskType getPermaJobAssociation() const;// public RVA = 0x506370
    TaskType getPermaJobAssociation_secondary() const;// public RVA = 0x506380
    float aggressionLevel; // 0x24 Member
    float noisyness; // 0x28 Member
    float aidLevel; // 0x2C Member
    float followMeWeight; // 0x30 Member
    float copyMeInfluence; // 0x34 Member
    bool normallyLeadsToSomething; // 0x38 Member
    float alertnessMult; // 0x3C Member
    bool forDirectPlayerOrdersOnly; // 0x40 Member
    bool forFulfillPlayerOrdersOrNPCOnly; // 0x41 Member
    TaskType key; // 0x44 Member
    bool needsTarget; // 0x48 Member
    int numResults; // 0x4C Member
    TaskStateData results[0xB]; // 0x50 Member
    // no_addr bool fulfillsResult(enum StateType _a1);// public missing arg names
    int numRequirements; // 0xA8 Member
    TaskStateData requirements[0xB]; // 0xAC Member
    function* scoreFunction; // 0x108 Member
    // no_addr bool isJob();// public
    bool isResultsComplete(AI* ai, const hand& target, const hand& subTarget, const Ogre::Vector3& location);// public RVA = 0x60EDF0
    bool isResultsComplete_ignoreSubtasker(AI* ai, const hand& target, const hand& subTarget, const Ogre::Vector3& location);// public RVA = 0x60E940
    void getRequirementComplaint(std::string& out, AI* ai, const hand& target, const Ogre::Vector3& location, const hand& subTarget, bool autoTargetFinder);// public RVA = 0x60F8A0
    bool _isRequirementsComplete(AI* ai, const hand& target, const Ogre::Vector3& location, hand& subTarget, bool autoTargetFinder, StateType& failedOn);// public RVA = 0x60F1C0
    bool isRequirementComplete(AI* ai, const hand& obj, int req, const Ogre::Vector3& location);// public RVA = 0x60E040
    void setTargetingFunction(function* finder, bool justNeedOne);// public RVA = 0x3176D0
    bool justDoOneTarget; // 0x120 Member
    bool isTargetFinder() const;// public RVA = 0x50B9E0
    void setSubTask(StateType state, bool required);// public RVA = 0x60DFC0
    TaskStateData* subTask; // 0x128 Member
    void setDialogueDeliveryTag(EventTriggerEnum d);// public RVA = 0x317710
    EventTriggerEnum dialogueDelivery; // 0x130 Member
    bool hasAction; // 0x134 Member
    std::string description; // 0x138 Member
    float runTargetFind(AI* ai, const hand& _target, hand& out, bool justAsking);// public RVA = 0x60ECE0
    bool _targetsRemaining(AI* ai, const hand& _target);// public RVA = 0x50B9F0
    function* _findTarget; // 0x160 Member
    // no_addr void ~TaskData();// public
    // no_addr class TaskData & operator=(const class TaskData & _a1);// public missing arg names
    // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
};

class Tasker : public Ogre::GeneralAllocatedObject
{
public:
    // Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<0> > offset = 0x8, length = 0x1
    // VTable         : (none)
    // no_addr void Tasker(const class Tasker & _a1);// public missing arg names
    Tasker();// protected RVA = 0x32D910
    Tasker* _CONSTRUCTOR();// protected RVA = 0x32D910
    virtual ~Tasker();// public RVA = 0x32D9D0 vtable offset = 0x0
    void _DESTRUCTOR();// public RVA = 0x32D9D0 vtable offset = 0x0
    bool checkTimeOfDay();// public RVA = 0x50C1D0
    float getFrameTime(CharBody* b);// public RVA = 0x32DB20
    // no_addr class Tasker & operator=(const class Tasker & _a1);// public missing arg names
    // no_addr class Tasker & operator=(int _a1);// public missing arg names
    // no_addr bool operator==(const class Tasker & _a1);// public missing arg names
    // no_addr bool operator!=(const class Tasker & _a1);// public missing arg names
    // no_addr bool operator bool();// public
    TaskType key() const;// public RVA = 0x2680D0
    bool unSkippableJob() const;// public RVA = 0x50BA40
    taskPriority priority; // 0x8 Member
    bool resetsWhenDone; // 0xC Member
    hand subject; // 0x10 Member
    Ogre::Vector3 getLocation() const;// public RVA = 0x3319E0
    void setLocation(const Ogre::Vector3& loc);// public RVA = 0x32D9F0
    // no_addr bool isTargetFinder();// public
    bool sameAs(Tasker* t) const;// public RVA = 0x506390
    const std::string& getDescription() const;// public RVA = 0x506430
    float weight; // 0x30 Member
    float score(AI* ai);// public RVA = 0x60F600
    bool isResultsComplete(AI* ai);// public RVA = 0x5137D0
    bool isResultsComplete_ignoreSubtasker(AI* ai);// public RVA = 0x50BBC0
    // no_addr bool isRequirementsComplete(class AI * _a1, bool _a2, enum StateType & _a3);// public missing arg names
    bool isRequirementsComplete(AI* ai, bool autoTargetFinder);// public RVA = 0x50BBF0
    std::string getRequirementComplaint(AI* ai, bool autoTargetFinder);// public RVA = 0x519920
    // no_addr bool isRequirementComplete(class AI * _a1, int _a2);// public missing arg names
    bool hasActionFunc() const;// public RVA = 0x50BC40
    bool isSubTasker() const;// public RVA = 0x50BC60
    hand getNextSubTarget(AI* ai);// public RVA = 0x50CF40
    // no_addr const class hand & getCurrentSubTarget();// public
    TaskStateData* getSubTask() const;// public RVA = 0x50BC80
    // no_addr bool isSingleTargetSubTasker();// public
    bool isSubTaskerTargetFinishedWith(AI* ai, const hand& target);// public RVA = 0x50C120
    // no_addr bool isPlaceholder();// public
    bool isInfiniteGoal() const;// public RVA = 0x50BC90
    bool needsSubjectOrLocation() const;// public RVA = 0x2680E0
    const TaskData* const getTaskData() const;// public RVA = 0x32DA00
    hand currentSubTarget; // 0x38 Member
    Ogre::Vector3 location; // 0x58 Member
    virtual void startAction(CharBody* _a1);// public RVA = 0x32DA10 vtable offset = 0x8 missing arg names
    void _NV_startAction(CharBody* _a1);// public RVA = 0x32DA10 vtable offset = 0x8 missing arg names
    virtual void runAction(CharBody* _a1) = 0;// public vtable offset = 0x10 missing arg names
    virtual void endAction(CharBody* _a1);// public RVA = 0x32DA20 vtable offset = 0x18 missing arg names
    void _NV_endAction(CharBody* _a1);// public RVA = 0x32DA20 vtable offset = 0x18 missing arg names
    virtual bool taskSaysItsFinished(Character* me) const;// public RVA = 0x32DA30 vtable offset = 0x20
    bool _NV_taskSaysItsFinished(Character* me) const;// public RVA = 0x32DA30 vtable offset = 0x20
    int startTime; // 0x64 Member
    int endTime; // 0x68 Member
    TaskData* taskData; // 0x70 Member
    float findTarget(AI* ai, hand& out);// protected RVA = 0x50BCA0
    bool _targetsRemaining(AI* ai);// protected RVA = 0x50BCD0
    bool isSubTaskerComplete(AI* ai);// protected RVA = 0x50C160
    // no_addr void __local_vftable_ctor_closure();// public
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x0 missing arg names
};
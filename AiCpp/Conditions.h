#pragma once
#include <iostream>

//---------------------Conditions
class Condition
{
public:
	virtual bool IsTriggered()
	{
		return false;
	};
};

enum class FloatConditionTypes
{
	superior,
	inferior,
	superior_equal,
	inferior_equal,
	between,

};

class FloatCondition : public Condition
{
public:
	FloatCondition(FloatConditionTypes typeP,float minValueP, float maxValueP, float* valueToCheckP) : type(typeP), minValue(minValueP), maxValue(maxValueP), valueToCheck( valueToCheckP)
	{};

	virtual bool IsTriggered()
	{
		switch (type)
		{
		case FloatConditionTypes::superior:
			if (minValue < *valueToCheck)
			{
				return true;
			}
			return false;
			break;
		case FloatConditionTypes::inferior:
			if (*valueToCheck < maxValue)
			{
				return true;
			}
			return false;

			break;
		case FloatConditionTypes::superior_equal:
			if (minValue <= *valueToCheck)
			{
				return true;
			}
			return false;
			break;
		case FloatConditionTypes::inferior_equal:
			if (*valueToCheck <= maxValue)
			{
				return true;
			}
			return false;
			break;
		case FloatConditionTypes::between:
			if (minValue < *valueToCheck && *valueToCheck < maxValue)
			{
				return true;
			}
			return false;

			break;
		default:
			break;
		}

		//std::cout << *valueToCheck << std::endl;

	};

private:
	FloatConditionTypes type;
	float minValue;
	float maxValue;
	float* valueToCheck = nullptr;

};

class BoolCondition : public Condition
{
public:
	BoolCondition(bool* valueP): value(valueP) {};

	virtual bool IsTriggered()
	{
		//std::cout << *value << std::endl;
		return *value;
	};
private:
	bool* value{ nullptr };

};

class AndContidion : public Condition
{
public:
	AndContidion(Condition conditionA, Condition conditionB) : condA(conditionA), condB(conditionB)
	{};

	virtual bool IsTriggered()
	{
		return condA.IsTriggered() and condB.IsTriggered();
	};

private:
	Condition condA;
	Condition condB;

};

class OrContidion : public Condition
{
public:
	OrContidion(Condition conditionA, Condition conditionB) : condA(conditionA), condB(conditionB)
	{};

	virtual bool IsTriggered()
	{
		return condA.IsTriggered() or condB.IsTriggered();
	};

private:
	Condition condA;
	Condition condB;

};

class NotContidion : public Condition
{
public:
	NotContidion(Condition* conditionA) : condA(conditionA)
	{};

	virtual bool IsTriggered()
	{
		return not condA->IsTriggered();
	};

private:
	Condition* condA;

};
//----------------------------------------------


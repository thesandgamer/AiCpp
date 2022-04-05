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

class FloatCondition : public Condition
{
public:
	FloatCondition(float minValueP, float maxValueP, float* valueToCheckP) : minValue(minValueP), maxValue(maxValueP), valueToCheck( valueToCheckP)
	{};

	virtual bool IsTriggered()
	{
		std::cout << *valueToCheck << std::endl;
		if (minValue< *valueToCheck && *valueToCheck < maxValue)
		{
			return true;
		}
		return false;
	};

private:
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
		std::cout << *value << std::endl;
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
	NotContidion(Condition conditionA) : condA(conditionA)
	{};

	virtual bool IsTriggered()
	{
		return not condA.IsTriggered();
	};

private:
	Condition condA;
	Condition condB;

};
//----------------------------------------------


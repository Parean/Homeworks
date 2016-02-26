#pragma once

class List
{
public:
    virtual void addValue(int value) = 0;
    virtual int findPositionOfValue(int value) const = 0;
    virtual bool removeValue(int value) = 0;
    virtual bool isEmpty() const = 0;
    virtual int length() const = 0;
    virtual ~List() {}
};

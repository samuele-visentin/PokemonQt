#ifndef STATUS_H
#define STATUS_H

#include <string>
#include <QDataStream>

class Pokemon;

class Status {
private:
    std::string _name;
    int _probability;
protected:
    int _duration;
public:
    Status(const std::string& name, int probability, int duration);
    virtual ~Status() = default;
    std::string getName() const;
    unsigned getDuration() const; 
    int getProbability() const;
    bool isFinish() const;
    virtual int statusEffect()=0;
    virtual Status* clone() const=0;
    virtual bool canAttack() const=0;
};

#endif // STATUS_H

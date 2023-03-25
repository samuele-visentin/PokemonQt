#ifndef TYPE_H
#define TYPE_H

#include <string>

class Type {
private:
    std::string name;
    Type(const std::string& n);
public:
    std::string getName() const;
    static const Type normal;
    static const Type fire;
    static const Type water;
    static const Type grass;
    static const Type electro;
};

#endif // TYPE_H

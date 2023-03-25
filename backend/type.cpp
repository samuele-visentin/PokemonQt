#include "type.h"

Type::Type(const std::string& s) : name(s){}

std::string Type::getName() const {
    return name;
}

const Type Type::normal("Normale");
const Type Type::fire("Fuoco");
const Type Type::water("Acqua");
const Type Type::grass("Erba");
const Type Type::electro("Elettricità");

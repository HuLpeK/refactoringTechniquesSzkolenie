#pragma once
#include <ostream>
class ID{
public:
    ID();

    bool operator==(const ID& lhs) const;

    friend std::ostream& operator<<(std::ostream& out, const ID& player);
private:

    int actId;
};
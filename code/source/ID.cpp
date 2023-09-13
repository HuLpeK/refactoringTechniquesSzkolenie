#include "../includes//ID.hpp"

ID::ID() {
    static int currId = 0;
    actId = currId++;
}

bool ID::operator==(const ID &lhs) const {
    return actId == lhs.actId;
}

std::ostream &operator<<(std::ostream &out, const ID &player) {
    return out << player.actId;
}



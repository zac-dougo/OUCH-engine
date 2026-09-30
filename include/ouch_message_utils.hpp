#pragma once

#include <array>

struct RegulatoryData {
    char participant_capacity{};
    char directed_wholesale{};
    std::array<char, 4> execution_venue{}; // Not applicable on OUCH; pad with ASCII spaces.
    std::array<char, 10> intermediary_id{};
    std::array<char, 20> order_origin{};
    std::array<char, 8> filler{}; // Ignore.
};

#pragma once

#include <array>
#include <cstdint>

#include "ouch_message_utils.hpp"

struct OrderAcceptedMsg {
    char message_type{};
    std::uint64_t timestamp{};
    std::array<char, 14> order_token{};
    std::uint32_t order_book_id{};
    char side{};
    std::uint64_t order_id{};
    std::uint64_t quantity{};
    std::uint32_t price{};
    std::uint8_t time_in_force{};
    std::uint8_t open_close{}; // Not used by ASX; ignore.
    std::array<char, 10> client_account{};
    std::uint8_t order_state{};
    std::array<char, 15> customer_info{};
    std::array<char, 32> exchange_info{};
    char clearing_participant{};
    std::int32_t crossing_key{};
    RegulatoryData regulatory_data{};
    char ouch_order_type{};
    std::uint32_t short_sell_quantity{};
    std::uint32_t minimum_acceptable_quantity{};
};

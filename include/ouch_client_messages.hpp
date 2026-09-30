#pragma once

#include <array>
#include <cstdint>

#include "ouch_message_utils.hpp"

struct EnterOrderMsg {
    char message_type{};
    std::array<char, 14> order_token{};
    std::uint32_t order_book_id{};
    char side{};
    std::uint64_t quantity{};
    std::int32_t price{};
    std::uint8_t time_in_force{};
    std::uint8_t open_close{}; // Not used by ASX; pad with zeros.
    std::array<char, 10> client_account{}; // Ultimate client making the order.
    std::array<char, 15> customer_info{}; // Customer's order identifier.
    std::array<char, 32> exchange_info{}; // Free text at the customer's discretion.
    char clearing_participant{};
    std::int32_t crossing_key{};
    RegulatoryData regulatory_data{};
    char ouch_order_type{};
    std::uint64_t short_sell_quantity{};
    std::uint64_t minimum_acceptable_quantity{};
};

struct ReplaceOrderMsg {
    char message_type{};
    std::array<char, 14> order_token{}; // Any order token previously used for this trade.
    std::uint32_t order_book_id{};
    char side{};
    std::uint64_t quantity{};
    std::int32_t price{};
    std::uint8_t time_in_force{};
    std::uint8_t open_close{}; // Not used by ASX; pad with zeros.
    std::array<char, 10> client_account{}; // Ultimate client making the order.
    std::array<char, 15> customer_info{}; // Customer's order identifier.
    std::array<char, 32> exchange_info{}; // Free text at the customer's discretion.
    char clearing_participant{};
    std::int32_t crossing_key{};
    RegulatoryData regulatory_data{};
    char ouch_order_type{};
    std::uint64_t short_sell_quantity{};
    std::uint64_t minimum_acceptable_quantity{};
};

struct CancelOrderMsg {
    char message_type{};
    std::array<char, 14> order_token{}; // Any order token previously used for this trade.
};

struct CancelByOrderIdMsg {
    char message_type{};
    std::uint32_t order_book_id{};
    char side{};
    std::uint64_t order_id{}; // Returned by ASX.
};

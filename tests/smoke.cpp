#include "ouch_client_messages.hpp"
#include "ouch_client_messages.hpp"
#include "ouch_host_messages.hpp"
#include "ouch_host_messages.hpp"
#include "ouch_message_utils.hpp"
#include "ouch_message_utils.hpp"

#include "ouch_decode.hpp"
#include "ouch_decode.hpp"
#include "ouch_encode.hpp"
#include "ouch_encode.hpp"
#include "ouch_utils.hpp"
#include "ouch_utils.hpp"

int main() {
    EnterOrderMsg enter;
    ReplaceOrderMsg replace;
    CancelOrderMsg cancel;
    CancelByOrderIdMsg cancel_by_id;
    OrderAcceptedMsg accepted;
    RegulatoryData regulatory;

    enter.message_type = 'O';
    enter.quantity = 10;
    enter.regulatory_data.participant_capacity = 'A';
    const bool passed = enter.message_type == 'O'
        && enter.quantity == 10
        && enter.order_token.size() == 14
        && enter.order_token[0] == '\0'
        && enter.regulatory_data.participant_capacity == 'A'
        && enter.regulatory_data.filler[0] == '\0'
        && replace.message_type == '\0'
        && replace.minimum_acceptable_quantity == 0
        && cancel.order_token[0] == '\0'
        && cancel_by_id.order_id == 0
        && accepted.timestamp == 0
        && accepted.regulatory_data.execution_venue[0] == '\0'
        && regulatory.directed_wholesale == '\0'
        && regulatory.intermediary_id[0] == '\0';
    return passed ? 0 : 1;
}

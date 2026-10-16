#pragma once

#include <vector>
#include <cstddef>
#include <cstdint>

constexpr int MIN_BID_TICK = 5000;
constexpr int MAX_BID_TICK = 9999;
constexpr int MIN_ASK_TICK = 10001;
constexpr int MAX_ASK_TICK = 15000;

enum class Side
{
    Buy,
    Sell
};

struct Level
{
    int price;
    long qty;
};

struct BBO
{
    bool has_bid;
    int bid_price;
    long bid_qty;

    bool has_ask;
    int ask_price;
    long ask_qty;
};

class OrderBook
{
public:
    void add_order(uint64_t id, Side side, int price, long qty);

    bool cancel_order(uint64_t id);

    BBO get_bbo() const;

    std::vector<Level> get_bids(int depth = 10) const;

    std::vector<Level> get_asks(int depth = 10) const;
};

inline bool is_valid_price(Side s, int tick)
{
    switch (s)
    {
    case Side::Buy:
        if (tick >= MIN_BID_TICK && tick <= MAX_BID_TICK)
            return true;
        else
            return false;
    case Side::Sell:
        if (tick >= MIN_ASK_TICK && tick <= MAX_ASK_TICK)
            return true;
        else
            return false;
    default:
        return false;
    }
}

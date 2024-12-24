#include <iostream>
#include <vector>
#include <algorithm>

struct Trade {
    std::string timestamp;
    std::string symbol;
    double price;
    int volume;
};

int main() {
    std::vector<Trade> trades = {
        {"2024-12-24 09:00:01", "AAPL", 180.25, 100},
        {"2024-12-24 09:00:02", "GOOG", 2800.50, 200},
        {"2024-12-24 09:00:01", "MSFT", 350.75, 150},
        {"2024-12-24 09:00:03", "AAPL", 181.00, 300},
        {"2024-12-24 09:00:02", "MSFT", 351.00, 100}
    };

    // Sort by timestamp
    std::sort(trades.begin(), trades.end(), [](const Trade& a, const Trade& b) {
        return a.timestamp < b.timestamp;
    });

    // Display sorted trades
    std::cout << "Trades sorted by Timestamp:\n";
    for (const auto& trade : trades) {
        std::cout << "Timestamp: " << trade.timestamp 
                  << ", Symbol: " << trade.symbol 
                  << ", Price: " << trade.price 
                  << ", Volume: " << trade.volume << "\n";
    }

    return 0;
}

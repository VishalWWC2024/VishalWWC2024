#include <iostream>
#include <vector>
#include <algorithm>

struct Transaction {
    int id;
    double amount;
    int frequency;
    double score;
};

double calculateScore(double amount, int frequency) {
    return 0.5 * amount + 0.3 * frequency;
}

int main() {
    std::vector<Transaction> transactions = {
        {101, 5000.0, 5, 0.0},
        {102, 200.0, 10, 0.0},
        {103, 15000.0, 2, 0.0},
        {104, 800.0, 20, 0.0},
        {105, 10000.0, 15, 0.0}
    };

    for (auto& tx : transactions) {
        tx.score = calculateScore(tx.amount, tx.frequency);
    }

    std::sort(transactions.begin(), transactions.end(), [](const Transaction& a, const Transaction& b) {
        return a.score > b.score;
    });

    std::cout << "Flagged Transactions (Score >= 5000):\n";
    for (const auto& tx : transactions) {
        if (tx.score >= 5000) {
            std::cout << "ID: " << tx.id << ", Score: " << tx.score << ", Amount: " << tx.amount << "\n";
        }
    }

    return 0;
}

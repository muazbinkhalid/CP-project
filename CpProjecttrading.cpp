#include <iostream>
#include <string>
using namespace std;

class CryptoWallet {
private:
    double balanceUSD;
    double balanceCrypto;
    double cryptoPrice;

public:
    CryptoWallet(double initialUSD, double initialCrypto, double initialCryptoPrice)
        : balanceUSD(initialUSD), balanceCrypto(initialCrypto), cryptoPrice(initialCryptoPrice) {}

    void showBalances() {
        std::cout << "Balance USD: $" << balanceUSD << std::endl;
        std::cout << "Balance Crypto: " << balanceCrypto << " coins" << std::endl;
        std::cout << "Current Crypto Price: $" << cryptoPrice << " per coin" << std::endl;
    }

    void buyCrypto(double amountUSD) {
        if (amountUSD > balanceUSD) {
            std::cout << "Insufficient USD balance." << std::endl;
            return;
        }
        double amountCrypto = amountUSD / cryptoPrice;
        balanceUSD -= amountUSD;
        balanceCrypto += amountCrypto;
        std::cout << "Bought " << amountCrypto << " coins for $" << amountUSD << std::endl;
    }

    void sellCrypto(double amountCrypto) {
        if (amountCrypto > balanceCrypto) {
            std::cout << "Insufficient crypto balance." << std::endl;
            return;
        }
        double amountUSD = amountCrypto * cryptoPrice;
        balanceCrypto -= amountCrypto;
        balanceUSD += amountUSD;
        std::cout << "Sold " << amountCrypto << " coins for $" << amountUSD << std::endl;
    }

    void updateCryptoPrice(double newPrice) {
        cryptoPrice = newPrice;
        std::cout << "Updated crypto price to $" << cryptoPrice << " per coin" << std::endl;
    }
};

int main() {
    double initialUSD = 1000.0;
    double initialCrypto = 0.0;
    double initialCryptoPrice = 50.0;

    CryptoWallet wallet(initialUSD, initialCrypto, initialCryptoPrice);

    std::string command;
    while (true) {
        std::cout << "\nEnter a command (show, buy, sell, update, exit): ";
        std::cin >> command;

        if (command == "show") {
            wallet.showBalances();
        }
        else if (command == "buy") {
            double amountUSD;
            std::cout << "Enter amount in USD to buy crypto: ";
            std::cin >> amountUSD;
            wallet.buyCrypto(amountUSD);
        }
        else if (command == "sell") {
            double amountCrypto;
            std::cout << "Enter amount in crypto to sell: ";
            std::cin >> amountCrypto;
            wallet.sellCrypto(amountCrypto);
        }
        else if (command == "update") {
            double newPrice;
            std::cout << "Enter new crypto price: ";
            std::cin >> newPrice;
            wallet.updateCryptoPrice(newPrice);
        }
        else if (command == "exit") {
            break;
        }
        else {
            std::cout << "Unknown command. Please try again." << std::endl;
        }
    }

    return 0;
}

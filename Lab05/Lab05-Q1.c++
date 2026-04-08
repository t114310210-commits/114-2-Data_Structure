#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;

class Card {
public:
    string colors;
    string rank;

    Card(string s, string r) : colors(s), rank(r) {}

    void display() const {
        cout << rank << " of " << colors << endl;
    }
};

class Stack {
private:
    vector<Card> stack;

public:
    void push(const Card& card) {
        stack.push_back(card);
    }

    Card pop() {
        if (stack.empty()) {
            throw runtime_error("Stack is empty!");
        }
        Card topCard = stack.back();
        stack.pop_back();
        return topCard;
    }

    bool isEmpty() const {
        return stack.empty();
    }
};

class Deck {
private:
    vector<Card> cards;
    Stack shuffledDeck;

public:
    Deck() {
        string colors[] = { "Hearts", "Diamonds", "Clubs", "Spades" };
        string ranks[] = { "2", "3", "4", "5", "6", "7", "8", "9",
                           "10", "J", "Q", "K", "A" };

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 13; j++) {
                cards.push_back(Card(colors[i], ranks[j]));
            }
        }
    }

    void shuffleDeck() {
        random_device rd;
        mt19937 g(rd());
        shuffle(cards.begin(), cards.end(), g);

        for (const Card& c : cards) {
            shuffledDeck.push(c);
        }
    }

    void drawAllCards() {
        while (!shuffledDeck.isEmpty()) {
            Card c = shuffledDeck.pop();
            c.display();
        }
    }
};

int main() {
    Deck deck;
    deck.shuffleDeck();
    cout << "Shuffled deck:" << endl;
    deck.drawAllCards();
    return 0;
}

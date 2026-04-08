#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;


class Card {
public:
    string colors; // 撲克牌的花色
    string rank;   // 撲克牌的點數

    // 建構子：初始化花色與點數
    Card(string s, string r) : colors(s), rank(r) {}

    // 輸出顯示樸克牌花色與點數
    void display() const {
        cout << rank << " of " << colors << endl;
    }
};

class Stack {
private:
    vector<Card> stack; // 用 vector 存放卡片

public:
       void push(const Card& card) {   // 將卡片推入堆疊頂端

        stack.push_back(card);
    }

    // 從堆疊頂端取出卡片
    Card pop() {
        if (stack.empty()) {
            throw runtime_error("Stack is empty!"); // 空堆疊發出提示
        }
        Card topCard = stack.back(); // 取得頂端卡片
        stack.pop_back();            // 移除頂端卡片
        return topCard;
    }

    // 判斷堆疊是有沒有東西
    bool isEmpty() const {
        return stack.empty();
    }
};

// 代表一副撲克牌
class Deck {
private:
    vector<Card> cards;   // 原始牌組，未洗牌
    Stack shuffledDeck;   // 用堆疊儲存洗好的牌

public:
    // 建構子：初始化 52 張撲克牌
    Deck() {
        string colors[] = { "Hearts", "Diamonds", "Clubs", "Spades" };
        string ranks[] = { "2", "3", "4", "5", "6", "7", "8", "9",
                           "10", "J", "Q", "K", "A" };

        // 迴圈將 52 張牌加入 cards
        for (int i = 0; i < 4; i++) {      // 四種花色
            for (int j = 0; j < 13; j++) { // 13 種點數
                cards.push_back(Card(colors[i], ranks[j]));
            }
        }
    }

    // 洗牌，並將洗好的牌放入堆疊
    void shuffleDeck() {
        random_device rd;      // 用於產生隨機種子
        mt19937 g(rd());       // 這個我不知道是甚麼
        shuffle(cards.begin(), cards.end(), g); // 打亂 cards

        // 將洗好的牌依序放入堆疊
        for (const Card& c : cards) {
            shuffledDeck.push(c);
        }
    }

    // 依序從堆疊取出所有卡片並顯示
    void drawAllCards() {
        while (!shuffledDeck.isEmpty()) {
            Card c = shuffledDeck.pop(); // 取出頂端卡片
            c.display();                 // 顯示卡片資訊
        }
    }
};

int main() {
    Deck deck;               // 建立一副牌，初始化 52 張卡
    deck.shuffleDeck();       // 洗牌並放入堆疊
    cout << "Shuffled deck:" << endl;
    deck.drawAllCards();      // 依序發牌並顯示
    return 0;
}

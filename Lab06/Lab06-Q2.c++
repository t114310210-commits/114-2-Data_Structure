#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <ctime>
using namespace std;

// 玩家資料（就存名字跟目前分數）
struct Player {
    string name;
    int score;
};

// 一張撲克牌（花色 + 點數）
class Card {
public:
    string suit;
    string rank;

    Card() {}
    Card(string s, string r) : suit(s), rank(r) {}

    // 印出這張牌
    void display() const {
        cout << rank << " of " << suit << endl;
    }
};

// 一整副牌（52張）
class Deck {
private:
    Card cards[52];

public:
    Deck() {
        // 四種花色 + 13種點數
        string suits[] = { "Hearts", "Diamonds", "Clubs", "Spades" };
        string ranks[] = { "2", "3", "4", "5", "6", "7", "8", "9", "10",
                           "J", "Q", "K", "A" };

        int k = 0;

        // 把所有牌組合出來（像雙層迴圈列舉）
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 13; j++) {
                cards[k++] = Card(suits[i], ranks[j]);
            }
        }
    }

    // 洗牌（隨機交換）
    void shuffleDeck() {
        srand(time(0));
        for (int i = 51; i > 0; i--) {
            int j = rand() % (i + 1);
            swap(cards[i], cards[j]);
        }
    }

    // 取得第 i 張牌
    Card getCard(int i) const {
        return cards[i];
    }
};

// 自己寫的 Queue（當作牌堆用）
class Queue {
private:
    vector<Card> deck;
    int Front;   // 指目前最前面的牌
    int Rear;    // 指最後一張牌
    int capacity;

public:
    Queue(int size) : Front(0), Rear(-1), capacity(size) {}

    // 放一張牌進去（放尾巴）
    void enqueue(Card card) {
        if (isFull()) {
            cout << "牌堆滿了\n";
            return;
        }
        deck.push_back(card);
        Rear++;
    }

    // 拿掉最前面的牌
    void dequeue() {
        if (isEmpty()) {
            cout << "牌堆空了\n";
            return;
        }
        Front++;
    }

    // 看最前面那張牌（但不拿走）
    Card front() {
        if (isEmpty()) {
            return Card("", "");
        }
        return deck[Front];
    }

    // 判斷是不是空的
    bool isEmpty() const {
        return Front > Rear;
    }

    // 判斷是不是滿的
    bool isFull() const {
        return deck.size() == capacity;
    }
};

// 初始化牌堆（先洗牌再丟進 Queue）
void initializeDeck(Queue& cardDeck) {
    Deck deck;

    deck.shuffleDeck(); // 洗牌

    // 一張一張丟進牌堆
    for (int i = 0; i < 52; i++) {
        cardDeck.enqueue(deck.getCard(i));
    }
}

// 初始化玩家（發兩張牌）
void initializePlayer(Player* player, string name, Queue& cardDeck) {
    player->name = name;
    player->score = 0;

    cout << player->name << " 抽到的牌: ";

    // 一開始發兩張
    for (int i = 0; i < 2; i++) {
        Card drawnCard = cardDeck.front(); // 拿最前面的牌
        cardDeck.dequeue();                // 從牌堆移除

        cout << drawnCard.rank << " of " << drawnCard.suit << "  ";

        // 算分數（簡單版 blackjack）
        if (drawnCard.rank == "A") player->score += 1;
        else if (drawnCard.rank == "J" || drawnCard.rank == "Q" || drawnCard.rank == "K")
            player->score += 10;
        else
            player->score += stoi(drawnCard.rank);
    }

    cout << "\n初始分數: " << player->score << endl;
}

// 玩家回合（自己決定要不要抽）
void playerTurn(Player* player, Queue& cardDeck) {
    char choice;

    // 分數沒爆 + 還有牌
    while (player->score < 21 && !cardDeck.isEmpty()) {
        cout << player->name << " 分數: " << player->score
             << " (h=抽, s=停): ";
        cin >> choice;

        if (choice == 'h') {
            // 抽一張
            Card newCard = cardDeck.front();
            cardDeck.dequeue();

            // 加分
            if (newCard.rank == "A") player->score += 1;
            else if (newCard.rank == "J" || newCard.rank == "Q" || newCard.rank == "K")
                player->score += 10;
            else
                player->score += stoi(newCard.rank);

            cout << "抽到: " << newCard.rank << " of " << newCard.suit
                 << " → 總分: " << player->score << endl;

            // 爆掉
            if (player->score > 21) {
                cout << "爆了\n";
                return;
            }
        }
        else if (choice == 's') {
            // 停牌
            break;
        }
    }
}

// 莊家回合（自動抽到 >=17）
void dealerTurn(Player* dealer, Queue& cardDeck) {
    while (dealer->score < 17 && !cardDeck.isEmpty()) {
        Card newCard = cardDeck.front();
        cardDeck.dequeue();

        if (newCard.rank == "A") dealer->score += 1;
        else if (newCard.rank == "J" || newCard.rank == "Q" || newCard.rank == "K")
            dealer->score += 10;
        else
            dealer->score += stoi(newCard.rank);

        cout << "莊家抽到: " << newCard.rank << " of " << newCard.suit
             << " → 總分: " << dealer->score << endl;

        if (dealer->score > 21) {
            cout << "莊家爆了\n";
            return;
        }
    }
}

// 比大小
void determineWinner(Player* player, Player* dealer) {
    if (player->score > 21)
        cout << "莊家贏\n";
    else if (dealer->score > 21 || player->score > dealer->score)
        cout << "玩家贏\n";
    else if (player->score == dealer->score)
        cout << "平手\n";
    else
        cout << "莊家贏\n";
}

int main() {
    Queue cardDeck(52);

    initializeDeck(cardDeck);

    Player player, dealer;

    initializePlayer(&player, "玩家", cardDeck);
    initializePlayer(&dealer, "莊家", cardDeck);

    playerTurn(&player, cardDeck);

    if (player.score <= 21) {
        cout << "\n莊家回合...\n";
        dealerTurn(&dealer, cardDeck);
        determineWinner(&player, &dealer);
    }

    return 0;
}

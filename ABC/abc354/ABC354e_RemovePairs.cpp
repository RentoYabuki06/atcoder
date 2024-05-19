#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

typedef pair<int, int> Card;

bool can_remove(const Card& card1, const Card& card2) {
    return card1.first == card2.first || card1.second == card2.second ||
           card1.first == card2.second || card1.second == card2.first;
}

int dp(int state, int turn, const vector<Card>& cards, unordered_map<int, int>& memo) {
    if (memo.count(state)) return memo[state];

    vector<int> remaining_cards;
    for (int i = 0; i < cards.size(); ++i) {
        if (state & (1 << i)) remaining_cards.push_back(i);
    }

    if (remaining_cards.size() < 2) return memo[state] = 1 - turn;

    for (int i = 0; i < remaining_cards.size(); ++i) {
        for (int j = i + 1; j < remaining_cards.size(); ++j) {
            if (can_remove(cards[remaining_cards[i]], cards[remaining_cards[j]])) {
                int new_state = state;
                new_state &= ~(1 << remaining_cards[i]);
                new_state &= ~(1 << remaining_cards[j]);
                if (dp(new_state, 1 - turn, cards, memo) == turn) {
                    return memo[state] = turn;
                }
            }
        }
    }
    return memo[state] = 1 - turn;
}

string solve(int N, const vector<Card>& cards) {
    unordered_map<int, int> memo;
    int initial_state = (1 << N) - 1;
    int winner = dp(initial_state, 0, cards, memo);
    return winner == 0 ? "Takahashi" : "Aoki";
}

int main() {
    int N;
    cin >> N;
    vector<Card> cards(N);
    for (int i = 0; i < N; ++i) {
        cin >> cards[i].first >> cards[i].second;
    }
    cout << solve(N, cards) << endl;
    return 0;
}

#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

string targetChannel;
int itargetChannel;

void input(vector<int>& vec) {
    cin >> targetChannel;
    itargetChannel = stoi(targetChannel);

    int n;
    cin >> n;
    vector<int> except(n);

    for (size_t i = 0; i < n; i++)
    {
        cin >> except[i];
    }
    sort(except.begin(), except.end());


    int index = 0;
    for (size_t i = 0; i < 10; i++)
    {
        if (index < except.size() && except[index] == i) {
            index++;
        }
        else {
            vec.push_back(i);
        }
    }
}

vector<int> Channels;
void MakeMinDiffChan(vector<int>& channel, string str) {
    if(str.length() != 0)
        Channels.push_back(stoi(str));

    if (str.length() == targetChannel.length() + 1) {
        return;
    }

    for (size_t i = 0; i < channel.size(); i++)
    {
        MakeMinDiffChan(channel, str + to_string(channel[i]));
    }
}

void solution(vector<int>& channel) {
    if (itargetChannel == 100) {
        cout << 0;
        return;
    }

    MakeMinDiffChan(channel, "");

    int minDiff = 2147483647;
    int diff, value;
    for (size_t i = 0; i < Channels.size(); i++)
    {
        int chan = Channels[i];

        int cnt = 0;
        do {
            cnt++;
            chan /= 10;
        } while (chan != 0);

        chan = Channels[i];
        diff = abs(itargetChannel - chan) + cnt;
        if (diff < minDiff) {
            minDiff = diff;
            value = chan;
        }

    }

    minDiff = min(minDiff, abs(itargetChannel - 100));

    cout << minDiff << endl;

}


int main()
{
    vector<int> channel;

    input(channel);

    solution(channel);

}

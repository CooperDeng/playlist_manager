#include <iostream>
#include <string>
#include "playlist.h"

int main () {

    std::string first_input;
    std::string first_letter;
    std::string size;
    int size_int;
    std::getline(std::cin, first_input);
    first_letter = first_input.substr(0,1);

    if (first_letter == "m") {
        size = first_input.substr(2);
        size_int = stoi(size);
    }

    playlist m(size_int);

    //the while loop that keeps searching for inputs
    while(true){

        std::string user_input;
        std::getline(std::cin, user_input);
        std::string rest;

        if (user_input.substr(0,1) == "i"){
            
            rest = user_input.substr(2);
            m.AddSong(rest);

        }

        if (user_input.substr(0,1) == "p"){

            rest = user_input.substr(2);            
            int rest_int;
            rest_int = stoi(rest);
            m.PlaySong(rest_int);

        }

        if (user_input.substr(0,1) == "e"){

            rest = user_input.substr(2);
            int rest_int;
            rest_int = stoi(rest);
            m.DeleteSong(rest_int);

        }

        // this is for testing the playlist, play with it if you want
        if (user_input.substr(0,1) == "d"){
            m.PrintSong();
        }

        //if there is no further input, we break out of while loop
        if(user_input == "" || !std::cin) {
            break;
        }

    }

    m.~playlist();

    return 0;

};


/*

------------------------------------------------------------------------
美好的事可不可以发生在我身上
-- 康士坦的变化球

毫无意外的旅程 做到壹些不劳而获的梦 看似幸运啊
毫无意外的旅程 平淡如水的爱情 看似安稳啊
毫无意外的旅程 得到一些可以任性的机会 看似自由啊
毫无意外的旅程 做到别人也想要做的事 看似精彩啊

但是事实上发生的从来没想过
真正想要的都被别人拿走
没决定太多事就这样到了今天
然后接下来变成硬撑的烂局
再打一剂希望麻醉了痛苦
只能进 不能退 扛不起 放不下
不得不走下去

我们半推半就的人生
没有和你一样被眷顾的未来
我们半推半就的人生
怎么过啊 怎么过啊

迷惘的灵魂啊 安静地运转吧
忍耐的灵魂啊 安静地运转吧
------------------------------------------------------------------------

附言：
    说实话，完全不知道为什么我要来这个专业，更多的是被家人逼着来的
    来这里的一年多，开心的时间屈指可数
    “只能进 不能退 扛不起 放不下 不得不走下去”
    人上大学哪有不疯的？硬撑罢了！硬撑罢了！硬撑罢了！

------------------------------------------------------------------------
*/

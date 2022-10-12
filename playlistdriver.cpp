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

#include <iostream>
#include <string>
#include "playlist.h"


playlist::playlist(int _max){    
    // making a playlist array 
    // each of the element should be a song
    songlist = new std::string[_max-1];
    max_list = _max;
    std::cout << "success" << std::endl; 
};


//adding a song to the end of the list
void playlist::AddSong(std::string song) {
    //for loop that goes through all the element until finding an empty one
    int found = song.find(";");
    std::string title = song.substr(0,found);
    if (song == "Muskrat Love;Captain and Tennille"||title == "My Heart Will Go On") {
        std::cout << "can not insert " << song << std::endl; 
        return;
    }

    for(int i = 0; i < max_list; i++){
        if (songlist[i] == song){
            std::cout << "can not insert " << song << std::endl;
            return;
        }
    }
    
    for (int i=0; i < max_list; i++){
        if (songlist[i] == ""){
            songlist[i] = song;
            std::cout << "success" << std::endl;
            return;
        }
    }
    std::cout << "can not insert " << song << "\n";
};


//inserting a song to _pos, move everything back by 1
void playlist::InsertSong(int _pos, std::string song){
    //inserting the song to _pos

    //temp variable
    std::string temp = songlist[_pos];
  
    songlist[_pos] = song; 
 
    //Right-shifting array
    for (int i = max_list -1; i > _pos; i--){
        if ( i-1 == _pos ){
            songlist[i] = temp;
            break;
        }
        songlist[i] = songlist[i-1];
    }
};


//delete specified song
void playlist::DeleteSong(int _pos){
    //deleting a song at _pos, move everything front by 1
    //if there is no song at the position, we do not do anything
    if (songlist[_pos] == "") {
        std::cout << "can not erase " << _pos << std::endl;
    }

    //Left-shifting the array
    else {
        songlist[_pos] = "";
        for (int i = _pos; i < max_list; i++){
            songlist[i] = songlist[i+1];
        }

        std::cout << "success \n";
    }
};


//play specified song
void playlist::PlaySong(int _pos){
    if (songlist[_pos] == "" || _pos < 0 || _pos >= max_list) {
        std::cout << "can not play " << _pos << std::endl;
    }

    else {
        std::cout << "played " << _pos << " " << songlist[_pos] << std::endl;
    }
};


//printing the entire songlist
void playlist::PrintSong(){
    for(int i = 0; i < max_list; i++){
        std::cout << songlist[i] << std::endl;

    }
};


//destructor 再见
playlist::~playlist(){

    delete []songlist;

    songlist = nullptr;

};


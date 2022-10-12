#include <iostream>


class playlist {
    //--------------------------------------------------private-----------------------------------------------//
    private:

    int max_list;
    std::string* songlist;


    //--------------------------------------------------public------------------------------------------------//
    public:

    //constructor
    playlist(int _max); 

    // destructor
    ~playlist();

    void AddSong(std::string song);
    void InsertSong(int _pos, std::string song);
    void DeleteSong(int _pos); 
    void PlaySong(int _pos);   
    void PrintSong();


};
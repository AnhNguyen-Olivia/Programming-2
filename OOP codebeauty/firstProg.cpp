#include <iostream>
#include <list>
using namespace std;

class YoutubeChannel {
    public: 
        string Name;                 
        string OwnerName;
        int SubscribersCount;
        list<string> PublishedVideosTitles;

        YoutubeChannel(string name, string onwerName) {
            Name = name;
            OwnerName = onwerName;
            SubscribersCount = 0;
        }

        // Class method
        void getInfo(){
            cout << "Channel Name: " << Name << endl;
            cout << "Owner Name: " << OwnerName << endl; 
            cout << "Subscribers Count: " << SubscribersCount << endl;
            for(string videoTitle : PublishedVideosTitles)
            {
                cout << "Published Video: " << videoTitle << endl;
            }
        }

};

int main(){
    YoutubeChannel ytChannel("PhD Cat", "Dr. Whiskers");
    ytChannel.PublishedVideosTitles.push_back("How to be a cat");
    ytChannel.PublishedVideosTitles.push_back("UIIAIUUUIAI");
    ytChannel.PublishedVideosTitles.push_back("Cat 101");

    YoutubeChannel ytChannel_2("Compulsive Gambler", "Yumeko Jabami");

    //Invoke the class method
    ytChannel.getInfo();
    ytChannel_2.getInfo();

    return 0;
}
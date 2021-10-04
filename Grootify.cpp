/*
Kayla Atsila Ivanka - 2017051008

Studi kasus: Queue Music Playlist

Program yang saya buat menggunakan queue yaitu antrian,
Fungsi queue yang saya buat berada di dalam Class dengan nama songQueue.
Di dalam program ini saya menggunakan STL yaitu vector
dan hasil program saya di cetak dalam sebuah file berbentuk .txt
di dalam program ini dapat menghitung jumlah lagu dalam queue dengan mengimplementasikan file pointer.
*/

#include <bits/stdc++.h>
using namespace std;

class songQueue{
public:
    int countData;
	vector<string> data;
    
    bool isEmpty(){
        return data.size() == 0;
    }

    string fetchFront(){
        return data.front();
    }
	
    void enqueue(string a){
        data.push_back(a);
        ++countData;
    }
    
    void dequeue(){
        if(!isEmpty()){
            data.erase(data.begin());
            --countData;
        }
    }

    void clear(){
        if(!isEmpty()){
            data.clear();
        }
    }

}inList;

//variabel global
int counter;
vector<string> song    {"Kenshi Yonezu ~ Lemon", 
                        "Official Hige Dandism ~ Pretender", 
                        "Yuuri ~ Dry Flower",
                        "Aimer ~ Kataomoi",
                        "King Gnu ~ Hakujitsu",
                        "Masaki Suda ~ Machigaisagashi",
                        "Kenshi Yonezu ~ Kanden",
                        "Official Hige Dandism ~ 115 man Kilo no Film",
                        "Silhouette ~ Kana-Boon"};

//prototyping prosedur dan fungsi
void home();
void recommendation();
void inQueue();

void add(int a);
void play();
void sortList();
void clearList();

//program main
int main(){
    clearList(); //reset database
    home();
}

void home(){
    char pick;
    do{
        system("cls");
        cout << endl << "\t+----------------------------------------------+"
             << endl << "\t|            MY PlAYLIST (Japan ver.)          |"  
             << endl << "\t+----------------------------------------------+"
             << endl
             << endl << "\t[1] ADD TO QUEUE"
             << endl << "\t[2] QUEUE"
             << endl << "\t[3] EXIT"
             << endl
             << endl << "\t+----------------------------------------------+"
             << endl << "\tChoose Option -> ", cin >> pick;
        system("cls");

        if(pick == '1'){
            recommendation();
        }else if(pick == '2'){
            inQueue();
        }else if(pick == '3'){
            cout << "Thank you! We are going to miss you."
                 << endl;
            exit(0);
        }else{
            home();
        }
    }while(pick == '1' || pick == '2' || pick == '3');   
}

void recommendation(){
    string which; 
    int i;

    cout << endl << "\t+-------------------------------------------------+"
         << endl << "\t|               Our Recommendation                |"
         << endl << "\t+-------------------------------------------------+"
         << endl << endl;

    for (auto it : song){
        cout << "\t" << ++i << ") " << it << endl;
    }

    cout << endl << "\t+-------------------------------------------------+"
         << endl << "\tChoose Song -> ", cin >> which;
    
    if(which == "1"){
        add(0);
    }else if(which == "2"){
        add(1);
    }else if(which == "3"){
        add(2);
    }else if(which == "4"){
        add(3);
    }else if(which == "5"){
        add(4);
    }else if(which == "6"){
        add(5);
    }else if(which == "7"){
        add(6);
    }else if(which == "8"){
        add(7);
    }else if(which == "9"){
        add(8);
    }else{
        system("cls");
        recommendation();
    }
}

void inQueue(){
    ifstream showList;
    string show;
    int i, c = inList.countData;
    char ans;

    showList.open("userPlaylist.txt");
		
        if(!inList.isEmpty()){
        	cout << endl << "\t+-----------------------------------------------+"
                 << endl << "\t| \t\tIn Queue: " << c << " track(s)\t        |"
                 << endl << "\t+-----------------------------------------------+"
                 << endl;
            
            while(!showList.eof()){
                getline(showList, show);

                if(show != ""){
                    cout << "\t" << ++i << ") " << show << endl;
                }
            }

            cout << endl << "\t+-----------------------------------------------+"    
                 << endl << endl;
        }else{
            cout << endl << "\tQueue is empty!" << endl;
        }

        cout << endl << "\t+-----------------------------------------------+"
             << endl << "\t|                    Option                     |"
             << endl << "\t+-----------------------------------------------+"
             << endl << "\t[1] PLAY"
             << endl << "\t[2] CLEAR"
             << endl << "\t[3] BACK"
             << endl << "\t+-----------------------------------------------+"
             << endl << "\tChoose -> ", cin >> ans;
        system("cls");

        if(ans == '1'){
            play();
        }else if(ans == '2'){
            clearList();
            cout << endl << "\t+----------------------------------------------+"
                 << endl << "\t|                Queue Cleared                 |"
                 << endl << "\t+----------------------------------------------+"            
                 << endl;
            system("pause");
        }else{
            home();
        }

    showList.close();
}

void add(int a){
    ofstream addNew;
    
    addNew.open("userPlaylist.txt", ios::app);
        addNew << song[a] << endl;

        inList.enqueue(song[a]);
        cout << endl << "\t+------------------------------------------------------+"
             << endl << "\t\t" << song[a] << " is added"
             << endl << "\t+------------------------------------------------------+"
             << endl << "\t" << inList.countData << " in track(s)"
             << endl << endl;

    addNew.close();

    system("pause");
}

void play(){
    ofstream updateData;
    ifstream remaining;
    string hold;

    updateData.open("userPlaylist.txt");
    remaining.open("userPlaylist.txt");
        
        if(!inList.isEmpty()){

            cout << endl << "\t+-------------------------------------------------------+"
                 << endl << "\t   > " << inList.fetchFront() << " is being played"
                 << endl << "\t+-------------------------------------------------------+";
            
            inList.dequeue();

            for(auto i : inList.data){
                updateData << i << endl;
            }
        
            while(!remaining.eof()){
                if(remaining.get() == '~'){
                    if(remaining.tellg() > 0){
                        ++counter;
                    }
                }
            }

            if(counter != 0){
                cout << endl << "\t" << counter << " more track(s) in queue" 
                     << endl << endl;
                counter = 0;
            }else{
                cout << endl << "\tThis is the end of the queue!" 
                     << endl << endl;       
            }
        }

    remaining.close();
    updateData.close();

    system("pause");
    system("cls");
    inQueue();
}

void clearList(){
    ofstream clearFile;
    
    clearFile.open("userPlaylist.txt", ios::trunc);

        inList.clear();

    clearFile.close();
}

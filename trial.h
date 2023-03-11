void append(char ar[],char c)
{
    int l=strlen(ar);
    ar[l]=c;
    ar[l+1]='\0';
}

void lower(char a[])                    //converts all char to lowercase
{
    int i=0;
    for(i=0;i<strlen(a);i++)
    {
        a[i]=tolower(a[i]);
    }
}

inline void rules()
{
    cout<<"\t\t\t\t\t\t1) Enter one alphabet at a time.\n";
    cout<<"\t\t\t\t\t\t2) If you are stuck, you have 2 hints:\n";
    cout<<"\t\t\t\t\t\t  a) press '+' to reveal a letter (you can do this only once).\n";
    cout<<"\t\t\t\t\t\t\t\t    -5 points\n";
    cout<<"\t\t\t\t\t\t  b) press '-' to guess the entire word at once.\n";
    cout<<"\t\t\t\t\t\t\t\t    +10 points if you guess the entire word\n";
    cout<<"\t\t\t\t\t\t\t\t    -5 points if you don't\n";
    cout<<"\t\t\t\t\t\t3) You lose a point for every wrong guess.\n";
    cout<<"\t\t\t\t\t\t4) You gain 20 points if you guess the entire word correctly, else you lose 5.\n\n";
}

void display_menu(char &ch)
{
    do
    {
        SetColor(10);
        cout<<"\n\t\t\t\t\t            *********** HANGMAN IN C++ ***********\n\n\n\n";
        SetColor(7);
        cout<<"\t\t\t\t\t\t--------------------------------------------------------------\n";
        
        cout<<"\t\t\t\t\t\t(P) Player vs Player                    (C) Computer chooses word\n\n";
        cout<<"\t\t\t\t\t\t(A) Add new word to list                (Q) Quit\n\n\n\t\t\t\t\t\tEnter your choice : ";
        SetColor(10);
        cin.get(ch);
        cin.ignore(30,'\n');
        ch=tolower(ch);
        SetColor(7);
    }
    while (ch!='c' && ch!='p' && ch!= 'q' && ch!= 'a');
        
    return;
}

class game:protected Word
{
    protected:
        char choosen[40],incorrect[40],level[10];
        int wrong,turns,score,t;
    public:
        game()
        {
            choosen[0]='\0';
            incorrect[0]='\0';
            level[0]='\0';
            wrong=0;
            turns=10;
            score=20;
        }
        void reset()
        {
            for(int i=0;i<strlen(choosen);i++)
                choosen[i]='\0';
            for(int i=0;i<strlen(incorrect);i++)
                incorrect[i]='\0';
            wrong=t=0;
            score=20;
            Word::reset();
        }
        void comp_chooses();
        virtual void player_chooses()
        {
            return;
        }
        
        virtual void player_adds()
        {
            return;
        }
        virtual int play();
        
        void draw();
        
        virtual void scoring()
        {
            score=score-wrong;
            if(t<30)
                score+=10;
            else if (t<60)
                score+=5;
            if(wrong==0)
                score+=5;
        }
        
};

void game::draw()
{
    cout << endl<<endl;
    switch(wrong)
    {
        case 0: break;
        case 1:
                SetColor(12);
                cout << "\t\t\t\t\t\t              "<<endl;
                cout << "\t\t\t\t\t\t           "<<endl;
                cout << "\t\t\t\t\t\t           "<<endl;
                cout << "\t\t\t\t\t\t          " <<endl;
                cout << "\t\t\t\t\t\t          " <<endl;
                cout << "\t\t\t\t\t\t          " <<endl;
                cout << "\t\t\t\t\t\t_______________"<<endl;
                SetColor(7);
                break;
        case 2:
                SetColor(12);
                cout << "\t\t\t\t\t\t |             "<<endl;
                cout << "\t\t\t\t\t\t |             "<<endl;
                cout << "\t\t\t\t\t\t |          "<<endl;
                cout << "\t\t\t\t\t\t |         " <<endl;
                cout << "\t\t\t\t\t\t |         " <<endl;
                cout << "\t\t\t\t\t\t |         " <<endl;
                cout << "\t\t\t\t\t\t_|______________"<<endl;
                SetColor(7);
                break;
        case 3:
                SetColor(12);
                cout << "\t\t\t\t\t\t_|______________"<<endl;
                cout << "\t\t\t\t\t\t | /        "<<endl;
                cout << "\t\t\t\t\t\t |/         " <<endl;
                cout << "\t\t\t\t\t\t |         " <<endl;
                cout << "\t\t\t\t\t\t |             "<<endl;
                cout << "\t\t\t\t\t\t |         " <<endl;
                cout << "\t\t\t\t\t\t_|______________"<<endl;
                SetColor(7);            
                break;
        case 4:
                SetColor(12);
                cout << "\t\t\t\t\t\t_|______________"<<endl;
                cout << "\t\t\t\t\t\t | /          }  "<<endl;
                cout << "\t\t\t\t\t\t |/              " <<endl;
                cout << "\t\t\t\t\t\t |               " <<endl;
                cout << "\t\t\t\t\t\t |             "<<endl;
                cout << "\t\t\t\t\t\t |               " <<endl;
                cout << "\t\t\t\t\t\t_|______________"<<endl;
                SetColor(7);
                break;
        case 5:
                SetColor(12);
                cout << "\t\t\t\t\t\t_|______________"<<endl;
                cout << "\t\t\t\t\t\t | /          }  "<<endl;
                cout << "\t\t\t\t\t\t |/           0   " <<endl;
                cout << "\t\t\t\t\t\t |               " <<endl;
                cout << "\t\t\t\t\t\t |             "<<endl;
                cout << "\t\t\t\t\t\t |               " <<endl;
                cout << "\t\t\t\t\t\t_|______________"<<endl;
                SetColor(7);
                break;
        case 6:
                SetColor(12);
                cout << "\t\t\t\t\t\t_|______________"<<endl;
                cout << "\t\t\t\t\t\t | /          }  "<<endl;
                cout << "\t\t\t\t\t\t |/           0   " <<endl;
                cout << "\t\t\t\t\t\t |            |   " <<endl;
                cout << "\t\t\t\t\t\t |            | "<<endl;
                cout << "\t\t\t\t\t\t |               " <<endl;
                cout << "\t\t\t\t\t\t_|______________"<<endl;
                SetColor(7);
                break;
        case 7:
                SetColor(12);
                cout << "\t\t\t\t\t\t_|______________"<<endl;
                cout << "\t\t\t\t\t\t | /          }  "<<endl;
                cout << "\t\t\t\t\t\t |/           0   " <<endl;
                cout << "\t\t\t\t\t\t |           \\|   " <<endl;
                cout << "\t\t\t\t\t\t |            |  " <<endl;
                cout << "\t\t\t\t\t\t |              "<<endl;
                cout << "\t\t\t\t\t\t_|______________"<<endl;
                SetColor(7);
                break;
        case 8:
                SetColor(12);
                cout << "\t\t\t\t\t\t_|______________"<<endl;
                cout << "\t\t\t\t\t\t | /          }  "<<endl;
                cout << "\t\t\t\t\t\t |/           0   " <<endl;
                cout << "\t\t\t\t\t\t |           \\|/   " <<endl;
                cout << "\t\t\t\t\t\t |            |  " <<endl;
                cout << "\t\t\t\t\t\t |              "<<endl;
                cout << "\t\t\t\t\t\t_|______________"<<endl;
                SetColor(7);
                break;
        case 9: 
                SetColor(12);
                cout << "\t\t\t\t\t\t_|______________"<<endl;
                cout << "\t\t\t\t\t\t | /          }  "<<endl;
                cout << "\t\t\t\t\t\t |/           0   " <<endl;
                cout << "\t\t\t\t\t\t |           \\|/   " <<endl;
                cout << "\t\t\t\t\t\t |            |"<<endl;
                cout << "\t\t\t\t\t\t |           /  " <<endl;
                cout << "\t\t\t\t\t\t_|______________"<<endl;
                SetColor(7);
                break;
 /*case 10*/default:
                SetColor(12);
                cout << "\t\t\t\t\t\t_|______________"<<endl;
                cout << "\t\t\t\t\t\t | /          }  "<<endl;
                cout << "\t\t\t\t\t\t |/           0   " <<endl;
                cout << "\t\t\t\t\t\t |           \\|/   " <<endl;
                cout << "\t\t\t\t\t\t |            |"<<endl;
                cout << "\t\t\t\t\t\t |           / \\ " <<endl;
                cout << "\t\t\t\t\t\t_|______________"<<endl;
                SetColor(7);
                break;
    }
}

class Level1: public game
{
    public:
    Level1()
    {
        char c[]="level1.txt";
        strcpy(level,c);
        score=20;
    }
    void player_adds();
    void scoring()
    {
        score=score-wrong;
        if(t<30)
            score+=10;
        else if (t<60)
            score+=5;
        if(wrong==0)
            score+=5;
    }
};

void game::comp_chooses()
{
    
    ifstream fin(level);           //opening file
    if(!fin)
        cout<<"\nsomething worg";
    int l,count=0;                      //l=length of word, count=number of lines
    long int now=time(NULL);            //current time in seconds
    while(!fin.eof())
    {
        fin.ignore(50,'\n');
        count++;
    }
    int line=now%count;   
    fin.seekg(ios::beg);                 
    for(int i=0;i<line;i++)             //selecting a random line
    {
        fin.ignore(50,'\n');            //ignore all chars until we reach \n,read each char until \n, then loop goes again
    }                                   //to get a random line

    fin>>category;                             //first char is the category
    fin>>length;                             //that is followed by the length of the word
    fin.ignore();                       //that is followed by a space, whihc is ignored
    
    fin.getline(word,length+1,'\n');              //reading the word
    
    
    fin.close();
}

void Level1::player_adds()
{
    
    char cat='\0';
    do
    {
        system("cls");
        SetColor(10);
        cout<<"\n\t\t\t\t\t\t\t\t    *********** HANGMAN IN C++ ***********\n\n";
        SetColor(7);
        if(cat!='\0')
            cout<<"\n\t\t\t\t\t\t No such category. Try again.\n\n";
        cout<<"\n\t\t\t\t\t\tThe categories:";
        cout<<"\n\t\t\t\t\t\t m) Movie";
        cout<<"\n\t\t\t\t\t\t a) Animal";
        cout<<"\n\t\t\t\t\t\t p) Sport";
        cout<<"\n\t\t\t\t\t\t s) Song";
        cout<<"\n\t\t\t\t\t\t c) Automobile Companies";
        cout<<"\n\t\t\t\t\t\t e) Electronics";
        cout<<"\n\t\t\t\t\t\t h) Clothing Brands";
        cout<<"\n\t\t\t\t\t\t w) Watch Brands";
        cout<<"\n\t\t\t\t\t\t z) Miscellaneous";
        
        
        cout<<"\n\n\t\t\t\t\t\tEnter the category code: ";
        cin>>cat;
        cin.ignore();                       //ignore the next line char
        cat=tolower(cat);
    }    
    while(cat!='m' && cat!='a' && cat!='p' && cat!='s' && cat!='c' && cat!='e' && cat!='h' && cat!='w' && cat!='z');
    
    cout<<"\n\t\t\t\t\t\t Enter the word(s): ";
    
    category=tolower(cat);              //get the character
    cin.getline(word,50);
    lower(word);
    length=strlen(word);
    ofstream file;                          //open file to write int it
    file.open(level,ios::app);
    file<<category<<length<<' '<<word<<endl;     //write char, length and word
    file.close();
}

class Level2: public game
{
    public:
    Level2()
    {
        score=30;
        char c[]="level2.txt";
        strcpy(level,c);
    }
    void player_adds();
    void scoring()
    {
        score=score-wrong;
        if(t<30)
            score+=15;
        else if (t<60)
            score+=10;
        if(wrong==0)
            score+=5;
    }
};

void Level2::player_adds()
{
    
    char cat='\0';
    do
    {
        system("cls");
        SetColor(10);
        cout<<"\n\t\t\t\t\t\t\t\t    *********** HANGMAN IN C++ ***********\n\n";
        SetColor(7);
        if(cat!='\0')
            cout<<"\n\t\t\t\t\t\t No such category. Try again.\n\n";
        cout<<"\n\t\t\t\t\t\tThe categories:";
        cout<<"\t\t\t\t\t\t\t r) Dictionary word";
        cout<<"\t\t\t\t\t\t\t i) Idioms, Phrases or Proverbs";
        cout<<"\n\t\t\t\t\t\t z) Miscellaneous";
        
        
        cout<<"\n\n\t\t\t\t\t\tEnter the category code: ";
        cin>>cat;
        cin.ignore();                       //ignore the next line char
        cat=tolower(cat);
    }    
    while(cat!='r' && cat!='i' && cat!='z' );//&& cat!='s' && cat!='c' && cat!='e' && cat!='h' && cat!='w' && cat!='z');
    
    cout<<"\n\t\t\t\t\t\t Enter the word(s): ";
    
    category=tolower(cat);              //get the character
    cin.getline(word,50);
    lower(word);
    length=strlen(word);
    ofstream file;                          //open file to write int it
    file.open(level,ios::app);
    file<<category<<length<<' '<<word<<endl;     //write char, length and word
    file.close();
}


int game::play()
{
    makedash();
    /*
    SetColor(10);
    cout<<"\n\t\t\t\t\t            ***********  HANGMAN  ***********\n\n\n\n";
    SetColor(7);
    */
    char c,gue[40];
    int q=0;
    long start_time=time(NULL),end_time;
    int counthint=0;
    for(int i=0;i<turns;i++)
    {
        
        cout<<"\n\n\t\t\t\t\t\t  You have "<<turns-i<<" guesses. Good luck!!\n\n";
        if(strlen(choosen)>0)
        {
            cout<<"\n\t\t\t\t\t\tYour previous guesses: ";
            for(int k=0;k<strlen(choosen);k++)
            {
                SetColor(10);
                if(inarr(incorrect,choosen[k]))
                    SetColor(12);
                cout<<"  "<<choosen[k];
                
            }
        }
        SetColor(7);
        if(compare()==1)
        {
            end_time=time(NULL);
            system("cls");
            t=end_time-start_time;
            scoring();
            SetColor(10);
        cout<<"\n\t\t\t\t\t            ***********  HANGMAN  ***********\n\n\n\n";
        SetColor(7);
            SetColor(10);
                cout<<"\n\t\t\t\t\t\t Congrats, You got it right!\n\n";
            SetColor(7);
            cout<<"\n\t\t\t\t\t\t The word was ";
            theword();
            cout<<"\n\t\t\t\t\t\t You made ";
            SetColor(12);
                cout<<wrong;
            SetColor(7);
            cout<<" wrong guesses";
            cout<<"\n\t\t\t\t\t\t Your score: ";
            SetColor(10);
                cout<<score;
            SetColor(7);
            cout<<"\n\t\t\t\t\t\t You took ";
            SetColor(15);
                cout<<t;
            SetColor(7);
            cout<<" seconds";
            draw();
            cin.get();
            return(1);
            break;
        }
        draw();
        cout<<"\n\n";
        type_of_word();
        cout<<"\n";
        show();
        cout<<endl;
        cout<<"\n\n\t\t\t\t\t\t Enter your guess: ";
        //cin>>c;
        SetColor(11);
        c=cin.get();
        SetColor(7);
        if(c=='\n')
        {
            i--;
            system("cls");
            SetColor(10);
            cout<<"\n\t\t\t\t\t            ***********  HANGMAN  ***********\n\n\n\n";
            SetColor(7);
            continue;
        }
        cin.ignore(50,'\n');
        if(c=='+')
        {
            i--;
            if(counthint==0)
            {
                c=reveal_one_alpha(choosen);
                check(c);
                append(choosen,c);
                q+=1;
                score-=5;
                
                system("cls");
                SetColor(10);
                cout<<"\n\t\t\t\t\t            ***********  HANGMAN  ***********\n\n";
                SetColor(7);
                cout<<"\n\n\t\t\t\t\t\t Score: -5 \n\n";
                
                counthint++;
            //continue;
            }
            else
            {
                system("cls");
            
                SetColor(10);
                cout<<"\n\t\t\t\t\t            ***********  HANGMAN  ***********\n\n";
                SetColor(12);
                cout<<"\n\t\t\t\t\t\t No hints left\n";
                SetColor(7);
            }
            continue;
        }
        
        if(c=='-')
        {
            cout<<"\n\t\t\t\t\t\t Make your guess: ";
            SetColor(11);
            cin.getline(gue,40,'\n');
            SetColor(7);
            //cin>>gue;
            lower(gue);
            i--;
            int f= group(gue);
            if(f==1)
            { 
                if(compare() && i>=3)
                {
                    score+=10;
                    continue;
                }
                
                for(int k=0;k<strlen(gue);k++)
                    if(!inarr(choosen,gue[k]))
                        append(choosen,gue[k]);
            }
            else if(f==0)
            {
                score-=5;
                system("cls");
                SetColor(10);
                    cout<<"\n\t\t\t\t\t            ***********  HANGMAN  ***********\n\n";
                SetColor(7);
                cout<<"\n\t\t\t\t\t\t You didn't get it right";
                cout<<"\n\t\t\t\t\t\t     Score: -5 \n\n";
                continue;
            }
            system("cls");
            SetColor(10);
            cout<<"\n\t\t\t\t\t            ***********  HANGMAN  ***********\n\n";
            SetColor(7);
            continue;
        }
        c=tolower(c);
        if(inarr(choosen,c)==1)
        {
            i--;
            system("cls");
            SetColor(10);
            cout<<"\n\t\t\t\t\t            ***********  HANGMAN  ***********\n\n";
            SetColor(7);
            cout<<"\n\n\t\t\t\t\t\tYou have already guessed "<<c<<". Make a different guess";
            continue;
        }
        append(choosen,c);

        if(check(c)==0)
        {
            wrong++;
            system("cls");
            SetColor(10);
            cout<<"\n\t\t\t\t\t            ***********  HANGMAN  ***********\n\n";
            SetColor(7);
            SetColor(12);
            cout<<"\n\t\t\t\t\t\t "<<c;
            SetColor(7);
            cout<<" is not in the word";
            cout<<"\n\t\t\t\t\t\t Score: -1 \n\n";
            append(incorrect,c);
            continue;
        }
        else
        {
            i--;
        }
        system("cls");
        SetColor(10);
        cout<<"\n\t\t\t\t\t            ***********  HANGMAN  ***********\n\n";
        SetColor(7);
        cout<<"\n\n\n\n";
    }
    if(compare()==0)
    {
        end_time=time(NULL);
        t=end_time-start_time;
        scoring();
        system("cls");
        SetColor(10);
        cout<<"\n\t\t\t\t\t            ***********  HANGMAN  ***********\n\n";
        SetColor(7);
        cout<<"\n\n\n\t\t\t\t\t\t You didn't get it right!\n\t\t\t\t\t\t  That's alright\n\t\t\t\t\t\t  Play again!";
        cout<<"\n\n\t\t\t\t\t\t The word was ";
        theword();
        cout<<"\n\t\t\t\t\t\t Your score: "<<0;
        cout<<"\n\t\t\t\t\t\t You took "<<t<<" seconds";
        cout<<endl;
        draw();
        cin.get();
        return(0);
    }
}

class PvP:public game
{
    int n,score1[5],score2[5],g1,g2,tscore1,tscore2;
    public:
        PvP()
        {
            n=g1=g2=tscore1=tscore2=0;
            for(int i=0;i<5;i++)
                score1[i]=score2[i]=0;
        }
        void setn()
        {
            int ch;
            cout<<"\n\t\t\t\t\t\t 1) Best of 3 rounds";
            cout<<"\n\t\t\t\t\t\t 2) Best of 5 rounds\n\t\t\t\t\t\t";
            cin>>ch;
            while(ch!=1 && ch!=2)
            {
                cout<<"\n\t\t\t\t\t\t Try again\n";
                cin>>ch;
            }
            if(ch==1)
                n=3;
            else   
                n=5;
        }
        void player_chooses();
        int play();
        void winner();
};

void PvP::player_chooses()
{
    category='z';       //miscellaneous category code
    
    cout<<"\n\t\t\t\t\t\t Enter the word(s): ";
    //cin.ignore();
    cin.getline(word,40);
    while(word[0]=='\0')
    {
        cout<<"\n\t\t\t\t\t\t Enter the word(s): ";
        //cin.ignore();
        cin.getline(word,40);
    }
    lower(word);
    if(strlen(word)!=0)
    {
        length=strlen(word);
        ofstream file;                          //open file to write in it
        file.open("level1.txt",ios::app);
        file<<category<<length<<' '<<word<<endl;     //write char, length and word
        file.close();
    }
    
    return;
}

int PvP:: play()
{
    int i=0;
    char q;
    setn();
    cin.ignore();
    //cin.get();
    /*SetColor(10);
        cout<<"\n\t\t\t\t\t            ***********  HANGMAN  ***********\n\n";
        SetColor(7);
        */
    while(i<n && ( (g1<=n/2  && g2<=n/2) || g1==g2) )
    {
        int p1=0,p2=0,p=0;
        system("cls");
        SetColor(10);
        cout<<"\n\t\t\t\t\t            ***********  HANGMAN  ***********\n\n";
        SetColor(7);

        cout<<"\n\n\n\t\t\t\t\t\t Player 1, ";
        player_chooses();
        system("cls");
        
        SetColor(10);
        cout<<"\n\t\t\t\t\t            ***********  HANGMAN  ***********\n\n";
        SetColor(7);
        
        cout<<"\n\t\t\t\t\t\t Player 2, guess the word: ";
        //cin.ignore();
        cin.get();
        p=game::play();
        if(p==1)
        {
            p1=1;
            score2[i]+=score;
            tscore2+=score;
        }
        else
        {
            score1[i]+=30;
            tscore1+=score;
        }
        system("cls");
        SetColor(10);
        cout<<"\n\t\t\t\t\t            ***********  HANGMAN  ***********\n\n";
        SetColor(7);
        reset();
        
        p=0;
        cout<<"\n\n\t\t\t\t\t\t Player 2, ";
        player_chooses();
        system("cls");
        
        SetColor(10);
        cout<<"\n\t\t\t\t\t            ***********  HANGMAN  ***********\n\n";
        SetColor(7);
        
        cout<<"\n\n\t\t\t\t\t\t Player 1, guess the word: ";
        cin.get();
        p=game::play();
        if(p==1)
        {
            p2=1;
            score1[i]+=score;
            tscore1+=score;
        }
        else
        {
            score2[i]+=30;
            tscore2+=score;
        }
        SetColor(10);
        if(p1>p2)
        {
            g1++;
            cout<<"\n\n\t\t\t\t\t\t Player 1 wins this round!!";
        }
        else if(p2>p1)
        {
            g2++;
            cout<<"\n\n\t\t\t\t\t\t Player 2 wins this round!!";
        }
        else if(score1[i]>score2[i])
        {
            g1++;
            cout<<"\n\n\t\t\t\t\t\t Player 1 wins this round!!";
        }
        else if(score2[i]>score1[i])
        {
            g2++;
            cout<<"\n\n\t\t\t\t\t\t Player 2 wins this round!!";
        }
        else 
        {
            cout<<"\n\n\t\t\t\t\t\t Round "<<i+1<<" was a tie\n";
        }
        SetColor(7);
        cout<<"\n\n\t\t\t\t\t\t Scores after Round "<<i+1<<":";
        SetColor(15);
        cout<<"\n\n\t\t\t\t\t\t Player 1: "<<tscore1;
        cout<<"\n\n\t\t\t\t\t\t Player 2: "<<tscore2;
        SetColor(7);
        cout<<"\n\n\t\t\t\t\t\t Press Enter to continue :";
        cin.get();
        
        //system("cls");
        /*else
        {
            g1++;
            g2++;
        }*/
        /*
        cout<<"\n i="<<i<<"  g1="<<g1<<"  g2="<<g2;
        for(int j=0;j<n;j++)
        {
            cout<<"\nscore1["<<j<<"]= "<<score1[j];
            cout<<"\nscore2["<<j<<"]= "<<score2[j];
        }
        */
        i++;
        reset();
    }    
    winner();
    return(3);
}

void PvP::winner()
{
    system("cls");
    SetColor(10);
    cout<<"\n\t\t\t\t\t            ***********  HANGMAN  ***********\n\n";
    //SetColor(7);
    if(g1>g2)
    {
        cout<<"\n\n\n\t\t\t\t\t\t\t\t Player 1 wins!!!";
    }
    else if(g1<g2)
    {
        cout<<"\n\n\n\t\t\t\t\t\t\t\t Player 2 wins!!!";
    }
    else if(tscore1>tscore2)
        cout<<"\n\n\n\t\t\t\t\t\t\t\t Player 1 wins!!!";
    else if(tscore1<tscore2)
        cout<<"\n\n\n\t\t\t\t\t\t\t\t Player 2 wins!!!";
    else 
        cout<<"\n\n\n\t\t\t\t\t\t\t\t It's a tie!!!";
    SetColor(7);
    cout<<"\n\n\n\t\t\t\t\t\t\t Press Enter to continue...";
    cin.get();
    //system("pause");
}
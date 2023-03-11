int inarr(char arr[],char c)        //checks if c is in arr[]
{
    for(int i=0;i<strlen(arr);i++)
        if(arr[i]==c)
            return(1);
        return(0);
}


void SetColor(int ForgC)
{
    WORD wColor;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
                      //We use csbi for the wAttributes word.
    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
                //Mask out all but the background attribute, and add in the forgournd color
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}

class Word
{
    protected:
    char word[40],dashes[40],category,letters[40];
    int length,num;
    public:
    Word()              //constructor
    {
        word[0]=dashes[0]=letters[0]='\0';
        num=0;
    }    
    void makedash()
    {
        int i=0;
        for(i=0;i<length;i++)                    //makes dashes
        {
            if(word[i]==' ' || ispunct(word[i]) || word[i]=='-')
                dashes[i]=word[i];//' ';
            
            else
                dashes[i]='-';
        }
        dashes[i]='\0';                     //terminates the dashes
        let_in_word();                      //indentifies unique letters in the word   
    }

    void show();                             //prints the dashes
    
    void type_of_word();                    //prints the categoy

    char reveal_one_alpha(char arr[]) ;      //reveals all occurances of one alpahabet
    
    int check(char l);                       //checks if l is in word

    int compare();                           //compares word and dashes
    
    void let_in_word();                      //identifies the different characters in word
    
    void theword();
    
    int group(char x[]);         //checks for group of chars
    
    void reset()
    {
        num=0;
        length=0;
        for(int i=0;i<strlen(word);i++)
            word[i]=dashes[i]='\0';
        for(int i=0;i<strlen(letters);i++)
            letters[0]='\0';
    }
};
void Word::show()
{
    if(num>0)
        cout<<"\t\t\t\t\t\tThere is atleast one digit! \n";
    SetColor(15);
    cout<<endl<<"\t\t\t\t\t\t"<<dashes;
    SetColor(7);
}

void Word::type_of_word()
{
        if (category=='m') cout<<"\t\t\t\t\t\t\t\tMovie";
        if (category=='a') cout<<"\t\t\t\t\t\t\t\tAnimal";
        if (category=='p') cout<<"\t\t\t\t\t\t\t\tSport";
        if (category=='s') cout<<"\t\t\t\t\t\t\t\tSong";
        if (category=='c') cout<<"\t\t\t\t\t\t\t\tAutomobile Companies";
        if (category=='e') cout<<"\t\t\t\t\t\t\t\tElectronics";
        if (category=='h') cout<<"\t\t\t\t\t\t\t\tClothing Brands";
        if (category=='w') cout<<"\t\t\t\t\t\t\t\tWatch Brands";
        if (category=='z') cout<<"\t\t\t\t\t\t\t\tMiscellaneous";
        if (category=='r') cout<<"\t\t\t\t\t\t\t\tDictionary word";
        if (category=='i') cout<<"\t\t\t\t\t\t\t\tIdioms, Phrases or Proverbs";
        cout<<endl;
}

char Word::reveal_one_alpha(char arr[])       //reveals all occurances of one alpahabet
{
    long i=time(NULL);
    int l=strlen(letters);
    i=i%l;
    while(i>=0 && i<l)
    {
        if(inarr(arr,letters[i])==0)
            return(letters[i]);
        i=(i+1)%l;
    }
}

int Word::check(char l)                       //checks if l is in word
{
    int flag=0;
    l=tolower(l);
    for(int i=0;i<length;i++)
    {
        if(word[i]==l)
        {
            flag=1;
            dashes[i]=l;
        }
    }
    return(flag);               //returns 1 if l exists in word, else 0
}

int Word::compare()                           //compares word and dashes
{
    for(int i=0;i<length;i++)
        if(word[i]!=dashes[i])
        {
            return(0);
        }
    return(1);                   //returns 1 if dashes==word
}

void Word::let_in_word()                      //identifies the different characters in word
{
    int j=0;
    for(int i=0;i<length;i++)
    {
        if(!isspace(word[i]) && !ispunct(word[i]))      //excludes spaces and puctuations
            if(inarr(letters,word[i])==0)
            {
                letters[j]=word[i];
                j++;
            }
        if(isdigit(word[i]))        //counts number of digits
            num++;
    }
    letters[j]='\0';
}

void Word::theword()
{
    SetColor(10);
    //cout<<word;             //prints the word
    int flag=1;
    for(int i=0;i<length;i++)
    {
        if(flag && isalpha(word[i]))
        {
            cout<<char(toupper(word[i]));
            flag=0;
        }
        else
            cout<<word[i];
        if(word[i]==' ')
            flag=1;
    }
    SetColor(7);
}

int Word::group(char x[])         //checks for group of chars
{
    if(strlen(x)>length)    //if x is longer than length
    {
        char ch;
        cout<<"\n\t\t\t\t\t Look like you've made a very long guess.\n Try again.\n\t\t\t\t\t   ";
        return(-1);
    }
    int flag=0,c=0;
    for(int k=0;k<=length-strlen(x);k++)
    {
        flag=1;
        for(int i=k,j=0; i<length && j<strlen(x); i++,j++)
        {
            if(word[i]!=x[j])
            {
                flag=0;
                continue;
            }
        }
        if(flag==1)
        {
            c=1;
            for(int i=k,j=0;j<strlen(x);j++,i++)
            {
                dashes[i]=x[j];
                check(dashes[i]);
            }
        }
    }
    return(c);
}
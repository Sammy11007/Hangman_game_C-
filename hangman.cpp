#include <iostream>
#include <cstdlib>      //for sysytem and exit
#include <fstream>
#include <string.h>      //for strlen, strcpy
#include <ctime>
#include <windows.h>
//#include <dos.h>
using namespace std;

#include"word.h"
#include"trial.h"

int main()
{
    char choice='\0';
    do
    {
        game *G;
        
        int p;
        char ch='\0',lvl;
        
        system("cls");
        SetColor(10);
        cout<<"\n\t\t\t\t\t            ***********  HANGMAN  ***********\n\n";
        SetColor(7);
        cout<<"\t\t\t\t\t\t--------------------------------------------------------------\n";
        cout<<"\t\t\t\t\t\tARE YOU READY TO SAVE HIM FROM THE GALLOWS? TAKE UP THE CHALLENGE!!!\n";
        cout<<"\t\t\t\t\t\tGAME RULES\n";
        rules();
        cout<<"\n\t\t\t\t\t Press enter to go to the game\n\t\t\t\t\t";
        cin.get();
        system("cls");
        display_menu(ch);
        if(ch=='p')
        {
            G=new PvP;
            G->play();
            delete G;
        }
        else if(ch=='c' || ch=='a')
        {
            system("cls");
            SetColor(10);
            cout<<"\n\t\t\t\t\t            ***********  HANGMAN  ***********\n\n";
            SetColor(7);
            cout<<"\t\t\t\t\t\t--------------------------------------------------------------\n";
            cout<<"\n\n\t\t                                   Choose the level: 1) EASY                2) HARD\n\t\t\t\t\t\t";
            cin>>lvl;
            cin.ignore(20,'\n');
            lvl=tolower(lvl);
            
            while(lvl!='2' && lvl!='1' && lvl!='e' && lvl!='h')
            {
                cout<<"\n\t\t\t\t\t\t Wrong entry, try again";
                cin>>lvl;
                cin.ignore(20,'\n');
                lvl=tolower(lvl);
            }
            if(lvl=='1' || lvl=='e')
                G=new Level1;
            else
                G=new Level2;
            system("cls");
        }
        else if(ch=='q')
        {
            system("cls");
            SetColor(10);
    cout<<"\n\t\t\t\t\t            ***********  HANGMAN  ***********\n\n\n\n";
    SetColor(7);
            //cout<<"\n\t\t\t\t\t            ***********  HANGMAN  ***********\n\n\n\n";
            cout<<"\t\t\t\t\t\tBe sure to play again!\n\n\n";
            
            exit(0);
        }
        if(ch=='a')
            G->player_adds();
        else if(ch=='c')
            G->comp_chooses();
        
        if(ch!='a' && ch!='p')
        {    
            SetColor(10);
            cout<<"\n\t\t\t\t\t            ***********  HANGMAN  ***********\n\n\n\n";
            SetColor(7);
            int r=G->play();
            delete G;
        }
        cout<<"\n\t\t\t\t\t\t Do you want to play again? y or n ";
        cin.get(choice);
        cin.ignore(20,'\n');
    }
    while(choice=='y' || choice=='Y');
    return(1);
}
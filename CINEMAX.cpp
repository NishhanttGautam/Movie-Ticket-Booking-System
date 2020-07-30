#include <iostream>
#include <stdlib.h>
using namespace std;
typedef struct node
{
    char row_no;
    int seat_no,pin;
    char book;
    struct node *next,*prev;
} node;
class main_class
{
public:
    node *hn;
    main_class()
    {
        hn=NULL;
    }
public:
    void create()
    {
        node *nn,*cn;
        int j=1;
        int k=2;
        char c ='A';
        do
        {
            int i=1;
            do
            {
                k=(k*k)/10+100-k/2;
                nn=new node();
                nn->next=nn->prev=NULL;
                nn->row_no=c;
                nn->seat_no=i;
                nn->pin=k;
                nn->book='a';
                if(hn==NULL)
                {
                    hn=nn;
                    nn->next=nn->prev=hn;
                }
                else
                {
                    cn=hn;
                    while(cn->next!=hn)
                        cn=cn->next;
                    cn->next=nn;
                    nn->prev=cn;
                    nn->next=hn;
                    hn->prev=nn;
                }
                i++;
            }
            while(i<=7);
            j++;
            c++;
        }
        while(j<=10);
    }
    void display()
    {
        system("color 79");
        node *cn;
        cn=hn;
        cout<<"------------------------------------------------------------------\n";
        cout<<"|                            Platinum                            |\n";
        while(cn->next!=hn)
        {
            if((cn->prev)->row_no!=cn->row_no)
                cout<<"| ";
            cout<<cn->row_no;
            cout<<cn->seat_no;
            if(cn->book=='a')
                cout << " -> a  ";
            else if(cn->book=='b'){
                {
                cout << " -> NA ";
                }
                }
            if((cn->next)->row_no!=cn->row_no)
                cout<<"|\n";
            if(cn->row_no=='C'&&cn->seat_no==7)
            {
                cout<<"------------------------------------------------------------------\n";
                cout<<"|                             gold                               |\n";
            }
            if(cn->row_no=='H'&&cn->seat_no==7)
            {
                cout<<"------------------------------------------------------------------\n";
                cout<<"|                            Silver                              |\n";
            }
            cn=cn->next;
        }
        cout<<cn->row_no;
        cout<<cn->seat_no;
        if(cn->book=='a')
            cout << " -> a  ";
        else
            cout << " -> b  ";
        cout<<"|\n";
        cout<<"------------------------------------------------------------------\n\n";
        cout<<"PLATINUM-> 150              GOLD-> 100                  SILVER->60\n";
    }
    void display1(node *tmp[20],int n)
    {
        if(n!=1)
        {
            cout<<"------------------------------------------------------------------\n";
            cout<<"THANK YOU!\nYOU HAVE SUCCESSFULLY BOOKED THE SEATS\n";
            for(int i=1; i<n; i++)
                cout<<tmp[i]->row_no<<tmp[i]->seat_no<<"    PIN : "<<tmp[i]->pin<<"\n";
            cout<<"!!!!!!!!!!!!!!!!!!KEEP PIN SAFELY!!!!!!!!!!!!!!!!!!!\n";
            cout<<"PINS ARE REQUIRED AT THE TIME OF CANCELLATION OF SEATS\n";
            cout<<"------------------------------------------------------------------\n";
        }
    }
    void book_seat()
    {
        node *cn,*temp[20];
        int n,z,flag;
        char row;
        int seat;
        char ch;
        do
        {
            z=1;
            cout<<"\nEnter No Of Tickets u Want To Buy: ";
            cin>>n;
            cout<<"\nEnter Seat Number(s): \n";
            for(int i=1; i<=n; i++)
            {
                cout<<"NO "<<i<<" = ";
                cin>>row>>seat;
                cn=hn;
                if(row>='A'&&row<='E')
                {
                    while(cn->next!=hn)
                    {
                        if(cn->row_no==row && cn->seat_no==seat)
                        {
                            if(cn->book=='a')
                            {
                                cn->book='b';
                                temp[z]=cn;
                                z++;
                            }
                            else
                            {
                                cout<<"INVALID CHOICE!\n";
                                cout<<cn->row_no<<cn->seat_no<<" Seat is already reserved \n";
                            }
                        }
                        cn=cn->next;
                    }
                    if(cn->row_no==row && cn->seat_no==seat)
                    {
                        if(cn->book=='a')
                        {
                            cn->book='b';
                            temp[z]=cn;
                            z++;
                        }
                        else
                        {
                            cout<<"INVALID CHOISE!\n";
                            cout<<cn->row_no<<cn->seat_no<<" Seat is already reserved\n";
                        }
                    }
                }
                else //
                {
                    while(cn->prev!=hn)
                    {
                        if(cn->row_no==row && cn->seat_no==seat)
                        {
                            if(cn->book=='a')
                            {
                                cn->book='b';
                                temp[z]=cn;
                                z++;
                            }
                            else
                            {
                                cout<<"INVALID CHOISE!\n";
                                cout<<cn->row_no<<cn->seat_no<<" Seat is already reserved \n";
                            }
                        }
                        cn=cn->prev;
                    }
                    if(cn->row_no==row && cn->seat_no==seat)
                    {
                        if(cn->book=='a')
                        {
                            cn->book='b';
                            temp[z]=cn;
                            z++;
                        }
                        else
                        {
                            cout<<"INVALID CHOICE!\n";
                            cout<<cn->row_no<<cn->seat_no<<" Seat is already reserved\n";
                        }
                    }
                }
            }
            display1(temp,z);
            cout<<"\n\nPRESS 1 To check Seat Status\n";
            cout<<"PRESS 2 To book other seat\n";
            cout<<"PRESS 3 To Exit BOOKING PORTAL\n";
            cout<<"\ninput: ";
            cin>>ch;
            if(ch==1)
                display();
        }
        while(ch=='2');
    }
    void cancel()
    {
        char row,ch;
        int seat,pin;
        node *cn;
        cout<<"SEAT CANCELLATION\n";
        do
        {
            ch='a';
            cn=hn;
            cout<<"SEAT NUMBER :";
            cin>>row>>seat;
            cout<<"PIN :";
            cin>>pin;
            if(row>='A'&&row<='E')
            {
                while(cn->next!=hn)
                {
                    if(cn->row_no==row && cn->seat_no==seat && cn->pin==pin)
                    {
                        cout<<"Are you sure u want to cancel the Seat (y/n) ";
                        char c;
                        cin>>c;
                        if(c=='y'||c=='Y')
                        {
                            cout<<"SEAT CANCELLED SUCCESSFULLY!\n";
                            cn->book='a';
                        }
                    }
                    else if(cn->row_no==row && cn->seat_no==seat && cn->pin!=pin)
                    {
                        cout<<"invalid SEAT NUMBER && PIN combination!!!!\n";
                    }
                    cn=cn->next;
                }
                if(cn->row_no==row && cn->seat_no==seat && cn->pin==pin)
                {
                    cout<<"Are you sure u want to cancel (y/n) ";
                    char c;
                    cin>>c;
                    if(c=='y'||c=='Y')
                    {
                        cout<<"SEAT CANCELLED SUCCESFULLY!\n";
                        cn->book='a';
                    }
                }
                else if(cn->row_no==row && cn->seat_no==seat && cn->pin!=pin)
                {
                    cout<<"invalid SEAT NUMBER && PIN combination!!!!\n";
                }
            }
            else
            {
                while(cn->next!=hn)
                {
                    if(cn->row_no==row && cn->seat_no==seat && cn->pin==pin)
                    {
                        cout<<"Are you sure u want to cancel the Seat (y/n) ";
                        char c;
                        cin>>c;
                        if(c=='y'||c=='Y')
                        {
                            cout<<"SEAT CANCELLED SUCCESFULLY!\n";
                            cn->book='a';
                        }
                    }
                    else if(cn->row_no==row && cn->seat_no==seat && cn->pin!=pin)
                    {
                        cout<<"invalid SEAT NUMBER && PIN combination!!!!\n";
                    }
                    cn=cn->next;
                }
                if(cn->row_no==row && cn->seat_no==seat && cn->pin==pin)
                {
                    cout<<"Are you sure u want to cancel (y/n) ";
                    char c;
                    cin>>c;
                    if(c=='y'||c=='Y')
                    {
                        cout<<"SEAT CANCELLED SUCCESFULLY!\n";
                        cn->book='a';
                    }
                }
                else if(cn->row_no==row && cn->seat_no==seat && cn->pin!=pin)
                {
                    cout<<"invalid SEAT NUMBER && PIN combination!!!!\n";
                }
            }
            cout<<"\n\nPRESS 1 To Check Seat Status\n";
            cout<<"PRESS 2 To cancel More Tickets\n";
            cout<<"PRESS 3 To Exit CANCELLATION PORTAL\n";
            cout<<"\ninput: ";
            cin>>ch;
            if(ch==1)
                display();
        }
        while(ch=='2');
    }
};

int main()
{
    main_class o;
    int ch;
    char c;
    cout<<"\n\n\n";
    cout<<"                 ---!!!    CINEMAX    !!!---\n";
    cout<<"            ----!!!  [ ARRANGEMENT SYSTEM]   !!!----\n\n";
    o.create();
    do
    {
        cout<<"\n\n\n";
        cout<<"PRESS 1-> BOOK TICKETS\n";
        cout<<"PRESS 2-> CANCEL TICKETS\n";
        cout<<"PRESS 3-> LIST OF MOVIES\n";
        cout<<"PRESS 4-> LUCKY DRAW WINNER\n";
        cout<<"PRESS 5-> EXIT\n";
        cout<<"\ninput: ";
        cin>>ch;
        switch(ch)
        {
        case 1:
            o.display();
            o.book_seat();
            o.display();
            break;
        case 2:
            o.display();
            o.cancel();
            o.display();
            break;
        case 4:{
            int v1 = rand() % 8;
            int v2= rand()%10;
            cout<<"column:"<<v1<<" ";
            cout<<"row:"<<v2<<" "<<"\n";
            cout<<"Congratulations!! You will be awarded a free coupon for discounted price"<<"\n";
            break;
        }
        case 3:{
            cout<<" "<<"1->"<<"Fantastic Beasts: The Crimes of Grindelwald"<<"\n";
            cout<<" "<<"2->"<<"Robin Hood"<<"\n";
            cout<<" "<<"3->"<< "The Nutcracker and the Four Realms"<<"\n";
            cout<<" "<<"4->"<<"Ralph Breaks The Internet:Wreck it Ralph 2"<<"\n";
            cout<<" "<<"5->"<<"The Girl in the Spider's Web"<<"\n";
            break;
        }
        }
             if(ch!=5)
        {
            cout<<"\n\nPRESS 1 To Main Menu\n";
            cout<<"PRESS 2 To Exit CINEMAX PORTAL\n";
            cout<<"\ninput: ";
            cin>>c;
        }
    }
    while(c=='1');
    cout<<"\n\n\n";
    return 0;
}

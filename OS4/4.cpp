#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <cmath>
#include <utility>
#include <cstdio>
#include <iomanip>
#include <iterator>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <ctime>
#include <conio.h>
#include <windows.h>

using namespace std;
const char ul=201; const char ur=187; const char dl=200; const char dr=188; const char ve=186;
const char go=205; const char ff=219; const char lf=221; const char rf=222; const char lur=203;
const char urd=185; const char uld=204; const char ldr=202; const char lurd=206; typedef long long ll;
char f[60][140]; int J;
ll n,m,i,k,j,t,All,x,y,z,q,w,ColFol=0,ColFil=0,LinePos=0,MaxMemory=536870912;
char c; string s,yyy; vector<int> v; string B; vector< pair<int,string> > Y;
ll random(ll r){return rand()%r;}

void gotoxy(unsigned x, unsigned y)
{
  x--; y--;
  COORD cr = {SHORT(x), SHORT(y)};
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cr);
}

string NumToStr(int K)
{
    string KK=""; int x=K;
    for(;;)
    {
        KK=char('0'+x%10)+KK;
        x/=10; if(x==0)break;
    }
    return KK;
}

string MemFormat(int E, int kkk)
{
    string res;
    if(E<1024)res=NumToStr(E)+" B";
    else if(E<1024*1024)res=NumToStr(E/1024)+","+NumToStr(((E%1024)*100/1024)/10)+NumToStr(((E%1024)*100/1024)%10)+" KB";
    else res=NumToStr(E/(1024*1024))+","+NumToStr(((E%(1024*1024))*100/(1024*1024))/10)+NumToStr(((E%(1024*1024))*100/(1024*1024))%10)+" MB";
    int oo=res.size(); for(int o=1; o<=kkk-oo; o++)res=" "+res; return res;
}

string CrFolName(){ string W="folder"+NumToStr(ColFol); return W; }
string CrFilName(){ string W="file"+NumToStr(ColFil)+".txt"; return W; }

string GetTime()
{
    time_t tim=time(0); tm *T=localtime(&tim); string s1="";

    if(T->tm_wday==1)s1="Mon "; else if(T->tm_wday==2)s1="Tue "; else
    if(T->tm_wday==3)s1="Wed "; else if(T->tm_wday==4)s1="Thu "; else
    if(T->tm_wday==5)s1="Fri "; else if(T->tm_wday==6)s1="Sat "; else s1="Sun ";

    if(T->tm_mon==0)s1+="Jan "; else if(T->tm_mon==1)s1+="Feb "; else
    if(T->tm_mon==2)s1+="Mar "; else if(T->tm_mon==3)s1+="Apr "; else
    if(T->tm_mon==4)s1+="May "; else if(T->tm_mon==5)s1+="Jun "; else
    if(T->tm_mon==6)s1+="Jul "; else if(T->tm_mon==7)s1+="Aug "; else
    if(T->tm_mon==8)s1+="Sep "; else if(T->tm_mon==9)s1+="Oct "; else
    if(T->tm_mon==10)s1+="Nov "; else s1+="Dec ";
    if(T->tm_mday<10)s1+="0"; s1+=NumToStr(T->tm_mday); s1+=" ";
    s1+=NumToStr(T->tm_year+1900); s1+=" ";
    if(T->tm_hour<10)s1+="0"; s1+=NumToStr(T->tm_hour); s1+=":";
    if(T->tm_min<10)s1+="0"; s1+=NumToStr(T->tm_min); s1+=":";
    if(T->tm_sec<10)s1+="0"; s1+=NumToStr(T->tm_sec); return s1;
}
struct SystemUnit
{
    bool Ex=1; vector<int> V; int Sz=0,Ind=-1,Ty=0;
    string Name="", DT="", P=""; string Tx="";
};
SystemUnit A[100001]; int AA[100001];
map<string,int> M;
map<string,int>::iterator it;
//vector<string,int> Ass;

int FindEmpty()
{
    int o; for(o=1; o<100001; o++)if(A[o].Ex==0)return o;
    return -1;
}

void RecPlusMem(string path, int mem)
{
    if(path=="NaN")return;
    A[M[path]].Sz+=mem;
    RecPlusMem(A[M[path]].P,mem);
}

SystemUnit NewUnit(int ind, string p, string name, string tx, int ty)
{
    SystemUnit sy;
    sy.Ex=1; sy.Ty=ty; sy.V.clear(); sy.Sz=tx.size(); sy.Ind=ind;
    sy.Name=name; sy.DT=GetTime(); sy.P=p; sy.Tx=tx;M[name]=ind;
    A[M[p]].V.push_back(ind);
    RecPlusMem(p,tx.size());
    return sy;
}

enum ConsoleColor
{
        Black         = 0,
        Blue          = 1,
        Green         = 2,
        Cyan          = 3,
        Red           = 4,
        Magenta       = 5,
        Brown         = 6,
        LightGray     = 7,
        DarkGray      = 8,
        LightBlue     = 9,
        LightGreen    = 10,
        LightCyan     = 11,
        LightRed      = 12,
        LightMagenta  = 13,
        Yellow        = 14,
        White         = 15
};

void Color(ConsoleColor text, ConsoleColor background)
{
   HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
   SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

void MakeLargeScreen()
{
    HANDLE out_handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD maxWindow = GetLargestConsoleWindowSize(out_handle); // размер самого большого возможного консольного окна
    SMALL_RECT srctWindow = { 0, 0, maxWindow.X - 1, maxWindow.Y - 1 };
    SMALL_RECT minWindow = { 0, 0, 0, 0 };
    SetConsoleWindowInfo(out_handle, true, &minWindow);
    SetConsoleScreenBufferSize(out_handle, maxWindow);
    SetConsoleWindowInfo(out_handle, true, &srctWindow);
}

void MakeCursor(bool boool)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO structCursorInfo;
    GetConsoleCursorInfo(handle,&structCursorInfo);
    structCursorInfo.bVisible = boool;
    SetConsoleCursorInfo(handle,&structCursorInfo);
}

void SetField(int MN)
{
    fstream inp; inp.open("field.txt");
    for(i=1; i<=60; i++)
    {
        for(j=1; j<=140; j++)
        {
            inp >> c;
            if(c!='Ы')
            {
                c=' ';
            }else c=219;
            f[i][j]=c;
        }
    }
    inp.close();
}

bool check(int x, int y)
{
    if(f[x][y]=='Ы')return 0;else return 1;
}


void DrawAll()
{
    int e,o; gotoxy(1,1); Color(White,Black);
    cout << ul << go << go << go << go << go << go << go << go << go << lur; for(e=1; e<=100; e++)cout << go; cout << ur << ul; for(e=1; e<=6; e++)cout << go; cout << lur; for(e=1; e<=21; e++)cout << go; cout << ur << ul << go << go << go << go << go << go << go << go << go << go << go << go << go << ur << endl;
    cout << ve; Color(LightCyan,Black); cout << "Directory"; Color(White,Black); cout << ve; for(e=1; e<=100; e++)cout << " "; cout << ve << ve; Color(LightGreen,Black); cout << "Memory"; Color(White,Black); cout << ve << "                     " << ve << ve; Color(Black,Red); cout << "Rus"; Color(White,Blue); cout << "Linux"; Color(White,Black); cout << " v1.0" << ve << endl;
    cout << dl << go << go << go << go << go << go << go << go << go << ldr; for(e=1; e<=100; e++)cout << go; cout << dr << dl; for(e=1; e<=6; e++)cout << go; cout << ldr; for(e=1; e<=21; e++)cout << go; cout << dr << dl << go << go << go << go << go << go << go << go << go << go << go << go << go << dr << endl;
    cout << ul; for(e=1; e<=74; e++)cout << go; cout << lur; for(e=1; e<=24; e++)cout << go; cout << lur; for(e=1; e<=10; e++)cout << go; cout << ur << ul; for(e=1; e<=50; e++)cout << go; cout << ur << endl;
    cout << ve << "Name"; for(e=1; e<=70; e++)cout << " "; cout << ve << "Date/Time"; for(e=1; e<=15; e++)cout << " "; cout << ve << "Size"; for(e=1; e<=6; e++)cout << " "; cout << ve << ve; Color(Black,White); for(e=1; e<=50; e++)cout << " "; Color(White,Black); cout << ve << endl;
    cout << uld; for(e=1; e<=74; e++)cout << go; cout << lurd; for(e=1; e<=24; e++)cout << go; cout << lurd; for(e=1; e<=10; e++)cout << go; cout << urd << ve; Color(Black,White); for(e=1; e<=50; e++)cout << " "; Color(White,Black); cout << ve << endl;
    for(o=1; o<=30; o++){cout << ve; for(e=1; e<=74; e++)cout << " "; cout << ve; for(e=1; e<=24; e++)cout << " "; cout << ve; for(e=1; e<=10; e++)cout << " "; cout << ve << ve; Color(Black,White); for(e=1; e<=50; e++)cout << " "; Color(White,Black); cout << ve << endl; }
    cout << dl; for(e=1; e<=74; e++)cout << go; cout << ldr; for(e=1; e<=24; e++)cout << go; cout << ldr; for(e=1; e<=10; e++)cout << go; cout << dr << dl; for(e=1; e<=50; e++)cout << go; cout << dr << endl;
    cout << ul << go << go << lur << go << go << go << go << go << go << go << go << go << go << ur << ul << go << go << lur << go << go << go << go << go << go << go << go << ur << ul << go << go << lur << go << go << go << go << ur << ul << go << go << lur << go << go << go << go << go << ur << ul << go << go << lur << go << go << go << go << go << go << ur << ul; for(e=1; e<=100; e++)cout << go; cout << ur << endl;
    cout << ve; Color(Yellow,Black); cout  << "F1"; Color(White,Black); cout << ve; Color(Yellow,Black); cout << "New folder"; Color(White,Black); cout << ve << ve; Color(Yellow,Black); cout << "F2"; Color(White,Black); cout << ve; Color(Yellow,Black); cout << "New file"; Color(White,Black); cout << ve << ve; Color(LightBlue,Black); cout << "F3"; Color(White,Black); cout << ve; Color(LightBlue,Black); cout << "Copy"; Color(White,Black); cout << ve << ve; Color(LightBlue,Black); cout << "F4"; Color(White,Black); cout << ve; Color(LightBlue,Black); cout << "Paste"; Color(White,Black); cout << ve << ve; Color(Red,Black); cout << "F5"; Color(White,Black); cout << ve; Color(Red,Black); cout << "Delete"; Color(White,Black); cout << ve << ve; for(e=1; e<=100; e++)cout << " "; cout << ve << endl;
    cout << dl << go << go << ldr << go << go << go << go << go << go << go << go << go << go << dr << dl << go << go << ldr << go << go << go << go << go << go << go << go << dr << dl << go << go << ldr << go << go << go << go << dr << dl << go << go << ldr << go << go << go << go << go << dr << dl << go << go << ldr << go << go << go << go << go << go << dr << dl; for(e=1; e<=100; e++)cout << go; cout << dr << endl;
}

void ShowText(string Z)
{
    MakeCursor(0);
    int o,e; Color(Black,White);
    for(o=0; o<Z.size(); o++)
    {
        if(o%50==0)gotoxy(114,5+o/50);
        cout << Z[o];
    }
    MakeCursor(1);
}

void ClearField()
{
    Color(Black,White);
    int o; for(o=0; o<1600; o++)
    {
        if(o%50==0)gotoxy(114,5+o/50);
        cout << " ";
    }
}

void DeletePath(string path)
{
    //cout << path << "                      " << endl;
    int o; for(o=0; o<A[M[path]].V.size(); o++)DeletePath(A[A[M[path]].V[o]].Name);
    A[M[path]].DT="NaN"; A[M[path]].Ex=0; A[M[path]].Name="NaN"; A[M[path]].P="NaN";
    A[M[path]].Sz=0; A[M[path]].Tx="NaN"; A[M[path]].Ty=0; A[M[path]].V.clear();
    M[path]=0;
}

void FillB(string path)
{
    if(!A[M[path]].Ex)return;
    B[M[path]]='1';
    int o; for(o=0; o<A[M[path]].V.size(); o++)FillB(A[A[M[path]].V[o]].Name);
}

void FindAll(string BufDir, int depth, int BS)
{
    string rt="";
    int o; for(o=0; o<BufDir.size(); o++)
    {
        if(o>=BS)rt+=BufDir[o];
    }

    if(depth)Y.push_back( {depth,rt} );
    for(o=0; o<A[M[BufDir]].V.size(); o++)FindAll(A[A[M[BufDir]].V[o]].Name,depth+1,BS);
}

int main()
{
    SetConsoleOutputCP(866);
    srand(time(0));
    MakeLargeScreen();
    //SetField(1);


    DrawAll();

    x=45; y=120;
    string CurrentDirectory="";
    string BufferDirectory="",Q="",QQ="";
    vector<string> Now; int IndNow=0,All=0;
    int CursorPos=0;
    M["/home"]=0; A[0].DT=GetTime(); A[0].Ex=1; A[0].Ind=0; A[0].Name="/home"; A[0].P="NaN"; A[0].Sz=0; A[0].Tx=""; A[0].Ty=1; A[0].V.clear();
    vector<int> AllPoses; AllPoses.clear();
    bool LeftWindow=1; bool FieldClean=1; int PastSize=0;
    MakeCursor(FALSE); bool ShowAll=0;
    ifstream input("system.txt");
    if(input.is_open() && input.peek()!=EOF)
    {
    int Vind,Vsz,Vtype,Vvs,Vi; string E1,E2,t11,t22,t33,t44,t55;
    input >> All >> MaxMemory >> ColFol >> ColFil;
    for(i=0; i<=All; i++)
    {
        input >> t11 >> t22 >> t33 >> t44 >> t55;
        A[i].DT=t11+" "+t22+" "+t33+" "+t44+" "+t55; A[i].V.clear();
        input >> Vind >> E1 >> E2 >> Vsz >> Vtype;
        A[i].Ind=Vind; A[i].Name=E1;
        A[i].P=E2; A[i].Sz=Vsz; A[i].Ty=Vtype;
        if(Vtype==1)
        {
            input >> Vvs; A[i].V.clear();
            for(j=0; j<Vvs; j++)
            {
                input >> Vi; A[i].V.push_back(Vi);
            }
        }
        else
        {
            input >> E1;
            if(E1=="#")E1="";
            A[i].Tx=E1;
        }
        A[i].Ex=1;
        M[A[i].Name]=i;
    }
    }
    /*gotoxy(1,20);
    for(i=0; i<=All; i++)
    {
        cout << A[i].DT << " " << A[i].Ex << " " << A[i].Ind << " " << A[i].Name << " " << A[i].P <<
        " " << A[i].Sz << " " << A[i].Tx << " " << A[i].Ty << " " << A[i].V.size();
        for(j=0; j<A[i].V.size(); j++)cout << " " << A[i].V[j]; cout << endl;
    }*/

    while(true)
    {
        Color(Red,Black); gotoxy(159,2);
        if(ShowAll)cout << All; else cout << "      ";
        PastSize=Now.size();
        Color(Black,Black);
        for(i=0; i<PastSize; i++)
        {
            gotoxy(75,7+i);
            cout << " ";
        }
        //gotoxy(120,4); cout << "Mistake here";



        //if(c==77 && check(x,y+1))y++;
        //if(c==75 && check(x,y-1))y--;
        if(LeftWindow)
        {
            Color(LightGreen,Black); gotoxy(121,2); cout << MemFormat(A[0].Sz,10) << "/" << MemFormat(MaxMemory,10);
        CurrentDirectory=A[IndNow].Name;
        Now.clear();
        if(IndNow)Now.push_back("[..]");
        //gotoxy(1,1); for(i=0; i<A[IndNow].V.size(); i++)cout << A[IndNow].V[i] << " ";
        for(i=0; i<A[IndNow].V.size(); i++)if(A[A[IndNow].V[i]].Ty==1)
        {
            QQ=""; Q=A[A[IndNow].V[i]].Name; for(j=Q.size()-1; j>=1; j--){ QQ=Q[j]+QQ; if(Q[j-1]=='/')break;}
            Now.push_back(QQ);
        }
        //gotoxy(1,1);
        for(i=0; i<A[IndNow].V.size(); i++)if(A[A[IndNow].V[i]].Ty==2)
        {
            QQ=""; Q=A[A[IndNow].V[i]].Name; for(j=Q.size()-1; j>=1; j--){ QQ=Q[j]+QQ; if(Q[j-1]=='/')break;}
            Now.push_back(QQ);
        }
        gotoxy(5,1);
        Color(White,Black);

            for(i=Now.size(); i<PastSize; i++)
            {
                Color(White,Black);
                gotoxy(2,7+i);
                for(j=1; j<=73; j++)cout << " ";
                gotoxy(77,7+i);
                for(j=1; j<=24; j++)cout << " ";
                gotoxy(102,7+i);
                for(j=1; j<=10; j++)cout << " ";
            }
            gotoxy(4,1);
        for(i=0; i<Now.size(); i++)
        {

            {
                gotoxy(2,7+i);
                if(!i && Now[i]=="[..]")
                {
                    if(i==LinePos)Color(LightGreen,White); else Color(LightGreen,Black);
                    cout << char(27) << " ";
                }
                if(A[M[CurrentDirectory+"/"+Now[i]]].Ty==1 && Now[i]!="[..]")
                {
                    if(i==LinePos)Color(Brown,White); else Color(Brown,Black);
                    cout << char(223) << " ";
                }
                if(A[M[CurrentDirectory+"/"+Now[i]]].Ty==2 && Now[i]!="[..]")
                {
                    if(i==LinePos)Color(Brown,White); else Color(Brown,Black);
                    cout << "  ";
                }


            if(i==LinePos)Color(Black,White); else
            {
                if(A[M[CurrentDirectory+"/"+Now[i]]].Ty==2)Color(DarkGray,Black); else Color(White,Black);
            }
            string NowI=Now[i];
            if(NowI.size()>=72)
            {
                if(NowI.size()==72)
                {
                    NowI.erase(72,NowI.size()-72);
                }
                else
                {
                    NowI.erase(72,NowI.size()-72);
                    NowI[NowI.size()-1]='.';
                    NowI[NowI.size()-2]='.';
                    NowI[NowI.size()-3]='.';
                }
            }
            cout << NowI;
            for(j=1; j<=72-NowI.size(); j++)cout << " ";
            gotoxy(77,7+i); if(Now[i]!="[..]")cout << A[M[CurrentDirectory+"/"+Now[i]]].DT; else for(j=1; j<=24; j++)cout << " ";
            Q=MemFormat(A[M[CurrentDirectory+"/"+Now[i]]].Sz,10);
            gotoxy(102,7+i); if(Now[i]!="[..]")cout << Q; else for(j=1; j<=10; j++)cout << " ";
            }
          gotoxy(3,1);

        }
        Color(LightCyan,Black);
        gotoxy(12,2);
        for(i=0; i<CurrentDirectory.size(); i++)if(i<100)cout << CurrentDirectory[i];
        if(CurrentDirectory.size()<100)for(i=1; i<=100-CurrentDirectory.size(); i++)cout << " ";
        if(CurrentDirectory.size()>100){gotoxy(109,2); cout << "...";}
        //Color(LightMagenta,Black);
        //gotoxy(y,x);
        //cout << "+";
        //gotoxy(120,40); //cout << All;
        }

        if(Now.size() && A[M[CurrentDirectory+"/"+Now[LinePos]]].Ty==2 && A[M[CurrentDirectory+"/"+Now[LinePos]]].Tx.size()){ ShowText(A[M[CurrentDirectory+"/"+Now[LinePos]]].Tx); FieldClean=0; }


        //gotoxy(45,5); cout << "                                                 ";
        int rrr=-100;
        if(Now.size())rrr=A[M[CurrentDirectory]].V.size();
        //gotoxy(45,5); cout << All << " " << LinePos << " " << Now.size() << "-" << rrr << " " << PastSize;
        if(LeftWindow)gotoxy(150,40);

        //gotoxy(30,35); cout << Now.size() << ":  "; for(i=0; i<Now.size(); i++)cout << " " << Now[i];

        //cout << "                          ";



        c=getch();




        //gotoxy(114,2); cout << "Changed at " << GetTime();
        if(c==27)
        {
            int kol=0; for(i=0; i<=All; i++)
            if(A[i].Ex){ AA[i]=kol; kol++; } else AA[i]=-1;
            ofstream output("system.txt"); Color(LightRed,Red);
            gotoxy(26,14); cout << ul; for(i=1; i<=102; i++)cout << go; cout << ur;
            gotoxy(26,15); cout << ve << "                                                                                                      " << ve;
            gotoxy(26,16); cout << ve << "                                                                                                      " << ve;
            gotoxy(26,17); cout << ve << "                                                                                                      " << ve;
            gotoxy(26,18); cout << ve << "                                                                                                      " << ve;
            gotoxy(26,19); cout << ve << "                                                                                                      " << ve;
            gotoxy(26,20); cout << dl; for(i=1; i<=102; i++)cout << go; cout << dr;


            Color(Black,LightGray);
            gotoxy(27,15); cout << ul; for(i=1; i<=100; i++)cout << go; cout << ur;
            gotoxy(27,16); cout << ve << "                                            Saving files                                            " << ve;
            gotoxy(27,17); cout << ve << "                                                                                                    " << ve;
            gotoxy(27,18); cout << ve << "                                                                                                    " << ve;
            gotoxy(27,19); cout << dl; for(i=1; i<=100; i++)cout << go; cout << dr;
            int Alll=All; for(i=0; i<=All; i++)if(!A[i].Ex)Alll--;
            output << Alll << " " << MaxMemory << " " << ColFol << " " << ColFil << endl;
            //Ass.clear(); for(i=0; i<=All; i++)Ass.push_back({A[i].Name,i});
            //sort(Ass.begin(),Ass.end());

            for(i=0; i<=All; i++)if(A[i].Ex)
            {
                output << A[i].DT << " " << AA[A[i].Ind] << " " << A[i].Name << " "
                << A[i].P << " " << A[i].Sz << " " << A[i].Ty << " ";
                if(A[i].Ty==2)
                {
                    if(!A[i].Tx.size())A[i].Tx="#";
                    output << A[i].Tx << endl;

                }
                else
                {
                    output << A[i].V.size();
                    for(j=0; j<A[i].V.size(); j++)
                    output << " " << AA[A[i].V[j]];
                    output << endl;
                }

                gotoxy(28,18);
                string Ee=A[i].Name;

                    if(Ee.size()>100)
                    {
                        Ee[97]='.'; Ee[98]='.'; Ee[99]='.';
                        Ee.erase(100,Ee.size()-100);
                    }
                    else if(Ee.size()<100)for(j=1; j<=100-A[i].Name.size(); j++)Ee+=' ';
                cout << Ee;
                gotoxy(77,17);
                cout << i*100/All << "%";
                gotoxy(84,16);
                if(i%400==0)cout << "   "; else
                if(i%400==100)cout << ".  "; else
                if(i%400==200)cout << ".. "; else
                if(i%400==300)cout << "...";
                gotoxy(40,40);
            }
            Sleep(1000);
            gotoxy(60,40); TerminateProcess(GetCurrentProcess(),0);
        }
        if(c==9)LeftWindow=!LeftWindow;
        //gotoxy(20,20);
        if(LeftWindow)
        {
            MakeCursor(FALSE);

        if(c==59 && Now.size()<30)
        {
            All++; ColFol++; A[All]=NewUnit(All,CurrentDirectory,CurrentDirectory+"/"+CrFolName(),"",1);
        }
        if(c==60 && Now.size()<30)
        {
            All++; ColFil++; A[All]=NewUnit(All,CurrentDirectory,CurrentDirectory+"/"+CrFilName(),"",2);
        }
        if(c==61 && Now.size() && Now[LinePos]!="[..]") //F3
        {
            BufferDirectory=CurrentDirectory+"/"+Now[LinePos];
            Color(LightCyan,Black);
            gotoxy(60,39);for(i=0; i<BufferDirectory.size(); i++)if(i<100)cout << BufferDirectory[i];
            if(BufferDirectory.size()<100)for(i=1; i<=100-BufferDirectory.size(); i++)cout << " ";
            if(BufferDirectory.size()>100){gotoxy(157,39); cout << "...";}
        }
        if(c==62 && A[M[CurrentDirectory]].V.size()<29 && BufferDirectory.size() && (A[0].Sz+A[M[BufferDirectory]].Sz<=MaxMemory)) //F3
        {
            B.clear(); for(i=0; i<100001; i++)B+="0"; FillB(BufferDirectory); string D=BufferDirectory,U="";
            for(J=D.size()-1; J>=0; J--)if(D[J]=='/')break; D.erase(0,J); D=CurrentDirectory+D;

            //gotoxy(30,30); cout << Now.size() << ":  "; for(i=0; i<Now.size(); i++)cout << " " << Now[i];
            for(;;)
            {
                gotoxy(1,1); //for(i=0; i<Now.size(); i++)cout << D << "=" << CurrentDirectory << "  " << Now[i] << "_";
                bool SameName=0;
                for(i=0; i<Now.size(); i++)if(D==(CurrentDirectory+"/"+Now[i]))
                {
                    U=D; for(J=D.size()-1; J>=0; J--)if(D[J]=='/')break;

                    D.clear(); for(j=0; j<=J; j++)D+=U[j]; D+="(copy)"; for(j=J+1; j<U.size(); j++)D+=U[j];

                    SameName=1; break;
                }

                if(!SameName)break;
            }
            if(U=="")
            {
                U=D; for(J=U.size()-1; J>=0; J--)if(U[J]=='/')break;
                D=CurrentDirectory;
                for(i=J; i<U.size(); i++)D+=U[i];
            }


            //cout << CurrentDirectory << " " << BufferDirectory << " " << D << "                    ";
            Y.clear(); FindAll(BufferDirectory,0,BufferDirectory.size());
            sort(Y.begin(),Y.end());
            //gotoxy(1,1); for(i=0; i<Y.size(); i++)cout << Y[i].second << " ";
            All++; A[All]=NewUnit(All,CurrentDirectory,D,A[M[BufferDirectory]].Tx,1+bool(D[D.size()-4]=='.'));
            for(i=0; i<Y.size(); i++)
            {
                yyy=Y[i].second;
                for(;;)
                {
                    if(!yyy.size())break;
                    if(yyy[yyy.size()-1]=='/')
                    {
                        yyy.erase(yyy.size()-1,1);
                        break;
                    }
                    else yyy.erase(yyy.size()-1,1);
                }
                //gotoxy(1,15+i); cout << "Cur: " << CurrentDirectory << " Buf: " << BufferDirectory << " Y: " << Y[i].second << " D: " << D << " " << yyy;
                //.clear();
                //U=D; for(J=U.size()-1; J>=0; J--)if(U[J]=='/')break;
                //for(j=J; j<U.size(); j++)D=CurrentDirectory+U[j];
                All++;
                if(A[M[BufferDirectory+Y[i].second]].Ty==1)
                {
                    //gotoxy(1,15+i); cout << All << " " << D+yyy << " " << CurrentDirectory+Y[i].second << " " << "" << 1;
                    A[All]=NewUnit(All,D+yyy,D+Y[i].second,"",1);
                }
                else if(A[M[BufferDirectory+Y[i].second]].Ty==2)
                {
                    //gotoxy(1,15+i); cout << All << " " << D+yyy << " " << CurrentDirectory+Y[i].second << " " << A[M[BufferDirectory+Y[i].second]].Tx << " 2";
                    A[All]=NewUnit(All,D+yyy,D+Y[i].second,A[M[BufferDirectory+Y[i].second]].Tx,2);
                }
            }
        }
        if(c==63 && Now.size() && Now[LinePos]!="[..]")
        {
            Color(DarkGray,LightGray);
            gotoxy(y,x);  //F1-59 F5-63
            //cout << CurrentDirectory+"/"+Now[LinePos] << "                 ";
            RecPlusMem(CurrentDirectory,-A[M[CurrentDirectory+"/"+Now[LinePos]]].Sz);
            //cout << "oki";
            //gotoxy(1,38);
            //for(w=0; w<A[M[ CurrentDirectory+"/"+Now[LinePos] ]].V.size(); w++)cout << A[A[M[ CurrentDirectory+"/"+Now[LinePos] ]].V[w]].Name << endl;
            for(i=0; i<A[M[CurrentDirectory]].V.size(); i++)if(A[A[M[CurrentDirectory]].V[i]].Name==CurrentDirectory+"/"+Now[LinePos])break;
            //cout << "koki";
            DeletePath(CurrentDirectory+"/"+Now[LinePos]);
            A[M[CurrentDirectory]].V[i]=A[M[CurrentDirectory]].V[ A[M[CurrentDirectory]].V.size()-1 ];
            A[M[CurrentDirectory]].V.pop_back();

            if(CurrentDirectory+'/'+Now[LinePos]==BufferDirectory)
                { BufferDirectory="";
            Color(LightCyan,Black);
            gotoxy(60,39);for(i=0; i<100; i++)cout << " ";}
            if(LinePos==Now.size()-1)LinePos--;
        }
        //gotoxy(120,4); cout << "------------";
        /*Color(DarkGray,LightGray);
        gotoxy(y,x);  //F1-59 F5-63
        cout << CurrentDirectory << "                                   ";*/

        if(c==64)ShowAll=!ShowAll;
        if(c==65)
        {
            gotoxy(1,37); for(i=0; i<Now.size(); i++)cout << Now[i] << " ";
        }
        /*{
            gotoxy(1,20);
            for(it=M.begin(); it!=M.end(); it++)
            {
                cout << it->first << " " << it->second << endl;
            }
        }*/
        if(c==80){LinePos++;if(!FieldClean)ClearField(),FieldClean=1;}
        if(c==72){LinePos--;if(!FieldClean)ClearField(),FieldClean=1;}
        if(LinePos==-1)LinePos=Now.size()-1;
        if(LinePos==Now.size())LinePos=0;
        if(c==13)if(A[M[CurrentDirectory+"/"+Now[LinePos]]].Ty!=2)
        {
            if(Now[LinePos]=="[..]"){ AllPoses.pop_back(); IndNow=M[A[M[CurrentDirectory]].P]; LinePos=AllPoses[AllPoses.size()]; ClearField(); } else
            { AllPoses.push_back(LinePos); IndNow=A[M[CurrentDirectory+"/"+Now[LinePos]]].Ind; LinePos=0; }
        }
        }



        if(!LeftWindow)gotoxy(114,5);
        if(Now.size() && A[M[CurrentDirectory+"/"+Now[LinePos]]].Ty==2 && !LeftWindow)
        {
            MakeCursor(TRUE);
            if(((c>32 && c<=175) || (c>=224 && c<=241)) && A[M[CurrentDirectory+"/"+Now[LinePos]]].Tx.size()<1600 && (A[0].Sz+1<=MaxMemory)){ A[M[CurrentDirectory+"/"+Now[LinePos]]].Tx+=c; RecPlusMem(CurrentDirectory+"/"+Now[LinePos],1); }
            else if(c==8 && A[M[CurrentDirectory+"/"+Now[LinePos]]].Tx.size()){Color(Black,White); gotoxy(114+(A[M[CurrentDirectory+"/"+Now[LinePos]]].Tx.size()-1)%50,5+(A[M[CurrentDirectory+"/"+Now[LinePos]]].Tx.size()-1)/50); cout << " "; A[M[CurrentDirectory+"/"+Now[LinePos]]].Tx=A[M[CurrentDirectory+"/"+Now[LinePos]]].Tx.substr(0,A[M[CurrentDirectory+"/"+Now[LinePos]]].Tx.size()-1); RecPlusMem(CurrentDirectory+"/"+Now[LinePos],-1); }
        }


    }
    return 0;
}


//void AddAll(string CurDir, string BufDir, string DirName)

